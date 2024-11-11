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
#include "ns3/carla-module.h"
#include "ns3/automotive-module.h"
#include "ns3/traci-module.h"
#include "ns3/internet-module.h"
#include "ns3/wave-module.h"
#include "ns3/mobility-module.h"
#include "ns3/sumo_xml_parser.h"
#include "ns3/packet-socket-helper.h"
#include "ns3/vehicle-visualizer-module.h"
#include "ns3/MetricSupervisor.h"
#include <unistd.h>


using namespace ns3;

NS_LOG_COMPONENT_DEFINE("v2v-80211p");

int
main (int argc, char *argv[])
{
  /*
   * In this example the generated vehicles will broadcast their CAMs and CPMs. Every vehicle transmits its messages
   * through a 802.11p interface.
   * Received CAMs and CPMs information is stored in each vehicle LDM.
   *
   */

  // Admitted data rates for 802.11p
  std::vector<float> rate_admitted_values{3,4.5,6,9,12,18,24,27};
  std::string datarate_config;

  /*** 0.a Mobility Options ***/
  std::string opencda_folder = "Opencda/";
  std::string opencda_config ="ms_van3t_example";
  bool opencda_ml = false;
  //Same mobility example but with active perception (using ML models for OpenCDA's perception module)
  //std::string opencda_config ="ms_van3t_example_ml";
  //bool opencda_ml = true;


  /*
   * Path to CARLA_OpenCDA.conf file created at installation with the following contents:
   *
   * OpenCDA_HOME=/path/to/OpenCDA/
   * CARLA_HOME=/path/to/CARLA_0.9.12
   * Python_Interpreter=/path/to/anaconda3/envs/opencda/bin/python3
   *
   * If installation was done without anaconda -> Python_Interpreter=python3.7
  */
  std::string carla_opencda_config="CARLA-OpenCDA.conf";

  std::string OpenCDA_HOME, CARLA_HOME, Python_Interpreter;



  bool verbose = true;
  bool realtime = false;
  std::string csv_name;
  std::string csv_name_cumulative;
  int txPower=23;
  double penetrationRate = 1.0;

  float datarate=12;
  bool vehicle_vis = false;

  // Disabling this option turns off the whole V2X application (useful for comparing the situation when the application is enabled and the one in which it is disabled)
  bool send_cam = true;
  double m_baseline_prr = 150.0;
  bool m_metric_sup = false;

  double simTime = 20;

  int numberOfNodes;
  uint32_t nodeCounter = 0;

  CommandLine cmd;

  /* Cmd Line option for application */
  cmd.AddValue ("realtime", "Use the realtime scheduler or not", realtime);
  cmd.AddValue ("opencda-config", "Location and name of OpenCDA configuration file", opencda_config);
  cmd.AddValue ("csv-log", "Name of the CSV log file", csv_name);
  cmd.AddValue ("vehicle-visualizer", "Activate the web-based vehicle visualizer for ms-van3t", vehicle_vis);
  cmd.AddValue ("send-cam", "Turn on or off the transmission of CAMs, thus turning on or off the whole V2X application",send_cam);
  cmd.AddValue ("csv-log-cumulative", "Name of the CSV log file for the cumulative (average) PRR and latency data", csv_name_cumulative);
  cmd.AddValue ("baseline", "Baseline for PRR calculation", m_baseline_prr);
  cmd.AddValue ("met-sup","Use the PRR supervisor or not",m_metric_sup);
  cmd.AddValue ("penetrationRate", "Rate of vehicles equipped with wireless communication devices", penetrationRate);

  /* Cmd Line option for 802.11p */
  cmd.AddValue ("tx-power", "OBUs transmission power [dBm]", txPower);
  cmd.AddValue ("datarate", "802.11p channel data rate [Mbit/s]", datarate);

  cmd.AddValue("sim-time", "Total duration of the simulation [s]", simTime);

  cmd.Parse (argc, argv);



  if(std::find(rate_admitted_values.begin(), rate_admitted_values.end(), datarate) == rate_admitted_values.end())
    {
      NS_FATAL_ERROR("Fatal error: invalid 802.11p data rate" << datarate << "Mbit/s. Valid rates are: 3, 4.5, 6, 9, 12, 18, 24, 27 Mbit/s.");
    }
  else
    {
      if(datarate==4.5)
        {
          datarate_config = "OfdmRate4_5MbpsBW10MHz";
        }
      else
        {
          datarate_config = "OfdmRate" + std::to_string((int)datarate) + "MbpsBW10MHz";
        }
    }

  if (verbose)
    {
      LogComponentEnable ("v2v-80211p", LOG_LEVEL_INFO);
      LogComponentEnable ("CABasicService", LOG_LEVEL_INFO);
      LogComponentEnable ("DENBasicService", LOG_LEVEL_INFO);
    }

  /* Use the realtime scheduler of ns3 */
  if(realtime)
      GlobalValue::Bind ("SimulatorImplementationType", StringValue ("ns3::RealtimeSimulatorImpl"));

  /*** 0.b Read from the CARLA_OpenCDA config file (default CARLA_OpenCDA.conf) to get the path for necessary executables
  ***/
  std::ifstream configFile(carla_opencda_config);
  if (!configFile) {
      NS_FATAL_ERROR("Error: File '"<< carla_opencda_config << "' does not exist. Please specify valid configuration file.");
  }

  std::string line;
  std::unordered_map<std::string, std::string*> configMap = {
      {"OpenCDA_HOME", &OpenCDA_HOME},
      {"CARLA_HOME", &CARLA_HOME},
      {"Python_Interpreter", &Python_Interpreter}
  };

  while (std::getline(configFile, line)) {
      std::istringstream lineStream(line);
      std::string key, value;
      if (std::getline(lineStream, key, '=') && std::getline(lineStream, value)) {
          auto it = configMap.find(key);
          if (it != configMap.end()) {
              *(it->second) = value;
          }
      }
  }

  for (const auto& pair : configMap) {
          if (pair.second->empty()) {
              NS_FATAL_ERROR( "Error: Value for '" << pair.first << "' in '"<< carla_opencda_config <<"' is empty.");
          }
      }

  /***
   * 0.c Read from OpenCDA config file the number of vehicles
   * */
  std::string config_yaml = OpenCDA_HOME+"/opencda/scenario_testing/config_yaml/" +opencda_config+ ".yaml";

  std::ifstream file(config_yaml);
      int spawnPositionCount = 0;
      int vehicleNum = 0;
      bool foundVehicleNum = false;

      if (file.is_open()) {
          while (getline(file, line)) {
              // Count occurrences of "spawn_position"
              if (line.find("spawn_position") != std::string::npos) {
                  spawnPositionCount++;
              }

              // Find and process "vehicle_num"
              if (!foundVehicleNum && line.find("vehicle_num") != std::string::npos) {
                  std::istringstream iss(line);
                  std::string key, value;
                  if (std::getline(iss, key, ':') && std::getline(iss, value)) {
                      foundVehicleNum = true;
                      vehicleNum = std::stoi(value);
                  }
              }
          }
          file.close();
      } else {
          NS_FATAL_ERROR("Error: cannot open file '"<< config_yaml << "'.");
      }

  numberOfNodes = spawnPositionCount + vehicleNum;
  std::cout<< "Number of vehicles: " << numberOfNodes << std::endl;
//  numberOfNodes = 30;


  /* Set the simulation time (in seconds) */
  NS_LOG_INFO("Simulation will last " << simTime << " seconds");
  ns3::Time simulationTime (ns3::Seconds(simTime));

  /*** 1. Create containers for OBUs ***/
  NodeContainer obuNodes;
  obuNodes.Create(numberOfNodes);

  /*** 2. Create and setup channel   ***/
  YansWifiPhyHelper wifiPhy;
  wifiPhy.Set ("TxPowerStart", DoubleValue (txPower));
  wifiPhy.Set ("TxPowerEnd", DoubleValue (txPower));
  NS_LOG_INFO("Setting up the 802.11p channel @ " << datarate << " Mbit/s, 10 MHz, and tx power " << (int)txPower << " dBm.");

  YansWifiChannelHelper wifiChannel = YansWifiChannelHelper::Default ();
  /*Example of using diffrent propagation model (after applying extension with apply-extension.sh in automotive/propagation-extended/)*/
  // YansWifiChannelHelper wifiChannel;
  // wifiChannel.SetPropagationDelay ("ns3::ConstantSpeedPropagationDelayModel");
  // wifiChannel.AddPropagationLoss ("ns3::CniUrbanmicrocellPropagationLossModel");
  Ptr<YansWifiChannel> channel = wifiChannel.Create ();
  wifiPhy.SetChannel (channel);
  /* To be removed when BPT is implemented */
  //Config::SetDefault ("ns3::ArpCache::DeadTimeout", TimeValue (Seconds (1)));

  /*** 3. Create and setup MAC ***/
  wifiPhy.SetPcapDataLinkType (YansWifiPhyHelper::DLT_IEEE802_11);
  NqosWaveMacHelper wifi80211pMac = NqosWaveMacHelper::Default ();
  Wifi80211pHelper wifi80211p = Wifi80211pHelper::Default ();
  std::cout << "Datarate: " << datarate_config << std::endl;
  wifi80211p.SetRemoteStationManager ("ns3::ConstantRateWifiManager",
                                      "DataMode", StringValue (datarate_config),
                                      "ControlMode", StringValue (datarate_config),
                                      "NonUnicastMode",StringValue (datarate_config));
  NetDeviceContainer netDevices = wifi80211p.Install (wifiPhy, wifi80211pMac, obuNodes);

  //wifiPhy.EnablePcap ("v2v-EVA",netDevices);

  /*** 4. Give packet socket powers to nodes (otherwise, if the app tries to create a PacketSocket, CreateSocket will end up with a segmentation fault */
  PacketSocketHelper packetSocket;
  packetSocket.Install (obuNodes);

  /*** 5. Setup Mobility and position node pool ***/
  MobilityHelper mobility;
  mobility.Install (obuNodes);

  /*** 6. Setup OpenCDA client ***/
  Ptr<OpenCDAClient> opencda_client = CreateObject<OpenCDAClient> ();
  opencda_client->SetAttribute ("CARLAHost", StringValue ("localhost"));
  opencda_client->SetAttribute ("UpdateInterval", DoubleValue (0.05));
  opencda_client->SetAttribute ("Port", UintegerValue (1337));
  opencda_client->SetAttribute ("PenetrationRate",DoubleValue(0.5));
  opencda_client->SetAttribute ("OpenCDA_config", StringValue(opencda_config));
  opencda_client->SetAttribute ("OpenCDA_HOME", StringValue(OpenCDA_HOME));
  opencda_client->SetAttribute ("CARLA_HOME", StringValue(CARLA_HOME));
  opencda_client->SetAttribute ("PythonInterpreter", StringValue(Python_Interpreter));
  /* If active perception is specified in OpenCDA's config YAML (eg. ms_van3t_example_ml). Default -> false */
  opencda_client->SetAttribute ("ApplyML", BooleanValue(opencda_ml));


  Ptr<MetricSupervisor> metSup = NULL;
  MetricSupervisor metSupObj(m_baseline_prr);
  if(m_metric_sup)
    {
      metSup = &metSupObj;
      metSup->setOpenCDACLient (opencda_client);
    }

  /*** 7. Setup interface and application for dynamic nodes ***/
  cooperativePerceptionHelper cooperativePerceptionHelper;
  cooperativePerceptionHelper.SetAttribute ("OpenCDAClient", PointerValue(opencda_client));
  cooperativePerceptionHelper.SetAttribute ("RealTime", BooleanValue(realtime));
  cooperativePerceptionHelper.SetAttribute ("PrintSummary", BooleanValue (true));
  cooperativePerceptionHelper.SetAttribute ("CSV", StringValue(csv_name));
  cooperativePerceptionHelper.SetAttribute ("Model", StringValue ("80211p"));
  /* callback function for node creation */
  STARTUP_FCN setupNewWifiNode = [&] (std::string vehicleID) -> Ptr<Node>
    {
      if (nodeCounter >= obuNodes.GetN())
        NS_FATAL_ERROR("Node Pool empty!: " << nodeCounter << " nodes created.");

      Ptr<Node> includedNode = obuNodes.Get(nodeCounter);
      ++nodeCounter; // increment counter for next node

      /* Install Application */
      ApplicationContainer AppSample = cooperativePerceptionHelper.Install (includedNode);

      AppSample.Start (Seconds (0.0));
      AppSample.Stop (simulationTime - Simulator::Now () - Seconds (0.1));

      return includedNode;
    };

  /* Callback function for node shutdown */
  SHUTDOWN_FCN shutdownWifiNode = [] (Ptr<Node> exNode,std::string vehicleID)
    {
      /* stop all applications */
      Ptr<cooperativePerception> appSample_ = exNode->GetApplication(0)->GetObject<cooperativePerception>();
      if(appSample_)
        appSample_->StopApplicationNow();

       /* Set position outside communication range */
      Ptr<ConstantPositionMobilityModel> mob = exNode->GetObject<ConstantPositionMobilityModel>();
      mob->SetPosition(Vector(-1000.0+(rand()%25),320.0+(rand()%25),250.0));// rand() for visualization purposes

      /* NOTE: further actions could be required for a safe shut down! */
    };

  /* start OpenCDA client with given function pointers */
  opencda_client->startCarlaAdapter (setupNewWifiNode, shutdownWifiNode);

  /*** 8. Start Simulation ***/
  Simulator::Stop (simulationTime);

  Simulator::Run ();
  Simulator::Destroy ();

  /* stop OpenCDA and CARLA simulation */
  opencda_client->stopSimulation ();

  if(m_metric_sup)
    {
      if(csv_name_cumulative!="")
      {
        std::ofstream csv_cum_ofstream;
        std::string full_csv_name = csv_name_cumulative + ".csv";

        if(access(full_csv_name.c_str(),F_OK)!=-1)
        {
          // The file already exists
          csv_cum_ofstream.open(full_csv_name,std::ofstream::out | std::ofstream::app);
        }
        else
        {
          // The file does not exist yet
          csv_cum_ofstream.open(full_csv_name);
          csv_cum_ofstream << "current_txpower_dBm,avg_PRR,avg_latency_ms" << std::endl;
        }

        csv_cum_ofstream << txPower << "," << metSup->getAveragePRR_overall () << "," << metSup->getAverageLatency_overall () << std::endl;
      }
      std::cout << "Average PRR: " << metSup->getAveragePRR_overall () << std::endl;
      std::cout << "Average latency (ms): " << metSup->getAverageLatency_overall () << std::endl;

      for(int i=1;i<numberOfNodes+1;i++) {
          std::cout << "Average latency of vehicle " << i << " (ms): " << metSup->getAverageLatency_vehicle (i) << std::endl;
          std::cout << "Average PRR of vehicle " << i << " (%): " << metSup->getAveragePRR_vehicle (i) << std::endl;
      }
    }


  return 0;
}
