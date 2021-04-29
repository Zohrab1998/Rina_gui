#include "flowshow.h"
#include "ui_flowshow.h"
#include"interfacer.h"
#include "network/flowstat.hpp"
#include<QProcess>
#include<QDebug>
#include <QString>
flowShow::flowShow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::flowShow)
{
    ui->setupUi(this);
    rl_flow_stats rl_flow_stats;
    int rx_pkt = rl_flow_stats.rx_pkt;
    QString rx_pktstring = QString::number(rx_pkt);
    ui->lineEdit_RxPkt->setText(rx_pktstring);
    int tx_pkt = rl_flow_stats.tx_pkt;
    QString tx_pktstring = QString::number(tx_pkt);
    ui->lineEdit_TxPkt->setText(tx_pktstring);
    int rx_Byte = rl_flow_stats.rx_byte;
    QString rx_Bytestring = QString::number(rx_Byte);
    ui->lineEdit_RxByte->setText(rx_Bytestring);
    int tx_Byte = rl_flow_stats.tx_byte;
    QString tx_Bytestring = QString::number(tx_Byte);
    ui->lineEdit_TxByte->setText(tx_Bytestring);
    int rtx_pkt = rl_flow_stats.rx_overrun_pkt;
    QString Rtx_pktstring = QString::number(rtx_pkt);
    ui->lineEdit_RtxPkt->setText(Rtx_pktstring);
    int rtx_Byte = rl_flow_stats.rx_overrun_byte;
    QString Rtx_Bytestring = QString::number(rtx_Byte);
    ui->lineEdit_RtxByte->setText(Rtx_Bytestring);
}

flowShow::~flowShow()
{
    delete ui;
}
