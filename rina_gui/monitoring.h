#ifndef MONITORING_H
#define MONITORING_H

#include <QMainWindow>

namespace Ui {
class Monitoring;
}

class Monitoring : public QMainWindow
{
    Q_OBJECT

public:
    explicit Monitoring(QWidget *parent = nullptr);
    void tvm();
    void vmcu();
    void ram();
    ~Monitoring();

private:
    Ui::Monitoring *ui;
};

#endif // MONITORING_H
