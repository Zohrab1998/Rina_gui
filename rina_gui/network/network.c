    // standard headers
#include <stdio.h>
#include <inttypes.h>
#include <rina/api.h>

// project headers
#include "network.h"


// [RINA OPEN]
int r_open(){

  int fd = rina_open();

  if (fd < 0){
    perror("");
  }

  return fd;
}

// [RINA_REGISTER]
int r_register(int open_fd, const char *app_name){

  int fd = rina_register(open_fd, NULL, app_name, 0);

  return fd;
}

// [RINA_UNREGISTER]
int r_unregister(int open_fd, char *app_name){

  int fd = rina_unregister(open_fd, NULL, app_name, 0);

  return fd;
}

// [RINA_ACCEPT]
int r_accept(int open_fd, char **new_remote_name){

  int fd = rina_flow_accept(open_fd, new_remote_name, NULL, RINA_F_NORESP);

  return fd;
}

// [RINA_RESPOND]
int r_respond(int open_fd, int accept_fd)
{
  int fd = rina_flow_respond(open_fd, accept_fd, 0);

  return fd;
}

// [RINA_FLOW_ALLOC]
int r_flow_alloc(const char *my_name, const char *server_name)
{
  int fd = rina_flow_alloc(NULL, my_name, server_name, NULL, 0);

  return fd;
}
