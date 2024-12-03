#include"cover.h"
#include"tool.h"
#include"neizhi.h"
#include"main.h"
#include"chapter1.h"//测试用，记得删
#include"chapter2.h"//测试用，记得删



int main()
{
	
	neizhi();
	
	
}

void start()//此类型更详细注释见chapter1.cpp
{
	beginpage();
	int x0 = 15, y0 = 1, x1 = 15, y1 = 1, clue;//“我”的初始位置（参数调整过后版本，并非gotoxy可用坐标）
	while (1)//实现与场景互动同时防止吃字
	{
		sidejudge(x1, y1);
		clue = cluejudge0(x1, y1);
		interact0(clue, x0, y0, x1, y1);

		x1 = x0;
		y1 = y0;
	}
}

void end1()
{
	cout << "你没能收拾好自己的书包";
	wait(2000);
	cout << "手机屏幕亮了，上面显示八点十分";
	wait(2000);
	cout << "BAD END 1 ：连寝室门都没踏出去         请自行退出，再试一次吧！";

}