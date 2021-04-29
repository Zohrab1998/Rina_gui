// project headers
#include "ipcptable.hpp"

// standard headers c
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <sys/ioctl.h>

// standard headers cxx
#include <iostream>

using namespace std;

/******************************************************************************/
// Setter // TO DO ---> observe
int Ipcpinfo::load() {

  int fd = rina_open();
  if (fd < 0) {
      perror("rina_open()");
      return fd;
  }

  int ret = ioctl(fd, RLITE_IOCTL_CHFLAGS, RL_F_IPCPS);
  if (ret < 0) {
      perror("ioctl()");
      return ret;
  }

  ret = fcntl(fd, F_SETFL, O_NONBLOCK);
  if (ret < 0) {
      perror("fcntl(F_SETFL, O_NONBLOCK)");
      return ret;
  }

  list_init(&ipcps);

    for (;;) {
        struct rl_kmsg_ipcp_update *upd;
        struct ipcp_attrs *scan;

        upd = (struct rl_kmsg_ipcp_update *)rl_read_next_msg(fd, 1);
        if (!upd) {
            if (errno && errno != EAGAIN) {
                perror("rl_read_next_msg()");
            }
            break;
        }

        assert(upd->hdr.msg_type == RLITE_KER_IPCP_UPDATE);

        if (upd->update_type == RL_IPCP_UPDATE_ADD) {
            attrs = (struct ipcp_attrs *)malloc(sizeof(*attrs));

            attrs->id           = upd->ipcp_id;
            attrs->name         = upd->ipcp_name;
            upd->ipcp_name      = NULL;
            attrs->dif_type     = upd->dif_type;
            upd->dif_type       = NULL;
            attrs->dif_name     = upd->dif_name;
            upd->dif_name       = NULL;
            attrs->addr         = upd->ipcp_addr;
            attrs->txhdroom     = upd->txhdroom;
            attrs->rxhdroom     = upd->rxhdroom;
            attrs->tailroom     = upd->tailroom;
            attrs->max_sdu_size = upd->max_sdu_size;

            list_for_each_entry (scan, &ipcps, node) {
                if (attrs->id < scan->id) {
                    break;
                }
            }
            list_add_tail(&attrs->node, &scan->node);
        }
        rl_msg_free(rl_ker_numtables, RLITE_KER_MSG_MAX, RLITE_MB(upd));
        rl_free(upd, RL_MT_MSG);
    }

    close(fd);
    return ret;
}


/******************************************************************************/
int Ipcpinfo::update() {

  this->load();

  this->table_rows = 0;
  char addrbuf[20];

  list_for_each_entry (attrs, &ipcps, node) {


    table_rows++;

    if (attrs->addr == RL_ADDR_NULL) {
      strncpy(addrbuf, "*", sizeof(addrbuf));
    } else {
      snprintf(addrbuf, sizeof(addrbuf), "%llu", (long long unsigned int)attrs->addr);
    }

    table_of_ipcps = (struct ipcp_attrs*)realloc(table_of_ipcps, table_rows * sizeof(struct ipcp_attrs));

    table_of_ipcps[table_rows - 1] = {
      .id = attrs-> id,
      .name = attrs->name,
      .addr = attrs->addr,
      .txhdroom = attrs->txhdroom,
      .rxhdroom = attrs->rxhdroom,
      .tailroom = attrs->tailroom,
      .max_sdu_size = attrs->max_sdu_size,
      .dif_type = attrs->dif_type,
      .dif_name = attrs->dif_name,
      .wait_for_delete = attrs->wait_for_delete,
    };

    }



    return 0;
}

/******************************************************************************/
// Getters

/*
* Returns the number of rows in IPCP table, to iterate over them.
*/
int
Ipcpinfo::getRowsN(){
  return this->table_rows;
}

/******************************************************************************/
struct ipcp_attrs *Ipcpinfo::getTable(){
  return table_of_ipcps;
}

/******************************************************************************/
struct ipcp_attrs *Ipcpinfo::getIpcpAttrs(std::string ipcp_name){

  char *ipcp_name_ = (char*)malloc(ipcp_name.length());
  strcpy(ipcp_name_, ipcp_name.c_str());

  this->update();
  int rows = this->getRowsN();
  struct ipcp_attrs *table = this->getTable();

  for (int i = 0; i < rows; i++) {
    if (!strcmp(table[i].name, ipcp_name_)) {
      return &table[i];
    }
  }


}































// eof
