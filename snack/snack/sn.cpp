#include "sn.h"
#include <conio.h>
sn::sn(int x, int y, int light, directions direction, int speed, char pic)
{
    m_ilength = light;
    m_iheadx = x;
    m_iheady = y;
    m_ispeed = speed;
    m_cpic = pic;
	m_enumcurrentdirection = direction;
	int i;
	for (i = 0; i < m_ilength; i++)
	{
		if(i==0)//初始化蛇头
		{
			point hpoint(0, 0, '#');
			m_vecbody.push_back(hpoint);
		}
		else//初始化蛇身
		{
			point hpoint(0, 0, '*');
			m_vecbody.push_back(hpoint);
		}
		switch (m_enumcurrentdirection)
		{
		case up:
			m_vecbody[i].m_x = m_iheadx;
			m_vecbody[i].m_y = m_iheady + i;
			break;
		case down:
			m_vecbody[i].m_x = m_iheadx;
			m_vecbody[i].m_y = m_iheady - i;
			break;
		case directions::left:
			m_vecbody[i].m_x = m_iheadx + i;
			m_vecbody[i].m_y = m_iheady;
			break;
		case directions::right:
			m_vecbody[i].m_x = m_iheadx - i;
			m_vecbody[i].m_y = m_iheady;
			break;
		};
	};

};

sn::~sn()
{

};

void sn::changedirection(int vkvalue)
{
		switch (vkvalue)
		{
		case 72:
			if (m_enumcurrentdirection != down)
			{
				m_enumcurrentdirection = up;
			};
			break;
		case 80:
			if (m_enumcurrentdirection != up)
			{
				m_enumcurrentdirection = down;
			};
			break;
		case 75:
			if (m_enumcurrentdirection != directions::right)
			{
				m_enumcurrentdirection = directions::left;
			};
			break;
		case 77:
			if (m_enumcurrentdirection != directions::left)
			{
				m_enumcurrentdirection = directions::right;
			};
			break;
	    };
}

void sn::move()
{
	int ch;
	if (_kbhit())//监听按键
	{//如果有按键按下，则_kbhit()函数返回真
		ch = _getch();//使用_getch()函数获取按下的键值
		//changeDir
		if (ch == 224)
		{
			ch = _getch();
		}
		changedirection(ch);
		if(ch==32)//暂停与继续
			while (1)
			{
				if (_kbhit())
				{//如果有按键按下，则_kbhit()函数返回真
					ch = _getch();//使用_getch()函数获取按下的键值
					//changeDir
					if (ch == 224)
					{
						ch = _getch();
					}
					if (ch == 32)
						break;
				}
			}
	}
	int i;
		for (i = m_ilength-1; i >=1; i--)
		{
			m_vecbody[i].m_x = m_vecbody[i - 1].m_x;
			m_vecbody[i].m_y = m_vecbody[i - 1].m_y;
		};
		switch (m_enumcurrentdirection)
		{
		case up:
			m_vecbody[0].m_y = m_vecbody[0].m_y - 1;
			break;
		case down:
			m_vecbody[0].m_y = m_vecbody[0].m_y + 1;
			break;
		case directions::left:
			m_vecbody[0].m_x = m_vecbody[0].m_x - 1;
			break;
		case directions::right:
			m_vecbody[0].m_x = m_vecbody[0].m_x + 1;
			break;
		};
};



void sn::showsnake()
{
	for (size_t i = 0; i<m_ilength; i++)
	{
		m_vecbody[i].addpoint();
	}
		
};

void sn::erasesnake()
{
		m_vecbody[m_ilength-1].erasepoint();
}

void sn::growup()
{
	
	point p(0,0,'*');
	m_vecbody.push_back(p);
	m_ilength++;
}

bool sn::eatfood(food *f1)
{
	if (m_vecbody[0].m_x == f1->m_x && m_vecbody[0].m_y == f1->m_y)
		return true;
	return false;
};