/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "ptrp-helper.h"
#include "ns3/ptrp-routing-protocol.h"
#include "ns3/node-list.h"
#include "ns3/names.h"
#include "ns3/ptr.h"
#include "ns3/ipv4-list-routing.h"
namespace ns3 {

/* ... */

ptrpHelper::ptrpHelper() : 
  Ipv4RoutingHelper ()
{
  m_agentFactory.SetTypeId ("ns3::ptrp::RoutingProtocol");
}

ptrpHelper* 
ptrpHelper::Copy (void) const 
{
  return new ptrpHelper (*this); 
}

Ptr<Ipv4RoutingProtocol> 
ptrpHelper::Create (Ptr<Node> node) const
{
  Ptr<ptrp::RoutingProtocol> agent = m_agentFactory.Create<ptrp::RoutingProtocol> ();
  node->AggregateObject (agent);
  return agent;
}

void 
ptrpHelper::Set (std::string name, const AttributeValue &value)
{
  m_agentFactory.Set (name, value);
}

int64_t
ptrpHelper::AssignStreams (NodeContainer c, int64_t stream)
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
      Ptr<ptrp::RoutingProtocol> ptrp = DynamicCast<ptrp::RoutingProtocol> (proto);
      if (ptrp)
        {
          currentStream += ptrp->AssignStreams (currentStream);
          continue;
        }
      // ptrp may also be in a list
      Ptr<Ipv4ListRouting> list = DynamicCast<Ipv4ListRouting> (proto);
      if (list)
        {
          int16_t priority;
          Ptr<Ipv4RoutingProtocol> listProto;
          Ptr<ptrp::RoutingProtocol> listptrp;
          for (uint32_t i = 0; i < list->GetNRoutingProtocols (); i++)
            {
              listProto = list->GetRoutingProtocol (i, priority);
              listptrp = DynamicCast<ptrp::RoutingProtocol> (listProto);
              if (listptrp)
                {
                  currentStream += listptrp->AssignStreams (currentStream);
                  break;
                }
            }
        }
    }
  return (currentStream - stream);
}


}

