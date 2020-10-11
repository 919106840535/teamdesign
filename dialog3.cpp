#include "dialog3.h"
#include "ui_dialog3.h"

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{"
                                    "border-image:url(://img/退出.png);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "border-image:url(://img/退出按下.png);"
                                    "}");
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::on_pushButton_clicked()
{
    start * win = new start;
    win->setFixedSize(win->width(), win->height());
    this->close();
    win->show();
}
