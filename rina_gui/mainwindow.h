#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "add.h"
#include "tablemodel.h"
#include "flowshow.h"
#include "configure.h"
#include "monitoring.h"
#include <QCloseEvent>
#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <QStringListModel>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals :
    void insertData1(const QString &,const QString&, const QString&, const QString&, const QString&, const QString&, const QString&);
    void deleteData(int row, QModelIndex parent);
    void flowData(int count, QStringList difdata);
    void checked(bool check);
    void comboBoxNames(const QStringList& NameOfIPCP);

private slots:
    void on_pushButton_clicked();
    void processOneThing();
    void deleteTableViewData(int row, QModelIndex parent);
    void on_pushButton_reset_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_flowShow_clicked();
    void on_pushButton_configure_clicked();
    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_monitoring_clicked();

private:

    QString nameIpcp1;
    QString nameDif1;
    QString shimNameIpcp1;
    QString shimNameDif1;
    QString id1;
    QString address1;
    QString enrollment1;

    Ui::MainWindow *ui;
    Add*add;
    tablemodel*model;
    flowShow*fs;
    Configure*conf;
    Monitoring*monitoring;
};
#endif // MAINWINDOW_H
