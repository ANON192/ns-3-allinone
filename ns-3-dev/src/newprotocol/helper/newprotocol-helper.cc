/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "newprotocol-helper.h"
#include "ns3/newprotocol-routing-protocol.h"
#include "ns3/node-list.h"
#include "ns3/names.h"
#include "ns3/ptr.h"
#include "ns3/ipv4-list-routing.h"
namespace ns3 {

/* ... */

newprotocolHelper::newprotocolHelper() : 
  Ipv4RoutingHelper ()
{
  m_agentFactory.SetTypeId ("ns3::newprotocol::RoutingProtocol");
}

newprotocolHelper* 
newprotocolHelper::Copy (void) const 
{
  return new newprotocolHelper (*this); 
}

Ptr<Ipv4RoutingProtocol> 
newprotocolHelper::Create (Ptr<Node> node) const
{
  Ptr<newprotocol::RoutingProtocol> agent = m_agentFactory.Create<newprotocol::RoutingProtocol> ();
  node->AggregateObject (agent);
  return agent;
}

void 
newprotocolHelper::Set (std::string name, const AttributeValue &value)
{
  m_agentFactory.Set (name, value);
}

int64_t
newprotocolHelper::AssignStreams (NodeContainer c, int64_t stream)
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
      Ptr<newprotocol::RoutingProtocol> newprotocol = DynamicCast<newprotocol::RoutingProtocol> (proto);
      if (newprotocol)
        {
          currentStream += newprotocol->AssignStreams (currentStream);
          continue;
        }
      // newprotocol may also be in a list
      Ptr<Ipv4ListRouting> list = DynamicCast<Ipv4ListRouting> (proto);
      if (list)
        {
          int16_t priority;
          Ptr<Ipv4RoutingProtocol> listProto;
          Ptr<newprotocol::RoutingProtocol> listnewprotocol;
          for (uint32_t i = 0; i < list->GetNRoutingProtocols (); i++)
            {
              listProto = list->GetRoutingProtocol (i, priority);
              listnewprotocol = DynamicCast<newprotocol::RoutingProtocol> (listProto);
              if (listnewprotocol)
                {
                  currentStream += listnewprotocol->AssignStreams (currentStream);
                  break;
                }
            }
        }
    }
  return (currentStream - stream);
}


}

