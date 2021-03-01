#pragma once
#include "point.h"
#include "ui.h"
class food :
    public point
{
public:
    food(int x = 0, int m_y = 0, char m_pic = '@');
    virtual ~food();
    void CreatePos();//生成食物位置
};

