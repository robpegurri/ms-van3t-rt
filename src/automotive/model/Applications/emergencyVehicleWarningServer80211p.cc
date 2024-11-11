/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 * Created by:
 *  Marco Malinverno, Politecnico di Torino (marco.malinverno1@gmail.com)
 *  Francesco Raviglione, Politecnico di Torino (francescorav.es483@gmail.com)
 *  Carlos Mateo Risma Carletti, Politecnico di Torino (carlosrisma@gmail.com)
*/

#include "emergencyVehicleWarningServer80211p.h"
#include "emergencyVehicleWarningClient80211p.h"

#include "ns3/CAM.h"
#include "ns3/DENM.h"
#include "ns3/socket.h"
#include "ns3/network-module.h"
#include "ns3/gn-utils.h"
#include "ns3/iviService.h"

#define PROVIDER_IDENTIFIER 16383
#define COUNTRY_CODE 0000


namespace ns3
{
  NS_LOG_COMPONENT_DEFINE("emergencyVehicleWarningServer");

  NS_OBJECT_ENSURE_REGISTERED(emergencyVehicleWarningServer80211p);

  TypeId
  emergencyVehicleWarningServer80211p::GetTypeId (void)
  {
    static TypeId tid =
        TypeId ("ns3::emergencyVehicleWarningServer")
        .SetParent<Application> ()
        .SetGroupName ("Applications")
        .AddConstructor<emergencyVehicleWarningServer80211p> ()
        .AddAttribute ("AggregateOutput",
           "If it is true, the server will print every second an aggregate output about cam and denm",
           BooleanValue (false),
           MakeBooleanAccessor (&emergencyVehicleWarningServer80211p::m_aggregate_output),
           MakeBooleanChecker ())
        .AddAttribute ("RealTime",
           "To compute properly timestamps",
           BooleanValue(false),
           MakeBooleanAccessor (&emergencyVehicleWarningServer80211p::m_real_time),
           MakeBooleanChecker ())
        .AddAttribute ("CSV",
            "CSV log name",
            StringValue (),
            MakeStringAccessor (&emergencyVehicleWarningServer80211p::m_csv_name),
            MakeStringChecker ())
        .AddAttribute ("MetricSupervisor",
            "Metric Supervisor to compute metrics according to 3GPP TR36.885 V14.0.0 page 70",
            PointerValue (0),
            MakePointerAccessor (&emergencyVehicleWarningServer80211p::m_metric_supervisor),
            MakePointerChecker<MetricSupervisor> ())
        .AddAttribute ("Client",
           "TraCI client for SUMO",
           PointerValue (0),
           MakePointerAccessor (&emergencyVehicleWarningServer80211p::m_client),
           MakePointerChecker<TraciClient> ())
        .AddAttribute ("SendCAM",
           "To enable/disable the transmission of CAM messages",
           BooleanValue(true),
           MakeBooleanAccessor (&emergencyVehicleWarningServer80211p::m_send_cam),
           MakeBooleanChecker ());
        return tid;
  }

  emergencyVehicleWarningServer80211p::emergencyVehicleWarningServer80211p ()
  {
    NS_LOG_FUNCTION(this);
    m_client = nullptr;
    m_cam_received = 0;
    m_denm_sent = 0;
    m_ivim_sent = 0;
    m_isTransmittingDENM = false;
  }

  emergencyVehicleWarningServer80211p::~emergencyVehicleWarningServer80211p ()
  {
    NS_LOG_FUNCTION(this);
  }

  void
  emergencyVehicleWarningServer80211p::DoDispose (void)
  {
    NS_LOG_FUNCTION(this);
    Application::DoDispose ();
  }


  void
  emergencyVehicleWarningServer80211p::StartApplication (void)
  {
    NS_LOG_FUNCTION(this);

    /*
     * In this example, the speed control is actuated in a small area at the center of the map (a circular area with 90m of radius).
     * In the inner area the maximum allowed speed is 6.94 m/s (25 km/h) while outside is 20.83 m/s (75 km/h).
     * The application will first of all determine this area, and then it will GeoBroadcast DENMs in that area, by specifying
     * in the RoadWorks container, the speed limit to be applied.
     * The DENM dissemination starts only when the RSU receives CAMs from vehicles. The DENMs generation is stopped
     * if no CAM is received by the RSU for more than 5 seconds.
    */

    m_id = m_client->GetStationId (this -> GetNode ());

    libsumo::TraCIPosition rsuPosXY = m_client->TraCIAPI::poi.getPosition (m_id);
    libsumo::TraCIPosition rsuPosLonLat = m_client->TraCIAPI::simulation.convertXYtoLonLat (rsuPosXY.x,rsuPosXY.y);

    /* Compute GeoArea for IVIMs */
    GeoArea_t geoArea;
    // Longitude and Latitude in [0.1 microdegree]
    geoArea.posLong = rsuPosLonLat.x*DOT_ONE_MICRO;
    geoArea.posLat = rsuPosLonLat.y*DOT_ONE_MICRO;
    // Radius [m] of the circle that covers the whole square area of the map in (x,y)
    geoArea.distA = 6000;
    // DistB [m] and angle [deg] equal to zero because we are defining a circular area as specified in ETSI EN 302 636-4-1 [9.8.5.2]
    geoArea.distB = 0;
    geoArea.angle = 0;
    geoArea.shape = CIRCULAR;

    /* TX socket for DENMs and RX socket for CAMs (one socket only is necessary) */
    TypeId tid = TypeId::LookupByName ("ns3::PacketSocketFactory");

    m_socket = Socket::CreateSocket (GetNode (), tid);

    /* Bind the socket to local address */
    PacketSocketAddress local_denm;
    local_denm.SetSingleDevice (GetNode ()->GetDevice (0)->GetIfIndex ());
    local_denm.SetPhysicalAddress (GetNode ()->GetDevice (0)->GetAddress ());
    local_denm.SetProtocol (0x8947);
    if (m_socket->Bind (local_denm) == -1)
    {
      NS_FATAL_ERROR ("Failed to bind server socket");
    }

    /* Set socket to broacdcast */
    PacketSocketAddress remote;
    remote.SetSingleDevice (GetNode ()->GetDevice (0)->GetIfIndex ());
    remote.SetPhysicalAddress (GetNode ()->GetDevice (0)->GetBroadcast ());
    remote.SetProtocol (0x8947);
    m_socket->Connect(remote);

    /* Create new BTP and GeoNet objects and set them in DENBasicService and CABasicService */
    m_btp = CreateObject <btp>();
    m_geoNet = CreateObject <GeoNet>();

    if(m_metric_supervisor!=nullptr)
    {
      m_geoNet->setMetricSupervisor(m_metric_supervisor);
    }

    m_btp->setGeoNet(m_geoNet);
    m_caService.setBTP(m_btp);
    m_iviService.setBTP(m_btp);

    /* Set sockets, callback and station properties in iviService */
    m_iviService.setSocketTx (m_socket);
    m_iviService.setSocketRx (m_socket);
    m_iviService.addIVIRxCallback (std::bind(&emergencyVehicleWarningServer80211p::receiveIVIM,this,std::placeholders::_1,std::placeholders::_2));

    // Setting geoArea address for ivims and realTime
    m_iviService.setGeoArea (geoArea);
    m_iviService.setRealTime (m_real_time);

    size_t start = m_id.find("_") + 1;
    size_t end = m_id.find_first_not_of("0123456789", start); // find the end of the id
    std::string id_str = m_id.substr(start, end - start);
    uint64_t id = std::stoull(id_str);
    m_iviService.setStationProperties (m_stationId_baseline + id, StationType_roadSideUnit);

    /* Set callback and station properties in CABasicService */
    m_caService.setStationProperties (m_stationId_baseline + id, StationType_roadSideUnit);
    m_caService.setSocketTx (m_socket);
    m_caService.setSocketRx (m_socket);
    m_caService.addCARxCallback (std::bind(&emergencyVehicleWarningServer80211p::receiveCAM,this,std::placeholders::_1,std::placeholders::_2));

    // Set the RSU position in the CA,DEN and IVI basic service (mandatory for any RSU object)
    // As the position must be specified in (lat, lon), we must take it from the mobility model and then convert it to Latitude and Longitude
    // As SUMO is used here, we can rely on the TraCIAPI for this conversion
    m_caService.setFixedPositionRSU (rsuPosLonLat.y,rsuPosLonLat.x);
    m_iviService.setFixedPositionRSU (rsuPosLonLat.y,rsuPosLonLat.x);

    VDP* traci_vdp = new VDPTraCI(m_client, m_id, true);

    m_caService.setVDP(traci_vdp);

    m_iviService.setVDP(traci_vdp);

    if(m_send_cam)
      {
        std::srand(Simulator::Now().GetNanoSeconds ());
        double desync = ((double)std::rand()/RAND_MAX);
        m_caService.startCamDissemination(desync);
      }

    if (!m_csv_name.empty ())
    {
      m_csv_ofstream_cam.open (m_csv_name+"-server.csv",std::ofstream::trunc);
      m_csv_ofstream_cam << "messageId,camId,timestamp,latitude,longitude,heading,speed,acceleration,x,y,stationtype" << std::endl;
    }

    /* If aggregate output is enabled, start it */
    if (m_aggregate_output)
      m_aggegateOutputEvent = Simulator::Schedule (Seconds(1), &emergencyVehicleWarningServer80211p::aggregateOutput, this);


    TriggerIvim ();
  }

  void
  emergencyVehicleWarningServer80211p::StopApplication ()
  {
    NS_LOG_FUNCTION(this);
    Simulator::Cancel (m_aggegateOutputEvent);
    Simulator::Cancel (m_terminate_denm_ev);

    if (!m_csv_name.empty ())
      m_csv_ofstream_cam.close ();

    if (m_aggregate_output)
      std::cout << Simulator::Now () << "," << m_cam_received  << "," << m_denm_sent << std::endl;
  }

  void
  emergencyVehicleWarningServer80211p::StopApplicationNow ()
  {
    NS_LOG_FUNCTION(this);
    StopApplication ();
  }

  void
  emergencyVehicleWarningServer80211p::TriggerIvim ()
  {
    // Trigger the iviData
    m_ivim_sent++;

    libsumo::TraCIPosition refPos,deltaPosDet,deltaPosRel;

    /*
     *   ZONES DESCRIPTION
     *
     *      x=-65     Relevance Zone                 Detection Zone   x=130
     *       |<-------------------------------> <--------------------->|
     * ________________________________________|____________________________
     *                                         |
     *                                         |
     *                                         |
     * - - - - - - - - - - - x - - - - - - - - X - - - - - x - - - - - - - -  y = -1
     *                       |                 |           |
     *                       |                 |           |
     *                       |                 |           |
     * ----------------------|-----------------|-----------|----------------
     * x-axis               17.5              100         115
     *                  DeltaPosRel          RefPos     DeltaPosDet
     * */


    //refPos = m_client->TraCIAPI::poi.getPosition (m_id);
    refPos = m_client->TraCIAPI::simulation.convertXYtoLonLat (100,-1); //Reference Position
    deltaPosDet = m_client->TraCIAPI::simulation.convertXYtoLonLat (115,-1);//Delta Position for Detection zone
    deltaPosRel = m_client->TraCIAPI::simulation.convertXYtoLonLat (17.5,-1);//Delta Position for Relevance zone


    /*IVI data creation */
    iviData Data;
    iviData::iviDataMandatory mandatoryData;
    mandatoryData.countryCode = COUNTRY_CODE;
    mandatoryData.providerIdentifier = PROVIDER_IDENTIFIER;
    Data.setIvimMandatory (mandatoryData);
    Data.setOptionalPresent(true,true,false,true,false);

    // General IVI container
    iviData::IVI_gic_t gic;
    iviData::IVI_gic_part_t gic_part;
    std::vector<iviData::gicPartRS_t> roadSignCodes;
    std::vector<long> detzoneIDs,relzoneIDs;
    gic_part.iviType = IviType_trafficRelatedInformationMessages;
    detzoneIDs.push_back (1); //ZoneID=1 --> DetectionZone
    gic_part.detectionZoneIds.setData (detzoneIDs);
    relzoneIDs.push_back (2); //ZoneID=2 --> RelevanceZone
    gic_part.relevanceZoneIds.setData (relzoneIDs);
    gic_part.direction.setData (Direction_sameDirection);

    iviData::gicPartRS RS;
    RS.RS_spm.setData (30);
    RS.RS_unit.setData (RSCUnit_kmperh);
    RS.RS_nature = 6;
    RS.RS_serialNumber = 59;
    RS.RS_trafficSignPictogram.setData (ISO14823Code__pictogramCode__serviceCategoryCode__trafficSignPictogram_informative);
    roadSignCodes.push_back (RS);

    gic_part.RS.push_back (RS);
    gic.GicPart.push_back (gic_part);

    Data.setIvimGic (gic);

    //Geographical Location Container
    iviData::IVI_glc_t glc;
    glc.referencePosition.latitude = refPos.y*DOT_ONE_MICRO;
    glc.referencePosition.longitude = refPos.x*DOT_ONE_MICRO;
    glc.referencePosition.altitude.setValue (AltitudeValue_unavailable);
    glc.referencePosition.altitude.setConfidence (AltitudeConfidence_unavailable);
    glc.referencePosition.positionConfidenceEllipse.semiMajorConfidence = SemiAxisLength_unavailable;
    glc.referencePosition.positionConfidenceEllipse.semiMinorConfidence = SemiAxisLength_unavailable;
    glc.referencePosition.positionConfidenceEllipse.semiMajorOrientation = HeadingValue_wgs84North;

    iviData::IVI_glc_part_t glc_part;
    iviData::IVI_glcP_zone_t zone;
    iviData::IVI_glcP_segment_t segment;
    std::vector<iviData::IVI_glcP_deltaPosition_t> deltaPositions;
    iviData::IVI_glcP_deltaPosition_t deltaPosition;

    //First GLC part --> ZoneID=1 --> Detection Zone
    glc_part.zoneId = 1;
    deltaPosition.deltaLat = (refPos.y-deltaPosDet.y)*DOT_ONE_MICRO;
    deltaPosition.deltaLong = (refPos.x-deltaPosDet.x)*DOT_ONE_MICRO;
    deltaPositions.push_back (deltaPosition);
    segment.line.deltaPositions.setData (deltaPositions);
    segment.laneWidth.setData((long) 9);
    zone.segment.setData(segment);
    glc_part.zone.setData(zone);
    glc.GlcPart.push_back(glc_part);

    deltaPositions.clear ();

    //Second GLC part --> ZoneID=2 --> Relevance Zone
    glc_part.zoneId = 2;
    deltaPosition.deltaLat = (refPos.y-deltaPosRel.y)*DOT_ONE_MICRO;
    deltaPosition.deltaLong = (refPos.x-deltaPosRel.x)*DOT_ONE_MICRO;
    deltaPositions.push_back (deltaPosition);

    segment.line.deltaPositions.setData (deltaPositions);
    segment.laneWidth.setData((long) 9);
    zone.segment.setData(segment);
    glc_part.zone.setData(zone);
    glc.GlcPart.push_back(glc_part);

    Data.setIvimGlc (glc);

    uint64_t id = std::stoi(m_id.substr (m_id.find("_") + 1));
    id = id + m_stationId_baseline;
    Data.setIvimStationID (id);


//    iviData::IVI_tc textContainer;
//    iviData::IVI_tc_part_t tc_part;
//    std::vector<long> appLanesPos;
//    std::vector<iviData::IVI_tc_text_t> textCont;
//    iviData::IVI_tc_text_t text;
//    tc_part.detectionZoneIds.setData (detzoneIDs);
//    tc_part.relevanceZoneIds = relzoneIDs;
//    tc_part.direction.setData (Direction_sameDirection); //Direction_sameDirection;
//    tc_part.data = "Left and central lane only for emergency vehicles";
//    appLanesPos.push_back (LanePosition_secondLaneFromOutside);
//    tc_part.applicableLanesPos.setData (appLanesPos);
//    text.bitLanguage = 00000;
//    text.textCont = "textCon";
//    textCont.push_back (text);
//    tc_part.text.setData (textCont);
//    textContainer.IVItcPart.push_back (tc_part);
//    Data.setIvimtc (textContainer);

    m_iviData = Data;


    m_iviService.appIVIM_trigger(Data);

    Simulator::Schedule (Seconds (1), &emergencyVehicleWarningServer80211p::RepeatIvim, this);

  }

  void
  emergencyVehicleWarningServer80211p::RepeatIvim ()
  {

        iviData Data = m_iviData;

        m_iviService.appIVIM_repetition(Data);

        Simulator::Schedule (Seconds (1), &emergencyVehicleWarningServer80211p::RepeatIvim, this);


  }

  void
  emergencyVehicleWarningServer80211p::receiveCAM (asn1cpp::Seq<CAM> cam, Address from)
  {
    m_cam_received++;

    if (!m_csv_name.empty ())
      {
        // messageId,camId,timestamp,latitude,longitude,heading,speed,acceleration
        m_csv_ofstream_cam << cam->header.messageId << "," << cam->header.stationId << ",";
        m_csv_ofstream_cam << cam->cam.generationDeltaTime << "," << asn1cpp::getField(cam->cam.camParameters.basicContainer.referencePosition.latitude,double)/DOT_ONE_MICRO << ",";
        m_csv_ofstream_cam << asn1cpp::getField(cam->cam.camParameters.basicContainer.referencePosition.longitude,double)/DOT_ONE_MICRO << "," ;
        m_csv_ofstream_cam << asn1cpp::getField(cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.heading.headingValue,double)/DECI << "," << asn1cpp::getField(cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.speed.speedValue,double)/CENTI << ",";
        m_csv_ofstream_cam << asn1cpp::getField(cam->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.longitudinalAcceleration.value,double)/DECI << std::endl;
      }
  }

  long
  emergencyVehicleWarningServer80211p::compute_timestampIts ()
  {
    /* To get millisec since  2004-01-01T00:00:00:000Z */
    auto time = std::chrono::system_clock::now(); // get the current time
    auto since_epoch = time.time_since_epoch(); // get the duration since epoch
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_epoch); // convert it in millisecond since epoch

    long elapsed_since_2004 = millis.count() - TIME_SHIFT; // in TIME_SHIFT we saved the millisec from epoch to 2004-01-01
    return elapsed_since_2004;
  }

  void
  emergencyVehicleWarningServer80211p::aggregateOutput()
  {
    std::cout << Simulator::Now () << "," << m_cam_received << "," << m_denm_sent << std::endl;
    m_aggegateOutputEvent = Simulator::Schedule (Seconds(1), &emergencyVehicleWarningServer80211p::aggregateOutput, this);
  }

  void
  emergencyVehicleWarningServer80211p::receiveIVIM (iviData ivim, Address from)
  {

    /* Must be modified such as if the vehicle is inside the 'restricted line zone', it must follow some specific instruction
     * depending if it is an emergency vehicle or a passenger vehicle*/
    /* This is just a sample dummy receiveIVIM function. The user can customize it to parse the content of a IVIM when it is received. */
    (void) ivim; // Contains the data received from the IVIM
    (void) from; // Contains the address from which the DENM has been received
  }

}








