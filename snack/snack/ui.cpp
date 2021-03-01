#include "ui.h"

enum { Do = 262, Re = 294, Mi = 330, Fa = 349, So = 392, La = 440, Xi = 494 };
/*定义播放一节音符的函数
f--表示音符，其值为上述定义的枚举型
a--	表示音高，其值为1(低音)、2(中音)、3(高音)
*/

const unsigned PER = 125;
/*定义1/8时间长度为125ms，快速*/

using namespace std;
int ui::uiscore = 0;
int ui::uilevel = 1;
int ui::uitime = 1;
int ui::highscore = 0;

void ui::drawGameArea()
{
	int i;
	for (i = 0; i <= uiwidth; i++)
	{
		gotoxy(i, 0);
		color(7);
		cout << "#";
	};
	color(9);
	for (i = 1; i < uiwidth-25; i++)
	{
		gotoxy(i, 3);
		cout << "#";
	};
	color(7);
	for (i = uiwidth-25; i < uiwidth; i++)
	{
		gotoxy(i, 3);
		cout << "#";
	};
	color(9);
	for (i = 1; i < uiwidth-25; i++)
	{
		gotoxy(i, uihight);
		cout << "#";
	};
	color(7);
	for (i = uiwidth-25; i < uiwidth; i++)
	{
		gotoxy(i, uihight);
		cout << "#";
	};
	for (i = 1; i <= uihight; i++)
	{
		if (i < 3)
		{
			gotoxy(0, i);
			color(7);
			cout << "#";
		}
		else
		{
			gotoxy(0, i);
			color(4);
			cout << "#";
		}
		gotoxy(uiwidth, i);
		color(7);
		cout << "#";
	};
	for (i = 3; i <= uihight; i++)
	{
		gotoxy(uiwidth-25, i);
		color(4);
		cout << "#";
	};
};
void ui::drawGameInfo()
{
	color(2);
	gotoxy(35, 2);
	cout << "游戏名:贪吃蛇" << " || " << "用户名:郝绍楠" << " || " << "分数:" << uiscore << " || " << "等级:" << uilevel;
	color(6);
	gotoxy(uiwidth - 16, 4);
	cout << "游戏规则" ;
	gotoxy(uiwidth - 22, 5);
	cout << "1.按空格键暂停/继续";
	gotoxy(uiwidth - 22, 6);
	cout << "按方向键移动";
	gotoxy(uiwidth - 22,7);
	cout << "2.蛇碰到左右墙壁或障";
	gotoxy(uiwidth - 22, 8);
	cout<< "碍物或自己身体时死亡";
	gotoxy(uiwidth - 22, 10);
	cout << "3.蛇碰到上下墙壁不死";
	gotoxy(uiwidth - 22, 11);
	cout<<"且将会从另一边穿出";
	gotoxy(uiwidth - 22, 13);
	cout << "4.蛇吃食物可得分";
	gotoxy(uiwidth - 22, 14);
	cout << "每得10分升一级";
	gotoxy(uiwidth - 22, 15);
	cout << "升级后蛇移速加快";
	gotoxy(uiwidth - 22, 16);
	cout << "食物消失速度加快";
	gotoxy(uiwidth - 22, 17);
	cout << "随等级增加障碍物数量";
	gotoxy(uiwidth - 22, 18);
	cout << "到8级后将不再增加难度";
	color(15);
	gotoxy(uiwidth - 22, 20);
	cout << "最高分：" << highscore;
	gotoxy(uiwidth - 22, 22);
	cout << "食物剩余时间：" << (uiwidth + uihight) - uitime<<" !";
}
void ui::drawBugArea(int x)
{
	switch (x)
	{
	case 2:
		gotoxy(45, 7);
		color(4);
		cout << "#*************#";
		break;
	case 4:
		gotoxy(45, 17);
		color(4);
		cout << "#*************#";
		break;
	case 6:
		gotoxy(25, 12);
		color(4);
		cout << "#*************#";
		break;
	case 8:
		gotoxy(65, 12);
		color(4);
		cout << "#*************#";
		break;
	default:
		break;
	}

}
;


void ui::eraseGameInfo()
{
	gotoxy(35, 2);
	cout << "游戏名:贪吃蛇" << " || " << "用户名:郝绍楠" << " || " << "分数:" << "   " << "||" << "等级:" << "  ";
	gotoxy(uiwidth - 22, 20);
	cout << "最高分：" << "    ";
	gotoxy(uiwidth - 20, 22);
	cout << "剩余时间：" << "   ";
};
void ui::helloui()
{
	printsnake();
	Sleep(50);
	gotoxy(45, 3);
	cout << "#*****************************#";
	gotoxy(45, 15);
	cout << "#*****************************#";
	point::gotoxy(56, 6);
	color(3);
	cout << "贪吃蛇";
	Play(Mi, 2, 2); Play(Mi, 2, 2); Play(Fa, 2, 2); Play(So, 2, 2);
	point::gotoxy(50, 7);
	cout << "~**######O:<-    *";
	point::gotoxy(57, 9);
	cout << "选项:";
	point::gotoxy(50, 11);
	cout<< "1:开始游戏  " << "0:退出  ";
	Play(Do, 2, 1);
}

int ui::endInfo()
{
	color(8);
	int q;
	system("cls");//清屏
	point::gotoxy(30, 5);
	cout << "***********************************************************";
	gotoxy(55, 10);
	color(8);
	cout << "/^\\/^\\";

	gotoxy(54, 11);
	cout << "|__| O|";

	gotoxy(53, 11);
	cout << "_";

	gotoxy(45, 12);
	cout << "\\/";

	gotoxy(51, 12);
	cout << "/";

	gotoxy(57, 12);
	cout << "\\_/";

	gotoxy(61, 12);
	cout << "\\";

	gotoxy(46, 13);
	cout << "\\___";

	gotoxy(52, 13);
	cout << "________/";

	gotoxy(51, 13);
	cout << "|";

	gotoxy(63, 13);
	cout << "//";

	gotoxy(52, 14);
	cout << "\\______";

	gotoxy(64, 14);
	cout << "\\";

	gotoxy(59, 15);
	cout << "|";

	point::gotoxy(54, 15);
	cout << "你死掉了";
	drawGameInfo();
	point::gotoxy(45, 18);
	cout << "是否重来？重来按：1 结束按：0   " ;
	cin >> q;
	system("cls");
	if(q==0)
	{
		color(6);
		point::gotoxy(45, 10);
		cout << "**********************************";
		point::gotoxy(60, 15);
		cout << "bye";
		point::gotoxy(45, 20);
		cout << "**********************************";
	}
	return q;
}

void ui::file_out()
{
	FILE* fp;
	fp = fopen("save.txt", "a+");
	fscanf_s(fp, "%d", &highscore);
	fclose(fp);
}

void ui::file_in()
{
	FILE* fp;
	fp = fopen("save.txt", "w+");
	fprintf(fp, "%d", uiscore);
	fclose(fp);
}

void ui::printsnake()
{
	gotoxy(35, 1);
	color(6);
	cout<<"/\\/\\/\\";

	gotoxy(35, 2);
	cout << "\\$\\ $/";      //修改蛇的字符画

	gotoxy(33, 2);
	color(2);
	cout << "_";

	gotoxy(25, 3);
	color(12);
	cout << "\\/";

	gotoxy(31, 3);
	color(2);
	cout << "/";

	gotoxy(36, 3);
	color(6);
	cout << "\\/\\/";

	gotoxy(41, 3);
	color(10);
	cout << " \\";

	gotoxy(26, 4);
	color(12);
	cout << "\\____";

	gotoxy(32, 4);
	cout << "_________/";

	gotoxy(31, 4);
	color(2);
	cout << "|";

	gotoxy(43, 4);
	color(10);
	cout << "\\";

	gotoxy(32, 5);
	color(2);
	cout << "\\_______";

	gotoxy(44, 5);
	color(10);
	cout << "\\";

	gotoxy(39, 6);
	cout << "|     |                  \\";

	gotoxy(38, 7);
	cout << "/      /                   \\";

	gotoxy(37, 8);
	cout << "/      /                    \\ \\";

	gotoxy(35, 9);
	cout << "/      /                       \\ \\";

	gotoxy(34, 10);
	cout << "/     /                          \\  \\";

	gotoxy(33, 11);
	cout << "/     /             _----_         \\   \\";

	gotoxy(32, 12);
	cout << "/     /           _-~      ~-_         |  |";

	gotoxy(31, 13);
	cout << "(      (        _-~    _--_    ~-_     _/  |";

	gotoxy(32, 14);
	cout << "\\     ~-____-~    _-~    ~-_    ~-_-~    /";

	gotoxy(33, 15);
	cout << "~-_           _-~          ~-_       _-~";

	gotoxy(35, 16);
	cout << "~--______-~                ~-___-~";

	Sleep(500);
	system("cls");

	gotoxy(35, 1);
	color(6);
	cout << "/^\\/^\\";

	gotoxy(34, 2);
	cout << "|__| O|";

	gotoxy(33, 2);
	color(2);
	cout << "_";

	gotoxy(25,3);
	color(12);
	cout << "\\/";

	gotoxy(31,3);
	color(2);
	cout << "/";

	gotoxy(37,3);
	color(6);
	cout << "\\_/";

	gotoxy(41,3);
	color(10);
	cout << "\\";

	gotoxy(26,4);
	color(12);
	cout << "\\___";

	gotoxy(32,4);
	cout << "________/";

	gotoxy(31,4);
	color(2);
	cout << "|";

	gotoxy(43, 4);
	color(10);
	cout << "//";

	gotoxy(32, 5);
	color(2);
	cout << "\\______";

	gotoxy(44, 5);
	color(10);
	cout << "\\";

	gotoxy(39, 6);
	cout << "|";
	                                   //shewei

	gotoxy(70, 16);
	cout << "/     /             _----_         \\   \\";

	gotoxy(69, 17);
	cout << "/     /           _-~      ~-_         |  |";

	gotoxy(68, 18);
	cout << "(      (        _-~    _--_    ~-_     _/  |";

	gotoxy(69, 19);
	cout << "\\     ~-____-~    _-~    ~-_    ~-_-~    /";

	gotoxy(70, 20);
	cout << "~-_           _-~          ~-_       _-~";

	gotoxy(72, 21);
	cout << "~--______-~                ~-___-~";
}

void ui::Play(int f, int a, int t)
{
	int i = 0;
	Beep((unsigned)(f * a), t * PER);
}