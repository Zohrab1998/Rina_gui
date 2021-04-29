// project headers
#include "netconf.hpp"
#include "ipcptable.hpp"

extern "C" {
  #include <rlite/kernel-msg.h>
  #include <rlite/ctrl.h>
  #include <rlite/conf.h>
  #include <rlite/uipcps-msg.h>
  #include "rlite-ctl.h"
  #include "rlite/list.h"
  #include "rlite/uipcps-helpers.h"
  #include "rlite/version.h"
}

// standard headers
#include <string>
#include <cstring>

using namespace std;
using namespace rina_network;

/******************************************************************************/
int rina_network::Netconf::ipcp_create(string ipcp_name, string dif_type, string dif_name){

  char *ipcp_name_ = (char*)malloc(ipcp_name.length());
  char *dif_type_ = (char*)malloc(dif_type.length());
  char *dif_name_ = (char*)malloc(dif_name.length());


  strcpy(ipcp_name_, ipcp_name.c_str());
  strcpy(dif_type_, dif_type.c_str());
  strcpy(dif_name_, dif_name.c_str());

  int status = rl_conf_ipcp_create(ipcp_name_, dif_type_, dif_name_);

  return status;
}

/******************************************************************************/
int Netconf::ipcp_destroy(uint16_t ipcp_id, const int sync = 0){

  int status = rl_conf_ipcp_destroy(ipcp_id, sync);

  return status;
}

/******************************************************************************/
int Netconf::ipcp_config(uint16_t ipcp_id, string p_name, string p_value){

  char *param_name = (char*)malloc(p_name.length());
  char *param_value = (char*)malloc(p_value.length());

  strcpy(param_name, p_name.c_str());
  strcpy(param_value, p_value.c_str());

  int status = rl_conf_ipcp_config(ipcp_id, param_name, param_value);

  return status;
}

/******************************************************************************/
int Netconf::ipcp_register(std::string ipcp_name, std::string dif_name) {

    struct rl_cmsg_ipcp_register req;

    // Convert IPCP/DIF name to char*
    char *ipcp_name_ = (char*)malloc(ipcp_name.length());
    char *dif_name_ = (char*)malloc(dif_name.length());
    strcpy(ipcp_name_, ipcp_name.c_str());
    strcpy(dif_name_, dif_name.c_str());

    // Fill ipcp attributes
    Ipcpinfo new_table;
    struct ipcp_attrs *attrs = new_table.getIpcpAttrs(ipcp_name);
    req.hdr.msg_type = RLITE_U_IPCP_REGISTER;
    req.hdr.event_id = 0;
    req.ipcp_name = strdup(ipcp_name_);
    req.dif_name     = strdup(dif_name_);
    req.reg          = 1;

    return 0;
    return request_response(RLITE_MB(&req), NULL, TO_DFLT_MSECS);
}









// eof
