#include "Hgame.h"
#include"tool.h"
#include"main.h"


IMAGE i_back;//easyx��ͼƬ����
IMAGE i_brick;
IMAGE i_player[2];
IMAGE i_mplayer[2];
IMAGE i_hook[2];
IMAGE i_mhook[2];
IMAGE i_clear;
IMAGE i_end;
IMAGE i_biggold;
IMAGE i_mbiggold;
IMAGE i_smallgold;
IMAGE i_msmallgold;
IMAGE i_diamond;
IMAGE i_mdiamond;
IMAGE i_stone;
IMAGE i_mstone;
IMAGE i_shushu_left[2];
IMAGE i_mshushu_left[2];
IMAGE i_shushu_right[2];
IMAGE i_mshushu_right[2];
IMAGE pause_background;
IMAGE i_start;
IMAGE i_logo;
IMAGE i_startbottom[3];
IMAGE i_hook2;
IMAGE i_mhook2;
IMAGE img;
IMAGE img_tmp[BIG_GOLD_AMOUNT + SMALL_GOLD_AMOUNT + STONE_AMOUNT+1][2];

GameState gameState;// ������Ϸ״̬����
ExMessage m;	// ������Ϣ����
Hook hook;
Player player;
List list;	//��������������Ϸ����
int Time = 30;	//��Ϸ����ʱ
int timer = 0;	//��ʱ��

//���涨�庯��
//�������
void Add(List* pList, Object obj) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p) {
		p->object = obj;// ���¶���ֵ���½ڵ�
		p->next = NULL;// �½ڵ����һ���ڵ��ʼ��Ϊ NULL
	}

	Node* last;
	last = pList->head;
	if (last) {// �ҵ���������һ���ڵ�
		while (last->next) {
			last = last->next;
		}
		last->next = p;// ���½ڵ���ӵ������ĩβ
	}
	else {
		pList->head = p;// �������Ϊ�գ����½ڵ��Ϊ�����ͷ�ڵ�
	}
}

//����ɾ��
void Delete(List* pList, int index) {
	Node* p, * q;
	int i = 0;
	for (p = pList->head, q = NULL; p; q = p, p = p->next) {
		if (i==index) {
			if (q) {
				q->next = p->next;	//q�ĺ�λ����p�ĺ�λ�����ǰ�p�������Ϻ��Ե�
			}
			else {	//�����λ����Ӧɾȥ��ֵ
				pList->head = p->next;	//����ͷΪp�ĺ�λ
			}
			free(p);
			break;
		}
		i++;
	}

}

//����ɾ��
void Delete(List* pList, Object* obj) {
	Node* p, * q;
	for (p = pList->head, q = NULL; p; q = p, p = p->next) {
		if (&p->object==obj) {
			if (q) {
				q->next = p->next;	//q�ĺ�λ����p�ĺ�λ�����ǰ�p�������Ϻ��Ե�
			}
			else {	//�����λ����Ӧɾȥ��ֵ
				pList->head = p->next;	//����ͷΪp�ĺ�λ
			}
			free(p);
			break;
		}
	}

}

//ͨ�������Ҷ��󣬺���������������ץȡ����
Object* Find(List* pList, int index) {
	Node* p;
	Object *obj;
	int i = 0;
	for (p = list.head; p; p = p->next) {
		if (i == index) {
			obj = &(p->object);
			return obj;
		}
		i++;
	}
	return NULL;//δ�ҵ�
}

//��ȡ�����¼�
void KeyboardEvent() {
	if (GetAsyncKeyState(27) & 0x8000) {	//���ESC
		getimage(&img, 0, 0, WINDOWS_WIDTH, WINDOWS_HEIGHT);
		gameState = Pause;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		if (hook.isThrow)	//������Ѿ���������ټ���
			return;
		ThrowHook();
	}
}

//��ȡ����¼�
void MouseEvent() {
	switch (m.message)//���¼����з���
	{
	case WM_MOUSEMOVE://���������ƶ��¼�
		if (gameState == Begin) {
			if (m.x > 90 && m.x < 236 && m.y>120 && m.y < 207)
				i_startbottom[0]=i_startbottom[2];
			else
				i_startbottom[0] = i_startbottom[1];
		}
		break;
	case WM_LBUTTONDOWN://����ǵ��������
		if (gameState == Running) {
			if (hook.isThrow)	//��������Ѿ�Ͷ�������ټ���
				return;
			ThrowHook();
		}
		if (gameState == Pause) {
			if (m.x > 85 && m.x < 177 && m.y>178 && m.y < 214) {	//����
				gameState = Running;
			}
			if (m.x > 238 && m.x < 328 && m.y>178 && m.y < 214) {	//�˳�
				closegraph();
				exit(0);
			}
		}
		if (gameState == Begin) {
			if (m.x > 90 && m.x < 236 && m.y>120 && m.y < 207) {	//��ʼ��Ϸ
				InputBox(player.name, 10, L"�������������", L"���������", L"player");
				Resize(NULL, WINDOWS_WIDTH, WINDOWS_HEIGHT);
				gameState = Running;
			}
			if (m.x > 115 && m.x < 255 && m.y>475 && m.y < 520) {//�˳���Ϸ
				closegraph();
				exit(0);
			}
		}
		break;
	case WM_RBUTTONDOWN://����ǵ������Ҽ�
		return;
	}

}

//����ͼƬ
void LoadImages() {
	loadimage(&i_back, _T(".\\Resources\\pictures\\level-background-0.jpg"));
	loadimage(&i_brick, _T(".\\Resources\\pictures\\brick.png"),WINDOWS_WIDTH+30,0,true);
	loadimage(&i_player[0], _T(".\\Resources\\pictures\\char1.jpg"));
	loadimage(&i_player[1], _T(".\\Resources\\pictures\\char2.jpg"));
	loadimage(&i_mplayer[0], _T(".\\Resources\\pictures\\char1_mask.jpg"));
	loadimage(&i_mplayer[1], _T(".\\Resources\\pictures\\char2_mask.jpg"));
	loadimage(&i_hook[0], _T(".\\Resources\\pictures\\hook.bmp"));
	loadimage(&i_mhook[0], _T(".\\Resources\\pictures\\hook_mask.bmp"));
	loadimage(&i_biggold, _T(".\\Resources\\pictures\\big_gold.png"));
	loadimage(&i_mbiggold, _T(".\\Resources\\pictures\\big_gold_mask.png"));
	loadimage(&i_smallgold, _T(".\\Resources\\pictures\\small_gold.bmp"));
	loadimage(&i_msmallgold, _T(".\\Resources\\pictures\\small_gold_mask.bmp"));
	loadimage(&i_diamond, _T(".\\Resources\\pictures\\diamond.png"));
	loadimage(&i_mdiamond, _T(".\\Resources\\pictures\\diamond_mask.png"));
	loadimage(&i_stone, _T(".\\Resources\\pictures\\stone.png"));
	loadimage(&i_mstone, _T(".\\Resources\\pictures\\stone_mask.png"));
	loadimage(&i_shushu_left[0], _T(".\\Resources\\pictures\\shushu.png"));
	loadimage(&i_shushu_left[1], _T(".\\Resources\\pictures\\shushu_diamond.png"));
	loadimage(&i_mshushu_left[0], _T(".\\Resources\\pictures\\shushu_mask.png"));
	loadimage(&i_mshushu_left[1], _T(".\\Resources\\pictures\\shushu_diamond_mask.png"));
	loadimage(&i_clear, _T(".\\Resources\\pictures\\clear.png"));
	loadimage(&i_end, _T(".\\Resources\\pictures\\end.jpg"));
	loadimage(&pause_background, _T(".\\Resources\\pictures\\pause_background.png"));
	loadimage(&i_start, _T(".\\Resources\\pictures\\start.png"));
	loadimage(&i_logo, _T(".\\Resources\\pictures\\logo.png"));
	loadimage(&i_startbottom[1], _T(".\\Resources\\pictures\\startbottom1.png"));
	loadimage(&i_startbottom[2], _T(".\\Resources\\pictures\\startbottom2.png"));
	loadimage(&i_hook2, _T(".\\Resources\\pictures\\hook2.jpg"));
	loadimage(&i_mhook2, _T(".\\Resources\\pictures\\hook2_mask.jpg"));
	i_hook[1] = i_hook[0];
	i_mhook[1] = i_mhook[0];
	i_startbottom[0]= i_startbottom[1];

	for (int i = 0; i < 2; i++) {//����ͷ
		i_shushu_right[i] = i_shushu_left[i];
		FlipImage(&i_shushu_right[i], &i_shushu_left[i]);//��תͼƬ
		i_mshushu_right[i] = i_mshushu_left[i];
		FlipImage(&i_mshushu_right[i], &i_mshushu_left[i]);
	}
}

//��Ϸ�����ʼ��
void Initialize() {
	gameState = Begin;
	srand(time(NULL));

	//��ʼ��player
	player.x = WINDOWS_WIDTH / 2 - 50;
	player.y = WINDOWS_HEIGHT / 2 - 240;
	player.score = 0;
	player.goal = 500;
	player.ani_timer = 0;
	player.ani_index = 0;
	player.isShow = false;

	//��ʼ��hook
	hook.x = player.x+60;
	hook.y = player.y+70;
	hook.length = 0;
	hook.angle = 0;
	hook.dir = 0;
	hook.speed = 5;
	hook.isThrow = false;
	hook.dx = 18;
	hook.dy = 0;
	hook.carry = 0;

	list.head = NULL;	//��ʼ������
	for (int i = 0; i < BIG_GOLD_AMOUNT; i++) {		// ���ɸ���A
		Object bigGold;
		bigGold.size = rand() % 3 + 6;	//��Χ6-8
		bigGold.score = 20 * bigGold.size;	//120-160���鷶Χ
		double scale = (bigGold.size - 6) / 10.0 + 1;
		img_tmp[i][0] = ZoomImage(&i_biggold, scale);// ���ö����ͼ�������
		img_tmp[i][1] = ZoomImage(&i_mbiggold, scale);
		bigGold.image = &img_tmp[i][0];
		bigGold.m_image = &img_tmp[i][1];
		SetObjectPosition(&list, &bigGold);// ���ö�������Ļ�ϵ�λ��
		bigGold.type = Gold;
		Add(&list, bigGold);// ��������ӵ�������
	}
	for (int i = 0; i < SMALL_GOLD_AMOUNT; i++) {	//����C++
		Object smallGold;
		smallGold.size = rand() % 3 + 1;	//��Χ1-3
		smallGold.score = 15 * smallGold.size;	//15-45
		double scale = (smallGold.size - 1) / 8.0 + 1;
		img_tmp[BIG_GOLD_AMOUNT + i][0] = ZoomImage(&i_smallgold, scale);
		img_tmp[BIG_GOLD_AMOUNT + i][1] = ZoomImage(&i_msmallgold, scale);
		smallGold.image = &img_tmp[BIG_GOLD_AMOUNT + i][0];
		smallGold.m_image = &img_tmp[BIG_GOLD_AMOUNT + i][1];
		SetObjectPosition(&list, &smallGold);
		smallGold.type = Gold;
		Add(&list, smallGold);
	}
	for (int i = 0; i < STONE_AMOUNT; i++) {		//����switch
		Object stone;
		img_tmp[BIG_GOLD_AMOUNT + SMALL_GOLD_AMOUNT+i][0] = ZoomImage(&i_stone, 1.6);
		img_tmp[BIG_GOLD_AMOUNT + SMALL_GOLD_AMOUNT+i][1] = ZoomImage(&i_mstone, 1.6);
		stone.image = &img_tmp[BIG_GOLD_AMOUNT + SMALL_GOLD_AMOUNT + i][0];
		stone.m_image = &img_tmp[BIG_GOLD_AMOUNT + SMALL_GOLD_AMOUNT + i][1];
		SetObjectPosition(&list, &stone);
		stone.size = 9;
		stone.score = 10;
		stone.type = Gold;
		Add(&list, stone);
	}
	for (int i = 0; i < DIAMOND_AMOUNT; i++) {	
		Object diamond;			//���ɱ�
		diamond.image = &i_diamond;
		diamond.m_image = &i_mdiamond;
		SetObjectPosition(&list, &diamond);
		diamond.size = 1;
		diamond.score = 50;
		diamond.type = Diamond;
		Add(&list, diamond);
			
		Object mouse;			//�������
		mouse.dir = rand() % 2;// ��������ƶ�����
		mouse.y = diamond.y;// �������ĳ�ʼ y ����Ϊ�ʵ� y ����
		if (mouse.dir == 0) {// ���������ƶ������������ʼ x �����ͼ��
			mouse.x = WINDOWS_WIDTH;
			mouse.image = &i_shushu_left[0];
			mouse.m_image = &i_mshushu_left[0];
		}
		else {
			mouse.x = 0;
			mouse.image = &i_shushu_right[0];
			mouse.m_image = &i_mshushu_right[0];
		}
		mouse.size = 1;
		mouse.score = 10;
		mouse.type = Mouse;
		Add(&list, mouse);
	}

}

//����ͼ��
void Draw() {
	putimage(0, 0, &i_back);	//���Ʊ���
	putimage(-10, 100, &i_brick);

	DrawPlayer();
	DrawObject();
	DrawHook();
	DrawUI();
}

//���ƽ�ɫ
void DrawPlayer() {
	if (hook.isThrow) {	//�������������Ŷ���
		player.ani_timer++;// ���Ӷ�����ʱ����ֵ
		if (player.ani_timer > 10) {// ���������ʱ����ֵ���� 10��������Ϊ 0�����л���������
			player.ani_timer = 0;
			player.ani_index = (player.ani_index + 1) % 2;
		}
		PutImageWithMask(player.x, player.y, &i_player[player.ani_index], &i_mplayer[player.ani_index]);// ʹ�õ�ǰ����������������
	}
	else {// �����δ����������Ĭ�ϵ�����ͼ
		PutImageWithMask(player.x, player.y, &i_player[0], &i_mplayer[0]);	
	}
}

//����UI
void DrawUI() {
	settextstyle(32, 0, L"����");
	settextcolor(RGB(77, 30, 170));
	setbkmode(TRANSPARENT);

	//���Ʒ���
	TCHAR scoreText[30];
	_stprintf_s(scoreText, _T("��Ǯ��$%d"), player.score);
	outtextxy(10,10,scoreText);

	//����Ŀ�����
	TCHAR goalText[30];
	_stprintf_s(goalText, _T("Ŀ����飺$%d"), player.goal);
	outtextxy(10, 50, goalText);

	//����ʱ��
	TCHAR timeText[30];
	_stprintf_s(timeText, _T("ʱ�䣺%d"), Time);
	outtextxy(800, 10, timeText);

	//�����������
	TCHAR nameText[30];
	_stprintf_s(nameText, _T("������ƣ�%s"), player.name);
	outtextxy(800-(wcslen(player.name)*16), 50, nameText);

	//���Ƶ÷���ʾ
	TCHAR getScoreText[30];// ����һ�� TCHAR ���� getScoreText�����ڴ洢�÷��ı�
	static int duringTimer = 60;//�������ʱ��
	if (player.isShow)// �����ҵ� isShow ����Ϊ�棬��ִ�����²���
	{
		_stprintf_s(getScoreText, _T("+%d"), player.getScore);// ʹ�� _stprintf_s ��������һ�õķ�����ʽ��Ϊ�ַ��������洢�� getScoreText ������
		settextcolor(LIGHTCYAN);
		outtextxy(player.x+40, player.y-20, getScoreText);
		duringTimer--;// ���ٳ�����ʱ����ֵ
		if (duringTimer == 0) {// ���������ʱ����ֵΪ 0������ҵ� isShow ��������Ϊ�٣������ó�����ʱ��
			player.isShow = false;
			duringTimer = 60;
		}
	}

}


//������Ϸ����
void DrawObject() {
	Node* p;// ����һ���ڵ�ָ�� p�����ڱ�������
	for (p = list.head; p; p = p->next) {// ���������е�ÿ���ڵ�
		PutImageWithMask(p->object.x, p->object.y, p->object.image, p->object.m_image);
	}
}

//������
void DrawHook() {
	hook.endx = hook.x + hook.length * sin(hook.angle*3.14/180);	//������ĩ������
	hook.endy = hook.y + hook.length * cos(hook.angle*3.14/180);
	setlinestyle(PS_SOLID, 8);
	setlinecolor(BLACK);
	line(hook.x, hook.y, hook.endx, hook.endy);	//�����ֱ�
	PutImageWithMask(hook.endx-hook.dx, hook.endy-hook.dy, &i_hook[1], &i_mhook[1]);

	//��������
	if (hook.isThrow) {
		int index=0;
		//�����ײ��ǽ��
		if (hook.endx > WINDOWS_WIDTH || hook.endy > WINDOWS_HEIGHT || hook.endx < 0) {
			hook.isBack = true;
		}
		//�����ײ������
		Node* p;
		for (p = list.head; p; p = p->next) {
			if (CollisionDetect(p->object)) {
				hook.isBack = true;
				hook.carry = p->object.size;// ��¼ץ���������С
				break;
			}
			index++;
		}

		if (hook.isBack)	//���ջ�
			if (hook.carry == 0)	//û�и��أ�֤��û��ץ����Ʒ
				HookBack(2 * hook.speed);// �������ٶ��ջ���
		        
			else
				HookBack(2 * hook.speed - hook.carry ,index);	//ץ������Ʒ
		else
			ThrowHook();
		
		if (hook.isBack)	//���ջ�ʱ
			if (hook.carry == 0)	//û�и��أ�֤��û��ץ����Ʒ
				HookBack(2 * hook.speed);

			else
				PutImageWithMask(hook.endx - hook.dx, hook.endy - hook.dy, &i_hook2, &i_mhook2);	//ץ������Ʒ����ͼƬ
		else
			ThrowHook();

	}

}

//����ת
void HookSway() {
	if (hook.isThrow) {	//�����������򷵻�
		return;
	}

	if (hook.angle >= 90) {// ����ֵĽǶȴ��ڵ��� 90 �ȣ���ı䷽��Ϊ��ʱ��
		hook.dir = 0;
	}
	if (hook.angle <= -90) {// ����ֵĽǶ�С�ڵ��� -90 �ȣ���ı䷽��Ϊ˳ʱ��
		hook.dir = 1;
	}
	switch (hook.dir)// ���ݵ�ǰ�ķ��򣬸ı��ֵĽǶ�
	{
	case 0:
		hook.angle--;
		break;
	case 1:
		hook.angle++;
		break;
	default:
		break;
	}
	rotateimage(&i_hook[1], &i_hook[0], hook.angle * 3.14 / 180, WHITE, true, true);	//��ת��ͼƬ
	rotateimage(&i_mhook[1], &i_mhook[0], hook.angle * 3.14 / 180, BLACK, true, true);
	

	//����ƫ������ʹ���Ӿ�����������ת
	if (hook.angle > 0) {// ����Ƕȴ��� 0
		hook.dy = 18 * sin(hook.angle * 3.14 / 180);// ���㴹ֱ�����ƫ�������� 18 ���ԽǶȵ�����ֵ
		hook.dx = 35 * cos(hook.angle * 3.14 / 180) - 18 * cos(hook.angle * 3.14 / 180);// ����ˮƽ�����ƫ�������� 35 ���ԽǶȵ�����ֵ���ټ�ȥ 18 ���ԽǶȵ�����ֵ
	}
	else {
		hook.dy = 18 * sin(abs(hook.angle) * 3.14 / 180);//abs�Ǿ���ֵ
		hook.dx = 20 * sin(abs(hook.angle) * 3.14 / 180) + 18 * cos(abs(hook.angle) * 3.14 / 180);
	}
}

//�����
void ThrowHook() {
	// ����״̬
	hook.isThrow = true;
	hook.isBack = false;
	hook.length += hook.speed;
	mciSendString(_T("open .\\Resources\\sound\\dig.mp3 alias dig"), 0, 0, 0);
	mciSendString(_T("play dig"), 0, 0, 0);	//������Ч
	
	
	
}

//�ջ���
void HookBack(int speed) {
	hook.length -= speed;// �����ֱ۳���
	if (hook.length <= 0) {
		hook.length = 0;
		hook.isThrow = false;
		PutImageWithMask(hook.endx - hook.dx, hook.endy - hook.dy, &i_hook[1], &i_hook[1]);
	}
}

//�ջ��ֺ�ץȡ������Ʒ
void HookBack(int speed, int index) {
	hook.length -= speed;
	Object* obj = Find(&list, index);	//ͨ�������ҵ�Ҫ�ջصĶ���
	if (obj == NULL) {// ���û���ҵ�������ֱ�ӷ���
		return;
	}
	else {// ���¶����λ��
		obj->x = hook.endx - hook.dx;
		obj->y = hook.endy - hook.dy;
		if (hook.length <= 0) {
			if (obj->score <= 10) {// ���ݶ���ķ������Ų�ͬ����Ч
				mciSendString(_T("open .\\Resources\\sound\\low-value.mp3 alias low-value"), 0, 0, 0);
				mciSendString(_T("play low-value"), 0, 0, 0);
			}
			else {
				mciSendString(_T("open .\\Resources\\sound\\normal-value.mp3 alias normal-value"), 0, 0, 0);
				mciSendString(_T("play normal-value"), 0, 0, 0);
			}
			hook.length = 0;
			hook.carry = 0;
			player.score += obj->score;	//�������ۼ�
			player.getScore = obj->score;	//��¼���ε÷�
			player.isShow = true;
			Delete(&list, index);	//ɾ����Ʒ
			hook.isThrow = false;
		}
	}
}

//����ƶ�
void ShushuMove() {
	Node* p;
	for (p = list.head; p; p = p->next) {
		if (p->object.type == Mouse) {	//ͨ���ڵ�p�����ҵ����

			if (p->object.dir == 0) {	//���������
				p->object.x = p->object.x - 1;
				Node* q;	//ͨ���ڵ�q���������ײ
					for (q = list.head; q; q = q->next) {
						if (CollisionDetect(p->object, q->object) && q->object.type == Diamond) {	//���ץ���˱�
							p->object.image = &i_shushu_left[1];
							p->object.m_image = &i_mshushu_left[1];
							p->object.score = 60;
							Delete(&list, &q->object);	//ɾ����
							break;
						}
					}
			}
			else {	//���������
				p->object.x = p->object.x + 1;
				Node* q;	//ͨ���ڵ�q���������ײ
					for (q = list.head; q; q = q->next) {
						if (CollisionDetect(p->object, q->object) && q->object.type == Diamond) {	//���ץ���˱�
							p->object.image = &i_shushu_right[1];
							p->object.m_image = &i_mshushu_right[1];
							p->object.score = 60;
							Delete(&list, &q->object);
							break;
						}
					}
			}

			if (p->object.score == 210) {	//����Ѿ�ץ���˱�
				if (p->object.x > WINDOWS_WIDTH || p->object.x+28 < 0) {
					Delete(&list, &p->object);	//����ƶ�����Ļ�⣬ɾ��
					break;
				}
				Node *q;
				for (q = list.head; q; q = q->next) {
					if (CollisionDetect(p->object, q->object) && q->object.type == Gold) {	//�����������
						if (p->object.dir == 0) {
							p->object.image = &i_shushu_right[1];
							p->object.m_image = &i_mshushu_right[1];
							p->object.dir = 1;
						}
						else {
							p->object.image = &i_shushu_left[1];
							p->object.m_image = &i_mshushu_left[1];
							p->object.dir = 0;
						}
					}
				}

			}

		}
	}

}

//���ö���λ��
void SetObjectPosition(List *pList,Object *obj) {
	if (pList->head == NULL) {
		//��һ��������Ҫ�����ײ
		obj->x = rand() % (WINDOWS_WIDTH - 50);
		obj->y = rand() % (WINDOWS_HEIGHT - 160) + 110;
		return;
	}

	int x, y;
	Node* p = pList->head;
	while (1)
	{
		x = rand() % (WINDOWS_WIDTH - 50);
		y = rand() % (WINDOWS_HEIGHT - 160) + 110;
		//�������е�ÿһ������ײ
		while (p) {
			if (CollisionDetect(x, y, obj->image->getwidth(), obj->image->getheight(), p->object)) {
				p = pList->head;	//�����ײ����������λ�ã����¼��
				break;
			}
			p = p->next;
		}
		//�����е�ÿһ�������
		if (p == NULL)
			break;
	}
	obj->x = x;
	obj->y = y;
	return;
}

//��ײ���
bool CollisionDetect(Object obj) {
	int rect1x = hook.endx-hook.dx;//������
	int rect1y = hook.endy-hook.dy;
	int rect1width = i_hook[1].getwidth();//�ֿ��
	int rect1height = i_hook[1].getheight();
	int rect2x = obj.x;//��������
	int rect2y = obj.y;
	int rect2width = obj.image->getwidth();//������
	int rect2height = obj.image->getheight();

	if ((rect1x+rect1width)>=rect2x &&//������ײ����
		(rect2x+rect2width)>=rect1x &&
		(rect1y+rect1height)>=rect2y &&
		(rect2y+rect2height)>=rect1y)
	{
		return true;
	}
	return false;
}

//��ײ���
bool CollisionDetect(int rect1x, int rect1y, int rect1width, int rect1height, Object obj) {
	int rect2x = obj.x;
	int rect2y = obj.y;
	int rect2width = obj.image->getwidth();
	int rect2height = obj.image->getheight();

	if ((rect1x + rect1width) >= rect2x &&
		(rect2x + rect2width) >= rect1x &&
		(rect1y + rect1height) >= rect2y &&
		(rect2y + rect2height) >= rect1y)
	{
		return true;
	}
	return false;
}

//��ײ���
bool CollisionDetect(Object obj1, Object obj2) {
	int rect1x = obj1.x;
	int rect1y = obj1.y;
	int rect1width = obj1.image->getwidth();
	int rect1height = obj1.image->getheight();
	int rect2x = obj2.x;
	int rect2y = obj2.y;
	int rect2width = obj2.image->getwidth();
	int rect2height = obj2.image->getheight();

	if ((rect1x + rect1width) >= rect2x &&
		(rect2x + rect2width) >= rect1x &&
		(rect1y + rect1height) >= rect2y &&
		(rect2y + rect2height) >= rect1y)
	{
		return true;
	}
	return false;
}

//��Ϸ��ʼ
void GameBegin() {
	Resize(NULL, i_start.getwidth(), i_start.getheight());// �������ڴ�С����Ӧ��ʼ����ı���ͼƬ
	putimage(0, 0, &i_start);
	TransparentImage(NULL, 20, 20, &i_logo);// ����͸����logo
	putimage(90, 120, &i_startbottom[0]);

	//��ӡĿ�����
	settextstyle(32, 0, L"����");
	LOGFONT font;// ��ȡ��ǰ������ʽ
	gettextstyle(&font);
	font.lfQuality = ANTIALIASED_QUALITY;	//�������Ч��Ϊ�����
	settextstyle(&font);
	settextcolor(RGB(77,30,170));
	setbkmode(TRANSPARENT);// ���ñ���ģʽΪ͸��
	TCHAR goalText[30];// ��ʽ��Ŀ������ı�
	_stprintf_s(goalText, _T("Ŀ����飺$%d"), player.goal);
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	fillroundrect(115, 390, 350, 435, 2, 2);// ����Բ�Ǿ�����ΪĿ�����ı���
	outtextxy(120, 400, goalText);// �ڱ���������ı�

	setfillcolor(WHITE);//�˳���Ϸ�������
	setlinecolor(WHITE);
	fillroundrect(115, 475, 255, 520, 2, 2);
	settextcolor(RGB(77, 30, 170));
	outtextxy(120, 480, _T("�˳���Ϸ"));
}

//��Ϸ����
void GameOver() {
	//��¼��ҵ÷�
	static int isopen = 1;//��ʾ�ļ��Ƿ��Ѿ���
	FILE* fp = NULL;
	errno_t err;//���� fopen_s �����Ĵ�����Ϣ
	if (isopen == 1) {
		err=fopen_s(&fp, "charts.txt", "a+, ccs=utf-8");//���ļ� "charts.txt"
	}
	wchar_t text[30];//�洢��Ҫд���ļ����ı�
	//���Ʒ���
	TCHAR scoreText[30];
	_stprintf_s(scoreText, _T("���ķ���Ϊ$%d"), player.score);

	mciSendString(_T("stop bgm"), 0, 0, 0);
	if (player.score >= player.goal) {	//��������ﵽĿ�꣬��Ϸ�ɹ�
		Resize(NULL, i_clear.getwidth(), i_clear.getheight());
		putimage(0, 0, &i_clear);
		outtextxy(300, 280, scoreText);
		TransparentImage(NULL, 50, 20, &i_logo);
		mciSendString(_T("play high-value"), 0, 0, 0);
		swprintf_s(text, L"��ң�%-10s��Ϸ�ɹ������飺%d\n", player.name,player.score);
		wait(5000);
		closegraph();
		wait(1000);
		start();
		
	}
	else {	//û�ﵽĿ�꣬��Ϸʧ��
		Resize(NULL, i_end.getwidth(), i_end.getheight());
		putimage(0, 0, &i_end);
		outtextxy(300, 200, _T("��ʧ����"));
		outtextxy(300, 280, scoreText);
		swprintf_s(text, L"��ң�%-10s��Ϸʧ�ܣ����飺%d\n", player.name, player.score);
		wait(5000);
		closegraph();
		wait(1000);
		end1();
	
	}
	if (isopen == 1&&err==0) {//д����ҵ÷�����
		fwprintf(fp, L"%s", text);
		fclose(fp);
		isopen = 0;
	}

}

// Start �ڳ���ʼ����ʱ������
void Start() {
	initgraph(WINDOWS_WIDTH, WINDOWS_HEIGHT, EX_SHOWCONSOLE);
	LoadImages();
	Initialize();
	//��������ļ�
	mciSendString(_T("open .\\Resources\\sound\\bgm.mp3 alias bgm"), 0, 0, 0);
	mciSendString(_T("open .\\Resources\\sound\\high-value.mp3 alias high-value"), 0, 0, 0);
	mciSendString(_T("play bgm repeat"), 0, 0, 0);
}

// Update ��ÿһ֡������
void Update() {
	peekmessage(&m, EX_MOUSE,true);//��ȡ����¼�
	switch (gameState)	//�ж���Ϸ״̬
	{
	case Begin:
		GameBegin();
		MouseEvent();
		break;

	case Running:
		timer++;	//��ʱ��+1
		if (timer == 60) {
			timer = 0;
			Time--;	//����ʱ
		}

		Draw();	//��ͼ

		HookSway();	//�ְڶ�
		ShushuMove();	//����ƶ�

		KeyboardEvent();	//��ȡ�����¼�
		MouseEvent();

		//����Ƿ������ȫ����
		if (list.head == NULL) {
			gameState = Finished;
		}
		//��⵹��ʱ�Ƿ����
		if (Time == 0) {
			gameState = Finished;
		}
		break;

	case Pause:
		putimage(0, 0, &img);
		putimage(50, 50, &pause_background);
		MouseEvent();
		break;

	case Finished:
		GameOver();
		break;

	}

	//�ر��Ѳ�����������ļ�
	WCHAR buffer[48];
	mciSendString(_T("status dig mode"), buffer, _countof(buffer), 0);
	if (wcscmp(buffer, L"stopped") == 0) {
		mciSendString(_T("close dig"), 0, 0, 0);
	}
	
	mciSendString(_T("status low-value mode"), buffer, _countof(buffer), 0);
	if (wcscmp(buffer, L"stopped") == 0) {
		mciSendString(_T("close low-value"), 0, 0, 0);
	}
	mciSendString(_T("status normal-value mode"), buffer, _countof(buffer), 0);
	if (wcscmp(buffer, L"stopped") == 0) {
		mciSendString(_T("close normal-value"), 0, 0, 0);
	}
}

int neizhi() {
	Start();
	BeginBatchDraw();
	while (true)
	{
		Update();
		FlushBatchDraw();
		Sleep(1000 / 60);
		cleardevice();

	}
	EndBatchDraw();
	
}
