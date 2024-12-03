#include "tool.h"
#include"cover.h"
#include <stdlib.h>
#include"chapter1.h"
void beginpage()//绘制开始界面
{
	gotoXY(45.5,3);
	setPrintColor(0x0c);
	const char* str = "奇迹大学生";
	const char* str1 = "———";
	const char* str2 = "开始早八";
	const char* str3 = "拒绝早八";
	const char* str4 = "提示：wasd移动，先调至英文输入法，尽量别一直长按";//48
	printMessage(str);
	wait(500);
	setPrintColor(0x0f);
	gotoXY(55.5, 3);
	printMessage(str1);
	wait(500);
	gotoXY(59.5, 3);
	cout << "我";
	wait(500);
	gotoXY(47.5, 6);
	printMessage(str2);
	wait(500);
	gotoXY(47.5, 9);
	printMessage(str3);
	wait(500);
	gotoXY(31.5, 12);
	printMessage(str4);
	
	
	
}

void interact0(int number, int& x0, int& y0, int x1, int y1)//number标记互动对象在地图上对应的情况
{
	switch (number)
	{
	case 0:
		
		break;
	case 1:
		viewme0(x0, y0, x1, y1);
		x0 = x1;
		y0 = y1;
		break;
	case 3:
	  {
		system("cls");
		wait(500);
		gotoXY(0, 0);
		const char* str1 = "区区早八，我不去了!";
		const char* str2 = "还没硬气三秒，良心的谴责还是促使我抓起了书包。";
		const char* str3 = "翘课是不可能翘课的，这辈子都是不可能翘课的。";
		printMessage(str1);
		wait(500);
		printMessage(str2);
		wait(500);
		printMessage(str3);
		wait(500);
		system("cls");
		yinru();
		break;
	    }
		
	case 2:
		yinru();
		break;
	
	}
}

int cluejudge0(int x1, int y1)//判断下一步的字是什么
{
	int number = map0[y1][x1];
	return number;
}

int map0[12][26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//开始界面地图
					0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,
					0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
					0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
					0,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,0,
					0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
					0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
					0,1,1,1,1,1,1,1,1,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,0,
					0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
					0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

void viewme0(int x0, int y0, int x1, int y1)//实现我的移动
{
	if (x0 != x1 || y0 != y1)
	{
		gotoXY(29+2*x0, 2+y0);
		cout << "  ";
		gotoXY(29+2*x1, 2+y1);
		cout << "我";
	}
}

void yinru()//打印引入文本
{
	system("cls");
	wait(500);
	gotoXY(0, 0);
	const char* str1 = "（看向手表）7：50";
	const char* str2 = "总算是收拾好出门了。";
	const char* str3 = "没看见舍友他们，可能已经。。。到教室了？";
	const char* str4 = "不好，我得赶紧追上他们！";
	const char* str5 = "（赶路中。。。）";
	printMessage(str1);
	wait(500);
	printMessage(str2);
	wait(500);
	printMessage(str3);
	wait(500);
	printMessage(str4);
	wait(500);
	printMessage(str5);
	wait(5000);
	system("cls");
	chapter1a();
}