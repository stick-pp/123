#include"chapter1.h"
#include"tool.h"
#include"chapter2.h"

void chapter1a()
{
    yinru1();
    wait(1000);
    mapdraw1();
    int x0 = 0, y0 = 2, x1 = 0, y1 = 2, clue;//���ҡ��ĳ�ʼ�ڵ�ͼ�����λ�ã�������������汾������gotoxy�������꣩
    while (1)//ʵ���볡������ͬʱ��ֹ����
    {
        sidejudge(x1, y1);
        clue = cluejudge1(x1, y1);
        interact1(clue, x0, y0, x1, y1);

        x1 = x0;
        y1 = y0;
    }
}

void mapdraw1()
{
    gotoXY(31,3);
    cout << "�ݲݻ��ݲݲݲ�";
    gotoXY(31, 4);
    cout << "  ��        ��";
    gotoXY(31, 5);
    cout << "  ��  è    �綯��";//"��"(30,5)���������ɵ�
    gotoXY(31, 6);
    cout << "  ��        ��";
    gotoXY(31, 7);
    cout << "�ݲݲݲݲݲݲ�";
    gotoXY(31, 20);
    cout << "������";
}

int map1[5][9] = {0,0,5,0,0,0,0,0,0,//x1=1,y1=2
                  0,0,1,1,1,1,0,0,0,
                  0,1,1,2,1,1,3,3,3,
                  0,0,1,1,1,1,0,0,0,
                  0,0,0,0,0,0,0,0,0};

void yinru1()
{
    system("cls");
    wait(500);
    gotoXY(0, 0);
    const char* str1 = "��ʰ��������������������������Ҵҳ��������š�";
    const char* str2 = "̧����ȥ����·���ԵĲ������деط賤��";
    const char* str3 = "�ң�����·֮ǰ����ôխ��?";
    const char* str4 = "��ûϸ�룬������ֻ�����ҵ��ҵĵ綯����";
    printMessage(str1);
    wait(500);
    printMessage(str2);
    wait(500);
    printMessage(str3);
    wait(500);
    printMessage(str4);
    wait(1000);
    system("cls");
}


int cluejudge1(int x1, int y1)//�ж���һ��������ʲô
{
    int number = map1[y1][x1];
    return number;
}

void interact1(int number, int& x0, int& y0, int x1, int y1)//number��ǻ��������ڵ�ͼ�϶�Ӧ�����
{
    switch (number)
    {
    case 0://ǽ

        break;
    case 1://�ҿ��ߵĵط�
        viewme1(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    case 2://è
        catinteraction();
        wait(2000);
        break;
    case 3://δ��è�������������綯������
        gotoXY(31, 10);
        cout << "һ���綯����������Ϥ�ĸо���";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ƺ���ҪԿ�ײ���������";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ң���ô����?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ң��ҵĵ綯��Կ��ȥ�Ķ���?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "û�취�ˣ���һҧ��һ���ۣ����Ⱦͱ�����ҵķ���";
        wait(2000);
        clear(31, 10, 100, 4);
        wait(500);
        system("cls");
        chapter1c();
        break;
    case 4://�����������綯������
        chapter1b();
        break;
    case 5://�뻨����
        gotoXY(31, 10);
        cout << "��ҹ������裬�����仨�к졣";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "��������һ����������ѡ��:";
        wait(2000);
        clearLine(31, 10);
        gotoXY(31, 10);
        cout << "ѡ����ʾ�������ĸ�󰴻س�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "j������     k������";
        char flowerchoose;
        cin >> flowerchoose;
        switch (flowerchoose)
        {
        case'j':
        {
            int p, q;//����
            for (p = 0; p <= 5; p++)
            {
                for (q = 0; q <= 5; q++)
                {
                    if (map1[p][q] == 1) map1[p][q] = 6;
                }
            }
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(31, 10);
            cout << "�����Ʒ���仨";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(37, 21);
            cout << "�仨������һ��С�컨�����������³���֦�⡭��";
            gotoXY(35, 3);
            cout << "��";
            gotoXY(31, 10);
            cout << "����������������ĸ�����";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(31, 10);
            cout << "����Ļ���ʪ�����ġ�";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(31, 10);
            cout << "�ҵ��ĺ�ȻҲ���ʪ�����ġ�";
            wait(2000);
            clear(31, 10, 100, 4);
            map1[0][2] = 0;
            break;
        }
        case'k':
            wait(500);
            clear(31, 10, 100, 4);
            gotoXY(35, 3);
            cout << "��";
            gotoXY(31, 10);
            cout << "��첻����������������������";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(31, 10);
            cout << "�������ǻ��������У����������µĲ��á�";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(31, 10);
            cout << "����������仨һ�ۣ��ּ�����ǰ��·��";
            wait(2000);
            clear(31, 10, 100, 4);
            map1[0][2] = 0;
            break;
        }
        break;
    case 6://ݭ�����ߵĵط�
        viewmeflo(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    }
}

void catinteraction()
{
    gotoXY(31, 10);
    cout << "Уè�����ڵ�·���룬����צ�ӳ��ҡ�������һ����";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "��������ǰ��������ѡ��:";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "ѡ����ʾ�������ĸ�󰴻س�";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "������j     ��������k          ";
    wait(2000);
    clear(31, 10, 100, 4);
    char catchoose;
    cin >> catchoose;
    switch (catchoose)
    {
    case'j':
        gotoXY(31, 10);
        cout << "�����Ȼ��Ҫ��èèʵ�ڿɰ���                   ";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�Ҷ��������ָ�Ҫߣè...";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "èèȴһ˦β���ܵ��ˡ�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 5);
        cout << "  ";
        map1[2][3] = 1;
        gotoXY(31, 10);
        cout << "�ң���ô����?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "���㶵ؿ���Уè����ݴ��в�����Ӱ��";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "ԭ��ȴ����һ����Կ�ס�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ң��ҵĵ綯��Կ�ס�������ô��������?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�����Ʒ:�綯��Կ��";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 20);
        cout << "�綯��Կ�ף�����մ�ż���èë��";
        map1[2][6] = 4;
        map1[2][7] = 4;
        map1[2][8] = 4;
        wait(500);
        break;
    case'k':
        gotoXY(31, 10);
        cout << "������                 ";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "èè��Ȼ�ɰ������ʵ����Ҫ��";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�Һ����ƿ�Уè�����Ⱦ�Ҫ������ǰ�ɱ���";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "è����~";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "Ȼ��Уèȴ�������ģ��Ƶ���ǰ����ס���ҡ�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "������֣�˳�����ķ���һ���������ҵĵ綯��Կ�������ڵ��ϡ�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ң��ҵĵ綯��Կ�ס�������ô��������?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "���㶵ؿ���Уè����ݴ��в�����Ӱ��";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 5);
        cout << "  ";
        map1[2][3] = 1;
        gotoXY(31, 10);
        cout << "�����Ʒ:�綯��Կ��";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 20);
        cout << "�綯��Կ�ף�����մ�ż���èë��";
        map1[2][6] = 4;
        map1[2][7] = 4;
        map1[2][8] = 4;
        break;
    }
}

void viewme1(int x0, int y0, int x1, int y1)//ʵ���ҵ��ƶ�
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31+2*x0, 3+y0);//ϵ��2ʹ���ҡ�һ����һ������ƶ�����ʼ����ʹ�ù���ܵ����ҡ��ĳ�ʼ����
        cout << "  ";
        gotoXY(31 + 2 * x1, 3+y1);
        cout <<"��";
    }
}

void viewmeflo(int x0, int y0, int x1, int y1)//ʵ���ҵ��ƶ�
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//ϵ��2ʹ���ҡ�һ����һ������ƶ�����ʼ����ʹ�ù���ܵ����ҡ��ĳ�ʼ����
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "ݭ";
    }
}

//.............................................................................................
void chapter1b()
{
    yinru2();
    mapdraw2();
    int x0 = 0, y0 = 2, x1 = 0, y1 = 2, clue;//���ҡ��ĳ�ʼ�ڵ�ͼ�����λ�ã�������������汾������gotoxy�������꣩
    while (1)//ʵ���볡������ͬʱ��ֹ����
    {
        sidejudge(x1, y1);
        clue = cluejudge2(x1, y1);
        interact2(clue, x0, y0, x1, y1);

        x1 = x0;
        y1 = y0;
    }
}

void yinru2()
{
    system("cls");
    wait(500);
    gotoXY(0, 0);
    const char* str1 = "�����ϵ綯����һ·�ɳۣ�������7:59���﹫��¥��";
    const char* str2 = "�Ҹ�׼���Ӻ������ȥ��ȴ�������������˸�����ʦ��";
    printMessage(str1);
    wait(500);
    printMessage(str2);
    wait(1000);
    system("cls");
}
void mapdraw2()
{
    gotoXY(31, 3);
    cout << "  ǽ��ǽ��ǽ��ǽ";
    gotoXY(31, 4);
    cout << "  ǽ          ǽ";
    gotoXY(31, 5);
    cout << "  ��  ʦ      ��";//"��"(30,5)���������ɵ�
    gotoXY(31, 6);
    cout << "  ǽ          ǽ";
    gotoXY(31, 7);
    cout << "  ǽǽǽǽǽǽǽ";

}

int map2[5][8] = { 0,0,4,0,4,0,4,0,//x1=2,y1=3
                  0,0,1,1,1,1,1,0,
                  0,1,1,2,1,1,1,3,
                  0,0,1,1,1,1,1,0,
                  0,0,0,0,0,0,0,0 };

int cluejudge2(int x1, int y1)//�ж���һ��������ʲô
{
    int number = map2[y1][x1];
    return number;
}

void interact2(int number, int& x0, int& y0, int x1, int y1)//number��ǻ��������ڵ�ͼ�϶�Ӧ�����
{
    switch (number)
    {
    case 0:

        break;
    case 1:
        viewme2(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    case 2:
        gotoXY(31, 10);
        cout << "�ң���ʦ�á���";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "��Ȼ�����ˣ�����װû������?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ұ���΢Ц����ʦ�ʺã���ʦҲ�º͵س��ҵ��ͷ��";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "��ʦ����ȥ׼���Ͽΰɡ�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ҵ�ͷ�첽�������ߣ����ȴ���ʦ���෴�ķ����н�Զ��";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�����Ͽ��ˣ���ʦ����Ҫȥ�Ķ���";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 5);
        cout << "  ";
        map2[2][3] = 1;
    case 3:
        gotoXY(31, 10);
        cout << "���ƿ������ŵĽ����š�";
        wait(2000);
        clear(31, 10, 100, 4);
        end2();
    case 4:
        gotoXY(31, 10);
        cout << "·������ʱ��������䳯������һ�ۡ�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "��Ϊ�ߵü����ҿ���̫������ֻע�⵽�кö���վ�ڲݴ��С�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ң��������ڰ�ʲô���?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ң��Ȼ�����˿Σ���ȥ�����ɡ�";
        wait(2000);
        clear(31, 10, 100, 4);
    }
}

void end2()
{
    system("cls");
    cout << "�������ϣ��Ҳ��������������ҡ�" << endl;
    wait(2000);
    cout << "���������ϵ��ǣ������ﲢû��������һ����������������" << endl;
    wait(2000);
    cout << "�Ѳ����ҼǴ�α��ˣ�" << endl;
    wait(2000);
    cout << "�����ɻ��أ��Ϳ�Ⱥ������Ϣ:" << endl;
    wait(2000);
    cout << "֪ͨ����ʦ��ʱ������Ҫ�ذ칫��һ�ˣ���ͬѧ��������ϰ��" << endl;
    wait(2000);
    cout << "������һ������һƨ�����£���������ҳ��̲ġ�" << endl;
    wait(2000);
    cout << "��Ȼ����е㿲���������һ������ˡ�" << endl;
    wait(2000);
    cout << "�ţ���ôƽ������Ѱ����һ���š�" << endl;
    wait(2000);
    cout << "NORMAL END 1 ��æµ�Ĵ�ѧ����          �����С�����" << endl;
    wait(2000);
    chapter1a();

}

void viewme2(int x0, int y0, int x1, int y1)//ʵ���ҵ��ƶ�
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//ϵ��2ʹ���ҡ�һ����һ������ƶ�����ʼ����ʹ�ù���ܵ����ҡ��ĳ�ʼ����
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "��";
    }
}

//.............................................................................................
void chapter1c()
{
    yinru3();
    mapdraw3();
    int x0 = 0, y0 = 5, x1 = 0, y1 = 5, clue;//���ҡ��ĳ�ʼ�ڵ�ͼ�����λ�ã�������������汾������gotoxy�������꣩
    while (1)//ʵ���볡������ͬʱ��ֹ����
    {
        sidejudge(x1, y1);
        clue = cluejudge3(x1, y1);
        interact3(clue, x0, y0, x1, y1);

        x1 = x0;
        y1 = y0;
    }
}

void chapter1ca()
{
    system("cls");
    mapdraw3();
    int x0 = 0, y0 = 5, x1 = 0, y1 = 5, clue;//���ҡ��ĳ�ʼ�ڵ�ͼ�����λ�ã�������������汾������gotoxy�������꣩
    while (1)//ʵ���볡������ͬʱ��ֹ����
    {
        sidejudge(x1, y1);
        clue = cluejudge3(x1, y1);
        interact3(clue, x0, y0, x1, y1);

        x1 = x0;
        y1 = y0;
    }
}

void yinru3()
{
    system("cls");
    wait(500);
    gotoXY(0, 0);
    const char* str1 = "����ͷһ·�񱼣����ڵ��˹���¥ǰ��";
    const char* str2 = "����¥��������ڣ�";
    const char* str3 = "A�ڿ�����·��Ҳ�����ﳵ��ߵ�һ����";
    const char* str4 = "B��������һ��С·����Ȼ��᫣����ܽ�Լ����ʱ�䡣";
    const char* str5 = "������̫��û�߹�B�ڣ�";
    const char* str6 = "�����߽�¥�����Ҳŷ�������¥�ݿ�ǰ��֪��ʱ�����˻���";
    const char* str7 = "ֻ��������¥�ݿ�Ϊʲô�ᰤ����ô����";
    const char* str8 = "��ֱ��������Ϸ��ģ��һ����";
    const char* str9 = "��һ��ĬĬ�²ۣ�һ����ǰ�ߡ�";
    printMessage(str1);
    wait(500);
    printMessage(str2);
    wait(1000);
    printMessage(str3);
    wait(500);
    printMessage(str4);
    wait(500);
    printMessage(str5);
    wait(500);
    printMessage(str6);
    wait(500);
    printMessage(str7);
    wait(500);
    printMessage(str8);
    wait(500);
    printMessage(str9);
    wait(500);
    system("cls");
}

void mapdraw3()
{
    gotoXY(31, 3);
    cout << "            ǽ  ǽ              ";
    gotoXY(31, 4);
    cout << "            ǽ��ǽ              ";
    gotoXY(31, 5);
    cout << "            ǽ  ǽ              ";
    gotoXY(31, 6);
    cout << "  ǽǽ��ǽǽǽ��ǽǽǽǽǽ      ";//"��"(30,8)���������ɵ�
    gotoXY(31, 7);
    cout << "  ǽ                    ǽǽǽǽ";
    gotoXY(31, 8);
    cout << "  ��                    ��  ��  ";
    gotoXY(31, 9);
    cout << "  ǽ                    ǽǽǽǽ";
    gotoXY(31, 10);
    cout << "  ǽǽǽǽǽǽ��ǽǽǽǽǽ      ";
    gotoXY(31, 11);
    cout << "            ǽ  ǽ              ";
    gotoXY(31, 12);
    cout << "            ǽ��ǽ              ";
    gotoXY(31, 13);
    cout << "            ǽ  ǽ              ";

}

int map3[11][16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,2,0,0,0,3,0,0,0,0,0,0,0,0,
                    0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
                    0,1,1,1,1,1,1,1,1,1,1,1,3,0,0,0,
                    0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
                    0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int cluejudge3(int x1, int y1)//�ж���һ��������ʲô
{
    int number = map3[y1][x1];
    return number;
}

void interact3(int number, int& x0, int& y0, int x1, int y1)//number��ǻ��������ڵ�ͼ�϶�Ӧ�����
{
    switch (number)
    {
    case 0:

        break;
    case 1:
        viewme3(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    case 2:
       
        gotoXY(31, 16);
        cout << "�ң������ô��һ�澵��?";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "�ҳ��ɵ�ͣ���˽Ų�����������ȥ��";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(37, 6);
        cout << "��";
        gotoXY(31, 16);
        cout << "����֣�������ӳ�����ǡ�";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "�Ҳ����ٶ࿴���ӿ�Ų��뿪���������ľ��ӡ�";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "ֻ���ⳡ�����Һ��������������";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(37, 6);
        cout << "��";
        break;
    case 3:
        gotoXY(31, 16);
        cout << "�߽����ҷ���ǽ�ϵ���һ��������ʳΪ�족��ë���鷨��";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "˵����ʳ�������������һ�û���緹�ء�";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "�����е���ˡ�";
        wait(2000);
        clear(31, 16, 100, 4);
        system("cls");
        chapter1e();
        break;
    case 4:
        gotoXY(31, 16);
        cout << "�߽����ҷ���ǽ�ϵ���һ�������������񡱵Ĺ��ʻ���";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "�¸¸¡���";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "��Ϊ����¥����ѧУ���˹�����";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "û������������е��ǲ��١�";
        wait(2000);
        clear(31, 16, 100, 4);
        system("cls");
        chapter1d();
        break;
    case 5:
        gotoXY(31, 16);
        cout << "�߽����ҷ���ǽ�ϵ�������ƺ��������أ�����������д��ʲô��";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "�ڿڿڿڿڡ�";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "�Ȼ���Ҹ������ʷ�����ʲô�ɡ�";
        wait(2000);
        clear(31, 16, 100, 4);
        system("cls");
        chapter2a();
        break;
    }
}

void viewme3(int x0, int y0, int x1, int y1)//ʵ���ҵ��ƶ�
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//ϵ��2ʹ���ҡ�һ����һ������ƶ�����ʼ����ʹ�ù���ܵ����ҡ��ĳ�ʼ����
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "��";
    }
}

//.............................................................................................
void chapter1d()
{
    yinru4();
    mapdraw4();
    int x0 = 0, y0 = 2, x1 = 0, y1 = 2, clue;//���ҡ��ĳ�ʼ�ڵ�ͼ�����λ�ã�������������汾������gotoxy�������꣩
    while (1)//ʵ���볡������ͬʱ��ֹ����
    {
        sidejudge(x1, y1);
        clue = cluejudge4(x1, y1);
        interact4(clue, x0, y0, x1, y1);

        x1 = x0;
        y1 = y0;
    }
}

void yinru4()
{
    system("cls");
    wait(500);
    gotoXY(0, 0);
    const char* str1 = "�������ţ��ҷ����Ҳ�֪���ģ���Ȼ�����˺����롣";
    const char* str2 = "�Ҳ���Ҫȥ����������?";
    const char* str3 = "�죺�¸¸¡���?";
    const char* str4 = "�ҵ���������ȴ����һ����У����Ҳ��ɵ�һ����";
    const char* str5 = "����������������ȴ�����ҵ�˫�۱���˳��";
    const char* str6 = "�ҵ�ͷ����ˮ��һ�գ��ŷ��ֲ�֪Ϊ���ұ���ˡ���һֻ��?!";
    printMessage(str1);
    wait(500);
    printMessage(str2);
    wait(1000);
    printMessage(str3);
    wait(500);
    printMessage(str4);
    wait(500);
    printMessage(str5);
    wait(500);
    printMessage(str6);
    wait(500);
    system("cls");
}

void mapdraw4()
{
    gotoXY(31, 3);
    cout << "  ���������ݲݰ�";
    gotoXY(31, 4);
    cout << "  ��          ��";
    gotoXY(31, 5);
    cout << "  ��    ��    ��";//"��"(30,5)���������ɵ�
    gotoXY(31, 6);
    cout << "  ��          ��";
    gotoXY(31, 7);
    cout << "  �������ݲݰ���";
    gotoXY(31, 20);
    cout << "������";
}

int map4[5][8] = { 0,2,2,2,2,4,4,2,//x1=2,y1=3
                  0,2,1,1,1,1,1,2,
                  0,1,1,1,3,1,1,4,
                  0,2,1,1,1,1,1,2,
                  0,2,2,2,4,4,2,2 };

int cluejudge4(int x1, int y1)//�ж���һ��������ʲô
{
    int number = map4[y1][x1];
    return number;
}

void interact4(int number, int& x0, int& y0, int x1, int y1)//number��ǻ��������ڵ�ͼ�϶�Ӧ�����
{
    switch (number)
    {
    case 0:

        break;
    case 1:
        viewme4(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    case 2:
        gotoXY(31, 10);
        cout << "Ŭ���ε����ߣ���׼��ȥ���ϣ�ȴ�����ݴ������������ֵ�è������";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "���У����ܱ�èץס!";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�Զ���˵�����Ǻ��ﰲȫЩ��";
        wait(2000);
        clear(31, 10, 100, 4);
        break;
    case 3:
        gotoXY(31, 10);
        cout << "̫���ˣ���С�������ڿ�����Ϣһ����!";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�ڵ�����Ϣ��ʱ�򣬷���һ���������Ķ�����";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�����Ʒ:�ҵĵ綯��Կ��";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 20);
        cout << "�ҵĵ綯��Կ��(��֣���ô��������?)";
        map4[0][5] = 5;
        map4[0][6] = 5;
        map4[2][7] = 5;
        map4[4][4] = 5;
        map4[4][5] = 5;
        map4[2][4] = 0;
        break;
    case 4:
        gotoXY(31, 10);
        cout << "è:��~";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "���ã��ݴ������è!";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "ƽ�������Ҿ��ÿɰ�����������������ֻ�ö���ÿ��¡�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "����!";
        wait(2000);
        clear(31, 10, 100, 4);
        break;
    case 5:
        gotoXY(31, 10);
        cout << "Կ���ܲ��ܾ���ô��ˮ��ɡ�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�����Կ�ף�������ǰ�ζ����ѡ��Ƭ�ɾ��ݵأ���Կ�׶��ڲݴ��С�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 20);
        cout << "                                    ";
        gotoXY(31, 10);
        cout << "�죺�¸¸¸¸¡�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "�����֮�󣬵üǵ����á�";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "è:��~";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "���ã���è!";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "����!";
        wait(2000);
        clear(31, 10, 100, 4);
        end4();
        break;
    }
}

void end4()
{
    system("cls");
    cout << "�������ˮ����Ҫ��Ķ��ӣ�" << endl;
    wait(2000);
    cout << "һ˫����ȴ����������Ѷ챧��������" << endl;
    wait(2000);
    cout << "��Ȼ����ʦ��" << endl;
    wait(2000);
    cout << "��ʦ����Ȼ�ܵ�������ˡ���" << endl;
    wait(2000);
    cout << "���������������������˵��˭����" << endl;
    wait(2000);
    cout << "��ʦ�����bug�����޸�һ�¡�" << endl;
    wait(2000);
    cout << "��ʦ���Ŷ죬���Ͽ������г�������ȥ��" << endl;
    wait(2000);
    cout << "BAD END 3 ������          �����С�����" << endl;
    wait(2000);
    map3[3][7] = 5;
    map3[5][12] = 5;
    map3[7][7] = 5;
    chapter1ca();
}

void viewme4(int x0, int y0, int x1, int y1)//ʵ���ҵ��ƶ�
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//ϵ��2ʹ���ҡ�һ����һ������ƶ�����ʼ����ʹ�ù���ܵ����ҡ��ĳ�ʼ����
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "��";
    }
}

//.............................................................................................
void chapter1e()
{
    yinru5();
    mapdraw5();
    int x0 = 0, y0 = 2, x1 = 0, y1 = 2, clue;//���ҡ��ĳ�ʼ�ڵ�ͼ�����λ�ã�������������汾������gotoxy�������꣩
    while (1)//ʵ���볡������ͬʱ��ֹ����
    {
        sidejudge(x1, y1);
        clue = cluejudge5(x1, y1);
        interact5(clue, x0, y0, x1, y1);

        x1 = x0;
        y1 = y0;
    }
}

void yinru5()
{
    system("cls");
    wait(500);
    gotoXY(0, 0);
    const char* str1 = "�߽�¥�ݿڣ��Ҳ�֪Ϊ������һ�����Ƶ�С��������ȫ����������������Ӳݣ�С�����ݵ���һ����ͨ����";
    const char* str2 = "��ǰ��!ͬѧ����������վ��һ����ʧ�˻�һ��һ����������";
    printMessage(str1);
    wait(500);
    printMessage(str2);
    wait(500);
    system("cls");
    
    gotoXY(31, 10);
    cout << "һ�ִ�δ�й�����������������Ѹ�ٲ����������д̼��ĵ���������";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "�Ҷ�ʱ�о����ȵļ�������û���ң��Ҳ����������������ǡ�";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "�Ҿ���������ǰ�����ֳ�һ�����Ķ��������֡�";
    wait(2000);
    clear(31, 10, 100, 4);
    
}

void mapdraw5()
{
    
    gotoXY(31, 3);
    cout << "            �ݲݲ�                              ";
    gotoXY(31, 4);
    cout << "  �ݲݲݲݲݴӴӴӲ�        �ݲݲݲݲݲݲݲݲ�  ";
    gotoXY(31, 5);
    cout << "  ���ӴӴӴӴӲݴӴӲݲ�  �ݴӴӴӴӴӴӴӴӴ�  ";//"��"(30,5)���������ɵ�
    gotoXY(31, 6);
    cout << "  �ݲݲݲݲݲ�  �ݴӴӴӲݲݴӲݲݲݲݲݲݲݲ�  ";
    gotoXY(31, 7);
    cout << "                  �ݲݴӴӴӴӲ�                ";
    gotoXY(31, 8);
    cout << "                      �ݲݲݲ�                  ";

}

int map5[6][24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x1=2,y1=3
                  0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                  0,1,1,1,1,1,1,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,2,
                  0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int cluejudge5(int x1, int y1)//�ж���һ��������ʲô
{
    int number = map5[y1][x1];
    return number;
}

void interact5(int number, int& x0, int& y0, int x1, int y1)//number��ǻ��������ڵ�ͼ�϶�Ӧ�����
{
    switch (number)
    {
    case 0:

        break;
    case 1:
        viewme5(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    case 2:
        gotoXY(31, 10);
        cout << "�Ҳ���������������......";
        wait(2000);
        clear(31, 10, 100, 4);
        system("cls");
        end3();
    }
}

void end3()
{
    cout << "BAD END 2 ��У԰����          �����С�����";
    wait(2000);
    map3[3][7] = 4;
    map3[5][12] = 4;
    map3[7][7] = 4;
    chapter1ca();
}

void viewme5(int x0, int y0, int x1, int y1)//ʵ���ҵ��ƶ�
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//ϵ��2ʹ���ҡ�һ����һ������ƶ�����ʼ����ʹ�ù���ܵ����ҡ��ĳ�ʼ����
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "��";
    }
}

