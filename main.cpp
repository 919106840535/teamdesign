#include "start.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    start w;
    w.setWindowTitle("2048小游戏");
    w.setFixedSize(w.width(),w.height());
    w.show();

    return a.exec();
}
