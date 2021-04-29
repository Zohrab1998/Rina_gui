#ifndef NETSTAT_H
#define NETSTAT_H

#include "netconf.hpp"

using namespace rina_network;

class Netstat : public Netconf {

public:
  int setStats(uint16_t);

};





#endif
