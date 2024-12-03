#include"tool.h"
using namespace std;
void setPrintColor(int color)//������ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);//windows.h https://blog.csdn.net/Fdog_/article/details/103764196
}

void wait(int m_seconds)//time.h����� https://blog.csdn.net/weixin_43460876/article/details/94832561
{
	clock_t endwait;//��long�������������� https://blog.csdn.net/m0_47965537/article/details/109455355
	endwait = clock() + m_seconds / 1000.0 * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}//��ͣ����

void gotoXY(double x, double y)//������̨�Ĺ���ƶ���ָ��������λ��
{
	COORD c;//wincontypes.h һ�ֽṹ
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//https://blog.csdn.net/baiqi123456/article/details/119753736
}

void clear(int x, int y, int w, int h)//����ָ����������(��(x,y)��(x+w,y+h)�ľ���
{
	for (int i = 0; i < h; i++) {
		gotoXY(x, y + i);
		for (int j = 0; j < w; j++) putchar(' ');//putchar���� https://blog.csdn.net/Luo_LA/article/details/106712099
	}//��ʵ���Ǵ�ո�
}

void printMessage(const char* str)//��ӡ����
{
	for (int i = 0; i < strlen(str); ++i)//strlen������https://blog.csdn.net/lht_521/article/details/105928323
	{
		cout << *(str + i);
		Sleep(70);//ʵ�����ּ�ͣ��
	}
	cout << endl;
}


void setXY(int x, int y)
{
	COORD pos;//��������short
	HANDLE obj;//strict������ʱ��ָ�����������handle��
	pos.X = x;//������short
	pos.Y = y;
	obj = GetStdHandle(STD_OUTPUT_HANDLE);//ȡ��������
	SetConsoleCursorPosition(obj, pos);//��λ���
}






void sidejudge(int& x1, int& y1)//�ж��ƶ�����
{

	if (_kbhit())//conio.h https://blog.csdn.net/qq_42918060/article/details/106359597
	{
		char input = _getch();//��ȡ������Ϣ
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

void clearLine(int x, int y)//��2���ӹ��󣬽�һ���ÿո񸲸�
{
	Sleep(500);
	setXY(x, y);
	for (int i = 0; i < 120; i++)
	{
		cout << " ";
	}
}

