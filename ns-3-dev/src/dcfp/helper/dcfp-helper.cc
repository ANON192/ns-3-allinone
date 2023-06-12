/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "dcfp-helper.h"
#include "ns3/dcfp-routing-protocol.h"
#include "ns3/node-list.h"
#include "ns3/names.h"
#include "ns3/ptr.h"
#include "ns3/ipv4-list-routing.h"
namespace ns3 {

/* ... */

dcfpHelper::dcfpHelper() : 
  Ipv4RoutingHelper ()
{
  m_agentFactory.SetTypeId ("ns3::dcfp::RoutingProtocol");
}

dcfpHelper* 
dcfpHelper::Copy (void) const 
{
  return new dcfpHelper (*this); 
}

Ptr<Ipv4RoutingProtocol> 
dcfpHelper::Create (Ptr<Node> node) const
{
  Ptr<dcfp::RoutingProtocol> agent = m_agentFactory.Create<dcfp::RoutingProtocol> ();
  node->AggregateObject (agent);
  return agent;
}

void 
dcfpHelper::Set (std::string name, const AttributeValue &value)
{
  m_agentFactory.Set (name, value);
}

int64_t
dcfpHelper::AssignStreams (NodeContainer c, int64_t stream)
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
      Ptr<dcfp::RoutingProtocol> dcfp = DynamicCast<dcfp::RoutingProtocol> (proto);
      if (dcfp)
        {
          currentStream += dcfp->AssignStreams (currentStream);
          continue;
        }
      // dcfp may also be in a list
      Ptr<Ipv4ListRouting> list = DynamicCast<Ipv4ListRouting> (proto);
      if (list)
        {
          int16_t priority;
          Ptr<Ipv4RoutingProtocol> listProto;
          Ptr<dcfp::RoutingProtocol> listdcfp;
          for (uint32_t i = 0; i < list->GetNRoutingProtocols (); i++)
            {
              listProto = list->GetRoutingProtocol (i, priority);
              listdcfp = DynamicCast<dcfp::RoutingProtocol> (listProto);
              if (listdcfp)
                {
                  currentStream += listdcfp->AssignStreams (currentStream);
                  break;
                }
            }
        }
    }
  return (currentStream - stream);
}


}

