#ifndef IPCP_STAT_H
#define IPCP_STAT_H

#include "netstat.hpp"

class Ipcpstat : public Netstat {

private:
  uint16_t id;
  uint64_t addr;
  string name;
  string dif_name;
  string dif_type;
  unsigned int txhdroom;
  unsigned int rxhdroom;
  unsigned int tailroom;
  unsigned int max_sdu_size;

public:
   Ipcpstat();
  ~Ipcpstat();

private:
  struct rl_ipcp_stats *ipcp_stats;

public:
  int setStats(uint16_t);

public:
  uint64_t getTxPkt();
  uint64_t getTxByte();
  uint64_t getTxErr();
  uint64_t getRxPkt();
  uint64_t getRxByte();
  uint64_t getRxErr();
  uint64_t getRTxPkt();
  uint64_t getRTxByte();

};






#endif
