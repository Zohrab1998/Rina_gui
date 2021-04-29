#include "add.h"
#include "ui_add.h"
#include "interfacer.h"
#include "tablemodel.h"
#include <qstandarditemmodel.h>
#include <QComboBox>
#include <QDebug>

#include "network/netconf.hpp"
#include "interfacer.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/if_link.h>
#include <QDebug>
#include <QProcess>
#include <QCheckBox>
#include<QMessageBox>
using namespace rina_network;



Add::Add(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    afa->interface();
    ui->comboBox_Id->addItems(nameOfAddressList);
    ui->comboBox_Address->addItems(addOfAddressList);
    addOfAddressList.clear();
    nameOfAddressList.clear();
    while(ui->comboBox_Id->currentIndex() != ui->comboBox_Address->currentIndex())
    {
        int curId= ui->comboBox_Id->currentIndex();
        ui->comboBox_Address->setCurrentIndex(curId);
    }
    ui->comboBox_enrollment->addItems(nameOfAllDIF);

    qDebug()<<nameOfIPCP;
    
}

Add::~Add()
{
    delete ui;
}

void Add::on_pushButton_close_clicked()
{

    close();
}

void Add::on_pushButton_Create_clicked()
{

    Netconf netconf;
    string ipcpName = ui->lineEdit_IpcpName->text().toUtf8().constData();
    string difName = ui->lineEdit_DifName->text().toUtf8().constData();
    string difType = ui->comboBox_difType->currentData(Qt::DisplayRole).toString().toUtf8().constData();
    netconf.ipcp_create(ipcpName,difType,difName);
    ui->pushButton_close->clicked();

}

interfacer::interfacer()
{
}

void Add::interface()
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

freeifaddrs(ifaddr);

}


void Add::on_comboBox_Id_activated(const QString &arg1)
{
    if(ui->comboBox_Id->currentIndex() != ui->comboBox_Address->currentIndex())
    {
        ui->comboBox_Address->setCurrentIndex(ui->comboBox_Id->currentIndex());
    }

}


void Add::on_comboBox_Address_activated(const QString &arg1)
{
    if(ui->comboBox_Address->currentIndex() != ui->comboBox_Id->currentIndex())
    {
        ui->comboBox_Id->setCurrentIndex(ui->comboBox_Address->currentIndex());
    }
}



void Add::comboBoxNamesSlot(const QStringList &arg1){

}

void Add::aButtonClicked(bool checked)
{
    if(checked){

        nameOfIPCP.clear();
        checked = false;
    }
}


void Add::on_lineEdit_IpcpName_textChanged(const QString &arg1)
{
    QString name = ui->lineEdit_IpcpName->text();
    int posofdot = 5;
    QString nameAfterDot = name.right(posofdot);
    if(nameAfterDot == ".IPCP"){
        ui->checkBox_nameIPCP->setChecked(true);
        ui->checkBox_nameIPCP->setStyleSheet("QCheckBox{ background-color = green}");
    }
    else
    {
        ui->checkBox_nameIPCP->setChecked(false);
    }
}

void Add::on_lineEdit_DifName_textChanged(const QString &arg1)
{
    QString name = ui->lineEdit_DifName->text();
    int posofdot = 4;
    QString nameAfterDot = name.right(posofdot);
    if(nameAfterDot == ".DIF"){
        ui->checkBox_DIFName->setChecked(true);
        ui->checkBox_DIFName->setStyleSheet("QCheckBox{ background-color = green}");
    }
    else
    {
        ui->checkBox_DIFName->setChecked(false);
    }
}




void Add::on_comboBox_enroller_currentIndexChanged(const QString &arg1)
{
    QString DifChange = ui->comboBox_enroller->currentText();
    int space = DifChange.lastIndexOf(QChar(' '));
    QString DifChanged = DifChange.right(space-1);
    ui->lineEdit_DifName->setText(DifChanged);
}




void Add::on_pushButton_register_clicked()
{
    Netconf netconf;
    string ipcpName = ui->lineEdit_IpcpName->text().toUtf8().constData();
    string difName = ui->lineEdit_DifName->text().toUtf8().constData();
    netconf.ipcp_register(ipcpName,difName);
}

void Add::on_comboBox_enrollment_activated(const QString &arg1)
{
    if(ui->comboBox_enrollment->currentText() == "enroll-enable"){
        ui->comboBox_enroller->setEnabled(false);
    }
    else if(ui->comboBox_enrollment->currentText() == "enroller"){
        ui->comboBox_enroller->setEnabled(true);
    }
}
