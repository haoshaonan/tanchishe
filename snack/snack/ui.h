#pragma once
#include "point.h"
//#pragma comment(lib, "winsock.lib")

class ui:
	public point
{
public:
	static const int uihight=25;
	static const int uiwidth=115;
	static int uiscore;
	static int uilevel;
	static int uitime;
	static int highscore;
public:
	void drawGameArea();
	void drawBugArea(int x);//��ʾ�ϰ���
	void drawGameInfo();
	void eraseGameInfo();
	void Play(int f, int a, int t);//������Ч
	void helloui();//��ӭ����
	int endInfo();//��������
	void file_out();//��ȡ��߷�
	void file_in();//д����߷�
	void printsnake();//������ҳ����ͼ��
};

