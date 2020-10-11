#include "game.h"
#include <iomanip>
#include <conio.h>
#include <ctime>

Game::Game()
{

}
bool Game::LOSE()
{
    bool lose=true;
    //标志位
    //出现0，表示还未结束
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <4; j++)
        {

            if (this->BoardList[i][j] == 0)
            {
                lose = false;
                return false;
            }
        }
    }
    //横竖相邻元素相等未结束
    for (int i = 0; i < 4 - 1; i++)
    {
        for (int j = 0; j < 4 - 1; j++)
        {
            if (this->BoardList[i][j]== this->BoardList[i][j+1]&& this->BoardList[i][j]!=0)
            {
                return false;
            }
            if (this->BoardList[j][i]== this->BoardList[j+1][i]&& this->BoardList[j][i]!=0)
            {
                lose = false;
                return false;
            }
        }
    }
    if (lose)
    {
        return true;
    }
    return false;
}
bool Game::LOSE_p1()
{
    bool lose=true;
    //标志位
    //出现0，表示还未结束
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <4; j++)
        {

            if (this->BoardList_p1[i][j] == 0)
            {
                lose = false;
                return false;
            }
        }
    }
    //横竖相邻元素相等未结束
    for (int i = 0; i < 4 - 1; i++)
    {
        for (int j = 0; j < 4 - 1; j++)
        {
            if (this->BoardList_p1[i][j]== this->BoardList_p1[i][j+1]&& this->BoardList_p1[i][j]!=0)
            {
                return false;
            }
            if (this->BoardList_p1[j][i]== this->BoardList_p1[j+1][i]&& this->BoardList_p1[j][i]!=0)
            {
                lose = false;
                return false;
            }
        }
    }
    if (lose)
    {
        return true;
    }
    return false;
}
bool Game::LOSE_p2()
{
    bool lose=true;
    //标志位
    //出现0，表示还未结束
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <4; j++)
        {

            if (this->BoardList_p2[i][j] == 0)
            {
                lose = false;
                return false;
            }
        }
    }
    //横竖相邻元素相等未结束
    for (int i = 0; i < 4 - 1; i++)
    {
        for (int j = 0; j < 4 - 1; j++)
        {
            if (this->BoardList_p2[i][j]== this->BoardList_p2[i][j+1]&& this->BoardList_p2[i][j]!=0)
            {
                return false;
            }
            if (this->BoardList_p2[j][i]== this->BoardList_p2[j+1][i]&& this->BoardList_p2[j][i]!=0)
            {
                lose = false;
                return false;
            }
        }
    }
    if (lose)
    {
        return true;
    }
    return false;
}

bool Game::WIN()
{
    for (int i = 0; i <4; i++)
    {
        for (int j = 0; j <4; ++j)
        {
            //出现2048，即为赢
            if (this->BoardList[i][j]==2048)
            {
                return true;
            }

        }
    }
    return false;
}
bool Game::WIN_p1()
{
    for (int i = 0; i <4; i++)
    {
        for (int j = 0; j <4; ++j)
        {
            //出现2048，即为赢
            if (this->BoardList_p1[i][j]==2048)
            {
                return true;
            }

        }
    }
    return false;
}
bool Game::WIN_p2()
{
    for (int i = 0; i <4; i++)
    {
        for (int j = 0; j <4; ++j)
        {
            //出现2048，即为赢
            if (this->BoardList_p2[i][j]==2048)
            {
                return true;
            }

        }
    }
    return false;
}
bool Game::AddBoard()
{
    int choice[] = { 4, 4, 4, 2, 2, 2, 2, 2 };//可以调节2和4出现的频率
    //srand(time(0));
    //int temp = (rand() % int((sizeof(choice)/sizeof (choice[0]) - 0))) + 0;
    int temp = rand() % 8 ;
    int p1 = rand() % 4;
    int p2 = rand() % 4;
    while (this->BoardList[p1][p2] != 0)//位置已有数字，重新选取
    {
        p1 = rand() % 4;
        p2 = rand() % 4;
    }
    this->BoardList[p1][p2] = choice[temp];
    this->ADD = false;
    return true;
}
bool Game::AddBoard_p1()
{
    int choice[] = { 4, 4, 4, 2, 2, 2, 2, 2 };//可以调节2和4出现的频率
    int temp = rand() % 8 ;
    int p1 = rand() % 4;
    int p2 = rand() % 4;
    while (this->BoardList_p1[p1][p2] != 0)//位置已有数字，重新选取
    {
        p1 = rand() % 4;
        p2 = rand() % 4;
    }
    this->BoardList_p1[p1][p2] = choice[temp];
    this->ADD_p1 = false;
    return true;
}
bool Game::AddBoard_p2()
{
    int choice[] = { 4, 4, 4, 2, 2, 2, 2, 2 };//可以调节2和4出现的频率
    //srand(time(0));
    //int temp = (rand() % int((sizeof(choice)/sizeof (choice[0]) - 0))) + 0;
    int temp = rand() % 8 ;
    int p1 = rand() % 4;
    int p2 = rand() % 4;
    while (this->BoardList_p2[p1][p2] != 0)//位置已有数字，重新选取
    {
        p1 = rand() % 4;
        p2 = rand() % 4;
    }
    this->BoardList_p2[p1][p2] = choice[temp];
    this->ADD_p2 = false;
    return true;
}

void Game::Up()
{
    for (int i = 0; i <4; i++)
    {
        for (int t = 0; t <3; t++)
        {
            for (int j = 0; j <4 - 1; j++)
            {
                if (this->BoardList[j][i] == 0)
                {
                    if (this->BoardList[j + 1][i]!=0)
                    {
                        this->ADD = true;
                    }
                    int temp = this->BoardList[j][i];
                    this->BoardList[j][i] = this->BoardList[j + 1][i];
                    this->BoardList[j + 1][i] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int j = 0; j < 4 - 1; j++)
        {
            // 2 2 2 2 ->4 0 2 2 ->4 0 4 0
            // 2 2 2 0 -> 4 0 2 0
            if (this->BoardList[j][i] == this->BoardList[j + 1][i])
            {
                if (this->BoardList[j][i]!=0)
                {
                    this->ADD = true;
                }
                this->BoardList[j][i] = this->BoardList[j][i] * 2;
                this->Scroe = this->BoardList[j][i] + this->Scroe;
                this->BoardList[j + 1][i] = 0;
            }
        }
        //3、 再次移动0元素
        for (int t = 0; t < 4; t++)
        {
            for (int j = 0; j < 4 - 1; j++)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList[j][i] == 0)
                {
                    auto temp = this->BoardList[j][i];
                    this->BoardList[j][i] = this->BoardList[j + 1][i];
                    this->BoardList[j + 1][i] = temp;
                }
            }
        }
    }
    if (this->LOSE() || this->WIN())
    {}
    else
    {
        if (this->ADD)
        {

            this->AddBoard();
            this->ADD = false;
        }
    }
}

void Game::Down()
{
    for (int i = 0; i < 4; i++)
    {
        for (int t = 3; t>0; t--)
        {
            for (int j = 4 - 1; j >0; j--)
            {
                if (this->BoardList[j][i] == 0)
                {
                    if (this->BoardList[j - 1][i] != 0)
                    {
                        this->ADD = true;
                    }
                    int temp = this->BoardList[j][i];
                    this->BoardList[j][i] = this->BoardList[j - 1][i];
                    this->BoardList[j - 1][i] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int j =4 - 1; j>0; j--)
        {
            // 2 2 2 2 ->4 0 2 2 ->4 0 4 0
            // 2 2 2 0 -> 4 0 2 0
            if (this->BoardList[j][i] == this->BoardList[j - 1][i])
            {
                if (this->BoardList[j][i] != 0)
                {
                    this->ADD = true;
                }
                this->BoardList[j][i] = this->BoardList[j][i] * 2;
                this->Scroe = this->BoardList[j][i] + this->Scroe;
                this->BoardList[j - 1][i] = 0;
            }
        }
        //3、 再次移动0元素
        for (int t =4; t >0; t--)
        {
            for (int j =4 - 1; j >0; j--)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList[j][i] == 0)
                {
                    auto temp = this->BoardList[j][i];
                    this->BoardList[j][i] = this->BoardList[j - 1][i];
                    this->BoardList[j - 1][i] = temp;
                }
            }
        }
    }
    if (this->LOSE() || this->WIN())
    {}
    else
    {
        if (this->ADD)
        {

            this->AddBoard();
            this->ADD = false;
        }
    }
}

void Game::Left()
{
    for (int j= 0; j <4; j++)
    {
        //1、先移动每行0元素（出现0就交换）,最多交换size(this->BoardList)次
        for (int t = 0; t <3; t++)
        {
            for (int i = 0; i <4 - 1; i++)
            {
                // 0 2 0 2 -> 2 0 2 0//
                if (this->BoardList[j][i] == 0)
                {
                    // 发生了移动，添加棋子标志位置真
                    if (this->BoardList[j][i + 1]!=0)
                    {
                        this->ADD = true;
                    }
                    int temp = this->BoardList[j][i];
                    this->BoardList[j][i] = this->BoardList[j][i + 1];
                    this->BoardList[j][i + 1] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int i = 0; i <4 - 1; i++)
        {
            // 2 2 2 2 ->4 0 2 2 ->4 0 4 0
            // 2 2 2 0 -> 4 0 2 0
            if (this->BoardList[j][i]== this->BoardList[j][i+1])
            {
                // 发生了合并，添加棋子标志位置真
                if (this->BoardList[j][i]!=0)
                {
                    this->ADD = true;
                }
                this->BoardList[j][i] = this->BoardList[j][i] * 2;
                this->Scroe = this->BoardList[j][i] + this->Scroe;
                this->BoardList[j][i + 1] = 0;
            }
        }
        //3、 再次移动0元素 4 0 2 0 -> 4 2 0 0
        for (int t = 0; t < 4; t++)
        {
            for (int i = 0; i <4 - 1; i++)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList[j][i] == 0)
                {
                    auto temp = this->BoardList[j][i];
                    this->BoardList[j][i] = this->BoardList[j][i + 1];
                    this->BoardList[j][i + 1] = temp;
                }
            }
        }
    }
    //赢了或者输了就不再添加
    if (this->LOSE()||this->WIN())
    {}
    else
    {
        if (this->ADD)
        {

            this->AddBoard();
            this->ADD = false;
        }
    }
}

void Game::Right()
{
    for (int j = 0; j < 4; j++)
    {
        //1、先移动每行0元素
        for (int t = 3; t >0;t--)
        {
            for (int i =4 - 1; i>0; i--)
            {
                if (this->BoardList[j][i] == 0)
                {
                    if (this->BoardList[j][i - 1]!=0)
                    {
                        this->ADD = true;
                    }
                    int temp = this->BoardList[j][i];
                    this->BoardList[j][i] = this->BoardList[j][i - 1];
                    this->BoardList[j][i - 1] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int i =4 - 1; i >0; i--)
        {
            if (this->BoardList[j][i] == this->BoardList[j][i - 1])
            {
                if (this->BoardList[j][i] != 0)
                {
                    this->ADD = true;
                }
                this->BoardList[j][i] = this->BoardList[j][i] * 2;
                this->Scroe = this->BoardList[j][i] + this->Scroe;
                this->BoardList[j][i - 1] = 0;
            }
        }
        //3、 再次移动0元素
        for (int t =4; t > 0; t--)
        {
            for (int i = 4 - 1; i > 0; i--)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList[j][i] == 0)
                {
                    auto temp = this->BoardList[j][i];
                    this->BoardList[j][i] = this->BoardList[j][i - 1];
                    this->BoardList[j][i - 1] = temp;
                }
            }
        }
    }
    //赢了或者输了就不再添加
    if (this->LOSE() || this->WIN())
    {}
    else
    {
        if (this->ADD)
        {

            this->AddBoard();
            this->ADD = false;
        }
    }
}

void Game::Up_p1()
{
    for (int i = 0; i <4; i++)
    {
        for (int t = 0; t <3; t++)
        {
            for (int j = 0; j <4 - 1; j++)
            {
                if (this-> BoardList_p1[j][i] == 0)
                {
                    if (this-> BoardList_p1[j + 1][i]!=0)
                    {
                        this->ADD_p1 = true;
                    }
                    int temp = this-> BoardList_p1[j][i];
                    this-> BoardList_p1[j][i] = this-> BoardList_p1[j + 1][i];
                    this-> BoardList_p1[j + 1][i] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int j = 0; j < 4 - 1; j++)
        {
            // 2 2 2 2 ->4 0 2 2 ->4 0 4 0
            // 2 2 2 0 -> 4 0 2 0
            if (this->BoardList_p1[j][i] == this->BoardList_p1[j + 1][i])
            {
                if (this->BoardList_p1[j][i]!=0)
                {
                    this->ADD_p1 = true;
                }
                this->BoardList_p1[j][i] = this->BoardList_p1[j][i] * 2;
                this->Scroe_p1 = this->BoardList_p1[j][i] + this->Scroe_p1;
                this->BoardList_p1[j + 1][i] = 0;
            }
        }
        //3、 再次移动0元素
        for (int t = 0; t < 4; t++)
        {
            for (int j = 0; j < 4 - 1; j++)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList_p1[j][i] == 0)
                {
                    auto temp = this->BoardList_p1[j][i];
                    this->BoardList_p1[j][i] = this->BoardList_p1[j + 1][i];
                    this->BoardList_p1[j + 1][i] = temp;
                }
            }
        }
    }
    if (this->LOSE_p1() || this->WIN_p2())
    {}
    else
    {
        if (this->ADD_p1)
        {

            this->AddBoard_p1();
            this->ADD_p1 = false;
        }
    }
}

void Game::Down_p1()
{
    for (int i = 0; i < 4; i++)
    {
        for (int t = 3; t>0; t--)
        {
            for (int j = 4 - 1; j >0; j--)
            {
                if (this->BoardList_p1[j][i] == 0)
                {
                    if (this->BoardList_p1[j - 1][i] != 0)
                    {
                        this->ADD_p1 = true;
                    }
                    int temp = this->BoardList_p1[j][i];
                    this->BoardList_p1[j][i] = this->BoardList_p1[j - 1][i];
                    this->BoardList_p1[j - 1][i] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int j =4 - 1; j>0; j--)
        {
            // 2 2 2 2 ->4 0 2 2 ->4 0 4 0
            // 2 2 2 0 -> 4 0 2 0
            if (this->BoardList_p1[j][i] == this->BoardList_p1[j - 1][i])
            {
                if (this->BoardList_p1[j][i] != 0)
                {
                    this->ADD_p1 = true;
                }
                this->BoardList_p1[j][i] = this->BoardList_p1[j][i] * 2;
                this->Scroe_p1 = this->BoardList_p1[j][i] + this->Scroe_p1;
                this->BoardList_p1[j - 1][i] = 0;
            }
        }
        //3、 再次移动0元素
        for (int t =4; t >0; t--)
        {
            for (int j =4 - 1; j >0; j--)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList_p1[j][i] == 0)
                {
                    auto temp = this->BoardList_p1[j][i];
                    this->BoardList_p1[j][i] = this->BoardList_p1[j - 1][i];
                    this->BoardList_p1[j - 1][i] = temp;
                }
            }
        }
    }
    if (this->LOSE_p1() || this->WIN_p1())
    {}
    else
    {
        if (this->ADD_p1)
        {

            this->AddBoard_p1();
            this->ADD_p1 = false;
        }
    }
}

void Game::Left_p1()
{
    for (int j= 0; j <4; j++)
    {
        //1、先移动每行0元素（出现0就交换）,最多交换size(this->BoardList)次
        for (int t = 0; t <3; t++)
        {
            for (int i = 0; i <4 - 1; i++)
            {
                // 0 2 0 2 -> 2 0 2 0//
                if (this->BoardList_p1[j][i] == 0)
                {
                    // 发生了移动，添加棋子标志位置真
                    if (this->BoardList_p1[j][i + 1]!=0)
                    {
                        this->ADD_p1 = true;
                    }
                    int temp = this->BoardList_p1[j][i];
                    this->BoardList_p1[j][i] = this->BoardList_p1[j][i + 1];
                    this->BoardList_p1[j][i + 1] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int i = 0; i <4 - 1; i++)
        {
            // 2 2 2 2 ->4 0 2 2 ->4 0 4 0
            // 2 2 2 0 -> 4 0 2 0
            if (this->BoardList_p1[j][i]== this->BoardList_p1[j][i+1])
            {
                // 发生了合并，添加棋子标志位置真
                if (this->BoardList_p1[j][i]!=0)
                {
                    this->ADD_p1 = true;
                }
                this->BoardList_p1[j][i] = this->BoardList_p1[j][i] * 2;
                this->Scroe_p1 = this->BoardList_p1[j][i] + this->Scroe_p1;
                this->BoardList_p1[j][i + 1] = 0;
            }
        }
        //3、 再次移动0元素 4 0 2 0 -> 4 2 0 0
        for (int t = 0; t < 4; t++)
        {
            for (int i = 0; i <4 - 1; i++)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList_p1[j][i] == 0)
                {
                    auto temp = this->BoardList[j][i];
                    this->BoardList_p1[j][i] = this->BoardList_p1[j][i + 1];
                    this->BoardList_p1[j][i + 1] = temp;
                }
            }
        }
    }
    //赢了或者输了就不再添加
    if (this->LOSE_p1()||this->WIN_p1())
    {}
    else
    {
        if (this->ADD_p1)
        {

            this->AddBoard_p1();
            this->ADD_p1 = false;
        }
    }
}

void Game::Right_p1()
{
    for (int j = 0; j < 4; j++)
    {
        //1、先移动每行0元素
        for (int t = 3; t >0;t--)
        {
            for (int i =4 - 1; i>0; i--)
            {
                if (this->BoardList_p1[j][i] == 0)
                {
                    if (this->BoardList_p1[j][i - 1]!=0)
                    {
                        this->ADD_p1 = true;
                    }
                    int temp = this->BoardList_p1[j][i];
                    this->BoardList_p1[j][i] = this->BoardList_p1[j][i - 1];
                    this->BoardList_p1[j][i - 1] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int i =4 - 1; i >0; i--)
        {
            if (this->BoardList_p1[j][i] == this->BoardList_p1[j][i - 1])
            {
                if (this->BoardList_p1[j][i] != 0)
                {
                    this->ADD_p1 = true;
                }
                this->BoardList_p1[j][i] = this->BoardList_p1[j][i] * 2;
                this->Scroe_p1 = this->BoardList_p1[j][i] + this->Scroe_p1;
                this->BoardList_p1[j][i - 1] = 0;
            }
        }
        //3、 再次移动0元素
        for (int t =4; t > 0; t--)
        {
            for (int i = 4 - 1; i > 0; i--)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList_p1[j][i] == 0)
                {
                    auto temp = this->BoardList_p1[j][i];
                    this->BoardList_p1[j][i] = this->BoardList_p1[j][i - 1];
                    this->BoardList_p1[j][i - 1] = temp;
                }
            }
        }
    }
    //赢了或者输了就不再添加
    if (this->LOSE_p1() || this->WIN_p1())
    {}
    else
    {
        if (this->ADD_p1)
        {

            this->AddBoard_p1();
            this->ADD_p1 = false;
        }
    }
}
void Game::Up_p2()
{
    for (int i = 0; i <4; i++)
    {
        for (int t = 0; t <3; t++)
        {
            for (int j = 0; j <4 - 1; j++)
            {
                if (this->BoardList_p2[j][i] == 0)
                {
                    if (this->BoardList_p2[j + 1][i]!=0)
                    {
                        this->ADD_p2 = true;
                    }
                    int temp = this->BoardList_p2[j][i];
                    this->BoardList_p2[j][i] = this->BoardList_p2[j + 1][i];
                    this->BoardList_p2[j + 1][i] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int j = 0; j < 4 - 1; j++)
        {
            // 2 2 2 2 ->4 0 2 2 ->4 0 4 0
            // 2 2 2 0 -> 4 0 2 0
            if (this->BoardList_p2[j][i] == this->BoardList_p2[j + 1][i])
            {
                if (this->BoardList_p2[j][i]!=0)
                {
                    this->ADD_p2 = true;
                }
                this->BoardList_p2[j][i] = this->BoardList_p2[j][i] * 2;
                this->Scroe_p2 = this->BoardList_p2[j][i] + this->Scroe_p2;
                this->BoardList_p2[j + 1][i] = 0;
            }
        }
        //3、 再次移动0元素
        for (int t = 0; t < 4; t++)
        {
            for (int j = 0; j < 4 - 1; j++)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList_p2[j][i] == 0)
                {
                    auto temp = this->BoardList_p2[j][i];
                    this->BoardList_p2[j][i] = this->BoardList_p2[j + 1][i];
                    this->BoardList_p2[j + 1][i] = temp;
                }
            }
        }
    }
    if (this->LOSE_p2() || this->WIN_p2())
    {}
    else
    {
        if (this->ADD_p2)
        {

            this->AddBoard_p2();
            this->ADD_p2 = false;
        }
    }
}

void Game::Down_p2()
{
    for (int i = 0; i < 4; i++)
    {
        for (int t = 3; t>0; t--)
        {
            for (int j = 4 - 1; j >0; j--)
            {
                if (this->BoardList_p2[j][i] == 0)
                {
                    if (this->BoardList_p2[j - 1][i] != 0)
                    {
                        this->ADD_p2 = true;
                    }
                    int temp = this->BoardList_p2[j][i];
                    this->BoardList_p2[j][i] = this->BoardList_p2[j - 1][i];
                    this->BoardList_p2[j - 1][i] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int j =4 - 1; j>0; j--)
        {
            // 2 2 2 2 ->4 0 2 2 ->4 0 4 0
            // 2 2 2 0 -> 4 0 2 0
            if (this->BoardList_p2[j][i] == this->BoardList_p2[j - 1][i])
            {
                if (this->BoardList_p2[j][i] != 0)
                {
                    this->ADD_p2= true;
                }
                this->BoardList_p2[j][i] = this->BoardList_p2[j][i] * 2;
                this->Scroe_p2 = this->BoardList_p2[j][i] + this->Scroe_p2;
                this->BoardList_p2[j - 1][i] = 0;
            }
        }
        //3、 再次移动0元素
        for (int t =4; t >0; t--)
        {
            for (int j =4 - 1; j >0; j--)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList_p2[j][i] == 0)
                {
                    auto temp = this->BoardList_p2[j][i];
                    this->BoardList_p2[j][i] = this->BoardList_p2[j - 1][i];
                    this->BoardList_p2[j - 1][i] = temp;
                }
            }
        }
    }
    if (this->LOSE_p2() || this->WIN_p2())
    {}
    else
    {
        if (this->ADD_p2)
        {

            this->AddBoard_p2();
            this->ADD_p2 = false;
        }
    }
}

void Game::Left_p2()
{
    for (int j= 0; j <4; j++)
    {
        //1、先移动每行0元素（出现0就交换）,最多交换size(this->BoardList)次
        for (int t = 0; t <3; t++)
        {
            for (int i = 0; i <4 - 1; i++)
            {
                // 0 2 0 2 -> 2 0 2 0//
                if (this->BoardList_p2[j][i] == 0)
                {
                    // 发生了移动，添加棋子标志位置真
                    if (this->BoardList_p2[j][i + 1]!=0)
                    {
                        this->ADD_p2 = true;
                    }
                    int temp = this->BoardList_p2[j][i];
                    this->BoardList_p2[j][i] = this->BoardList_p2[j][i + 1];
                    this->BoardList_p2[j][i + 1] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int i = 0; i <4 - 1; i++)
        {
            // 2 2 2 2 ->4 0 2 2 ->4 0 4 0
            // 2 2 2 0 -> 4 0 2 0
            if (this->BoardList_p2[j][i]== this->BoardList_p2[j][i+1])
            {
                // 发生了合并，添加棋子标志位置真
                if (this->BoardList_p2[j][i]!=0)
                {
                    this->ADD_p2 = true;
                }
                this->BoardList_p2[j][i] = this->BoardList_p2[j][i] * 2;
                this->Scroe_p2 = this->BoardList_p2[j][i] + this->Scroe_p2;
                this->BoardList_p2[j][i + 1] = 0;
            }
        }
        //3、 再次移动0元素 4 0 2 0 -> 4 2 0 0
        for (int t = 0; t < 4; t++)
        {
            for (int i = 0; i <4 - 1; i++)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList_p2[j][i] == 0)
                {
                    auto temp = this->BoardList_p2[j][i];
                    this->BoardList_p2[j][i] = this->BoardList_p2[j][i + 1];
                    this->BoardList_p2[j][i + 1] = temp;
                }
            }
        }
    }
    //赢了或者输了就不再添加
    if (this->LOSE_p2()||this->WIN_p2())
    {}
    else
    {
        if (this->ADD_p2)
        {

            this->AddBoard_p2();
            this->ADD_p2 = false;
        }
    }
}

void Game::Right_p2()
{
    for (int j = 0; j < 4; j++)
    {
        //1、先移动每行0元素
        for (int t = 3; t >0;t--)
        {
            for (int i =4 - 1; i>0; i--)
            {
                if (this->BoardList_p2[j][i] == 0)
                {
                    if (this->BoardList_p2[j][i - 1]!=0)
                    {
                        this->ADD_p2 = true;
                    }
                    int temp = this->BoardList_p2[j][i];
                    this->BoardList_p2[j][i] = this->BoardList_p2[j][i - 1];
                    this->BoardList_p2[j][i - 1] = temp;
                }
            }
        }
        // 2、合并同类项
        for (int i =4 - 1; i >0; i--)
        {
            if (this->BoardList_p2[j][i] == this->BoardList_p2[j][i - 1])
            {
                if (this->BoardList_p2[j][i] != 0)
                {
                    this->ADD_p2 = true;
                }
                this->BoardList_p2[j][i] = this->BoardList_p2[j][i] * 2;
                this->Scroe_p2 = this->BoardList_p2[j][i] + this->Scroe_p2;
                this->BoardList_p2[j][i - 1] = 0;
            }
        }
        //3、 再次移动0元素
        for (int t =4; t > 0; t--)
        {
            for (int i = 4 - 1; i > 0; i--)
            {
                // 0 2 0 2 -> 2 2 0 0
                if (this->BoardList_p2[j][i] == 0)
                {
                    auto temp = this->BoardList_p2[j][i];
                    this->BoardList_p2[j][i] = this->BoardList_p2[j][i - 1];
                    this->BoardList_p2[j][i - 1] = temp;
                }
            }
        }
    }
    //赢了或者输了就不再添加
    if (this->LOSE_p2() || this->WIN_p2())
    {}
    else
    {
        if (this->ADD_p2)
        {

            this->AddBoard_p2();
            this->ADD_p2 = false;
        }
    }
}
void Game::Restart()
{
    this->Scroe = 0;//初始分数
    this->ADD = false;//是否添加棋子
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            this->BoardList[i][j] =0;
        }
    }
    this->AddBoard();
    this->AddBoard();
}
void Game::Restart_p1()
{
    this->Scroe_p1 = 0;//初始分数
    this->ADD_p1 = false;//是否添加棋子
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            this->BoardList_p1[i][j] =0;
        }
    }
    this->AddBoard_p1();
    this->AddBoard_p1();
}
void Game::Restart_p2()
{
    this->Scroe_p2 = 0;//初始分数
    this->ADD_p2 = false;//是否添加棋子
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            this->BoardList_p2[i][j] =0;
        }
    }
    this->AddBoard_p2();
    this->AddBoard_p2();
}
