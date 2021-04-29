#include "flowstat.hpp"


/******************************************************************************/
// Constructor
Flowstat::Flowstat(){
  this->flow_stats = (struct rl_flow_stats*)malloc(sizeof(struct rl_flow_stats));
}

/******************************************************************************/
// Destructor
Flowstat::~Flowstat(){
  free(flow_stats);
}

/******************************************************************************/
// Getters
uint64_t Flowstat::getTxPkt(){
  return this->flow_stats->tx_pkt;
}

uint64_t Flowstat::getTxByte(){
  return this->flow_stats->tx_byte;
}

uint64_t Flowstat::getRxPkt(){
  return this->flow_stats->rx_pkt;
}

uint64_t Flowstat::getRxByte(){
  return this->flow_stats->rx_byte;
}

uint64_t Flowstat::getRxOPkt(){
  return this->flow_stats->rx_overrun_pkt;
}

uint64_t Flowstat::getRxOByte(){
  return this->flow_stats->rx_overrun_byte;
}

/******************************************************************************/
// Setters
int Flowstat::setStats(uint16_t port_id = 0){

  int status = rl_conf_flow_get_stats(port_id, this->flow_stats);

  return status;
}
