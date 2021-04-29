#ifndef NETWORK_H
#define NETWORK_H

// [RINA OPEN]
int r_open();

// [RINA_REGISTER]
int r_register(int open_fd, const char *app_name);

// [RINA_UNREGISTER]
int r_unregister(int open_fd, char *app_name);

// [RINA_ACCEPT]
int r_accept(int open_fd, char **new_remote_name);

// [RINA_RESPOND]
int r_respond(int open_fd, int accept_fd);

// [RINA_FLOW_ALLOC]
int r_flow_alloc(const char *my_name, const char *server_name);



#endif // NETWORK_H
