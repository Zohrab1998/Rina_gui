#ifndef FLOW_STAT_H
#define FLOW_STAT_H

#include "netstat.hpp"

class Flowstat : public Netstat {

public:
   Flowstat();
  ~Flowstat();


private:
  struct rl_flow_stats *flow_stats;

public:
  int setStats(uint16_t);

public:
  uint64_t getTxPkt();
  uint64_t getTxByte();
  uint64_t getRxPkt();
  uint64_t getRxByte();
  uint64_t getRxOPkt();
  uint64_t getRxOByte();

};

#endif
