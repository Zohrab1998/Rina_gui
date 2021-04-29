#ifndef ADD_H
#define ADD_H

#include <QMainWindow>
#include "tablemodel.h"
#include "interfacer.h"
#include <QProcess>

namespace Ui {
class Add;
}

class Add : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();


private slots:
   void on_pushButton_close_clicked();
   void on_pushButton_Create_clicked();
   void interface();
   void on_comboBox_Id_activated(const QString &arg1);
   void on_comboBox_Address_activated(const QString &arg1);
   void comboBoxNamesSlot(const QStringList &arg1);
   void aButtonClicked(bool checked);
   void on_lineEdit_IpcpName_textChanged(const QString &arg1);
   void on_lineEdit_DifName_textChanged(const QString &arg1);
   void on_comboBox_enroller_currentIndexChanged(const QString &arg1);
   void on_pushButton_register_clicked();

   void on_comboBox_enrollment_activated(const QString &arg1);

private:
    Ui::Add *ui;
    QString nameIpcp;
    QString nameDif;
    QString shimNameIpcp;
    QString shimNameDif;
    QString id;
    QString address;
    QString enrollment;

    Add*afa;
    interfacer*intfa;
    tablemodel*model;

signals :
    void insertData(const QString &,const QString&, const QString&, const QString&, const QString&, const QString&, const QString&);

};

#endif // ADD_H
