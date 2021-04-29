#include "configure.h"
#include "ui_configure.h"
#include "interfacer.h"
#include "network/netconf.hpp"

#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <QDebug>
using namespace rina_network;

Configure::Configure(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Configure)
{
    ui->setupUi(this);
    interface();

}

void Configure::interface()
{

    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char host[NI_MAXHOST];


    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++)
    {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET && ifa->ifa_name != "lo") {
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }
            printf("%s \t\t address: <%s>\n", ifa->ifa_name, host);

            nameOfAddress = ifa->ifa_name;
            nameOfAddressList << nameOfAddress;

            addOfAddress = host;
            addOfAddressList << addOfAddress;


        }

    }


    ui->comboBox_Id->addItems(nameOfAddressList);

freeifaddrs(ifaddr);

}
Configure::~Configure()
{
    delete ui;
}

void Configure::on_pushButton_configure_clicked()
{
    Netconf netconf;
    netconf.ipcp_config(idOfConfing.toUInt(),ui->comboBox_Id->currentData(Qt::DisplayRole).toString().toUtf8().constData(),"netdev");
}

