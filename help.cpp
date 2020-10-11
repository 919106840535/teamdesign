#include "help.h"
#include "ui_help.h"
#include <QLabel>

help::help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);







}

help::~help()
{
    delete ui;
}
