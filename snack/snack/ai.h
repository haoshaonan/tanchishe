#pragma once
#include "food.h"
#include "sn.h"
#include "ui.h"
#include <conio.h>
#include <Windows.h>
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���

class ai
{
public:
	ai(int x=0, int y=1,int s=0,int z=0);
	virtual ~ai();

	int run();
	int color(int a);//�ı���ɫ
	bool checkfailed();//����
	bool checklevel();//�ж�����
	void changeinfo();//���±���
	void drawGameArea();
	void drawGameInfo();
	void eraseGameInfo();
	void drawBugArea(int x);//��ʾ�ϰ���
	void erasedos();//ɾ�����
	void Play(int f, int a, int t);//������Ч
	int endInfo();//����
	void file_out();//��ȡ��߷�
	void file_in();//д����߷�

public:
	food* f1;
	sn* s1;
	int m_score;//�÷�
	int m_level;
	int m_t;//ʱ��
	int m_highscore;//��߷�
};

