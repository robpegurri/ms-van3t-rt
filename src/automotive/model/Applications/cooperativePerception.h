#ifndef cooperativePerception_H
#define cooperativePerception_H

#include "ns3/OpenCDAClient.h"
#include "ns3/vdpopencda.h"
#include "ns3/opencda-sensor.h"
#include "ns3/MetricSupervisor.h"
#include "ns3/traci-client.h"
#include "ns3/application.h"
#include "ns3/asn_utils.h"

#include <unordered_map>

#include "ns3/denBasicService.h"
#include "ns3/caBasicService.h"
#include "ns3/cpBasicService.h"
#include "ns3/cpBasicService_v1.h"
#include "ns3/vdpTraci.h"
#include "ns3/socket.h"

#include "ns3/sumo-sensor.h"
#include "ns3/LDM.h"

namespace ns3 {

class cooperativePerception : public Application
{
  public:

    /**
     * \brief Get the type ID.
     * \return the object TypeId
     */
    static TypeId GetTypeId (void);

    cooperativePerception ();

    virtual ~cooperativePerception ();

    void StopApplicationNow ();

    /**
     * \brief Callback to handle a CAM reception.
     *
     * This function is called everytime a packet is received by the CABasicService.
     *
     * \param the ASN.1 CAM structure containing the info of the packet that was received.
     */
    void receiveCAM (asn1cpp::Seq<CAM> cam, Address from);

    /**
     * \brief Callback to handle a CPM reception.
     *
     * This function is called everytime a packet is received by the CPBasicService.
     *
     * \param the ASN.1 CPM structure containing the info of the packet that was received.
     */
    void receiveCPM (asn1cpp::Seq<CollectivePerceptionMessage> cpm, Address from);

    /**
     * \brief Callback to handle a CPM reception.
     *
     * This function is called everytime a packet is received by the CPBasicService.
     *
     * \param the ASN.1 CPM structure containing the info of the packet that was received.
     */
    void receiveCPMV1 (asn1cpp::Seq<CPMV1> cpm, Address from);

  protected:
    virtual void DoDispose (void);

  private:

    DENBasicService m_denService; //!< DEN Basic Service object
    CABasicService m_caService; //!< CA Basic Service object
    CPBasicService m_cpService; //!< CP Basic Service object
    CPBasicServiceV1 m_cpService_v1; //!< CP Basic Service object version 1 (for CPMv1)
    Ptr<btp> m_btp; //! BTP object
    Ptr<GeoNet> m_geoNet; //! GeoNetworking Object
    Ptr<SUMOSensor> m_sumo_sensor;
    Ptr<OpenCDASensor> m_opencda_sensor;
    Ptr<LDM> m_LDM; //! LDM object
    Ipv4Address m_ipAddress; //!< C-V2X self IP address (set by 'v2v-cv2x.cc')
    Ptr<Socket> m_socket; //!< Socket TX/RX for everything
    std::string m_model; //!< Communication Model (possible values: 80211p and cv2x)

    vehicleData_t translateCPMdata(asn1cpp::Seq<CollectivePerceptionMessage> cpm, asn1cpp::Seq<PerceivedObject>, int objectIndex, int newID);
    vehicleData_t translateCPMV1data (asn1cpp::Seq<CPMV1> cpm, int objectIndex, int newID);

    virtual void StartApplication (void);
    virtual void StopApplication (void);

    double m_distance_threshold;
    double m_heading_threshold;

    Ptr<TraciClient> m_traci_client; //!< TraCI client
    Ptr<OpenCDAClient> m_opencda_client; //! OpenCDA client
    std::string m_id; //!< vehicle id
    std::string m_type; //!< vehicle type
    double m_max_speed; //!< To save initial veh max speed
    double m_denm_intertime; //!< Time between two consecutives DENMs
    bool m_print_summary; //!< To print a small summary when vehicle leaves the simulation
    bool m_already_print; //!< To avoid printing two summaries
    bool m_real_time; //!< To decide wheter to use realtime scheduler
    std::string m_csv_name; //!< CSV log file name
    std::ofstream m_csv_ofstream_cam; //!< CSV log stream (CAM), created using m_csv_name
    std::map<int, std::map<int,int>> m_recvCPMmap;  //! Structure mapping, for each CV that we have received a CPM from, the CPM's PO ids with the ego LDM's PO ids


    /* Counters */
    int m_cam_received;
    int m_cpm_received;

    EventId m_send_cam_ev; //!< Event to send the CAM


    bool m_send_cam;

    Ptr<PRRSupervisor> m_PRR_supervisor = nullptr;

  };

} // namespace ns3

#endif /* cooperativePerception_H */


