
#include <fstream>
#include <iostream>
#include <dirent.h>
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/mobility-module.h"
#include "ns3/aodv-module.h"

//#include "ns3/aodvrtt-module.h"
//#include "ns3/wpr-module.h"
//#include "ns3/dpr-module.h"
//#include "ns3/aomdv-module.h"
//#include "ns3/npb-module.h"
//#include "ns3/dcfp-module.h"
#include "ns3/ncpr-module.h"
//#include "ns3/newprotocol-module.h"
//#include "ns3/ourprotocol-module.h"
//#include "ns3/mprp-module.h"
#include "ns3/ptrp-module.h"
//#include "ns3/ptrprtt-module.h"


#include "ns3/olsr-module.h"
#include "ns3/dsdv-module.h"
#include "ns3/dsr-module.h"
#include "ns3/applications-module.h"
#include "ns3/yans-wifi-helper.h"

#include "ns3/ipv4-flow-classifier.h"
#include "ns3/flow-monitor.h"
#include "ns3/flow-monitor-helper.h"

using namespace ns3;
using namespace dsr;
using namespace std;


int protocolChoice = 1;
double TotalNodes = 50;
double TotalTime = 100;
int nSinks = 10;                  //default = 10
int nodeSpeed = 30;               //in m/s was 20 set 5?
int tries = 0;
std::string rate ("2048bps");
std::string phyMode ("DsssRate11Mbps");


NS_LOG_COMPONENT_DEFINE ("manet-routing-compare");


  static uint32_t SentPackets = 0;
  static uint32_t ReceivedPackets = 0;
  static uint32_t LostPackets = 0;
  static uint32_t packetsReceivedIncludingOverhead = 0;
  static uint32_t port = 9;
  static uint32_t bytesTotal = 0;
  static uint32_t packetsReceived = 0;
  
class RoutingExperiment
{
public:
  RoutingExperiment ();
  void Run (int nSinks, double txp, std::string CSVfileName);
  //static void SetMACParam (ns3::NetDeviceContainer & devices,
  //                                 int slotDistance);
  std::string CommandSetup (int argc, char **argv);

private:
  Ptr<Socket> SetupPacketReceive (Ipv4Address addr, Ptr<Node> node);
  void ReceivePacket (Ptr<Socket> socket);
  void CheckThroughput ();



  std::string m_CSVfileName;
  int m_nSinks;
  std::string m_protocolName;
  double m_txp;
  bool m_traceMobility;
  uint32_t m_protocol;
};
//constructor 
RoutingExperiment::RoutingExperiment ()
  : m_CSVfileName ("NCPRtestingFirsttime.csv"),
    m_traceMobility (false),
    m_protocol (protocolChoice) // 1=AODV 2=NCPR 3=DCFP 4=DSDV 5=DSR
   
{
}



//calculate goodput not just counting rreq.rrer, rrep

//Think maybe ncpr and all don't send as many RREQ in the first place because when erasing the drop packet part of algorithm, it doesn't have same results as aodv

// so i rewrote it and erasing the drop packet from rebroadcast delay timer gets good results with pdr





static inline std::string
PrintReceivedPacket (Ptr<Socket> socket, Ptr<Packet> packet, Address senderAddress)
{
  std::ostringstream oss;

  oss << Simulator::Now ().GetSeconds () << " " << socket->GetNode ()->GetId ();

  if (InetSocketAddress::IsMatchingType (senderAddress))
    {
      InetSocketAddress addr = InetSocketAddress::ConvertFrom (senderAddress);
      oss << " received one packet from " << addr.GetIpv4 ();
    }
  else
    {
      oss << " received one packet!";
    }
  oss << "  Packets:   " << packetsReceived;
  return oss.str ();
}

void
RoutingExperiment::ReceivePacket (Ptr<Socket> socket)
{
  Ptr<Packet> packet;
  Address senderAddress;
  while ((packet = socket->RecvFrom (senderAddress)))
    {
      //count these and compare
      //these are only data packets not overhead
      bytesTotal += packet->GetSize ();
      packetsReceived += 1;
      NS_LOG_UNCOND (PrintReceivedPacket (socket, packet, senderAddress));
    }
}

void
RoutingExperiment::CheckThroughput ()
{
  double kbs = (bytesTotal * 8.0) / 1000;
  bytesTotal = 0;

  std::ofstream out (m_CSVfileName.c_str (), std::ios::app);

  out << (Simulator::Now ()).GetSeconds () << ","
      << kbs << ","
      << packetsReceived << ","
      << m_nSinks << ","
      << m_protocolName << ","
      << m_txp << ""
      << std::endl;

  out.close ();
  //packetsReceived = 0;
  Simulator::Schedule (Seconds (1), &RoutingExperiment::CheckThroughput, this);
}

Ptr<Socket>
RoutingExperiment::SetupPacketReceive (Ipv4Address addr, Ptr<Node> node)
{
  TypeId tid = TypeId::LookupByName ("ns3::UdpSocketFactory");
  Ptr<Socket> sink = Socket::CreateSocket (node, tid);
  InetSocketAddress local = InetSocketAddress (addr, port);
  sink->Bind (local);
  
  sink->SetRecvCallback (MakeCallback (&RoutingExperiment::ReceivePacket, this));
  //count data packets here for recieving end then compare
//yashars advice
//i think i am counting overhead packets, need to only count data packets and use goodput
//try comparing counted packets in code vs flowmon and broadcasted number vs all that jazz
  //packetsReceivedIncludingOverhead += 1;

  return sink;
}

std::string
RoutingExperiment::CommandSetup (int argc, char **argv)
{
  CommandLine cmd;
  cmd.AddValue ("CSVfileName", "The name of the CSV output file name", m_CSVfileName);
  cmd.AddValue ("traceMobility", "Enable mobility tracing", m_traceMobility);
  cmd.AddValue ("protocol", "1=AODV;2=NCPR;3=DCFP;4=DSDV;5=DSR", m_protocol);
  cmd.Parse (argc, argv);
  return m_CSVfileName;
}

//First class is over, RoutingExperiment

int
main (int argc, char *argv[])
{
  // Delete all temp files
  ofstream streamd;
  std::string const HOMEd = std::getenv("HOME") ? std::getenv("HOME") : ".";
  string pathd = "/repos/ns-3-allinone/ns-3-dev/outputTextFiles/10.1.1.";
  for(int i = 1; i < 256; i++){
    streamd.open(HOMEd + pathd + to_string(i) + ".txt", fstream::trunc);
    streamd.close();
  }

  ofstream streamdv;
  std::string const HOMEdv = std::getenv("HOME") ? std::getenv("HOME") : ".";
  string pathdv = "/repos/ns-3-allinone/ns-3-dev/outputResults/RaValues";
  
  std::ofstream stream2;
  std::string HOME2 = std::getenv("HOME") ? std::getenv("HOME") : ".";
  string path2 = "/repos/ns-3-allinone/ns-3-dev/outputResults/RaValues";


  // DON'T FORGET TO SET THIS FOR LONGER ONES
  bool doItAll = false;
  //write a list sort for rtt
  TotalTime = 50.009;

  if(doItAll == true){
    for(tries = -6; tries <= 0; tries++){
      // 1 is AODV, 2 is NCPR, 3 is PTRP, 7 is newProtocol     ra is accrinug up along with nni it evens out but newproto doesnt
      for(protocolChoice = 1; protocolChoice <= 4; protocolChoice+=1){
        // Goes through 50, 100, 150, 200 and 250 number of nodes
        //speed
        for(nodeSpeed = 50; nodeSpeed <= 50; nodeSpeed+= 400){
          for(nSinks = 20; nSinks <= 30; nSinks += 100){
            // Changes number of CBR connections from 10, 15 to 20
            for(TotalNodes = 50; TotalNodes <= 250; TotalNodes += 50){
              if(doItAll == true && protocolChoice == 4){
                //protocolChoice++;
                //doItAll = false;
              }//when recv rreq and checking in routtable, check extra routetable and send there instead same way instead of broadcasting

              RoutingExperiment experiment; //Object is created 
              std::string CSVfileName = experiment.CommandSetup (argc,argv);
              std::ofstream out (CSVfileName.c_str ());
              out << std::endl;
              out.close ();
              double txp = 7.5;
              //when adding fileio the error suggests the ipv4 address for a nodes has incorrect number of dots in it

              stream2.open(HOME2 + path2 + ".txt", ios::app);
              stream2 << endl << "NextExpirement" << endl;
              stream2.close();

        
              // Delete all temp files and reset values to 0
              for(int i = 1; i < 256; i++){
                streamd.open(HOMEd + pathd + to_string(i) + ".txt", fstream::trunc);
                streamd.close();
              }
              bytesTotal = 0;
              packetsReceived = 0;
              SentPackets = 0;
              ReceivedPackets = 0;
              LostPackets = 0;
              packetsReceivedIncludingOverhead = 0;


              experiment.Run (nSinks, txp, CSVfileName);
            }
          }
        }
        ofstream streamvalues;
        string pathvalues = "/repos/ns-3-allinone/ns-3-dev/outputResults/resultValues";  
        streamvalues.open(HOMEd + pathvalues + ".txt", ios::out | ios::app);
        streamvalues << endl;
        streamvalues.close();
      }
    }
  } else {
        // DON'T FORGET THE doItAll = false

        protocolChoice = 3;
        TotalNodes = 50;
        TotalTime = 5;
        nSinks = 10;                  //default = 10, tests = 20
        nodeSpeed = 20;               //default = 5/20?
        
        RoutingExperiment experiment; //Object is created 
        std::string CSVfileName = experiment.CommandSetup (argc,argv);
        std::ofstream out (CSVfileName.c_str ());
        out << std::endl;
        out.close ();
        double txp = 7.5;             //default 7.5
        experiment.Run (nSinks, txp, CSVfileName);
  }

}

//check the ncpr fc and fp actual values then try ra^cfni cause ra mightbbe wrong if not try the base ncpr again with sendreq having ppt/n/sum=0 //scrap it all start from ncpr and do it again without copypasting prev work in case of errors
//find the place where ttl for reply ack not recieved happens then replace with rtt array instead of send packet because there has to be a send packet function there
void
RoutingExperiment::Run (int nSinks, double txp, std::string CSVfileName)
{
  if(protocolChoice == 3){
    txp++;
    rate = "2548bps";//rate ("2048bps");
  }
  Packet::EnablePrinting ();
  m_nSinks = nSinks;
  m_txp = txp;
  m_CSVfileName = CSVfileName;

  int nWifis = TotalNodes;


  std::string tr_name (m_protocolName);     
  //nodeSpeed = 30; //in m/s was 20 set 5?
  int nodePause = 0; //in s
  m_protocolName = "protocol";

  
  Config::SetDefault  ("ns3::OnOffApplication::PacketSize",StringValue ("64"));
  Config::SetDefault ("ns3::OnOffApplication::DataRate",  StringValue (rate));

  //Set Non-unicastMode rate to unicast mode
  Config::SetDefault ("ns3::WifiRemoteStationManager::NonUnicastMode",StringValue (phyMode));

  NodeContainer adhocNodes;
  adhocNodes.Create (nWifis);

  // Save number of nodes
  ofstream stream2;
  std::string const HOME2 = std::getenv("HOME") ? std::getenv("HOME") : ".";
  string path2 = "/repos/ns-3-allinone/ns-3-dev/outputResults/numberOfNodes";  
  stream2.open(HOME2 + path2 + ".txt", ios::out | ios::trunc);
  stringstream toWrite2;
  toWrite2 << nWifis;
  stream2 << toWrite2.str();
  stream2.close();  
  
  // Save node speed
  ofstream stream3;
  std::string const HOME3 = std::getenv("HOME") ? std::getenv("HOME") : ".";
  string path3 = "/repos/ns-3-allinone/ns-3-dev/outputResults/nodeSpeed";  
  stream3.open(HOME2 + path2 + ".txt", ios::out | ios::trunc);
  stringstream toWrite3;
  toWrite3 << nodeSpeed;
  stream3 << toWrite2.str();
  stream3.close();

  // setting up wifi phy and channel using helpers
  WifiHelper wifi;
  wifi.SetStandard (WIFI_PHY_STANDARD_80211b);
  //YANS - Yet Another NEtwork Simulator
  YansWifiPhyHelper wifiPhy =  YansWifiPhyHelper::Default ();
  YansWifiChannelHelper wifiChannel;
  wifiChannel.SetPropagationDelay ("ns3::ConstantSpeedPropagationDelayModel");
  wifiChannel.AddPropagationLoss ("ns3::FriisPropagationLossModel");
  wifiPhy.SetChannel (wifiChannel.Create ());

  // Add a mac and disable rate control
  WifiMacHelper wifiMac;
  wifi.SetRemoteStationManager ("ns3::ConstantRateWifiManager",
                                "DataMode",StringValue (phyMode),
                                "ControlMode",StringValue (phyMode));

  wifiPhy.Set ("TxPowerStart",DoubleValue (txp));
  wifiPhy.Set ("TxPowerEnd", DoubleValue (txp));

  wifiMac.SetType ("ns3::AdhocWifiMac");
  NetDeviceContainer adhocDevices = wifi.Install (wifiPhy, wifiMac, adhocNodes);

  MobilityHelper mobilityAdhoc;
  int64_t streamIndex = 0; // used to get consistent mobility across scenarios

  ObjectFactory pos;
  pos.SetTypeId ("ns3::RandomRectanglePositionAllocator");
  pos.Set ("X", StringValue ("ns3::UniformRandomVariable[Min=0.0|Max=1000.0]"));
  pos.Set ("Y", StringValue ("ns3::UniformRandomVariable[Min=0.0|Max=1000.0]"));
  //300x1500metres 
  //flag topology size 1000x1000
  Ptr<PositionAllocator> taPositionAlloc = pos.Create ()->GetObject<PositionAllocator> ();
  streamIndex += taPositionAlloc->AssignStreams (streamIndex);

  std::stringstream ssSpeed;
  ssSpeed << "ns3::UniformRandomVariable[Min=0.0|Max=" << nodeSpeed << "]";
  std::stringstream ssPause;
  ssPause << "ns3::ConstantRandomVariable[Constant=" << nodePause << "]";
  mobilityAdhoc.SetMobilityModel ("ns3::RandomWaypointMobilityModel",
                                  "Speed", StringValue (ssSpeed.str ()),
                                  "Pause", StringValue (ssPause.str ()),
                                  "PositionAllocator", PointerValue (taPositionAlloc));
  mobilityAdhoc.SetPositionAllocator (taPositionAlloc);
  mobilityAdhoc.Install (adhocNodes);
  streamIndex += mobilityAdhoc.AssignStreams (adhocNodes, streamIndex);
  NS_UNUSED (streamIndex); // From this point, streamIndex is unused
  //protocol section
  ncprHelper ncpr;
  //dcfpHelper dcfp;
  //npbHelper npb;
  //newprotocolHelper newprotocol;
  //ourprotocolHelper ourprotocol;
  //AomdvHelper aomdv;
  //MprpHelper mprp;
  //aodvrttHelper aodvrtt;
  ptrpHelper ptrp;
  //ptrprttHelper ptrprtt;

  //AodvHelper aodv;
  //DprHelper dpr;
  //WprHelper wpr;
  AodvHelper aodv;
  OlsrHelper olsr;
  DsdvHelper dsdv;
  DsrHelper dsr;
  DsrMainHelper dsrMain;
  Ipv4ListRoutingHelper list;
  InternetStackHelper internet;

  switch (m_protocol)
    {
    case 1:
      list.Add (aodv, 100);
      m_protocolName = "AODV";
      break;
    case 2:
      list.Add (ncpr, 100);
      m_protocolName = "NCPR";
      break;
    case 3:
      list.Add(ptrprtt, 100);
      m_protocolName = "PTRP";
      break;
    case 4:
      //list.Add(npb, 100);
      m_protocolName = "NPB";
      break;
      //list.Add (mprp, 100);
      //m_protocolName = "MPRP";
    /*
      list.Add (newprotocol, 100);
      m_protocolName = "newprotocol";
      break;*/

    case 5:
      //list.Add (aomdv, 100);
      //m_protocolName = "AOMDV";
      //list.Add(wpr, 100);
      m_protocolName = "WPR";
      break;
    case 6:
      //list.Add (dpr, 100);
      m_protocolName = "DPR";
      break;
    default:
      NS_FATAL_ERROR ("No such protocol:" << m_protocol);
    }


//if i get the ip out of bouinds i may be installing the wrong type of adhoc nodes
  if (m_protocol < 40)
    {
      internet.SetRoutingHelper (list);
      internet.Install (adhocNodes);
    }
  else if (m_protocol == 6)
    {
      internet.Install (adhocNodes);
      dsrMain.Install (dsr, adhocNodes);
    }
//application sends to ipv4layer sends to routing protocol, 
  NS_LOG_INFO ("assigning ip address");

  Ipv4AddressHelper addressAdhoc;
  addressAdhoc.SetBase ("10.1.1.0", "255.255.255.0");
  Ipv4InterfaceContainer adhocInterfaces;
  adhocInterfaces = addressAdhoc.Assign (adhocDevices);

  OnOffHelper onoff1 ("ns3::UdpSocketFactory",Address ());
  onoff1.SetAttribute ("OnTime", StringValue ("ns3::ConstantRandomVariable[Constant=1.0]"));
  onoff1.SetAttribute ("OffTime", StringValue ("ns3::ConstantRandomVariable[Constant=0.0]"));
// setup callback for spv4ListRoutingHelpeinks
  for (int i = 0; i < nSinks; i++)
    {
      Ptr<Socket> sink = SetupPacketReceive (adhocInterfaces.GetAddress (i), adhocNodes.Get (i));

      AddressValue remoteAddress (InetSocketAddress (adhocInterfaces.GetAddress (i), port));
      onoff1.SetAttribute ("Remote", remoteAddress);

      Ptr<UniformRandomVariable> var = CreateObject<UniformRandomVariable> ();
      ApplicationContainer temp = onoff1.Install (adhocNodes.Get (i + nSinks));
      temp.Start (Seconds (var->GetValue (0.0,1.0)));
      temp.Stop (Seconds (TotalTime));
    }

  std::stringstream ss;
  ss << nWifis;
  std::string nodes = ss.str ();

  std::stringstream ss2;
  ss2 << nodeSpeed;
  std::string sNodeSpeed = ss2.str ();

  std::stringstream ss3;
  ss3 << nodePause;
  std::string sNodePause = ss3.str ();

  std::stringstream ss4;
  ss4 << rate;
  std::string sRate = ss4.str ();

  //NS_LOG_INFO ("Configure Tracing.");
  //tr_name = tr_name + "_" + m_protocolName +"_" + nodes + "nodes_" + sNodeSpeed + "speed_" + sNodePause + "pause_" + sRate + "rate";

//  AsciiTraceHelper ascii;
//  Ptr<OutputStreamWrapper> osw = ascii.CreateFileStream ( (m_protocolName + ".tr").c_str());
//  wifiPhy.EnableAsciiAll (osw);
  //AsciiTraceHelper ascii;
//  MobilityHelper::EnableAsciiAll (ascii.CreateFileStream (m_protocolName + ".mob"));

//Powerful tool in ns3 called Flowmonitor... This will create a XML File, //
//and one can use python element tree to parse this... 


  FlowMonitorHelper flowmon;
  Ptr<FlowMonitor> monitor = flowmon.InstallAll();

  NS_LOG_INFO ("Run Simulation.");

  CheckThroughput ();
  
  Simulator::Stop (Seconds (TotalTime));
  Simulator::Run ();

//read from file for new number each time to keep track of which run im looking at, increment afterwards
//fileoutput all the NSLOGS 

  ofstream stream;
  ofstream streamvalues;

  std::string const HOME = std::getenv("HOME") ? std::getenv("HOME") : ".";
  const char *path = "/repos/ns-3-allinone/ns-3-dev/outputResults/resultscount";  
  string pathvalues = "/repos/ns-3-allinone/ns-3-dev/outputResults/resultValues";  
  stream.open(HOME + path + ".txt", ios::out | ios::app);
  streamvalues.open(HOME + pathvalues + ".txt", ios::out | ios::app);

  ifstream streambroadcasts;
  string pathbc = "/repos/ns-3-allinone/ns-3-dev/outputResults/tempbroadcasts";  
  streambroadcasts.open(HOME + pathbc + ".txt", ios::out | ios::app);
  //streambroadcasts << m_broadcastCount << endl;


  stringstream toWrite;
  stringstream toWritevalues;

  int j = 0;
  float AvgThroughput = 0;
  Time Jitter;
  Time Delay;

  Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier> (flowmon.GetClassifier ());
  std::map<FlowId, FlowMonitor::FlowStats> stats = monitor->GetFlowStats ();

  for (std::map<FlowId, FlowMonitor::FlowStats>::const_iterator iter = stats.begin (); iter != stats.end (); ++iter)
    {
	  //Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow (iter->first);
 /*
    NS_LOG_UNCOND("----Flow ID:" <<iter->first);
    NS_LOG_UNCOND("Src Addr" <<t.sourceAddress << "Dst Addr "<< t.destinationAddress);
    NS_LOG_UNCOND("Sent Packets=" <<iter->second.txPackets);
    NS_LOG_UNCOND("Received Packets =" <<iter->second.rxPackets);
    NS_LOG_UNCOND("Lost Packets =" <<iter->second.txPackets-iter->second.rxPackets);
    NS_LOG_UNCOND("Packet delivery ratio =" <<iter->second.rxPackets*100/iter->second.txPackets << "%");
    NS_LOG_UNCOND("Packet loss ratio =" << (iter->second.txPackets-iter->second.rxPackets)*100/iter->second.txPackets << "%");
    NS_LOG_UNCOND("Delay =" <<iter->second.delaySum);
    NS_LOG_UNCOND("Jitter =" <<iter->second.jitterSum);
    NS_LOG_UNCOND("Throughput =" <<iter->second.rxBytes * 8.0/(iter->second.timeLastRxPacket.GetSeconds()-iter->second.timeFirstTxPacket.GetSeconds())/1024<<"Kbps"); 
*/
    SentPackets = SentPackets +(iter->second.txPackets);
    ReceivedPackets = ReceivedPackets + (iter->second.rxPackets);
    LostPackets = LostPackets + (iter->second.txPackets-iter->second.rxPackets);
    AvgThroughput = AvgThroughput + (iter->second.rxBytes * 8.0/(iter->second.timeLastRxPacket.GetSeconds()-iter->second.timeFirstTxPacket.GetSeconds())/1024);
    Delay = Delay + (iter->second.delaySum);
    Jitter = Jitter + (iter->second.jitterSum);

    j = j + 1;

  }


  AvgThroughput = AvgThroughput/j;


  //streamvalues <<"Protocol/Nodes/Sim Time/CBR Connections/Total Sent Packets/Total Recieved Packets/Total Data Packets Recieved(without overhead or flowmon)/Total Recieved Packets (including overhead)/Total Lost Packets/Packet Loss Ratio/Packet Delivery Ratio/Average Throughput/End to End Delay/End to End Jitter" << endl;
  
  streamvalues << m_protocolName << "/" << TotalNodes << "/" << TotalTime << "/" << nSinks << "/";
  streamvalues << SentPackets << "/";
  streamvalues << ReceivedPackets << "/";
  streamvalues << packetsReceived << "/";

  streamvalues << packetsReceivedIncludingOverhead << "/";
  streamvalues << LostPackets << "/";
  streamvalues << ((LostPackets*100.00)/SentPackets) << "/";
  streamvalues << ((ReceivedPackets*100.00)/SentPackets) << "/";
  streamvalues << AvgThroughput << "/";
  streamvalues << Delay << "/";
  streamvalues << Jitter << "/";
  streamvalues << j << "/";

  //string broadcasts >> streambroadcasts;
  //streamvalues << broadcasts;


  streamvalues << endl << toWritevalues.str();
  streamvalues.close();
  


  stream << endl <<"--------Total Results----------";
  stream << endl <<"Protocol / Nodes / Sim Time / CBR Connections = " << m_protocolName << " / " << TotalNodes << " / " << TotalTime << " / " << nSinks << endl;
  stream << endl <<"Total Sent Packets  = " << SentPackets;
  stream << endl <<"Total Received Packets = " << ReceivedPackets;
  stream << endl <<"Total Data Packets Recieved (Without Overhead/FlowMon) = " << packetsReceived;

  stream << endl <<"Total Received Packets (Including Overhead) = " << packetsReceivedIncludingOverhead;
  stream << endl <<"Total Lost Packets = " << LostPackets;
  stream << endl <<"Packet Loss Ratio = " << ((LostPackets*100.00)/SentPackets)<< "%";
  stream << endl <<"Packet Delivery Ratio = " << ((ReceivedPackets*100.00)/SentPackets)<< "%";
  stream << endl <<"Average Throughput = " << AvgThroughput<< "Kbps";
  stream << endl <<"End to End Delay = " << Delay;
  stream << endl <<"End to End Jitter delay = " << Jitter;
  stream << endl <<"Total Flow ID's " << j;
  stream << endl;
  monitor->SerializeToXmlFile("manet-routing.xml", true, true);

  flowmon.SerializeToXmlFile ((m_protocolName + ".flowmon").c_str(), true, true);
  
  stream << endl << toWrite.str();
  stream.close();
  streambroadcasts.close();



  // Debugging information
  cout << "Packet Delivery Ratio = " << ((ReceivedPackets*100.00)/SentPackets)<< "%" << endl;
  cout << "Total Sent Packets  = " << SentPackets << endl;
  cout << "Total Received Packets = " << ReceivedPackets << endl;
  cout << "Total Data Packets Recieved (Without Overhead/FlowMon) = " << packetsReceived << endl;

  // Delete all temp files
  ofstream streamd;
  std::string const HOMEd = std::getenv("HOME") ? std::getenv("HOME") : ".";
  string pathd = "/repos/ns-3-allinone/ns-3-dev/outputTextFiles/10.1.1.";
  for(int i = 1; i < 256; i++){
    streamd.open(HOMEd + pathd + to_string(i) + ".txt", fstream::trunc);
    streamd.close();
  }

  Simulator::Destroy ();
}

