#ifndef START_H
#define START_H

#include <QWidget>
#include "widget.h"
#include <QPushButton>
#include "help.h"
#include "double_p.h"

namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private slots:
    void on_pushbutton_single_clicked();

    void on_pushButton_help_clicked();

    void on_pushButton_double_clicked();

private:
    Ui::start *ui;
};

#endif // START_H
