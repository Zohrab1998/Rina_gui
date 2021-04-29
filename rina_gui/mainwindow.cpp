#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add.h"
#include "flowshow.h"
#include "tablemodel.h"
#include "interfacer.h"
#include "network/netconf.hpp"
#include "network/ipcptable.hpp"
#include "configure.h"
#include <QItemSelectionModel>
#include <QFile>
#include <QTableView>
#include <QTextStream>
#include <QFile>
#include <QStandardItem>
#include <QFileDialog>
#include <QDebug>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<QStringListModel>
#include <QTimer>
using namespace std;
using namespace rina_network;

QString idOfConfing;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model=new tablemodel;
    ui->tableView->setModel(model);

    ui->pushButton_configure->setEnabled(false);

add=new Add(this);

Ipcpinfo info;
info.update();
struct ipcp_attrs *ipcps = info.getTable();
       for(int i = 0; i< info.getRowsN();i++){
           unsigned int id = ipcps[i].id;
           QString name = QString(ipcps[i].name);
           QString dif_type = QString(ipcps[i].dif_type);
           QString dif_name = QString(ipcps[i].dif_name);
           QString address = QString::number(ipcps[i].addr);
           unsigned int  txhdroom = ipcps[i].txhdroom;
           unsigned int rxhdroom= ipcps[i].rxhdroom;
           unsigned int troom = ipcps[i].tailroom;
           unsigned int mss = ipcps[i].max_sdu_size;
           model->addDataAuto(id,name,dif_type,dif_name,address,txhdroom,rxhdroom,troom,mss);
           QTimer *timer = new QTimer(this); connect(timer, SIGNAL(timeout()), this, SLOT(processOneThing())); timer->start(10000);
           }
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    add=new Add(this);
    system("sudo modprobe rlite");
    system("sudo modprobe rlite-normal");
    system("sudo modprobe rlite-shim-eth");
    system("sudo rlite-uipcps -d");

    add->show();
}

void MainWindow::deleteTableViewData(int row, QModelIndex parent){

    model->deleteData(row, parent);

}


void MainWindow::on_pushButton_reset_clicked()
{
    system("sudo rlite-ctl reset");
    system("rm save.csv");
    model=new tablemodel;
    ui->tableView->setModel(model);
    bool check = true;
    emit checked(check);

}
void MainWindow::on_pushButton_delete_clicked()
{
    int currentRow =ui->tableView->currentIndex().row();
    Netconf netconf;
    netconf.ipcp_destroy(currentRow,0);
    processOneThing();
}


void MainWindow::on_pushButton_flowShow_clicked()
{
    fs = new flowShow(this);
    int currentRow=ui->tableView->currentIndex().row();
    fs->show();

}
void MainWindow::processOneThing()
{
    model=new tablemodel;
    ui->tableView->setModel(model);
    Ipcpinfo info;
    info.update();
    struct ipcp_attrs *ipcps = info.getTable();
    qDebug()<<info.getRowsN();
    for(int i = 0; i< info.getRowsN();i++){
    unsigned int id = ipcps[i].id;
    QString name = QString(ipcps[i].name);
    QString dif_type = QString(ipcps[i].dif_type);
    QString dif_name = QString(ipcps[i].dif_name);
    QString address = QString::number(ipcps[i].addr);
    unsigned int  txhdroom = ipcps[i].txhdroom;
    unsigned int rxhdroom= ipcps[i].rxhdroom;
    unsigned int troom = ipcps[i].tailroom;
    unsigned int mss = ipcps[i].max_sdu_size;
      model->addDataAuto(id,name,dif_type,dif_name,address,txhdroom,rxhdroom,troom,mss);
}
}

void MainWindow::on_pushButton_configure_clicked()
{
    conf = new Configure(this);
    conf->show();
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    const QModelIndex &selected= ui->tableView->selectionModel()->currentIndex();
    QVariant value = selected.sibling(selected.row(),2).data();
    QVariant id = selected.sibling(selected.row(),0).data();
    idOfConfing = id.toString();
    qDebug()<<idOfConfing;
    if(value == "shim-eth"){
        ui->pushButton_configure->setEnabled(true);
    }
        else if (value == "normal") {
        ui->pushButton_configure->setEnabled(false);
        }

}

void MainWindow::on_pushButton_monitoring_clicked()
{
    monitoring = new Monitoring(this);
    monitoring->show();
}
