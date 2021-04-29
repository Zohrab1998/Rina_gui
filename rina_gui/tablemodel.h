#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QAbstractTableModel>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
using namespace std;


struct Structure {
  unsigned int  id;
  QString name;
  QString dif_type;
  QString dif_name;
  QString addr;
  unsigned int  txhdroom;
  unsigned int  rxhdroom;
  unsigned int tailroom;
  unsigned int max_sdu_size;
};


class tablemodel: public QAbstractTableModel
{
public:
    tablemodel(QObject*parent=nullptr);
    void addDataAuto(const unsigned int  &,const QString &,const QString &,const QString &,const QString &,const unsigned int &,const unsigned int &,const unsigned int &,const unsigned int &);
    void deleteData(int, QModelIndex);
    int rowCount(const QModelIndex& parent=QModelIndex())const override;
    int columnCount(const QModelIndex& parent=QModelIndex())const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section,Qt::Orientation orientation,int role)const override;
    void insertData(const QString &,const QString&, const QString&, const QString&, const QString&, const QString&, const QString&);
    string rctl_exec(const char*);


private:
    QVector<Structure> ipcp_attrs_struct;
    QVector<int> indexData;
};

#endif // TABLEMODEL_H
