#ifndef NETCONF_H
#define NETCONF_H

#include <string>

#ifdef __cplusplus
extern "C" {
#include <rlite/conf.h>
}
#endif

using namespace std;

namespace rina_network {

  class Netconf {

  public:
    int ipcp_create(string, string, string);
    int ipcp_destroy(uint16_t, const int);
    int ipcp_config(uint16_t ipcp_id, std::string p_name, std::string p_value);
    int ipcp_register(std::string ipcp_name, std::string dif_name);

  };
}







#endif
