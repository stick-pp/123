#include"chapter1.h"
#include"tool.h"
#include"chapter2.h"

void chapter1a()
{
    yinru1();
    wait(1000);
    mapdraw1();
    int x0 = 0, y0 = 2, x1 = 0, y1 = 2, clue;//“我”的初始在地图上相对位置（参数调整过后版本，并非gotoxy可用坐标）
    while (1)//实现与场景互动同时防止吃字
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
    cout << "草草花草草草草";
    gotoXY(31, 4);
    cout << "  草        草";
    gotoXY(31, 5);
    cout << "  我  猫    电动车";//"我"(30,5)，但参数可调
    gotoXY(31, 6);
    cout << "  草        草";
    gotoXY(31, 7);
    cout << "草草草草草草草";
    gotoXY(31, 20);
    cout << "背包：";
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
    const char* str1 = "收拾好书包，我三步并做两步，急匆匆出了寝室门。";
    const char* str2 = "抬眼望去，道路两旁的草郁郁葱葱地疯长。";
    const char* str3 = "我：这条路之前有这么窄吗?";
    const char* str4 = "我没细想，我现在只想快点找到我的电动车。";
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


int cluejudge1(int x1, int y1)//判断下一步的字是什么
{
    int number = map1[y1][x1];
    return number;
}

void interact1(int number, int& x0, int& y0, int x1, int y1)//number标记互动对象在地图上对应的情况
{
    switch (number)
    {
    case 0://墙

        break;
    case 1://我可走的地方
        viewme1(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    case 2://猫
        catinteraction();
        wait(2000);
        break;
    case 3://未与猫互动的情况下与电动车互动
        gotoXY(31, 10);
        cout << "一辆电动车，有种熟悉的感觉。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "似乎需要钥匙才能启动。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我：怎么回事?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我：我的电动车钥匙去哪儿了?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "没办法了，我一咬牙一闭眼，拔腿就奔向教室的方向。";
        wait(2000);
        clear(31, 10, 100, 4);
        wait(500);
        system("cls");
        chapter1c();
        break;
    case 4://摸摸情况下与电动车互动
        chapter1b();
        break;
    case 5://与花互动
        gotoXY(31, 10);
        cout << "昨夜雨疏风骤，满地落花残红。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我脑子里一闪而过两种选择:";
        wait(2000);
        clearLine(31, 10);
        gotoXY(31, 10);
        cout << "选项提示：打出字母后按回车";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "j：捡起     k：不捡";
        char flowerchoose;
        cin >> flowerchoose;
        switch (flowerchoose)
        {
        case'j':
        {
            int p, q;//变字
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
            cout << "获得物品：落花";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(37, 21);
            cout << "落花（送你一朵小红花，开在昨天新长的枝桠…）";
            gotoXY(35, 3);
            cout << "化";
            gotoXY(31, 10);
            cout << "耳边隐隐响起温柔的歌声。";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(31, 10);
            cout << "手里的花是湿漉漉的。";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(31, 10);
            cout << "我的心忽然也变得湿漉漉的。";
            wait(2000);
            clear(31, 10, 100, 4);
            map1[0][2] = 0;
            break;
        }
        case'k':
            wait(500);
            clear(31, 10, 100, 4);
            gotoXY(35, 3);
            cout << "化";
            gotoXY(31, 10);
            cout << "落红不是无情物，化作春泥更护花。";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(31, 10);
            cout << "就让它们化在泥土中，明年又是新的灿烂。";
            wait(2000);
            clear(31, 10, 100, 4);
            gotoXY(31, 10);
            cout << "我最后看了那落花一眼，又急急朝前赶路。";
            wait(2000);
            clear(31, 10, 100, 4);
            map1[0][2] = 0;
            break;
        }
        break;
    case 6://莪可以走的地方
        viewmeflo(x0, y0, x1, y1);
        x0 = x1;
        y0 = y1;
        break;
    }
}

void catinteraction()
{
    gotoXY(31, 10);
    cout << "校猫蹲坐在道路中央，舔舔爪子朝我“喵”了一声。";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "摆在我面前的是两个选择:";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "选项提示：打出字母后按回车";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "摸摸：j     不摸摸：k          ";
    wait(2000);
    clear(31, 10, 100, 4);
    char catchoose;
    cin >> catchoose;
    switch (catchoose)
    {
    case'j':
        gotoXY(31, 10);
        cout << "早八虽然重要，猫猫实在可爱。                   ";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我蹲下身，伸手刚要撸猫...";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "猫猫却一甩尾巴跑掉了。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 5);
        cout << "  ";
        map1[2][3] = 1;
        gotoXY(31, 10);
        cout << "我：怎么回事?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我愣愣地看着校猫钻进草丛中不见身影。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "原地却留下一串车钥匙。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我：我的电动车钥匙………怎么会在这里?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "获得物品:电动车钥匙";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 20);
        cout << "电动车钥匙（上面沾着几缕猫毛）";
        map1[2][6] = 4;
        map1[2][7] = 4;
        map1[2][8] = 4;
        wait(500);
        break;
    case'k':
        gotoXY(31, 10);
        cout << "不摸摸                 ";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "猫猫虽然可爱，早八实在重要。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我含泪绕开校猫，拔腿就要继续向前飞奔。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "猫：喵~";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "然而校猫却不依不饶，绕到我前面拦住了我。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我正奇怪，顺着它的方向一看，发现我的电动车钥匙正躺在地上。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我：我的电动车钥匙………怎么会在这里?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我愣愣地看着校猫钻进草丛中不见身影。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 5);
        cout << "  ";
        map1[2][3] = 1;
        gotoXY(31, 10);
        cout << "获得物品:电动车钥匙";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 20);
        cout << "电动车钥匙（上面沾着几缕猫毛）";
        map1[2][6] = 4;
        map1[2][7] = 4;
        map1[2][8] = 4;
        break;
    }
}

void viewme1(int x0, int y0, int x1, int y1)//实现我的移动
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31+2*x0, 3+y0);//系数2使“我”一整格一整格地移动，初始参数使得光标能到“我”的初始坐标
        cout << "  ";
        gotoXY(31 + 2 * x1, 3+y1);
        cout <<"我";
    }
}

void viewmeflo(int x0, int y0, int x1, int y1)//实现我的移动
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//系数2使“我”一整格一整格地移动，初始参数使得光标能到“我”的初始坐标
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "莪";
    }
}

//.............................................................................................
void chapter1b()
{
    yinru2();
    mapdraw2();
    int x0 = 0, y0 = 2, x1 = 0, y1 = 2, clue;//“我”的初始在地图上相对位置（参数调整过后版本，并非gotoxy可用坐标）
    while (1)//实现与场景互动同时防止吃字
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
    const char* str1 = "我骑上电动车，一路飞驰，总算在7:59到达公教楼。";
    const char* str2 = "我刚准备从后门溜进去，却在走廊上碰见了高数老师。";
    printMessage(str1);
    wait(500);
    printMessage(str2);
    wait(1000);
    system("cls");
}
void mapdraw2()
{
    gotoXY(31, 3);
    cout << "  墙窗墙窗墙窗墙";
    gotoXY(31, 4);
    cout << "  墙          墙";
    gotoXY(31, 5);
    cout << "  我  师      门";//"我"(30,5)，但参数可调
    gotoXY(31, 6);
    cout << "  墙          墙";
    gotoXY(31, 7);
    cout << "  墙墙墙墙墙墙墙";

}

int map2[5][8] = { 0,0,4,0,4,0,4,0,//x1=2,y1=3
                  0,0,1,1,1,1,1,0,
                  0,1,1,2,1,1,1,3,
                  0,0,1,1,1,1,1,0,
                  0,0,0,0,0,0,0,0 };

int cluejudge2(int x1, int y1)//判断下一步的字是什么
{
    int number = map2[y1][x1];
    return number;
}

void interact2(int number, int& x0, int& y0, int x1, int y1)//number标记互动对象在地图上对应的情况
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
        cout << "我：老师好——";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "既然碰上了，还能装没看见吗?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我保持微笑向老师问好，老师也温和地冲我点点头。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "老师：快去准备上课吧。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我低头快步往教室走，余光却瞟到老师朝相反的方向渐行渐远。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "都快上课了，老师这是要去哪儿？";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 5);
        cout << "  ";
        map2[2][3] = 1;
    case 3:
        gotoXY(31, 10);
        cout << "我推开虚掩着的教室门。";
        wait(2000);
        clear(31, 10, 100, 4);
        end2();
    case 4:
        gotoXY(31, 10);
        cout << "路过窗户时，我无意间朝外望了一眼。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "因为走得急，我看不太分明，只注意到有好多人站在草丛中。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我：外面是在办什么活动吗?";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "我：等会儿下了课，再去看看吧。";
        wait(2000);
        clear(31, 10, 100, 4);
    }
}

void end2()
{
    system("cls");
    cout << "紧赶慢赶，我踩着铃声奔进教室。" << endl;
    wait(2000);
    cout << "出乎我意料的是，教室里并没有像往常一样坐得满满当当。" << endl;
    wait(2000);
    cout << "难不成我记错课表了？" << endl;
    wait(2000);
    cout << "我正疑惑呢，就看群里有消息:" << endl;
    wait(2000);
    cout << "通知：老师临时有事需要回办公室一趟，请同学们先上自习。" << endl;
    wait(2000);
    cout << "我松了一口气，一屁股坐下，从书包里找出教材。" << endl;
    wait(2000);
    cout << "虽然早八有点坎坷，不过我还算走运。" << endl;
    wait(2000);
    cout << "嗯，多么平凡而又寻常的一天呐。" << endl;
    wait(2000);
    cout << "NORMAL END 1 ：忙碌的大学生活          回溯中。。。" << endl;
    wait(2000);
    chapter1a();

}

void viewme2(int x0, int y0, int x1, int y1)//实现我的移动
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//系数2使“我”一整格一整格地移动，初始参数使得光标能到“我”的初始坐标
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "我";
    }
}

//.............................................................................................
void chapter1c()
{
    yinru3();
    mapdraw3();
    int x0 = 0, y0 = 5, x1 = 0, y1 = 5, clue;//“我”的初始在地图上相对位置（参数调整过后版本，并非gotoxy可用坐标）
    while (1)//实现与场景互动同时防止吃字
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
    int x0 = 0, y0 = 5, x1 = 0, y1 = 5, clue;//“我”的初始在地图上相对位置（参数调整过后版本，并非gotoxy可用坐标）
    while (1)//实现与场景互动同时防止吃字
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
    const char* str1 = "我闷头一路狂奔，终于到了公教楼前。";
    const char* str2 = "公教楼有两个入口：";
    const char* str3 = "A口靠近马路，也是我骑车最常走的一条。";
    const char* str4 = "B口则连着一条小路，虽然崎岖，但能节约不少时间。";
    const char* str5 = "或许是太久没走过B口，";
    const char* str6 = "当我走进楼道，我才发现三个楼梯口前不知何时挂上了画。";
    const char* str7 = "只是这三个楼梯口为什么会挨得这么近？";
    const char* str8 = "简直就像是游戏穿模了一样。";
    const char* str9 = "我一边默默吐槽，一边往前走。";
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
    cout << "            墙  墙              ";
    gotoXY(31, 4);
    cout << "            墙梯墙              ";
    gotoXY(31, 5);
    cout << "            墙  墙              ";
    gotoXY(31, 6);
    cout << "  墙墙镜墙墙墙画墙墙墙墙墙      ";//"我"(30,8)，但参数可调
    gotoXY(31, 7);
    cout << "  墙                    墙墙墙墙";
    gotoXY(31, 8);
    cout << "  我                    画  梯  ";
    gotoXY(31, 9);
    cout << "  墙                    墙墙墙墙";
    gotoXY(31, 10);
    cout << "  墙墙墙墙墙墙画墙墙墙墙墙      ";
    gotoXY(31, 11);
    cout << "            墙  墙              ";
    gotoXY(31, 12);
    cout << "            墙梯墙              ";
    gotoXY(31, 13);
    cout << "            墙  墙              ";

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

int cluejudge3(int x1, int y1)//判断下一步的字是什么
{
    int number = map3[y1][x1];
    return number;
}

void interact3(int number, int& x0, int& y0, int x1, int y1)//number标记互动对象在地图上对应的情况
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
        cout << "我：这儿怎么有一面镜子?";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "我迟疑地停下了脚步，朝镜中望去。";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(37, 6);
        cout << "你";
        gotoXY(31, 16);
        cout << "好奇怪，镜子里映出的是…";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "我不敢再多看，加快脚步离开了那面诡异的镜子。";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "只是这场景，我好像在哪里见过。";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(37, 6);
        cout << "镜";
        break;
    case 3:
        gotoXY(31, 16);
        cout << "走近后，我发现墙上的是一幅“民以食为天”的毛笔书法。";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "说到“食”，我想起来我还没吃早饭呢。";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "……有点饿了。";
        wait(2000);
        clear(31, 16, 100, 4);
        system("cls");
        chapter1e();
        break;
    case 4:
        gotoXY(31, 16);
        cout << "走近后，我发现墙上的是一幅“处处闻啼鸟”的工笔花鸟。";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "嘎嘎嘎——";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "因为公教楼靠近学校的人工湖，";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "没听到鸟鸣，鹅叫倒是不少。";
        wait(2000);
        clear(31, 16, 100, 4);
        system("cls");
        chapter1d();
        break;
    case 5:
        gotoXY(31, 16);
        cout << "走近后，我发现墙上的这幅画似乎是损坏严重，看不清上面写了什么。";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "口口口口口。";
        wait(2000);
        clear(31, 16, 100, 4);
        gotoXY(31, 16);
        cout << "等会儿找个人问问发生了什么吧。";
        wait(2000);
        clear(31, 16, 100, 4);
        system("cls");
        chapter2a();
        break;
    }
}

void viewme3(int x0, int y0, int x1, int y1)//实现我的移动
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//系数2使“我”一整格一整格地移动，初始参数使得光标能到“我”的初始坐标
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "我";
    }
}

//.............................................................................................
void chapter1d()
{
    yinru4();
    mapdraw4();
    int x0 = 0, y0 = 2, x1 = 0, y1 = 2, clue;//“我”的初始在地图上相对位置（参数调整过后版本，并非gotoxy可用坐标）
    while (1)//实现与场景互动同时防止吃字
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
    const char* str1 = "走着走着，我发现我不知怎的，竟然来到了湖中央。";
    const char* str2 = "我不是要去高数教室吗?";
    const char* str3 = "鹅：嘎嘎嘎…噶?";
    const char* str4 = "我的自言自语却化作一串鹅叫，让我不由得一惊。";
    const char* str5 = "我伸手想摸摸脸，却发现我的双臂变成了翅膀。";
    const char* str6 = "我低头往湖水中一照，才发现不知为何我变成了——一只鹅?!";
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
    cout << "  岸岸岸岸草草岸";
    gotoXY(31, 4);
    cout << "  岸          岸";
    gotoXY(31, 5);
    cout << "  鹅    岛    草";//"我"(30,5)，但参数可调
    gotoXY(31, 6);
    cout << "  岸          岸";
    gotoXY(31, 7);
    cout << "  岸岸岸草草岸岸";
    gotoXY(31, 20);
    cout << "背包：";
}

int map4[5][8] = { 0,2,2,2,2,4,4,2,//x1=2,y1=3
                  0,2,1,1,1,1,1,2,
                  0,1,1,1,3,1,1,4,
                  0,2,1,1,1,1,1,2,
                  0,2,2,2,4,4,2,2 };

int cluejudge4(int x1, int y1)//判断下一步的字是什么
{
    int number = map4[y1][x1];
    return number;
}

void interact4(int number, int& x0, int& y0, int x1, int y1)//number标记互动对象在地图上对应的情况
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
        cout << "努力游到岸边，刚准备去岸上，却听到草从中有若隐若现的猫叫声。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "不行，不能被猫抓住!";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "对鹅来说，还是湖里安全些。";
        wait(2000);
        clear(31, 10, 100, 4);
        break;
    case 3:
        gotoXY(31, 10);
        cout << "太好了，是小岛！终于可以休息一下了!";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "在岛上休息的时候，发现一个亮晶晶的东西。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "获得物品:我的电动车钥匙";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 20);
        cout << "我的电动车钥匙(奇怪，怎么会在这里?)";
        map4[0][5] = 5;
        map4[0][6] = 5;
        map4[2][7] = 5;
        map4[4][4] = 5;
        map4[4][5] = 5;
        map4[2][4] = 0;
        break;
    case 4:
        gotoXY(31, 10);
        cout << "猫:喵~";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "不好，草丛里藏着猫!";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "平常会让我觉得可爱的声音，现在听来只让鹅觉得可怕。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "快逃!";
        wait(2000);
        clear(31, 10, 100, 4);
        break;
    case 5:
        gotoXY(31, 10);
        cout << "钥匙总不能就那么扔水里吧。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "鹅叼着钥匙，奋力朝前游动最后选了片干净草地，把钥匙丢在草丛中。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(37, 20);
        cout << "                                    ";
        gotoXY(31, 10);
        cout << "鹅：嘎嘎嘎嘎嘎。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "变回我之后，得记得来拿。";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "猫:喵~";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "不好，是猫!";
        wait(2000);
        clear(31, 10, 100, 4);
        gotoXY(31, 10);
        cout << "快逃!";
        wait(2000);
        clear(31, 10, 100, 4);
        end4();
        break;
    }
}

void end4()
{
    system("cls");
    cout << "鹅奋力划水，刚要落荒而逃，" << endl;
    wait(2000);
    cout << "一双大手却从天而降，把鹅抱了起来。" << endl;
    wait(2000);
    cout << "居然是老师？" << endl;
    wait(2000);
    cout << "老师：果然跑到这儿来了……" << endl;
    wait(2000);
    cout << "像是自言自语，又像是特意说给谁听。" << endl;
    wait(2000);
    cout << "老师：这个bug得再修复一下。" << endl;
    wait(2000);
    cout << "老师抱着鹅，在上课铃声中朝教室走去。" << endl;
    wait(2000);
    cout << "BAD END 3 ：鹅鹅鹅          回溯中。。。" << endl;
    wait(2000);
    map3[3][7] = 5;
    map3[5][12] = 5;
    map3[7][7] = 5;
    chapter1ca();
}

void viewme4(int x0, int y0, int x1, int y1)//实现我的移动
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//系数2使“我”一整格一整格地移动，初始参数使得光标能到“我”的初始坐标
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "鹅";
    }
}

//.............................................................................................
void chapter1e()
{
    yinru5();
    mapdraw5();
    int x0 = 0, y0 = 2, x1 = 0, y1 = 2, clue;//“我”的初始在地图上相对位置（参数调整过后版本，并非gotoxy可用坐标）
    while (1)//实现与场景互动同时防止吃字
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
    const char* str1 = "走进楼梯口，我不知为何来到一条逼仄的小道，两旁全是密密麻麻丛生的杂草，小道仅容得下一个人通过。";
    const char* str2 = "而前方!同学们密密麻麻站在一起，像失了魂一样一动不动！！";
    printMessage(str1);
    wait(500);
    printMessage(str2);
    wait(500);
    system("cls");
    
    gotoXY(31, 10);
    cout << "一种从未有过的力量在我身体里迅速勃发，脑中有刺激的电流流过。";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "我顿时感觉极度的饥饿感吞没了我，我不由自主地走向他们。";
    wait(2000);
    clear(31, 10, 100, 4);
    gotoXY(31, 10);
    cout << "我竟看到他们前方浮现出一连串的二进制数字。";
    wait(2000);
    clear(31, 10, 100, 4);
    
}

void mapdraw5()
{
    
    gotoXY(31, 3);
    cout << "            草草草                              ";
    gotoXY(31, 4);
    cout << "  草草草草草从从从草        草草草草草草草草草  ";
    gotoXY(31, 5);
    cout << "  饿从从从从从草从从草草  草从从从从从从从从从  ";//"我"(30,5)，但参数可调
    gotoXY(31, 6);
    cout << "  草草草草草草  草从从从草草从草草草草草草草草  ";
    gotoXY(31, 7);
    cout << "                  草草从从从从草                ";
    gotoXY(31, 8);
    cout << "                      草草草草                  ";

}

int map5[6][24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//x1=2,y1=3
                  0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                  0,1,1,1,1,1,1,0,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,2,
                  0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,
                  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int cluejudge5(int x1, int y1)//判断下一步的字是什么
{
    int number = map5[y1][x1];
    return number;
}

void interact5(int number, int& x0, int& y0, int x1, int y1)//number标记互动对象在地图上对应的情况
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
        cout << "我产生了奇异的满足感......";
        wait(2000);
        clear(31, 10, 100, 4);
        system("cls");
        end3();
    }
}

void end3()
{
    cout << "BAD END 2 ：校园饿人          回溯中。。。";
    wait(2000);
    map3[3][7] = 4;
    map3[5][12] = 4;
    map3[7][7] = 4;
    chapter1ca();
}

void viewme5(int x0, int y0, int x1, int y1)//实现我的移动
{
    if (x0 != x1 || y0 != y1)
    {
        gotoXY(31 + 2 * x0, 3 + y0);//系数2使“我”一整格一整格地移动，初始参数使得光标能到“我”的初始坐标
        cout << "  ";
        gotoXY(31 + 2 * x1, 3 + y1);
        cout << "饿";
    }
}

