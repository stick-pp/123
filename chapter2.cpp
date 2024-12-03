#include"chapter2.h"
#include"tool.h"
using namespace std;

void chapter2a()
{
    yinru6();
    mapdraw6();
    int x0 = 0, y0 = 2, x1 = 0, y1 = 2, clue;//“我”的初始在地图上相对位置（参数调整过后版本，并非gotoxy可用坐标）
    while (1)//实现与场景互动同时防止吃字
    {
        sidejudge(x1, y1);
        clue = cluejudge6(x1, y1);
        interact6(clue, x0, y0, x1, y1);

        x1 = x0;
        y1 = y0;
    }
}

void yinru6()
{
    system("cls");
    wait(500);
    gotoXY(0, 0);
    const char* str1 = "我突然来到一条只有行人的小路，路上都是赶课的大学生。";
    const char* str2 = "秋日的枫叶红黄在阳光下闪出奇异的金色。";
    printMessage(str1);
    wait(500);
    printMessage(str2);
    wait(500);
    system("cls");
}

void mapdraw6()
{
    gotoXY(31, 3);
    cout << "  马路牙子马路牙子马路牙子马路牙子马路牙子";
    gotoXY(31, 4);
    cout << "                叶";
    gotoXY(31, 5);
    cout << "  我";//"我"(30,5)，但参数可调
    gotoXY(31, 6);
    cout << "            猫                友        探寻之路";
    gotoXY(31, 8);
    cout << "                  路人";
    gotoXY(31, 10);
    cout << "  马路牙子马路牙子马路牙子马路牙子马路牙子";

}

int map6[9][24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
                    0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
                    0,1,1,1,1,1,3,1,1,1,1,1,1,1,1,5,1,1,1,1,6,6,6,6,
                    0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,
                    0,1,1,1,1,1,1,1,1,4,4,1,1,1,1,1,1,1,1,1,0,0,0,0,
                    0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0, 
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int cluejudge6(int x1, int y1)//判断下一步的字是什么
{
    int number = map6[y1][x1];
    return number;
}

void interact6(int number, int& x0, int& y0, int x1, int y1)//number标记互动对象在地图上对应的情况
{
    switch (number)
    {
    case 0:

        break;
    case 1:
        viewme6(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    case 2:
        gotoXY(31, 13);
        cout << "一片金黄的被风吹落的枫叶，真是好看呢。";
        wait(2000);
        clear(31, 13, 100, 4);
        break;
    case 3:
        gotoXY(31, 13);
        cout << "小猫发出喵呜喵呜的声音，我弯下腰摸了摸它。";
        wait(2000);
        clear(31, 13, 100, 4);
        break;
    case 4:
        gotoXY(31, 13);
        cout << "路人：快点！高数课要迟到了！！";
        wait(2000);
        clear(31, 13, 100, 4);
        break;
    case 5:
        friendinteraction();
        break;
    case 6:
        break;
    case 7:
        system("cls");
        chapter2b();
        break;
    }
}

void friendinteraction()
{
    gotoXY(31, 13);
    cout << "朋友低着头来来回回地迈着步子，似乎在思考着什么。";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "'哦！' 我看到了班级里的团支书，激动地叫了一声。";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "朋友听到了，抬起头跟我打招呼。";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "我：你怎么在这里？还不上课吗，高数课要迟到啦！";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "友：高数课怎么有我头脑中的疑惑重要？";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "我：什么疑惑？";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "友：我今早看见高数老师在湖边抱起一只鹅。";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "我：啊，什么？";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "友：老师近日这样奇怪的举动越来越多了，你有没有发现nk大学处处透露一丝诡异的气氛？";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "我：我之前也确实发现过一些奇怪的事，但没有放在心上罢了。";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "友：我发现公教楼4层办公室最近经常发生异常事件......";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "我：对了，高数老师的办公室就在4层，并且他从来不让我们去他的办公室。";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "友：我们何不从高数老师的办公室开启这段探索之旅？";
    wait(2000);
    clear(31, 13, 100, 4);
    gotoXY(31, 13);
    cout << "j：走吧     k：我想想";
    char friendchoose;
    cin >> friendchoose;
    switch (friendchoose)
    {
    case'j':
    {
        map6[3][20] = 1;
        map6[3][21] = 1;
        map6[3][22] = 1;
        map6[3][23] = 7;
        map6[3][15] = 0;
        break;
    }
    case'k':
    {
        gotoXY(31, 13);
        cout << "友：我还不知道你？你上高数课也是摸鱼。";
        wait(2000);
        clear(31, 13, 100, 4);
        gotoXY(31, 13);
        cout << "我：那去就去吧！";
        wait(2000);
        clear(31, 13, 100, 4);
        map6[3][20] = 1;
        map6[3][21] = 1;
        map6[3][22] = 1;
        map6[3][23] = 7;
        map6[3][15] = 0;
        break;
    }
    }
    wait(2000);
    clear(31, 13, 100, 4);
    
}

void viewme6(int x0, int y0, int x1, int y1)//实现我的移动
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//系数2使“我”一整格一整格地移动，初始参数使得光标能到“我”的初始坐标
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "我";
    }
}

//。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
void chapter2b()
{
    mapdraw7();
    int x0 = 0, y0 = 6, x1 = 0, y1 = 6, clue;//“我”的初始在地图上相对位置（参数调整过后版本，并非gotoxy可用坐标）
    while (1)//实现与场景互动同时防止吃字
    {
        sidejudge(x1, y1);
        clue = cluejudge7(x1, y1);
        interact7(clue, x0, y0, x1, y1);

        x1 = x0;
        y1 = y0;
    }
}

void mapdraw7()
{
    gotoXY(31, 3);
    cout << "                墙墙墙墙";
    gotoXY(31, 4);
    cout << "                墙按钮墙";
    gotoXY(31, 5);
    cout << "                墙    墙";
    gotoXY(31, 6);
    cout << "  墙墙墙墙墙墙墙墙油画墙墙墙墙";//"从"(30,9)，但参数可调
    gotoXY(31, 7);
    cout << "  墙  桌电桌脑桌        柜柜墙";
    gotoXY(31, 8);
    cout << "  墙  桌  桌  桌        书柜墙";
    gotoXY(31, 9);
    cout << "  从      桌            書柜墙";
    gotoXY(31, 10);
    cout << "  门                    柜柜墙";
    gotoXY(31, 11);
    cout << "  墙相            椅        墙";
    gotoXY(31, 12);
    cout << "  墙片                      墙";
    gotoXY(31, 13);
    cout << "  墙      白板              墙";
    gotoXY(31, 14);
    cout << "  墙墙墙窗墙墙墙墙墙墙窗墙墙墙";
    gotoXY(31, 22);
    cout << "背包：";
}

int map7[12][15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,
                    0,0,1,0,6,0,6,0,1,1,1,1,0,0,0,
                    0,0,1,13,1,9,1,15,1,1,1,1,7,0,0,
                    0,1,1,1,1,0,1,1,1,1,1,1,11,0,0,
                    0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,
                    0,0,3,1,1,1,1,1,1,0,1,1,1,1,0,
                    0,0,3,1,1,1,1,1,1,1,1,1,1,1,0,
                    0,0,1,1,1,4,4,1,1,1,1,1,1,1,0,
                    0,0,0,0,5,0,0,0,0,0,0,5,0,0,0};//x1=1,y1=6

int cluejudge7(int x1, int y1)//判断下一步的字是什么
{
    int number = map7[y1][x1];
    return number;
}

void interact7(int number, int& x0, int& y0, int x1, int y1)//number标记互动对象在地图上对应的情况
{
    switch (number)
    {
    case 0:

        break;
    case 1:
        viewme7(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    case 2:
        gotoXY(31, 17);
        cout << "我们按下按钮。";
        wait(2000);
        clear(31, 17, 100, 4);
        animation();
        break;
    case 3:
        gotoXY(31, 17);
        cout << "老师抱着我宿舍门口的那只猫的合影，nk的秋天可真美啊。";
        wait(2000);
        clear(31, 17, 100, 4);
        break;
    case 4:
        gotoXY(31, 17);
        cout << "上面有老师用泰勒展开做题的笔迹。";
        wait(2000);
        clear(31, 17, 100, 4);
        gotoXY(31, 17);
        cout << "我：真没想到逃课了还要碰到高数题！！";
        wait(2000);
        clear(31, 17, 100, 4);
        break;
    case 5:
        gotoXY(31, 17);
        cout << "开窗可以看到平静无波的新开湖，几只大白鹅游过。";
        wait(2000);
        clear(31, 17, 100, 4);
        break;
    case 6:
        gotoXY(31, 17);
        cout << "老师的壁纸是世界末日主题电影的海报，奇奇怪怪;更奇怪的是键盘旁还有一根漂亮的鹅毛。";
        wait(2000);
        clear(31, 17, 100, 4);
        break;
    case 7:
        gotoXY(31, 17);
        cout << "高深的数学书。。。";
        wait(2000);
        clear(31, 17, 100, 4);
        break;
    case 8:
        gotoXY(31, 17);
        cout << "一幅好看的风景画，色彩浓艳。";
        wait(2000);
        clear(31, 17, 100, 4);
        break;
    case 9:
        gotoXY(31, 17);
        cout << "桌子下的抽屉有些松动，朋友轻轻地打开它。";
        wait(2000);
        clear(31, 17, 100, 4);
        gotoXY(31, 17);
        cout << "一只眼镜安静地躺在那里。";
        wait(2000);
        clear(31, 17, 100, 4);
        gotoXY(31, 17);
        cout << "这是一只暗金色的玳瑁眼镜，看的出来有点年头了，但老师把它保护的很好，镜腿在灯下发出暗暗幽光。";
        wait(2000);
        clear(31, 17, 100, 4);
        gotoXY(31, 17);
        cout << "j：戴上它。           k：不戴上它，把抽屉合上。";
        char choose1;
        cin >> choose1;
        switch (choose1)
        {
        case'j':
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "朋友：按照科幻电影的套路，戴上它会有新的世界在我面前！";
            wait(2000);
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "我戴上了眼镜。";
            wait(2000);
            clear(31, 17, 100, 4);
            map7[3][9] = 10;
            map7[3][10] = 10;
            map7[5][5] = 0;
            break;
        case'k':
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "我：继续探索别的地方。";
            wait(2000);
            clear(31, 17, 100, 4);
            break;
        
        }
        break;
    case 10:
        gotoXY(31, 17);
        cout << "油画上原来密密麻麻有着电路芯片般的条纹图案。";
        wait(2000);
        clear(31, 17, 100, 4);
        gotoXY(31, 17);
        cout << "我暗中感觉到这画的背后隐藏着关于世界的秘密，但它密不透风。";
        wait(2000);
        clear(31, 17, 100, 4);
        gotoXY(31, 17);
        cout << "我又只得在办公室里继续寻找。";
        wait(2000);
        clear(31, 17, 100, 4);
        break;
    case 11:
        gotoXY(31, 17);
        cout << "j：拿出书。";
        char choose3;
        cin >> choose3;
        switch (choose3)
        {
        case'j':
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "办公室里好像响了一声。";
            wait(2000);
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "我：这奇怪的声音好像发出在油画的那面墙上。";
            wait(2000);
            clear(31, 17, 100, 4);
            map7[6][12] = 12;
            map7[3][9] = 14;
            map7[3][10] = 14;
            break;
        }
        break;
    case 12:
        gotoXY(31, 17);
        cout << "j：把书重新放回书架。";
        char choose;
        cin >> choose;
        switch (choose)
        {
        case'j':
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "办公室里好像又响了一声。";
            wait(2000);
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "我：这奇怪的声音好像发出在油画的那面墙上。";
            wait(2000);
            clear(31, 17, 100, 4);
            map7[6][12] = 11;
            break;
        }
        break;
    case 13:
        gotoXY(31, 17);
        cout << "我一不小心碰掉了老师桌上的一支笔，捡起来，却发现它格外的沉。";
        wait(2000);
        clear(31, 17, 100, 4);
        gotoXY(31, 17);
        cout << "j：拿着它探索。            k：把它放回桌上。";
        char choose2;
        cin >> choose2;
        switch (choose2)
        {
        case'j':
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "获得物品：笔";
            wait(2000);
            clear(31, 17, 100, 4);
            gotoXY(37, 22);
            cout << "笔（有点沉的笔，笔尖的形状很奇怪）";
            map7[5][3] = 0;
            monitor = 1;
            break;
        case'k':
            break;
        
        }
        break;
    case 14:
        if (monitor == 0)
        {
            gotoXY(31, 17);
            cout << "看见画的右上角有一个孔，隐隐地发出幽光。";
            wait(2000);
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "伸出手摸了摸，这好像是一个钥匙口，那么用什么来打开呢？";
            wait(2000);
            clear(31, 17, 100, 4);
        }
        if (monitor == 1)
        {
            gotoXY(31, 17);
            cout << "看见画的右上角有一个孔，隐隐地发出幽光。";
            wait(2000);
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "我试着用笔插入孔中，意外的是竟然适配。";
            wait(2000);
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "轻轻扭动笔杆，墙壁内传来阵阵机械传动声，";
            wait(2000);
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "轰隆隆——";
            wait(2000);
            clear(31, 17, 100, 4);
            gotoXY(31, 17);
            cout << "一个暗室出现在我们面前。";
            wait(2000);
            clear(31, 17, 100, 4);
            map7[3][9] = 1;
            map7[3][10] = 1;
            gotoXY(49, 6);
            cout << "    ";
        }
        break;
    case 15:
        gotoXY(31, 17);
        cout << "老师的桌子上有一本牛皮封的日记本:";
        wait(2000);
        clear(31, 17, 100, 4);
        gotoXY(31, 17);
        cout << "我和朋友翻开它：";
        wait(2000);
        clear(31, 17, 100, 4);
        gotoXY(31, 17);
        cout << "上面的笔迹看起来完全不像出自同一人之手，随着时间流逝，笔迹不断变换，之前的笔迹也不再有过了......";
        wait(2000);
        clear(31, 17, 100, 4);
        break;
    }
}

int monitor = 0;//检测笔

void animation()
{
    gotoXY(31, 7);
    cout << "  墙  桌电    桌        柜柜墙";
    gotoXY(31, 5);
    cout << "                        ";
    gotoXY(31, 12);
    cout << "                            墙";
    gotoXY(31, 14);
    cout << "  墙墙墙    墙墙墙  墙窗  墙墙";
    wait(100);
    gotoXY(31, 7);
    cout << "  墙  桌      桌          柜  ";
    gotoXY(31, 6);
    cout << "  墙墙    墙墙墙墙油画墙    墙";
    gotoXY(31, 3);
    cout << "                  墙  墙";
    wait(100);
    gotoXY(31, 8);
    cout << "  墙      桌                墙";
    gotoXY(31, 13);
    cout << "          白                  ";
    gotoXY(31, 6);
    cout << "  墙墙    墙    墙    墙    墙";
    wait(100);
    gotoXY(31, 3);
    cout << "                        ";
    gotoXY(31, 4);
    cout << "                墙按    ";
    gotoXY(31, 9);
    cout << "                        書    ";
    gotoXY(31, 10);
    cout << "  门                    柜    ";
    gotoXY(31, 11);
    cout << "                  椅        墙";
    gotoXY(31, 6);
    cout << "          墙    墙          墙";
    gotoXY(31, 14);
    cout << "      墙    墙墙墙        墙墙";
    wait(100);
    gotoXY(31, 4);
    cout << "                        ";
    gotoXY(31, 7);
    cout << "      桌                      ";
    gotoXY(31, 14);
    cout << "      墙                  墙  ";
    gotoXY(31, 11);
    cout << "                              ";
    gotoXY(31, 8);
    cout << "                              ";
    wait(50);
    system("cls");
    wait(1000);
    trueend();
    
}

void viewme7(int x0, int y0, int x1, int y1)//实现我的移动
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//系数2使“我”一整格一整格地移动，初始参数使得光标能到“我”的初始坐标
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "从";
    }
}

//.............................................................................................................

void trueend()
{
    gotoXY(31, 10);
    cout << "从";
    gotoXY(31, 5);
    cout << "祝贺你们通过考验，发现世界的真相。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 5);
    cout << "你们可以选择留在这里继续完善这个世界，也可以选择遗忘这一切，回归普通的生活。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 15);
    cout << "友：所以我们真的生活在虚拟数据世界之中？";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 5);
    cout << "是的。因为这个世界还在试验当中，出现bug也是难免。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 15);
    cout << "我想起了无端消失的电动车钥匙，公教楼三个紧挨着的楼梯口……";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 15);
    cout << "友：那我们还能回到现实世界吗？";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 5);
    cout << "如果你愿意相信，那么哪里都是现实；如果你不愿意相信，那么哪里都是虚拟。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 15);
    cout << "友：……";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 15);
    cout << "言外之意就是，我们只能接受无法回到现实世界这个事实。";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 5);
    cout << "你们可以选择留在这里继续完善这个世界，也可以选择遗忘这一切，回归普通的生活。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 5);
    cout << "字幕又不依不饶地重复了一遍，似乎是在催促我们做出选择。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 15);
    cout << "我：为什么说这个世界还只是一个试验，做这个试验的目的又是什么？";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 5);
    cout << "字幕停顿良久。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 5);
    cout << "为了延续人类文明的火种。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 5);
    cout << "天文学家观测到，约200年后，太阳会爆发巨大的辐射，碳基生物将难以生存。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 5);
    cout << "所以一边派出宇航员寻找新的栖居地，一边尝试将人类意识数据化，以此来保存文明形态。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 5);
    cout << "但因为技术还不成熟，所以目前只是分板块、小规模地模拟校园、社区这些相对封闭的环境。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 15);
    cout << "这次，轮到我和朋友沉默了。";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 15);
    cout << "友：“留在这里”是什么意思？";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 5);
    cout << "你们通过了解谜考验，说明你们有能力发现世界运行时产生的不合理漏洞。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 5);
    cout << "不过如果选择留在这里，那关于你的一切将会被世界清除。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 15);
    cout << "清除……就像从未存在过。";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 5);
    cout << "你们可以选择留在这里继续完善这个世界，也可以选择遗忘这一切，回归普通的生活。";
    wait(2000);
    clear(31, 5, 100, 4);
    gotoXY(31, 15);
    cout << "是时候做出选择了。";
    wait(2000);
    clear(31, 15, 100, 4);
    gotoXY(31, 13);
    cout << "j：留下来     k：走出去";
    char finchoose;
    cin >> finchoose;
    switch (finchoose)
    {
    case'j':
    {
        system("cls");
        gotoXY(31, 10);
        cout << "我";
        gotoXY(31, 15);
        cout << "我选择了留下，而朋友选择了离开。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "离开前，朋友忽然转身看着我。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "友：我会一直记得你的。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我还没来得及回应朋友，就见朋友消失在一片0和1组成的乱流中。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "现在只剩下我一个人处在黑暗中，我反而轻松地笑了笑。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我：说吧，需要我扮演什么？";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我：校猫，高数老师，还是一朵落花？";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 5);
        cout << "你很聪明。";
        wait(2000);
        clear(31, 5, 100, 4);
        gotoXY(31, 5);
        cout << "既然你知道自己要做什么了，那就期待你的表现吧。";
        wait(2000);
        clear(31, 5, 100, 4);
        gotoXY(31, 10);
        cout << "  ";
        gotoXY(31, 15);
        cout << "我重构了公教楼，把那三个楼道分散开。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我在“口口口口口”那幅画上，填好了一句五言。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我来到那面镜子面前，把映出的影像复原。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我捡起一地落花，重现花开时的灿烂。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "……";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我为每个还在熟睡中的大学生，调好了闹钟。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我：早八，可不能迟到啊。";
        wait(2000);
        clear(31, 15, 100, 4);
        system("cls");
        gotoXY(31, 15);
        cout << "TRUE END 1  新世界";
        wait(2000);
        clear(31, 15, 100, 4);
        

        break;
    }
    case'k':
    {
        system("cls");
        gotoXY(31, 10);
        cout << "我";
        gotoXY(31, 15);
        cout << "我选择了离开，而朋友选择了留下。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我最后看了朋友一眼，朋友注意到我的目光，对我笑了笑。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "友：再会。";
        wait(2000);
        clear(31, 15, 100, 4);
        gotoXY(31, 15);
        cout << "我还没来得及说什么，就被一片0和1组成的乱流裹挟，失去了知觉。";
        wait(2000);
        system("cls");
        gotoXY(31, 15);
        cout << "再醒来，是被闹钟吵醒的。";
        wait(2000);
        gotoXY(31, 15);
        cout << "7：40";
        wait(2000);
        gotoXY(31, 15);
        cout << "幸好昨晚设了闹钟……嗯？我昨晚设过闹钟吗？";
        wait(2000);
        gotoXY(31, 15);
        cout << "我不再细想，打着哈欠按掉闹铃，眼皮沉沉地起床。";
        wait(2000);
        gotoXY(31, 15);
        cout << "悠哉游哉地收拾好书包，去食堂买了早饭。";
        wait(2000);
        gotoXY(31, 15);
        cout << "我骑上电动车，一边往公教楼赶，一边欣赏道路两旁开得灿烂的花。";
        wait(2000);
        gotoXY(31, 15);
        cout << "高数课下课，一起上课的同学拉住我，";
        wait(2000);
        gotoXY(31, 15);
        cout << "同学：听说B口那边重新装修过了，要一起去看看吗？";
        wait(2000);
        gotoXY(31, 15);
        cout << "‘处处闻啼鸟’";
        wait(2000);
        gotoXY(31, 15);
        cout << "‘民以食为天’";
        wait(2000);
        gotoXY(31, 15);
        cout << "我跟在同学身后，一起走过两个楼梯口。";
        wait(2000);
        gotoXY(31, 15);
        cout << "我在最后一个楼梯口前停住了脚步。";
        wait(2000);
        gotoXY(31, 15);
        cout << "‘空山不见人’";
        wait(2000);
        gotoXY(31, 15);
        cout << "我瞥向一旁干净明亮的镜子，映出我和同学的侧影。";
        wait(2000);
        gotoXY(31, 15);
        cout << "有种茫然的熟悉感。";
        wait(2000);
        gotoXY(31, 15);
        cout << "我：我好像忘了什么重要的事情。";
        wait(2000);
        gotoXY(31, 15);
        cout << "我：或许是在梦里。";
        wait(2500);
        gotoXY(31, 15);
        cout << "出了公教楼，我看着明朗的晴天。";
        wait(2000);
        gotoXY(31, 15);
        cout << "风吹过我的耳畔，给我一个轻柔的拥抱。";
        wait(2000);
        gotoXY(31, 15);
        cout << "多么平凡而又寻常的一天。";
        wait(2000);
        gotoXY(31, 15);
        cout << "TRUE END 2 终于。。。能好好上课了";
        wait(2000);
        break;
    }
    }
    
}