/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "clafaodv-helper.h"
#include "ns3/clafaodv-routing-protocol.h"
#include "ns3/node-list.h"
#include "ns3/names.h"
#include "ns3/ptr.h"
#include "ns3/ipv4-list-routing.h"
namespace ns3 {

/* ... */

clafaodvHelper::clafaodvHelper() :
  Ipv4RoutingHelper ()
{
  m_agentFactory.SetTypeId ("ns3::clafaodv::RoutingProtocol");
}

clafaodvHelper*
clafaodvHelper::Copy (void) const
{
  return new clafaodvHelper (*this);
}

Ptr<Ipv4RoutingProtocol> 
clafaodvHelper::Create (Ptr<Node> node) const
{
  Ptr<clafaodv::RoutingProtocol> agent = m_agentFactory.Create<clafaodv::RoutingProtocol> ();
  node->AggregateObject (agent);
  return agent;
}

void 
clafaodvHelper::Set (std::string name, const AttributeValue &value)
{
  m_agentFactory.Set (name, value);
}

int64_t
clafaodvHelper::AssignStreams (NodeContainer c, int64_t stream)
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
      Ptr<clafaodv::RoutingProtocol> clafaodv = DynamicCast<clafaodv::RoutingProtocol> (proto);
      if (clafaodv)
        {
          currentStream += clafaodv->AssignStreams (currentStream);
          continue;
        }
      // clafaodv may also be in a list
      Ptr<Ipv4ListRouting> list = DynamicCast<Ipv4ListRouting> (proto);
      if (list)
        {
          int16_t priority;
          Ptr<Ipv4RoutingProtocol> listProto;
          Ptr<clafaodv::RoutingProtocol> listclafaodv;
          for (uint32_t i = 0; i < list->GetNRoutingProtocols (); i++)
            {
              listProto = list->GetRoutingProtocol (i, priority);
              listclafaodv = DynamicCast<clafaodv::RoutingProtocol> (listProto);
              if (listclafaodv)
                {
                  currentStream += listclafaodv->AssignStreams (currentStream);
                  break;
                }
            }
        }
    }
  return (currentStream - stream);
}


}

