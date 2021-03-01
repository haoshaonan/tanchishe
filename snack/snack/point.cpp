#include "point.h"

using namespace std;
point::point(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_pic = pic;
};
point::~point()
{
}
int point::color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
	return 0;
}
void point::gotoxy(int x,int y)//ָ��λ����ʾ
{
	COORD coor;
	coor.X = x;
	coor.Y = y;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coor);
}
void point::addpoint()//��ʾԪ��
{
	gotoxy(m_x, m_y);
	cout << m_pic;
};
void point::erasepoint()//����Ԫ��
{
	gotoxy(m_x, m_y);
	cout << " ";
};