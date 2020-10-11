#include "start.h"
#include "ui_start.h"
#include <QWidget>

start::start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::start)
{

    ui->setupUi(this);

    ui->pushbutton_single->setStyleSheet("QPushButton{"
                                    "border-image:url(://img/单人游戏.png);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "border-image:url(://img/单人游戏按下.png);"
                                    "}");
    ui->pushButton_double->setStyleSheet("QPushButton{"
                                    "border-image:url(://img/多人游戏.png);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "border-image:url(://img/多人游戏按下.png);"
                                    "}");
    ui->pushButton_help->setStyleSheet("QPushButton{"
                                    "border-image:url(://img/帮助.png);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "border-image:url(://img/帮助按下.png);"
                                    "}");
    ui->label_background->setStyleSheet("QLabel{border-image: url(://img/开始背景.png);}");
}

start::~start()
{
    delete ui;
}

void start::on_pushbutton_single_clicked()
{

    Widget * win = new Widget;
    this->hide();
    win->setWindowTitle("单人游戏");
    win->show();
}

void start::on_pushButton_help_clicked()
{
    static help * win = new help;
    win->setWindowTitle("帮助");

    win->show();
}

void start::on_pushButton_double_clicked()
{
    double_p * win = new double_p;
    win->setWindowTitle("双人游戏");
    this->hide();
    win->show();
}
