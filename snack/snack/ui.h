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
	void drawBugArea(int x);//显示障碍物
	void drawGameInfo();
	void eraseGameInfo();
	void Play(int f, int a, int t);//播放音效
	void helloui();//欢迎界面
	int endInfo();//死亡界面
	void file_out();//读取最高分
	void file_in();//写入最高分
	void printsnake();//绘制首页大蛇图像
};

