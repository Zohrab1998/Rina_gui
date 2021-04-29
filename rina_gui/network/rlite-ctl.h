#ifndef RLITE_CTL_H
#define RLITE_CTL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <assert.h>
#include <sys/ioctl.h>
#include <poll.h>

#include "rlite/list.h"
#include "rlite/uipcps-msg.h"
#include "rlite/conf.h"
#include "rlite/uipcps-helpers.h"
#include "rlite/version.h"

#define TO_DFLT_MSECS 10000

static void * malloc_or_quit(size_t size);
static void * strdup_or_quit(const char *s);
static struct ipcp_attrs * lookup_ipcp_by_name(const char *name);
typedef int (*response_handler_t)(struct rl_msg_base_resp *);
static struct ipcp_attrs *ipcp_by_dif(const char *dif_name);
static struct ipcp_attrs *select_ipcp();
static int uipcps_connect(void);
static int uipcps_disconnect(int sfd);
static int read_response(int sfd, response_handler_t handler, unsigned to_msecs);
static int request_response(struct rl_msg_base *req, response_handler_t handler, unsigned to_msecs);
static char *byteprint(char *buf, size_t len, uint64_t bytes);
static int ipcp_create(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_destroy(int argc, char **argv, struct cmd_descriptor *cd);
static int reset(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_config(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_config_get(int argc, char **argv, struct cmd_descriptor *cd);
static int str_count_elems(const char *s);
static int kernel_control_write(struct rl_msg_base *msg);
static int ipcp_sched_config(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_register_common(int argc, char **argv, unsigned int reg, struct cmd_descriptor *cd);
static int ipcp_register(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_unregister(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_enroll_common(int argc, char **argv, rl_msg_t msg_type);
static int ipcp_enroll(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_lower_flow_alloc(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_enroll_retry(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcps_show(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_stats(int argc, char **argv, struct cmd_descriptor *cd);
static int flows_show(int argc, char **argv, struct cmd_descriptor *cd);
static int flow_dump(int argc, char **argv, struct cmd_descriptor *cd);
static int regs_show(int argc, char **argv, struct cmd_descriptor *cd);
static char * component_name_wrap(const char *name);
static int ipcp_policy_mod(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_policy_param_mod(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_enroller_mod(int argc, char **argv, struct cmd_descriptor *cd, int enable);
static int ipcp_enroller_enable(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_enroller_disable(int argc, char **argv, struct cmd_descriptor *cd);
static int probe(int argc, char **argv, struct cmd_descriptor *cd);
static int terminate(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_neigh_disconnect(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_route_mod(int argc, char **argv, struct cmd_descriptor *cd);
#ifdef RL_MEMTRACK
static int memtrack_dump(int argc, char **argv, struct cmd_descriptor *cd);
#endif
static int ipcp_rib_show_handler(struct rl_msg_base_resp *b_resp);
static int ipcp_rib_show(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_policy_list(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcp_policy_param_list(int argc, char **argv, struct cmd_descriptor *cd);
static int ipcps_load();
static void sigint_handler(int signum);


#ifdef __cplusplus
}
#endif


#endif // RLITE_CTL_H
