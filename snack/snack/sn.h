#pragma once
#include "food.h"
#include<vector>
using namespace std;
typedef enum {
    up,down,left,right
}directions;

class sn 
{
    public:
        sn(int x = 40, int y = 10, int light = 4, directions direction = directions::right, int speed = 300, char pic = '*');
        virtual ~sn();

        void changedirection(int vkvalue);//更改方向
        void move();//移动
        bool eatfood(food *f1);
        void showsnake();
        void erasesnake();
        void growup();//增长

public:
    int m_ilength;
    int m_iheadx;
    int m_iheady;
    int m_ispeed;
    int m_cpic;
    directions m_enumcurrentdirection;
    vector<point> m_vecbody;

};

