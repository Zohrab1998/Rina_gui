#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QMainWindow>
#include"interfacer.h"


namespace Ui {
class Configure;
}

class Configure : public QMainWindow
{
    Q_OBJECT

public:
    explicit Configure(QWidget *parent = nullptr);
    ~Configure();
private slots:
    void interface();

    void on_pushButton_configure_clicked();

private:
    Ui::Configure *ui;
};

#endif // CONFIGURE_H
