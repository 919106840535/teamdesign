#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{"
                                    "border-image:url(://img/退出.png);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "border-image:url(://img/退出按下.png);"
                                    "}");
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    start * win = new start;
    win->setFixedSize(win->width(), win->height());
    this->close();
    win->show();
}
