#include"tool.h"
using namespace std;
void setPrintColor(int color)//设置颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//windows.h https://blog.csdn.net/Fdog_/article/details/103764196
}

void wait(int m_seconds)//time.h库详解 https://blog.csdn.net/weixin_43460876/article/details/94832561
{
	clock_t endwait;//即long，进行了重命名 https://blog.csdn.net/m0_47965537/article/details/109455355
	endwait = clock() + m_seconds / 1000.0 * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}//暂停函数

void gotoXY(double x, double y)//将控制台的光标移动到指定的坐标位置
{
	COORD c;//wincontypes.h 一种结构
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//https://blog.csdn.net/baiqi123456/article/details/119753736
}

void clear(int x, int y, int w, int h)//清理指定矩形区域(从(x,y)到(x+w,y+h)的矩形
{
	for (int i = 0; i < h; i++) {
		gotoXY(x, y + i);
		for (int j = 0; j < w; j++) putchar(' ');//putchar函数 https://blog.csdn.net/Luo_LA/article/details/106712099
	}//其实就是打空格
}

void printMessage(const char* str)//打印文字
{
	for (int i = 0; i < strlen(str); ++i)//strlen函数：https://blog.csdn.net/lht_521/article/details/105928323
	{
		cout << *(str + i);
		Sleep(70);//实现文字间停顿
	}
	cout << endl;
}


void setXY(int x, int y)
{
	COORD pos;//包含两个short
	HANDLE obj;//strict被定义时可指向任意变量（handle）
	pos.X = x;//那两个short
	pos.Y = y;
	obj = GetStdHandle(STD_OUTPUT_HANDLE);//取得输出句柄
	SetConsoleCursorPosition(obj, pos);//定位光标
}






void sidejudge(int& x1, int& y1)//判断移动方向
{

	if (_kbhit())//conio.h https://blog.csdn.net/qq_42918060/article/details/106359597
	{
		char input = _getch();//获取键盘信息
		switch (input)
		{
		case 'w':
			y1 = y1 - 1;
			break;
		case's':
			y1 = y1 + 1;
			break;
		case'a':
			x1 -= 1;
			break;
		case'd':
			x1 += 1;
			break;
		
		}
		
		gotoXY(x1, y1);
	}
}

void clearLine(int x, int y)//在2秒钟过后，将一行用空格覆盖
{
	Sleep(500);
	setXY(x, y);
	for (int i = 0; i < 120; i++)
	{
		cout << " ";
	}
}

