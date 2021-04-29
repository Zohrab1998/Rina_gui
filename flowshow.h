#ifndef FLOWSHOW_H
#define FLOWSHOW_H

#include <QMainWindow>
#include "network/flowstat.hpp"

namespace Ui {
class flowShow;
}

class flowShow : public QMainWindow
{
    Q_OBJECT

public:
    explicit flowShow(QWidget *parent = nullptr);
    ~flowShow();
private:
    Ui::flowShow *ui;
};

#endif // FLOWSHOW_H
