#include "dialog.h"
#include "ui_dialog.h"
#include "widget.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{"
                                    "border-image:url(://img/退出.png);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "border-image:url(://img/退出按下.png);"
                                    "}");
    ui->pushButton_2->setStyleSheet("QPushButton{"
                                    "border-image:url(://img/继续.png);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "border-image:url(://img/继续按下.png);"
                                    "}");
}




Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_released()
{

    emit this->jixu();
    this->hide();

}

void Dialog::on_pushButton_released()
{

    emit this->tuichu();
    this->hide();


}
void Dialog::loseshow(){
    ui->label->setStyleSheet("QLabel{"
                       "border-image:url(://img/lose.png);"
                       "}");

}
void Dialog::winshow(){
    ui->label->setStyleSheet("QLabel{"
                       "border-image:url(://img/win.png);"
                       "}");


}


