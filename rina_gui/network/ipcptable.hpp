#ifndef IPCP_INFO_H
#define IPCP_INFO_H

#include <string>

#ifdef __cplusplus
extern "C" {
#include "rlite/conf.h"
}
#endif

struct ipcp_attrs {
  rl_ipcp_id_t id;
  char *name;
  rlm_addr_t addr;
  unsigned int txhdroom;
  unsigned int rxhdroom;
  unsigned int tailroom;
  unsigned int max_sdu_size;
  char *dif_type;
  char *dif_name;
  int wait_for_delete;
  struct list_head node;
};


class Ipcpinfo {

private:
  struct list_head  ipcps;
  struct ipcp_attrs *attrs;
  struct ipcp_attrs *table_of_ipcps = 0;
  int table_rows;

private:
  int load();

public:
  int update();
  int getRowsN();
  struct ipcp_attrs *getTable();
  struct ipcp_attrs *getIpcpAttrs(std::string ipcp_name);

};


#endif // IPCP_INFO_H
