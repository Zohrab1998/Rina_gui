#ifndef INTERFACER_H
#define INTERFACER_H

#include <QItemSelectionModel>
#include <QFile>
#include <QString>


static QString nameOfAddress;
static QStringList nameOfAddressList;
static QString addOfAddress;
static QStringList addOfAddressList;
static QStringList nameOfIPCP;
static QStringList nameOfAllIPCP;
static QStringList nameOfAllethIPCP;
static QStringList nameOfAllDIF;
static QStringList nameOfDIF;
extern QString idOfConfing;

class interfacer
{
public:
    interfacer();
    void interface();
};

#endif // INTERFACER_H
