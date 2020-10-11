#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{"
                                    "border-image:url(://img/退出.png);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "border-image:url(://img/退出按下.png);"
                                    "}");
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_clicked()
{
    start * win = new start;
    win->setFixedSize(win->width(), win->height());
    this->close();
    win->show();
}
