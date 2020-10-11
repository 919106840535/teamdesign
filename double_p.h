#ifndef DOUBLE_P_H
#define DOUBLE_P_H

#include <QWidget>
#include "game.h"
#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
#include <QLabel>

namespace Ui {
class double_p;
}

class double_p : public QWidget
{
    Q_OBJECT

public:
     Game game1;
     Game game2;
    explicit double_p(QWidget *parent = 0);
    ~double_p();
     void SHOW1();
     void SHOW2();

private slots:
    void on_pushButton_clicked();

private:
    void keyPressEvent(QKeyEvent *event);
    Ui::double_p *ui;
};

#endif // DOUBLE_P_H
