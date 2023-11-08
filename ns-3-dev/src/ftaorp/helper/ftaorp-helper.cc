/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ftaorp-helper.h"
#include "ns3/ftaorp-routing-protocol.h"
#include "ns3/node-list.h"
#include "ns3/names.h"
#include "ns3/ptr.h"
#include "ns3/ipv4-list-routing.h"
namespace ns3 {

/* ... */

ftaorpHelper::ftaorpHelper() :
  Ipv4RoutingHelper ()
{
  m_agentFactory.SetTypeId ("ns3::ftaorp::RoutingProtocol");
}

ftaorpHelper*
ftaorpHelper::Copy (void) const
{
  return new ftaorpHelper (*this);
}

Ptr<Ipv4RoutingProtocol> 
ftaorpHelper::Create (Ptr<Node> node) const
{
  Ptr<ftaorp::RoutingProtocol> agent = m_agentFactory.Create<ftaorp::RoutingProtocol> ();
  node->AggregateObject (agent);
  return agent;
}

void 
ftaorpHelper::Set (std::string name, const AttributeValue &value)
{
  m_agentFactory.Set (name, value);
}

int64_t
ftaorpHelper::AssignStreams (NodeContainer c, int64_t stream)
{
  int64_t currentStream = stream;
  Ptr<Node> node;
  for (NodeContainer::Iterator i = c.Begin (); i != c.End (); ++i)
    {
      node = (*i);
      Ptr<Ipv4> ipv4 = node->GetObject<Ipv4> ();
      NS_ASSERT_MSG (ipv4, "Ipv4 not installed on node");
      Ptr<Ipv4RoutingProtocol> proto = ipv4->GetRoutingProtocol ();
      NS_ASSERT_MSG (proto, "Ipv4 routing not installed on node");
      Ptr<ftaorp::RoutingProtocol> ftaorp = DynamicCast<ftaorp::RoutingProtocol> (proto);
      if (ftaorp)
        {
          currentStream += ftaorp->AssignStreams (currentStream);
          continue;
        }
      // ftaorp may also be in a list
      Ptr<Ipv4ListRouting> list = DynamicCast<Ipv4ListRouting> (proto);
      if (list)
        {
          int16_t priority;
          Ptr<Ipv4RoutingProtocol> listProto;
          Ptr<ftaorp::RoutingProtocol> listftaorp;
          for (uint32_t i = 0; i < list->GetNRoutingProtocols (); i++)
            {
              listProto = list->GetRoutingProtocol (i, priority);
              listftaorp = DynamicCast<ftaorp::RoutingProtocol> (listProto);
              if (listftaorp)
                {
                  currentStream += listftaorp->AssignStreams (currentStream);
                  break;
                }
            }
        }
    }
  return (currentStream - stream);
}


}

