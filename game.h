#ifndef GAME_H
#define GAME_H
class Game
{
public:
    int Scroe = 0;//初始分数
    int Scroe_p1 = 0;
    int Scroe_p2 = 0;
    bool ADD = false;
    bool ADD_p2 = false;
    bool ADD_p1 = false;//是否添加棋子
    int BoardList[4][4] = {};
    int BoardList_p1[4][4]={};
    int BoardList_p2[4][4]={};
    Game();// 构造函数， 初始化一些参数
    bool AddBoard();//添加棋子
    bool AddBoard_p1();
    bool AddBoard_p2();
    void Up();//上下左右按键事件，都类似，以左按键为母版
    void Down();
    void Right();
    void Left();
    void Restart();//复位
    void Restart_p1();
    void Restart_p2();
    bool WIN();//判断是否赢了
    bool WIN_p1();
    bool WIN_p2();
    bool LOSE();//判断是否输了
    bool LOSE_p1();
    bool LOSE_p2();
    void Up_p1();
    void Down_p1();
    void Right_p1();
    void Left_p1();
    void Up_p2();
    void Down_p2();
    void Right_p2();
    void Left_p2();

};


#endif // GAME_H
