#include"cover.h"
#include"tool.h"
#include"neizhi.h"
#include"main.h"
#include"chapter1.h"//�����ã��ǵ�ɾ
#include"chapter2.h"//�����ã��ǵ�ɾ



int main()
{
	
	neizhi();
	
	
}

void start()//�����͸���ϸע�ͼ�chapter1.cpp
{
	beginpage();
	int x0 = 15, y0 = 1, x1 = 15, y1 = 1, clue;//���ҡ��ĳ�ʼλ�ã�������������汾������gotoxy�������꣩
	while (1)//ʵ���볡������ͬʱ��ֹ����
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
	cout << "��û����ʰ���Լ������";
	wait(2000);
	cout << "�ֻ���Ļ���ˣ�������ʾ�˵�ʮ��";
	wait(2000);
	cout << "BAD END 1 ���������Ŷ�ṳ̂��ȥ         �������˳�������һ�ΰɣ�";

}