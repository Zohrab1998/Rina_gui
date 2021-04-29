#include "ipcpstat.hpp"

using namespace std;
using namespace rina_network;

/******************************************************************************/
// Constructor
Ipcpstat::Ipcpstat(){
  this->ipcp_stats = (struct rl_ipcp_stats*)malloc(sizeof(struct rl_ipcp_stats));
}

/******************************************************************************/
// Destructor
Ipcpstat::~Ipcpstat(){
  free(ipcp_stats);
}

/******************************************************************************/
// Getters
uint64_t Ipcpstat::getTxPkt(){
  return this->ipcp_stats->tx_pkt;
}

uint64_t Ipcpstat::getTxByte(){
  return this->ipcp_stats->tx_byte;
}

uint64_t Ipcpstat::getTxErr(){
  return this->ipcp_stats->tx_err;
}

uint64_t Ipcpstat::getRxPkt(){
  return this->ipcp_stats->rx_pkt;
}

uint64_t Ipcpstat::getRxByte(){
  return this->ipcp_stats->rx_byte;
}

uint64_t Ipcpstat::getRxErr(){
  return this->ipcp_stats->rx_err;
}

uint64_t Ipcpstat::getRTxPkt(){
  return this->ipcp_stats->rtx_pkt;
}

uint64_t Ipcpstat::getRTxByte(){
  return this->ipcp_stats->rtx_byte;
}

/******************************************************************************/
// Setters
int Ipcpstat::setStats(uint16_t ipcp_id){

  int status = rl_conf_ipcp_get_stats(ipcp_id, this->ipcp_stats);

  return status;
}
