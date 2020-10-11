#include "double_p.h"
#include "ui_double_p.h"
#include "start.h"
#include "game.h"
#include <QKeyEvent>
#include <QString>
#include <QDebug>

double_p::double_p(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::double_p)
{
    ui->setupUi(this);
    this->setFocus();
    game1.Restart_p1();
    game2.Restart_p2();
    this->SHOW1();
    this->SHOW2();
    QGraphicsView *g1= ui->graphicsView1;
    g1->setStyleSheet("border-image:url(://img/双人背景.png)");
    ui->pushButton->setStyleSheet("QPushButton{"
                                    "border-image:url(://img/返回.png);"
                                    "}"
                                    "QPushButton:pressed{"
                                    "border-image:url(://img/返回按下.png);"
                                    "}");

}
void double_p::SHOW1()
{
    //通过改变不同位置的样式表来显示不同的数字
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            int x=i*4+j;
            QGraphicsView *p=nullptr;
            //选择指针指向位置（第几行第几列）
            switch (x) {
            case 0: p=ui->graphicsView_p11;break;
            case 1: p=ui->graphicsView_p12;break;
            case 2: p=ui->graphicsView_p13;break;
            case 3: p=ui->graphicsView_p14;break;
            case 4: p=ui->graphicsView_p15;break;
            case 5: p=ui->graphicsView_p16;break;
            case 6: p=ui->graphicsView_p17;break;
            case 7: p=ui->graphicsView_p18;break;
            case 8: p=ui->graphicsView_p19;break;
            case 9: p=ui->graphicsView_p110;break;
            case 10: p=ui->graphicsView_p111;break;
            case 11: p=ui->graphicsView_p112;break;
            case 12: p=ui->graphicsView_p113;break;
            case 13: p=ui->graphicsView_p114;break;
            case 14: p=ui->graphicsView_p115;break;
            case 15: p=ui->graphicsView_p116;break;
            default:break;
            }
            //选择显示的数据
            switch(game1.BoardList_p1[i][j])
            {
            case 0:p->setStyleSheet("border-image:url(:/img/0.png)");break;
            case 2:p->setStyleSheet("border-image:url(:/img/2.png)");break;
            case 4:p->setStyleSheet("border-image:url(:/img/4.png)");break;
            case 8:p->setStyleSheet("border-image:url(:/img/8.png)");break;
            case 16:p->setStyleSheet("border-image:url(:/img/16.png)");break;
            case 32:p->setStyleSheet("border-image:url(:/img/32.png)");break;
            case 64:p->setStyleSheet("border-image:url(:/img/64.png)");break;
            case 128:p->setStyleSheet("border-image:url(:/img/128.png)");break;
            case 256:p->setStyleSheet("border-image:url(:/img/256.png)");break;
            case 512:p->setStyleSheet("border-image:url(:/img/512.png)");break;
            case 1024:p->setStyleSheet("border-image:url(:/img/1024.png)");break;
            case 2048:p->setStyleSheet("border-image:url(:/img/2048.png)");break;
            default:break;

            }
        }
    }

}
void double_p::SHOW2()
{
    //通过改变不同位置的样式表来显示不同的数字
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            int x=i*4+j;
            QGraphicsView *p=nullptr;
            //选择指针指向位置（第几行第几列）
            switch (x) {
            case 0: p=ui->graphicsView_p21;break;
            case 1: p=ui->graphicsView_p22;break;
            case 2: p=ui->graphicsView_p23;break;
            case 3: p=ui->graphicsView_p24;break;
            case 4: p=ui->graphicsView_p25;break;
            case 5: p=ui->graphicsView_p26;break;
            case 6: p=ui->graphicsView_p27;break;
            case 7: p=ui->graphicsView_p28;break;
            case 8: p=ui->graphicsView_p29;break;
            case 9: p=ui->graphicsView_p210;break;
            case 10: p=ui->graphicsView_p211;break;
            case 11: p=ui->graphicsView_p212;break;
            case 12: p=ui->graphicsView_p213;break;
            case 13: p=ui->graphicsView_p214;break;
            case 14: p=ui->graphicsView_p215;break;
            case 15: p=ui->graphicsView_p216;break;
            default:break;
            }
            //选择显示的数据
            switch(game2.BoardList_p2[i][j])
            {
            case 0:p->setStyleSheet("border-image:url(:/img/0.png)");break;
            case 2:p->setStyleSheet("border-image:url(:/img/2.png)");break;
            case 4:p->setStyleSheet("border-image:url(:/img/4.png)");break;
            case 8:p->setStyleSheet("border-image:url(:/img/8.png)");break;
            case 16:p->setStyleSheet("border-image:url(:/img/16.png)");break;
            case 32:p->setStyleSheet("border-image:url(:/img/32.png)");break;
            case 64:p->setStyleSheet("border-image:url(:/img/64.png)");break;
            case 128:p->setStyleSheet("border-image:url(:/img/128.png)");break;
            case 256:p->setStyleSheet("border-image:url(:/img/256.png)");break;
            case 512:p->setStyleSheet("border-image:url(:/img/512.png)");break;
            case 1024:p->setStyleSheet("border-image:url(:/img/1024.png)");break;
            case 2048:p->setStyleSheet("border-image:url(:/img/2048.png)");break;
            default:break;

            }
        }
    }

}
void double_p::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_W)
    {
        game1.Up_p1();
        this->SHOW1();
    }
    if(event->key()==Qt::Key_A)
    {
        game1.Left_p1();
        this->SHOW1();
    }
    if(event->key()==Qt::Key_D)
    {
        game1.Right_p1();
        this->SHOW1();
    }
    if(event->key()==Qt::Key_S)
    {
        game1.Down_p1();
        this->SHOW1();

    }
    if(event->key()==Qt::Key_Up)
    {
        game2.Up_p2();
        this->SHOW2();
    }
    if(event->key()==Qt::Key_Left)
    {
        game2.Left_p2();
        this->SHOW2();
    }
    if(event->key()==Qt::Key_Right)
    {
        game2.Right_p2();
        this->SHOW2();
    }
    if(event->key()==Qt::Key_Down)
    {
        game2.Down_p2();
        this->SHOW2();

    }
    if(game1.WIN_p1()||game2.WIN_p2()){
        //弹出一个对话框：
        if (game1.WIN_p1()){
            Dialog1 * win = new Dialog1;
            win->setFixedSize(win->width(), win->height());
            win->setModal(true);
            this->close();
            win->show();
        }
        if (game2.WIN_p2()){
            Dialog2 * win = new Dialog2;
            win->setFixedSize(win->width(), win->height());
            win->setModal(true);
            this->close();
            win->show();
        }
    }
    if(game1.LOSE_p1()&&game2.LOSE_p2()){
        //比较分数 判断输赢：
        if (game1.Scroe_p1 >game2.Scroe_p2){
            Dialog1 * win = new Dialog1;
            win->setFixedSize(win->width(), win->height());
            win->setModal(true);
            this->close();
            win->show();
        }
        else if (game1.Scroe_p1 < game2.Scroe_p2){
            Dialog2 * win = new Dialog2;
            win->setFixedSize(win->width(), win->height());
            win->setModal(true);
            this->close();
            win->show();
        }else if (game1.Scroe_p1 == game2.Scroe_p2){
            Dialog3 * win = new Dialog3;
            win->setFixedSize(win->width(), win->height());
            win->setModal(true);
            this->close();
            win->show();
        }
    }
}

double_p::~double_p()
{
    delete ui;
}

void double_p::on_pushButton_clicked()
{
    this->hide();
    start *win = new start;
    win->setWindowTitle("2048小游戏");
    win->show();

}
