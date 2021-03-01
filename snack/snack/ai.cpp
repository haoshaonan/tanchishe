#include "ai.h"

enum { Do = 262, Re = 294, Mi = 330, Fa = 349, So = 392, La = 440, Xi = 494 };
/*定义播放一节音符的函数
f--表示音符，其值为上述定义的枚举型
a--	表示音高，其值为1(低音)、2(中音)、3(高音)
*/

const unsigned PER = 125;
/*定义1/8时间长度为125ms，快速*/

ai::ai(int x,int y,int s,int z)
{
    m_score = x;
    m_level = y;
    m_highscore=s;
    m_t = z;
     s1 = new sn;
     f1 = new food;
}
ai:: ~ai()
{
    delete f1;
    f1 = NULL;
    delete s1;
    s1 = NULL;
}

int ai::run()
{
    erasedos();
    PlaySound("C:\\Users\\dell\\source\\repos\\snack\\sn.wav", NULL, SND_ALIAS | SND_ASYNC);
    int i;
    int q;
    f1->CreatePos();
    for (i = 0; i < s1->m_ilength; i++)//判断食物是否出现到蛇身上，若是则重新分配食物
    {
        while (f1->m_x == s1->m_vecbody[i].m_x && f1->m_y == s1->m_vecbody[i].m_y)
        {
            f1->CreatePos();
        }
    };
    color(7);
    f1->addpoint();

                                                                                      //蛇开始移动
    while (checkfailed())
    {
        s1->move();
        color(9);
        s1->showsnake();
        Sleep(s1->m_ispeed);
        s1->erasesnake();
        drawBugArea(m_level);//放置障碍物
        if (s1->m_vecbody[0].m_y == ui::uihight)//判断是否到下边缘并穿越
            s1->m_vecbody[0].m_y = 4;
        if (s1->m_vecbody[0].m_y == 3)//判断是否到上边缘并穿越
            s1->m_vecbody[0].m_y = ui::uihight-1;

                                                                                        //蛇吃到食物
        if (s1->eatfood(f1))
                   {
                       f1->erasepoint();
                       PlaySound("C:\\Users\\dell\\source\\repos\\snack\\eat.wav", NULL, SND_ALIAS | SND_ASYNC);
                       s1->growup();
                       m_score++;
                       if (checklevel())//升级并加速
                       {
                           m_level++;
                           if (s1->m_ispeed>50)
                               s1->m_ispeed -= 50;//速度最快为50
                       }
                       changeinfo();//更新标题

                                                                                          //重新显示新食物
                       f1->CreatePos();
                       for (i = 0; i < s1->m_ilength; i++)     //判断食物是否出现到蛇身上，若是则重新分配食物
                       {
                           while (f1->m_x == s1->m_vecbody[i].m_x && f1->m_y == s1->m_vecbody[i].m_y)
                           {
                               f1->CreatePos();
                           };
                       }
                       switch (m_level)      //判断食物是否出现在障碍物上，若是则重新分配食物
                       {
                       case 1:
                           break;
                       case 2:
                       case 3:
                               for (size_t j = 0; j < 15; j++)
                               {
                                   while (f1->m_x == 45 + j && f1->m_y == 7)
                                   {
                                       f1->CreatePos();
                                   };
                               };
                               break;
                       case 4:
                       case 5:
                           for (size_t j = 0; j < 15; j++)
                           {
                               while (f1->m_x == 45 + j && f1->m_y == 17)
                               {
                                   f1->CreatePos();
                               };
                               while (f1->m_x == 45 + j && f1->m_y == 7)
                               {
                                   f1->CreatePos();
                               };
                           };
                           break;
                       case 6:
                       case 7:
                           for (size_t j = 0; j < 15; j++)
                           {
                               while (f1->m_x == 25 + j && f1->m_y == 12)
                               {
                                   f1->CreatePos();
                               };
                               while (f1->m_x == 45 + j && f1->m_y == 17)
                               {
                                   f1->CreatePos();
                               };
                               while (f1->m_x == 45 + j && f1->m_y == 7)
                               {
                                   f1->CreatePos();
                               };
                           };
                           break;
                       case 8:
                       default:
                           for (size_t j = 0; j < 15; j++)
                           {
                               while (f1->m_x == 65 + j && f1->m_y == 12)
                               {
                                   f1->CreatePos();
                               };
                               while (f1->m_x == 25 + j && f1->m_y == 12)
                               {
                                   f1->CreatePos();
                               };
                               while (f1->m_x == 45 + j && f1->m_y == 17)
                               {
                                   f1->CreatePos();
                               };
                               while (f1->m_x == 45 + j && f1->m_y == 7)
                               {
                                   f1->CreatePos();
                               };
                           };
                           break;
                       }
                       color(7);
                       f1->addpoint();
                       m_t = 0;    //倒计时复位
                       PlaySound("C:\\Users\\dell\\source\\repos\\snack\\sn.wav", NULL, SND_ALIAS | SND_ASYNC);//音乐复位
                   };
        m_t++;


        if (m_t == (ui::uiwidth + ui::uihight))//计时消除食物，可随等级提高加快消失速度
        {
            f1->erasepoint();
            Play(Xi, 2, 1);
            f1->CreatePos();
            for (i = 0; i < s1->m_ilength; i++)//判断食物是否出现到蛇身上，若是则重新分配食物
            {
                while (f1->m_x == s1->m_vecbody[i].m_x && f1->m_y == s1->m_vecbody[i].m_y)
                {
                    f1->CreatePos();
                }
            };
            color(7);
            f1->addpoint();
            m_t = 0;
            PlaySound("C:\\Users\\dell\\source\\repos\\snack\\sn.wav", NULL, SND_ALIAS | SND_ASYNC);//音乐复位
        }
        changeinfo();  //刷新显示倒计时
    }
    q=endInfo();//判断是否重来
    return q;
}

int ai::color(int a)
{
    ui u1;
    u1.color(a);
    return 0;
}


bool ai::checkfailed()
{
    for (size_t i = 3; i<s1->m_ilength; i++)//从第四节蛇身开始
    {
        if (s1->m_vecbody[0].m_x == s1->m_vecbody[i].m_x &&
            s1->m_vecbody[0].m_y == s1->m_vecbody[i].m_y)//判断蛇头是否自残
        {
            return 0;
        }
    };
        if (s1->m_vecbody[0].m_x == ui::uiwidth-25  || s1->m_vecbody[0].m_x == 0)//判断蛇头是否撞左右墙壁
        {
            return 0;
        }
        else
        {
            switch (m_level)
            {
            case 1:
                break;
            case 2:
            case 3:
                for (size_t j = 0; j < 15; j++)
                {
                    if (s1->m_vecbody[0].m_x == 45+j && s1->m_vecbody[0].m_y == 7)//判断蛇头是否撞障碍物1
                        return 0;
                }
                break;
            case 4:
            case 5:
                for (size_t j = 0; j < 15; j++)
                {
                    if (s1->m_vecbody[0].m_x == 45+j && s1->m_vecbody[0].m_y == 17)//判断蛇头是否撞障碍物2
                        return 0;
                    else
                    {
                        if (s1->m_vecbody[0].m_x == 45+j && s1->m_vecbody[0].m_y == 7)//判断蛇头是否撞障碍物1
                            return 0;
                    }
                }
                break;
            case 6:
            case 7:
                for (size_t j = 0; j < 15; j++)
                {
                    if (s1->m_vecbody[0].m_x == 25+j && s1->m_vecbody[0].m_y == 12)//判断蛇头是否撞障碍物3
                        return 0;
                    else
                    {
                            if (s1->m_vecbody[0].m_x == 45+j && s1->m_vecbody[0].m_y == 17)//判断蛇头是否撞障碍物2
                                return 0;
                            else
                            {
                                if (s1->m_vecbody[0].m_x == 45+j && s1->m_vecbody[0].m_y == 7)//判断蛇头是否撞障碍物1
                                    return 0;
                            }
                    }
                }
                break;
            case 8:
            default:
                for (size_t j = 0; j < 15; j++)
                {
                    if (s1->m_vecbody[0].m_x == 65+j && s1->m_vecbody[0].m_y == 12)//判断蛇头是否撞障碍物4
                        return 0;
                    else
                    {
                            if (s1->m_vecbody[0].m_x == 25+j && s1->m_vecbody[0].m_y == 12)//判断蛇头是否撞障碍物3
                                return 0;
                            else
                            {
                                    if (s1->m_vecbody[0].m_x == 45+j && s1->m_vecbody[0].m_y == 17)//判断蛇头是否撞障碍物2
                                        return 0;
                                    else
                                    {
                                        if (s1->m_vecbody[0].m_x == 45+j && s1->m_vecbody[0].m_y == 7)//判断蛇头是否撞障碍物1
                                            return 0;
                                    }
                            }
                    }
                }
                break;
            }
        }
    return 1;


}

bool ai::checklevel()//判断是否升级
{
    if (m_score!=0 && m_score % 1 == 0)
        return true;
    else
        return false;
}

void ai::changeinfo()
{
    ui::uiscore = m_score;
    ui::uilevel = m_level;
    ui::highscore = m_highscore;
    ui::uitime = m_t;
    ai::eraseGameInfo();
    ai::drawGameInfo();
}

void ai::drawGameArea()
{
    ui u1;
    u1.drawGameArea();
}

void ai::drawGameInfo()
{
    ui u1;
    file_out();
    u1.drawGameInfo();  
}

void ai::eraseGameInfo()
{
    ui u1;
    u1.eraseGameInfo();
}

void ai::drawBugArea(int x)
{
    ui u1;
    if (checkfailed())//判断障碍物是否出现在蛇头上，若在则待蛇头移开后再放
    {
        u1.drawBugArea(x);
    }
}

void ai::erasedos()//删除光标
{
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = sizeof(cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}


void ai::Play(int f, int a, int t)
{
    ui u1;
    u1.Play(f, a, t);
}

int ai::endInfo()
{
    int q;
    ui u1;
   u1.Play(So, 2, 2); u1.Play(Fa, 2, 2); u1.Play(Mi, 2, 2); u1.Play(Re, 2, 2);
    q=u1.endInfo();
    if (m_score > u1.highscore)
        file_in();
    Play(Do, 2, 1);
    return q;
}

void ai::file_out()
{
    ui u1;
    u1.file_out();
}

void ai::file_in()
{
    ui u1;
    u1.file_in();
}

