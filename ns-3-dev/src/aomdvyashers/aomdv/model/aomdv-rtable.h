#ifndef AOMDV_RTABLE_H
#define AOMDV_RTABLE_H

#include <stdint.h>
#include <cassert>
#include <map>
#include <stdlib.h>  
#include <list>
#include <sys/types.h>
#include "ns3/ipv4.h"
#include "ns3/ipv4-route.h"
#include "ns3/timer.h"
#include "ns3/net-device.h"
#include "ns3/output-stream-wrapper.h"

namespace ns3 {
namespace aomdv {

/**
 * \ingroup aomdv
 * \brief Route record states
 */
enum RouteFlags
{
  VALID = 0,          //!< VALID
  INVALID = 1,        //!< INVALID
  IN_SEARCH = 2,      //!< IN_SEARCH
};

class RouteItem{
public:
  RouteItem(Ptr<NetDevice> dev=0, Ipv4Address dst = Ipv4Address(), Ipv4Address src=Ipv4Address(), 
              uint16_t hops = 1000, Ipv4Address nextHop = Ipv4Address());  

 ~RouteItem(){};
  
  uint16_t GetHops() const
  {
    return m_hops;
  } 
  Ipv4Address GetSource() const
  {
    return m_ipv4Route->GetSource();
  }
  void SetHops(uint16_t hops){
    m_hops = hops; 
  }
  RouteItem
  getMe() const{
    return *this;
  }
  bool operator< (RouteItem second){
    if(this->GetHops() < second.GetHops()) return true;
    return false;
  }


  bool operator<= (RouteItem second){
    if(this->GetHops() <= second.GetHops()) return true;
    return false;
  }
  bool operator> (RouteItem second){
    if(this->GetHops() > second.GetHops()) return true;
    return false;
  }
  bool operator>= (RouteItem second){
    if(this->GetHops() >= second.GetHops()) return true;
    return false;
  }
  
  Ipv4Address GetDestination()
  {
    return m_ipv4Route->GetDestination();
  }

  void SetDestination(Ipv4Address dst){
    m_ipv4Route->SetDestination(dst);
  }

  Ptr<Ipv4Route> GetRoute()
  {
    return m_ipv4Route;
  }

  Ptr<NetDevice> GetOutputDevice () const
  {
    return m_ipv4Route->GetOutputDevice ();
  }
  
  void SetRoute (Ptr<Ipv4Route> r)
  {
    m_ipv4Route = r;
  }
  
  void SetNextHop (Ipv4Address nextHop)
  {
    m_ipv4Route->SetGateway (nextHop);
  }
  
  Ipv4Address GetNextHop () const
  {
    return m_ipv4Route->GetGateway ();
  }
  

  void SetOutputDevice (Ptr<NetDevice> dev)
  {
    m_ipv4Route->SetOutputDevice (dev);
  }
  void SetDevice(Ptr<NetDevice> dev)
  {
    m_ipv4Route->SetOutputDevice (dev);
  }
  Ptr<NetDevice> GetDevice()
  {
    return m_ipv4Route->GetOutputDevice();
  }
private:
  uint16_t m_hops;
  Ptr<Ipv4Route> m_ipv4Route;
};


/**
 * \ingroup aomdv
 * \brief Routing table entry
 */
class RoutingTableEntry
{
public:
  /**
   * constructor
   *
   * \param dev the device
   * \param dst the destination IP address
   * \param vSeqNo verify sequence number flag
   * \param seqNo the sequence number
   * \param iface the interface
   * \param hops the number of hops
   * \param nextHop the IP address of the next hop
   * \param lifetime the lifetime of the entry
   */
  RoutingTableEntry (Ptr<NetDevice> dev = 0,Ipv4Address dst = Ipv4Address (), bool vSeqNo = false, uint32_t seqNo = 0,
                     Ipv4InterfaceAddress iface = Ipv4InterfaceAddress (), uint16_t  hops = 0,
                     Ipv4Address nextHop = Ipv4Address (), Time lifetime = Simulator::Now ());

  ~RoutingTableEntry ();
  void AddRouteItem(RouteItem & rt);
  bool Update(RouteItem & rt);
  bool IsEmptyRoute() const{
    if(m_rlist.empty()) return true;
    return false;
  }
  bool RemoveNextHopRoute(Ipv4Address nextHop){
    bool result = false;
    if(m_rlist.empty())
    {
      return result;
    }
    std::list<RouteItem>::iterator i = m_rlist.begin();
    
    while(i!= m_rlist.end())
    {
      if(i->GetNextHop() == nextHop){
        i = m_rlist.erase(i);
        result = true;
      }
      else{
        i++;
      }
    }
    
    
    
    return result;
  }
  ///\name Precursors management
  //\{
  /**
   * Insert precursor in precursor list if it doesn't yet exist in the list
   * \param id precursor address
   * \return true on success
   */
  bool InsertPrecursor (Ipv4Address id);
  /**
   * Lookup precursor by address
   * \param id precursor address
   * \return true on success
   */
  bool LookupPrecursor (Ipv4Address id);
  /**
   * \brief Delete precursor
   * \param id precursor address
   * \return true on success
   */
  bool DeletePrecursor (Ipv4Address id);
  /// Delete all precursors
  void DeleteAllPrecursors ();
  /**
   * Check that precursor list is empty
   * \return true if precursor list is empty
   */
  bool IsPrecursorListEmpty () const;
  /**
   * Inserts precursors in output parameter prec if they do not yet exist in vector
   * \param prec vector of precursor addresses
   */
  void GetPrecursors (std::vector<Ipv4Address> & prec) const;
  //\}
  void Sort();
  /**
   * Mark entry as "down" (i.e. disable it)
   * \param badLinkLifetime duration to keep entry marked as invalid
   */
  void Invalidate (Time badLinkLifetime);

  // Fields
  /**
   * Get destination address function
   * \returns the IPv4 destination address
   */
  Ipv4Address GetDestination () const
  {
    RouteItem temp = m_rlist.front();
    return temp.GetDestination();
  }
  void Purge();

  /**
   * Get route function
   * \returns The IPv4 route
   */
  Ptr<Ipv4Route> GetRoute () const
  {
    RouteItem temp = m_rlist.front();
    return temp.GetRoute();
  }
  /**
   * Set route function
   * \param r the IPv4 route
   */
  // void SetRoute (Ptr<Ipv4Route> r)
  // {
  //   m_ipv4Route = r;
  // }
  // /**
  //  * Set next hop address
  //  * \param nextHop the next hop IPv4 address
  //  */
  void SetNextHop (Ipv4Address nextHop)
  {
    Ptr<Ipv4Route> _temp = this->GetRoute();
    _temp->SetGateway (nextHop);
  }
  // /**
  //  * Get next hop address
  //  * \returns the next hop address
  //  */
  Ipv4Address GetNextHop () const
  {
    RouteItem temp = m_rlist.front();
    return temp.GetNextHop();
  }
  // /**
  //  * Set output device
  //  * \param dev The output device
  //  */
  void SetOutputDevice (Ptr<NetDevice> dev)
  {
    Ptr<Ipv4Route> _temp = this->GetRoute();
    _temp->SetOutputDevice (dev);
  }
  /**
   * Get output device
   * \returns the output device
   */
  Ptr<NetDevice> GetOutputDevice () const
  {
    RouteItem temp = m_rlist.front();
    return temp.GetOutputDevice ();  
  }
  Ptr<NetDevice> GetOutputDevice (Ipv4Address nextHop) const
  {
    for(std::list<RouteItem>::const_iterator it = m_rlist.begin();
      it!=m_rlist.end();++it){
      if(it->GetNextHop() == nextHop) {
        return it->GetOutputDevice();
      }
    }
    // std::cout<<"No route found to "<<nextHop<<std::endl;
    return GetOutputDevice ();
  }
  /**
   * Get the Ipv4InterfaceAddress
   * \returns the Ipv4InterfaceAddress
   */
  Ipv4InterfaceAddress GetInterface () const
  {
    return m_iface;
  }
  /**
   * Set the Ipv4InterfaceAddress
   * \param iface The Ipv4InterfaceAddress
   */
  void SetInterface (Ipv4InterfaceAddress iface)
  {
    m_iface = iface;
  }

  bool IsValidInterFace()
  {
    if (m_iface.GetLocal()!=Ipv4Address("102.102.102.102"))
    {
      return true;
    }
    return false;
  }
  
  /**
   * Set the valid sequence number
   * \param s the sequence number
   */
  void SetValidSeqNo (bool s)
  {
    m_validSeqNo = s;
  }
  /**
   * Get the valid sequence number
   * \returns the valid sequence number
   */
  bool GetValidSeqNo () const
  {
    return m_validSeqNo;
  }
  /**
   * Set the sequence number
   * \param sn the sequence number
   */
  void SetSeqNo (uint32_t sn)
  {
    m_seqNo = sn;
  }
  /**
   * Get the sequence number
   * \returns the sequence number
   */
  uint32_t GetSeqNo () const
  {
    return m_seqNo;
  }
  /**
   * Set the number of hops
   * \param hop the number of hops
   */
  void SetHop (uint16_t hop)
  {
    m_hops = hop;
  }
  /**
   * Get the number of hops
   * \returns the number of hops
   */
  uint16_t GetHop () const
  {
    return m_hops;
  }
  /**
   * Set the lifetime
   * \param lt The lifetime
   */
  void SetLifeTime (Time lt)
  {
    m_lifeTime = lt + Simulator::Now ();
  }
  /**
   * Get the lifetime
   * \returns the lifetime
   */
  Time GetLifeTime () const
  {
    return m_lifeTime - Simulator::Now ();
  }
  /**
   * Set the route flags
   * \param flag the route flags
   */
  void SetFlag (RouteFlags flag)
  {
    m_flag = flag;
  }
  /**
   * Get the route flags
   * \returns the route flags
   */
  RouteFlags GetFlag () const
  {
    return m_flag;
  }
  /**
   * Set the RREQ count
   * \param n the RREQ count
   */
  void SetRreqCnt (uint8_t n)
  {
    m_reqCount = n;
  }
  /**
   * Get the RREQ count
   * \returns the RREQ count
   */
  uint8_t GetRreqCnt () const
  {
    return m_reqCount;
  }
  /**
   * Increment the RREQ count
   */
  void IncrementRreqCnt ()
  {
    m_reqCount++;
  }
  /**
   * Set the unidirectional flag
   * \param u the uni directional flag
   */
  void SetUnidirectional (bool u)
  {
    m_blackListState = u;
  }
  /**
   * Get the unidirectional flag
   * \returns the unidirectional flag
   */
  bool IsUnidirectional () const
  {
    return m_blackListState;
  }
  /**
   * Set the blacklist timeout
   * \param t the blacklist timeout value
   */
  void SetBlacklistTimeout (Time t)
  {
    m_blackListTimeout = t;
  }
  /**
   * Get the blacklist timeout value
   * \returns the blacklist timeout value
   */
  Time GetBlacklistTimeout () const
  {
    return m_blackListTimeout;
  }
  /// RREP_ACK timer
  Timer m_ackTimer;

  /**
   * \brief Compare destination address
   * \param dst IP address to compare
   * \return true if equal
   */
  bool operator== (Ipv4Address const  dst) const
  {
    RouteItem temp = m_rlist.front();
    Ptr<Ipv4Route> _ipv4Route = temp.GetRoute();
    return (_ipv4Route->GetDestination () == dst);
  }
  /**
   * Print packet to trace file
   * \param stream The output stream
   */
  void Print (Ptr<OutputStreamWrapper> stream) const;

  bool CompareRouteItems(RouteItem & first, RouteItem & second);

  bool FindRoute(Ipv4Address nextHop, RouteItem & rt );
private:
  /// Valid Destination Sequence Number flag
  bool m_validSeqNo;
  /// Destination Sequence Number, if m_validSeqNo = true
  uint32_t m_seqNo;
  /// Hop Count (number of hops needed to reach destination)
  uint16_t m_hops;
  /**
  * \brief Expiration or deletion time of the route
  *	Lifetime field in the routing table plays dual role:
  *	for an active route it is the expiration time, and for an invalid route
  *	it is the deletion time.
  */
  Time m_lifeTime;
  /** Ip route, include
   *   - destination address
   *   - source address
   *   - next hop address (gateway)
   *   - output device
   */
  //Ptr<Ipv4Route> m_ipv4Route;
  /// Output interface address
  Ipv4InterfaceAddress m_iface;
  /// Routing flags: valid, invalid or in search
  RouteFlags m_flag;

  /// List of precursors
  std::vector<Ipv4Address> m_precursorList;
  /// When I can send another request
  Time m_routeRequestTimout;
  /// Number of route requests
  uint8_t m_reqCount;
  /// Indicate if this entry is in "blacklist"
  bool m_blackListState;
  /// Time for which the node is put into the blacklist
  Time m_blackListTimeout;
  //list of possible routings
  std::list<RouteItem> m_rlist;
};

/**
 * \ingroup aomdv
 * \brief The Routing table used by aomdv protocol
 */
class RoutingTable
{
public:
  /**
   * constructor
   * \param t the routing table entry lifetime
   */
  RoutingTable (Time t);
  ///\name Handle lifetime of invalid route
  //\{
  Time GetBadLinkLifetime () const
  {
    return m_badLinkLifetime;
  }
  void SetBadLinkLifetime (Time t)
  {
    m_badLinkLifetime = t;
  }
  
  //\}
  /**
   * Add routing table entry if it doesn't yet exist in routing table
   * \param r routing table entry
   * \return true in success
   */
  bool AddRoute (RoutingTableEntry & r);
  bool AddRoute (RoutingTableEntry & rt,Ipv4Address & dst);
  /**
   * Delete routing table entry with destination address dst, if it exists.
   * \param dst destination address
   * \return true on success
   */
  bool DeleteRoute (Ipv4Address dst);
  /**
   * Lookup routing table entry with destination address dst
   * \param dst destination address
   * \param rt entry with destination address dst, if exists
   * \return true on success
   */
  bool LookupRoute (Ipv4Address dst, RoutingTableEntry & rt);
  /**
   * Lookup route in VALID state
   * \param dst destination address
   * \param rt entry with destination address dst, if exists
   * \return true on success
   */
  bool LookupValidRoute (Ipv4Address dst, RoutingTableEntry & rt);
  bool LookupRouteNotState (Ipv4Address dst, RoutingTableEntry & rt,RouteFlags st);
  /**
   * Update routing table
   * \param rt entry with destination address dst, if exists
   * \return true on success
   */
  bool Update (RoutingTableEntry & rt);
  bool Update (RoutingTableEntry & rt, Ipv4Address dst);
  /**
   * Set routing table entry flags
   * \param dst destination address
   * \param state the routing flags
   * \return true on success
   */
  bool SetEntryState (Ipv4Address dst, RouteFlags state);
  /**
   * Lookup routing entries with next hop Address dst and not empty list of precursors.
   *
   * \param nextHop the next hop IP address
   * \param unreachable
   */
  void GetListOfDestinationWithNextHop (Ipv4Address nextHop, std::map<Ipv4Address, uint32_t> & unreachable);
  /**
   *   Update routing entries with this destination as follows:
   *  1. The destination sequence number of this routing entry, if it
   *     exists and is valid, is incremented.
   *  2. The entry is invalidated by marking the route entry as invalid
   *  3. The Lifetime field is updated to current time plus DELETE_PERIOD.
   *  \param unreachable routes to invalidate
   */
  void InvalidateRoutesWithDst (std::map<Ipv4Address, uint32_t> const & unreachable);
  /**
   * Delete all route from interface with address iface
   * \param iface the interface IP address
   */
  void DeleteAllRoutesFromInterface (Ipv4InterfaceAddress iface);
  /// Delete all entries from routing table
  void Clear ()
  {
    m_ipv4AddressEntry.clear ();
  }
  /// Delete all outdated entries and invalidate valid entry if Lifetime is expired
  void Purge ();
  /** Mark entry as unidirectional (e.g. add this neighbor to "blacklist" for blacklistTimeout period)
   * \param neighbor - neighbor address link to which assumed to be unidirectional
   * \param blacklistTimeout - time for which the neighboring node is put into the blacklist
   * \return true on success
   */
  bool MarkLinkAsUnidirectional (Ipv4Address neighbor, Time blacklistTimeout);
  /**
   * Print routing table
   * \param stream the output stream
   */
  void Print (Ptr<OutputStreamWrapper> stream) const;

private:
  /// The routing table
  std::map<Ipv4Address, RoutingTableEntry> m_ipv4AddressEntry;
  /// Deletion time for invalid routes
  Time m_badLinkLifetime;
  /**
   * const version of Purge, for use by Print() method
   * \param table the routing table entry to purge
   */
  void Purge (std::map<Ipv4Address, RoutingTableEntry> &table) const;
};

}  // namespace aomdv
}  // namespace ns3

#endif /* AOMDV_RTABLE_H */
