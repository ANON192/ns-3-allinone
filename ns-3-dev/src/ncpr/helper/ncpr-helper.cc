/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ncpr-helper.h"
#include "ns3/ncpr-routing-protocol.h"
#include "ns3/node-list.h"
#include "ns3/names.h"
#include "ns3/ptr.h"
#include "ns3/ipv4-list-routing.h"
namespace ns3 {

/* ... */

ncprHelper::ncprHelper() : 
  Ipv4RoutingHelper ()
{
  m_agentFactory.SetTypeId ("ns3::ncpr::RoutingProtocol");
}

ncprHelper* 
ncprHelper::Copy (void) const 
{
  return new ncprHelper (*this); 
}

Ptr<Ipv4RoutingProtocol> 
ncprHelper::Create (Ptr<Node> node) const
{
  Ptr<ncpr::RoutingProtocol> agent = m_agentFactory.Create<ncpr::RoutingProtocol> ();
  node->AggregateObject (agent);
  return agent;
}

void 
ncprHelper::Set (std::string name, const AttributeValue &value)
{
  m_agentFactory.Set (name, value);
}

int64_t
ncprHelper::AssignStreams (NodeContainer c, int64_t stream)
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
      Ptr<ncpr::RoutingProtocol> ncpr = DynamicCast<ncpr::RoutingProtocol> (proto);
      if (ncpr)
        {
          currentStream += ncpr->AssignStreams (currentStream);
          continue;
        }
      // ncpr may also be in a list
      Ptr<Ipv4ListRouting> list = DynamicCast<Ipv4ListRouting> (proto);
      if (list)
        {
          int16_t priority;
          Ptr<Ipv4RoutingProtocol> listProto;
          Ptr<ncpr::RoutingProtocol> listncpr;
          for (uint32_t i = 0; i < list->GetNRoutingProtocols (); i++)
            {
              listProto = list->GetRoutingProtocol (i, priority);
              listncpr = DynamicCast<ncpr::RoutingProtocol> (listProto);
              if (listncpr)
                {
                  currentStream += listncpr->AssignStreams (currentStream);
                  break;
                }
            }
        }
    }
  return (currentStream - stream);
}


}

