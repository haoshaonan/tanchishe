#pragma once
#include <iostream>
#include <cstdlib>
#include <windows.h>
class point
{
public:
	int m_x;
	int m_y;
	char m_pic;
public:
	point(int m_x = 0, int m_y = 0, char m_pic = '*');
	static void gotoxy(int x, int y);//ָ��λ�����
	void addpoint();//��ʾ�ַ�
	virtual ~point();
	int color(int a);//�ı���ɫ
	void erasepoint();//�����ַ�
};

