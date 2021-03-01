#include "food.h"
#include <ctime>
using namespace std;
food::food(int x, int y, char pic)
{
    m_x = x;
    m_y = y;
    m_pic = pic;
};
food::~food()
{
}

void food::CreatePos()
{
    srand((int)time(0));//限定随机值范围
    m_x = 2+rand() % (ui::uiwidth -27);//计算公式rand()%(up-low+1)+low
    m_y = 4+rand() % (ui::uihight -4);
}