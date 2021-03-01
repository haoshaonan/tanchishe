#pragma once
#include "food.h"
#include "sn.h"
#include "ui.h"
#include <conio.h>
#include <Windows.h>
#include "mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库

class ai
{
public:
	ai(int x=0, int y=1,int s=0,int z=0);
	virtual ~ai();

	int run();
	int color(int a);//改变颜色
	bool checkfailed();//判死
	bool checklevel();//判断升级
	void changeinfo();//更新标题
	void drawGameArea();
	void drawGameInfo();
	void eraseGameInfo();
	void drawBugArea(int x);//显示障碍物
	void erasedos();//删除光标
	void Play(int f, int a, int t);//播放音效
	int endInfo();//结束
	void file_out();//读取最高分
	void file_in();//写入最高分

public:
	food* f1;
	sn* s1;
	int m_score;//得分
	int m_level;
	int m_t;//时间
	int m_highscore;//最高分
};

