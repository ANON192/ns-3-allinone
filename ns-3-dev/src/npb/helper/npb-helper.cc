/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "npb-helper.h"
#include "ns3/npb-routing-protocol.h"
#include "ns3/node-list.h"
#include "ns3/names.h"
#include "ns3/ptr.h"
#include "ns3/ipv4-list-routing.h"
namespace ns3 {

/* ... */

npbHelper::npbHelper() : 
  Ipv4RoutingHelper ()
{
  m_agentFactory.SetTypeId ("ns3::npb::RoutingProtocol");
}

npbHelper* 
npbHelper::Copy (void) const 
{
  return new npbHelper (*this); 
}

Ptr<Ipv4RoutingProtocol> 
npbHelper::Create (Ptr<Node> node) const
{
  Ptr<npb::RoutingProtocol> agent = m_agentFactory.Create<npb::RoutingProtocol> ();
  node->AggregateObject (agent);
  return agent;
}

void 
npbHelper::Set (std::string name, const AttributeValue &value)
{
  m_agentFactory.Set (name, value);
}

int64_t
npbHelper::AssignStreams (NodeContainer c, int64_t stream)
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
      Ptr<npb::RoutingProtocol> npb = DynamicCast<npb::RoutingProtocol> (proto);
      if (npb)
        {
          currentStream += npb->AssignStreams (currentStream);
          continue;
        }
      // npb may also be in a list
      Ptr<Ipv4ListRouting> list = DynamicCast<Ipv4ListRouting> (proto);
      if (list)
        {
          int16_t priority;
          Ptr<Ipv4RoutingProtocol> listProto;
          Ptr<npb::RoutingProtocol> listnpb;
          for (uint32_t i = 0; i < list->GetNRoutingProtocols (); i++)
            {
              listProto = list->GetRoutingProtocol (i, priority);
              listnpb = DynamicCast<npb::RoutingProtocol> (listProto);
              if (listnpb)
                {
                  currentStream += listnpb->AssignStreams (currentStream);
                  break;
                }
            }
        }
    }
  return (currentStream - stream);
}


}

