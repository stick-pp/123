#include "tool.h"
#include"cover.h"
#include <stdlib.h>
#include"chapter1.h"
void beginpage()//���ƿ�ʼ����
{
	gotoXY(45.5,3);
	setPrintColor(0x0c);
	const char* str = "�漣��ѧ��";
	const char* str1 = "������";
	const char* str2 = "��ʼ���";
	const char* str3 = "�ܾ����";
	const char* str4 = "��ʾ��wasd�ƶ����ȵ���Ӣ�����뷨��������һֱ����";//48
	printMessage(str);
	wait(500);
	setPrintColor(0x0f);
	gotoXY(55.5, 3);
	printMessage(str1);
	wait(500);
	gotoXY(59.5, 3);
	cout << "��";
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

void interact0(int number, int& x0, int& y0, int x1, int y1)//number��ǻ��������ڵ�ͼ�϶�Ӧ�����
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
		const char* str1 = "������ˣ��Ҳ�ȥ��!";
		const char* str2 = "��ûӲ�����룬���ĵ�Ǵ���Ǵ�ʹ��ץ���������";
		const char* str3 = "�̿��ǲ������̿εģ��Ⱳ�Ӷ��ǲ������̿εġ�";
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

int cluejudge0(int x1, int y1)//�ж���һ��������ʲô
{
	int number = map0[y1][x1];
	return number;
}

int map0[12][26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//��ʼ�����ͼ
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

void viewme0(int x0, int y0, int x1, int y1)//ʵ���ҵ��ƶ�
{
	if (x0 != x1 || y0 != y1)
	{
		gotoXY(29+2*x0, 2+y0);
		cout << "  ";
		gotoXY(29+2*x1, 2+y1);
		cout << "��";
	}
}

void yinru()//��ӡ�����ı�
{
	system("cls");
	wait(500);
	gotoXY(0, 0);
	const char* str1 = "�������ֱ�7��50";
	const char* str2 = "��������ʰ�ó����ˡ�";
	const char* str3 = "û�����������ǣ������Ѿ��������������ˣ�";
	const char* str4 = "���ã��ҵøϽ�׷�����ǣ�";
	const char* str5 = "����·�С�������";
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