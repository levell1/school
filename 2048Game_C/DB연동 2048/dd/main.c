#include<stdio.h>		
#include<string.h>
#include<my_global.h>	
#include<mysql.h>		

#include<time.h>		
#include<conio.h>		//console and port I/O
#include<windows.h>		//
#include<math.h>		

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "last0317"
#define DB_NAME "test3"
#define CHOP(x) x[strlen(x)-1]=' '

//ȭ��ǥ�� �ƽ�Ű�ڵ� DEFINE
#define LEFT 75		
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define L 76
#define l 108

//�����̵� X�� �� Y�� DEFINE
#define MAP_ADJ_X 10
#define MAP_ADJ_Y 5

//ȸ������ SIZE
#define SIZE 100
//����ͻ��� x,y ��ǥ�� �̵���Ű�� �Լ� windows.h �����ԵǾ��ִ�.
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef enum { NOCURSOR } CURSOR_TYPE;
//Ŀ�� ǥ�ø� �����ִ� �Լ�  
void setcursortype(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	}
	// SetConsoleCursorInfo(�β� or ���⿩��) �� �����ϴ� ����
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
// ������
int board[4][4] = {
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
};

int x = 0;
int game_over_on = 0;	//���� ���� ����ġ 
int score;				//���� �����Լ� 
int made_32;			// �� �ش��ϴ� ��ȣ�� ����� ���������  
int made_64;			// �޼��� ����ֱ� ���� ������
int made_128;
int made_256;
int made_512;
int made_1024;
int made_2048;
int made_4096;

//ȸ�� ����ü
struct USER {
	char ID[50];
	char Pass[50];
	int highscore;
	int item;
};

struct USER us[SIZE] = { 0 };

int menu(void);
int login(void);
int make(struct USER *p);
void login_dis(struct USER *p, int usnum);
int del(struct USER *p);


void reset(struct USER *p, int usnum);				// ������ �ʱ�ȭ 
void draw(void);				// �������� �׸� 
void new_num(void);				// ���ο� ���� 2�� 4�� �����ǿ� ���� 
int  get_key(struct USER *p, int usnum);				// Ű�Է¹ް� �����̴� �Լ� 
void check_2048(struct USER *p, int usnum);			// ����� ��������� �޼��� ����ִ� �Լ� 
void check_game_over(int usnum);		// ���ӿ����� �Ǵ��ϴ� �Լ� 


int main(void)
{
	MYSQL conn;
	MYSQL *connection;
	MYSQL_RES *sql_result;
	MYSQL_ROW sql_row;

	char buffer[100];


	mysql_init(&conn);

	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3307, (char*)NULL, 0);

	mysql_query(connection, "select * from login");

	sql_result = mysql_store_result(connection);

	gotoxy(MAP_ADJ_X - 10, MAP_ADJ_Y + 15);
	printf("	  �ÿ��� DB �����ڷ�\n\n");
	printf("	ID	PASS	SCORE	ITEM \n");
	int row1 = 0;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) //db�� ����ü ����
	{
		strcpy(us[row1].ID, sql_row[0]);
		strcpy(us[row1].Pass, sql_row[1]);
		us[row1].highscore = atoi(sql_row[2]);
		us[row1].item = atoi(sql_row[3]);
		printf("%10s %9s %8d %6d \n", us[row1].ID, us[row1].Pass, us[row1].highscore, us[row1].item);

		row1++;
	}
	mysql_free_result(sql_result);

	setcursortype(NOCURSOR); //���콺 Ŀ���� ����� 

	int usnum = 0;
	int log = menu();

	if (log == 0) {	//ȸ������
		usnum = make(us);
		sprintf(buffer, "insert into login values" "('%s','%s','%d','%d')", us[usnum].ID, us[usnum].Pass, 0, 0);
		mysql_query(connection, buffer);

	}
	else  if (log == 1) {//�α���
		usnum = login();
	}
	else  if (log == 2) {//ȸ��Ż��
		usnum = del(us);
		sprintf(buffer, "DELETE FROM login WHERE ID = '%s'", us[usnum].ID);
		mysql_query(connection, buffer);
		gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
		printf("ȸ��Ż�� �Ǿ����ϴ�.");
		gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 8);
		printf("������ �ٽý������ּ���.  ");
		Sleep(2000);
		system("cls"); //ȭ���� ���� 
		exit(1);
	}

	else {
		gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
		printf(" �ٽ��Է��ϼ���  ");
		main();
	}
	login_dis(us, usnum);//�α��� ���
	getch();
	reset(us, usnum); //������ �ʱ�ȭ 

	while (1) {
		if (get_key(us, usnum)) {//Ű �Է��� �������� �ִ� ��쿡�� 
			sprintf(buffer, "UPDATE login set highscore = %d WHERE id = '%s'", us[usnum].highscore, us[usnum].ID);
			mysql_query(connection, buffer);

			sprintf(buffer, "UPDATE login set item = %d WHERE id = '%s'", us[usnum].item, us[usnum].ID);
			mysql_query(connection, buffer);

			check_2048(us, usnum);			// ���üũ 
			sprintf(buffer, "UPDATE login set item = %d WHERE id = '%s'", us[usnum].item, us[usnum].ID);

			mysql_query(connection, buffer);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			gotoxy(MAP_ADJ_X + 30, MAP_ADJ_Y - 3);
			printf("%3d ", us[usnum].item);

			new_num();				//���ο� ���ڸ� ���� 
		}
		check_game_over(usnum); // ���ӿ����Ǵ� 

	}

	mysql_close(&conn);
	return 0;
}

//����ȭ�� ����
void reset(struct USER *p, int usnum) {
	int i, j; // for���� ������ ������ 

	system("cls"); //ȭ���� ���� 

	//�������� �ʱ�ȭ 
	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) board[i][j] = 0;

	score = 0;	//�������� �ʱ�ȭ 
	game_over_on = 0;
	made_32 = 0;
	made_64 = 0;
	made_128 = 0;
	made_256 = 0;
	made_512 = 0;
	made_1024 = 0;
	made_2048 = 0;
	made_4096 = 0;

	//����� �׸�     
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   �� ����    ����            ��ITEM��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(MAP_ADJ_X + 40, MAP_ADJ_Y - 4);
	printf("�� ITEM : Q ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(MAP_ADJ_X + 40, MAP_ADJ_Y - 3);
	printf("�� ITEM : W ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ����������������            ��%3d ��", p[usnum].item);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(MAP_ADJ_X + 30, MAP_ADJ_Y - 3);
	printf("%3d ", us[usnum].item);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   �� ����    ����            ��������  ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 1);
	printf("����������������������������");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 1);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 2);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 3);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 4);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 5);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 6);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 7);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 8);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 9);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 10);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 11);
	printf("��                        ��");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 12);
	printf("����������������������������");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 14);
	printf(" �� ��,��,��,�� : Move");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 16);
	printf(" �� ESC : Quit");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 18);
	printf(" �� �ٽ÷α��� : L");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 20);
	printf(" �� ITEM (Q): �������� �����մϴ�. ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22);
	printf(" �� ITEM (W): ������ġ ���ڸ� �Ѵܰ� ���׷��̵� �մϴ�. ");

	//���ο� ���ڸ� 2�� ���� 
	new_num();
	new_num();
}
//����Ű Ŭ���� �̺�Ʈ
int get_key(struct USER *p, int usnum) {
	int i, j;
	int scorere;
	int key = 0; //�Է¹��� Ű�� �����ϴ� ���� 
	int act = 0; //�Է¹��� Ű�� ��ȿ�� �ۿ��� ������ �Լ��� ���� return�ϴ� ���� ���� ���� 
	int mov = -1; //�Է¹��� Ű�� ��ȿ�� �ۿ��� ������ �ݺ����� Ż���Ҽ� �ְ� �ϴ� ���� 

	gotoxy(0, 24); //ESCŰ�� �������� ȭ�� ���� �Ʒ��� ���Ṯ���� ���� ���� Ŀ�� �̵� 
	key = getch(); //Ű�Է¹��� 
	if (key == ESC) {
		system("cls");
		gotoxy(0, 21); //ȭ�� ���� �Ʒ��� ���Ṯ���� ���� ���� Ŀ�� �̵� 
		printf("�����մϴ�.");
		Sleep(300);
		exit(0); // ESCŰ�� ������ �������� 
	}
	if (key == 'q')
	{
		if (p[usnum].item > 0)
		{
			p[usnum].item--;
			for (i = 0; i < 4; i++)
			{
				board[i][0] = 0;
				draw();
				gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
				printf("   �� ����    ����            ��ITEM��");
				gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
				printf("  ����������������            ��%3d ��", p[usnum].item);
				gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
				printf("   �� ����    ����            ��������");
			}

		}
		else {
			gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 4);
			printf("�������̺����մϴ�.");
			Sleep(300);
			gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 4);
			printf("                   ");
		}
	}
	srand(time(NULL));
	int ran = rand() % 5;
	int ran1 = rand() % 5;

	if (key == 'w')
	{
		if (p[usnum].item > 0)
		{
			p[usnum].item--;
			for (i = 0; board[ran][ran1] == 0; i++)
			{
				ran = rand() % 5;
				ran1 = rand() % 5;
			}
			int rannum = board[ran][ran1] * 2;
			board[ran][ran1] = 0;        //�ִϸ��̼� ȿ�� �ι������� 
			draw();		Sleep(100);
			board[ran][ran1] = rannum;
			draw();
			board[ran][ran1] = 0;        //�ִϸ��̼� ȿ�� �ι������� 
			draw();		Sleep(100);
			board[ran][ran1] = rannum;
			draw();		Sleep(100);
			board[ran][ran1] = rannum;
			draw();
			gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
			printf("   �� ����    ����            ��ITEM��");
			gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
			printf("  ����������������            ��%3d ��", p[usnum].item);
			gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
			printf("   �� ����    ����            ��������");

		}
		else {
			gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 4);
			printf("�������̺����մϴ�.");
			Sleep(300);
			gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 4);
			printf("                   ");
		}
	}
	if (key == 't')
	{
		p[usnum].item++;
	}
	if (key == 0xE0 || key == 0) { // 0xE0 ���ڰ� �ƴ� Ȯ��Ű��� Ư�̰��ε� �� ���� ch�� �Է¹ޱ� ���ؼ�
		key = getch();

		switch (key) {
		case LEFT:     //���ʹ���Ű�� ������� 
			for (; mov != 0;) {     //�Լ� ����� mov���� -1�̹Ƿ� ó���� �ݵ�� ����ǰ� ������ 0���� ����, 
				mov = 0;         //���� �����ǿ� ��ȭ�� �ִ� ��쿡 ��ġ �����Ͽ� �����ǿ� ��ȭ�� ���������� �ݺ� 
				for (i = 0; i < 4; i++) {  // ������� �˻� 
					for (j = 1; j <= 3; j++) { //���� ���ʿ�(0��°��)�� �˻��� �ʿ䰡 �����Ƿ� 1~3������ ������� �˻� 
						if (board[i][j] == 0 || board[i][j] > 10000) continue; //�ڱ� ���� 0 Ȥ�� 10000���� ū ���,
						if (board[i][j - 1] != 0 && board[i][j - 1] != board[i][j]) continue;
						//�ڱ� ���ʰ��� 0�� �ƴϰ� �ڽŰ� �ٸ� ��� �ٽ� �˻�(j++�� �����)
						if (board[i][j - 1] == 0) board[i][j - 1] = board[i][j]; //�ڱ� ���ʰ��� 0�ΰ�� �ڱⰪ ���� 
						else if (board[i][j] == board[i][j - 1]) { //�ڱ� ���ʰ��� ������ ��쿡 
							board[i][j - 1] *= 2; //���ʰ��� 2���(�ڱ� ���� ���ϴ°Ͱ� ����) 
							board[i][j - 1] += 10000; // �ӽ÷� ������ �Լ� �������� �ٽ� ���� ���ҽ�Ŵ  

							score += 2 * (board[i][j]); //������ ����     
						}
						board[i][j] = 0; //�ڱ� ���� 0���� ���� 
						act++; // action�� ������ �˸�(get_key �Լ� ����� �Ǵܵ�) 
						mov++; // mov�� ������ �˸�(for���ȿ����� ���ǰ� ���µ�) 

					}   // 10000�� �ȴ��ϸ� ���� ���ٿ� ���� 2,2,2,2 �� ��� ����Ű�� ������ �ѹ���
						//  8,0,0,0���� �ٲ�.. 10000�� ���ϰ�, ���� 10000���� ū ��� ������ ���� �ʰ� �Ͽ�
						// 2,2,2,2 ���� 4,4,0,0���� �ٲ� 
				}

				if (mov != 0) draw();// ������ ��ȭ�� �ִ� ��� 
			}                        // ���� �ٱ� for���� �ѹ� �������� ȭ���� �׷���(�ִϸ��̼� ȿ��) 
			break;

		case RIGHT: // ������ ����Ű�� �������. �۵������� ���� �¿츸 �ٲ� 
			for (; mov != 0;) {
				mov = 0;
				for (j = 2; j >= 0; j--) { //2����, 1����, 0������ ������� �˻�. 
					for (i = 0; i < 4; i++) {  // ������� �˻�
						if (board[i][j] == 0 || board[i][j] > 10000) continue;
						if (board[i][j + 1] != 0 && board[i][j + 1] != board[i][j]) continue;
						if (board[i][j + 1] == 0) board[i][j + 1] = board[i][j];
						else if (board[i][j] < 10000 && board[i][j] == board[i][j + 1]) {
							board[i][j + 1] *= 2;
							board[i][j + 1] += 10000;
							score += 2 * (board[i][j]);
						}
						board[i][j] = 0;
						mov++;
						act++;
					}
				}
				if (mov != 0) draw();
			}
			break;

		case UP: // ���� ����Ű�� �������. �۵������� ���� 
			for (; mov != 0;) {
				mov = 0;
				for (i = 1; i <= 3; i++) { //1����, 2����, 3������ ������� �˻� 
					for (j = 0; j < 4; j++) { //��� ���� �˻� 
						if (board[i][j] == 0 || board[i][j] > 10000) continue;
						if (board[i - 1][j] != 0 && board[i - 1][j] != board[i][j]) continue;
						if (board[i - 1][j] == 0) board[i - 1][j] = board[i][j];
						else if (board[i][j] < 10000 && board[i][j] == board[i - 1][j]) {
							board[i - 1][j] *= 2;
							board[i - 1][j] += 10000;
							score += 2 * (board[i][j]);
						}
						board[i][j] = 0;
						act++;
						mov++;
					}
				}
				if (mov != 0) draw();
			}
			break;

		case DOWN: // �Ʒ��� ����Ű�� �������. �۵������� ����
			for (; mov != 0;) {
				mov = 0;
				for (i = 2; i >= 0; i--) { //2����, 1����, 0������ ������� �˻�  
					for (j = 0; j < 4; j++) { //��� ���� �˻�  
						if (board[i][j] == 0 || board[i][j] > 10000) continue;
						if (board[i + 1][j] != 0 && board[i + 1][j] != board[i][j]) continue;
						if (board[i + 1][j] == 0) board[i + 1][j] = board[i][j];
						else if (board[i][j] < 10000 && board[i][j] == board[i + 1][j]) {
							board[i + 1][j] *= 2;
							board[i + 1][j] += 10000;
							score += 2 * (board[i][j]);
						}
						board[i][j] = 0;
						act++;
						mov++;
					}
				}
				if (mov != 0) draw();
			}
			break;
		}
	}


	for (i = 0; i < 4; i++) { //�ӽ÷� �������״� 10000�� ����. 
		for (j = 0; j < 4; j++) {
			if (board[i][j] > 10000)board[i][j] -= 10000;
		}
	}
	if (p[usnum].highscore < score) {
		p[usnum].highscore = score;
	}
	if ((key == L) || (key == l)) {
		system("cls"); //ȭ���� ���� 
		main();
	}
	if (act == 0) return 0; //���� Ű�Է��� ��ȭ�� ������ 0�� return 
	else return 1;  //Ű�Է��� ��ȭ�� ������ 1�� return 
}

//���� ���ڻ��� ǥ��
void draw() {
	int i, j, k; // for���� ������ ���� ���� 
	int num; // �������� ���� ȭ�鿡 ĭ�� ǥ���ϱ� ���� ������ �˻��ϰ� �Ǵµ� 
			 // 10000�� ������ ���,  �̰��� �ӽ÷� �� ���ڸ� �����ϴ� ���� 

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));
			if (board[i][j] == 0) {												//���� 0�϶� �޼��� ���flag�� ���� �ٸ� ����� ������ 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//��� ���� 8
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));				//��ĭ�� ������ġ X,Y MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3)
				printf("      ");
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);
				if (made_2048 == 1) printf("  ��  ");
				else if (made_1024 == 1) printf("  ��  ");
				else if (made_512 == 1) printf("  ��  ");
				else if (made_256 == 1) printf("  ��  ");
				else if (made_128 == 1) printf("  ��  ");
				else if (made_64 == 1) printf("  ��  ");
				else if (made_32 == 1) printf("  ��  ");
				else printf("  ��  ");
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);
				printf("      ");
			}
			else {
				num = ((board[i][j] > 10000) ? board[i][j] - 10000 : board[i][j]);					//10000�� ������ ��� ���� 
				if (game_over_on == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);//���ӿ����� ��쿡�� ȸ������ 
				else {
					for (k = 0; k < 12;) if ((int)pow(2, ++k) == num) break;		//���� ���� �ٸ� ������ ����	//pow ex) pow(2,3) �� 2�� 3�� = 8�� ��Ÿ����.
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k + 1);//���� ���� 
				}
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));
				printf("������");
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);
				printf(" %4d ", num);
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);
				printf("������");
				if (game_over_on == 1) Sleep(200);   //���ӿ����� ��� ��ĭ �׸��� 0.2���� ������ 
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //���� ����� ��ħ 

	gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 11);
	printf("Score : %6d \n", score); //����ǥ�� 
	Sleep(50);
}
//�����ǿ� �������� 2,4 ���ڻ���
void new_num() {
	int i, j; //for���� ������ ����

	int cnt; //�����ǿ� ��ĭ�� ���� �����ϴ� ���� 
	int rdm; //����ǥ�� ���� ������ ���� �����ϴ� ���� 
	int n_num; // ���ο� ���� 2, 4�� �����ϴ� ���� 
	int* p0[16] = { 0 }; //��ĭ�� ��ġ�� ����� ������ �迭 

	for (i = 0, cnt = 0; i < 4; i++) { //��ü �������� �˻�
		for (j = 0; j < 4; j++) {
			if (board[i][j] == 0) { //��ĭ�� ������ 
				p0[cnt++] = &board[i][j]; //�� ��ġ�� ������ �迭�� ����, cnt�� ���� 
			}
		}
	}

	srand(time(0)); //���� ���� 
	rdm = rand() % (cnt); //������ �迭cnt������ ���� ������ ����. 
	n_num = (rand() % 100 < 80) ? 2 : 4; //80%Ȯ���� 2�� �����, 20%Ȯ���� 4�� ���� 

	*p0[rdm] = n_num; //��ĭ�� ���� ���� 
	draw();
}
//���������޼��� �̺�Ʈ ����
void check_2048(struct USER *p, int usnum) { //32������ ���ο� ū ���� ó�� ��������� �޼��� ǥ��. 
	int i, j, k;
	int item = us[usnum].item;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (board[i][j] == 32 && made_32 == 0) { //ó������ �ǿ� 32�� ������  �̺�Ʈ ����
				made_32 = 1;
				for (k = 0; k < 3; k++) {
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					printf("                                        ");
					Sleep(100);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					printf("Yon made 32 : ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("Good job!");
					Sleep(100);
				}
				item++;
				p[usnum].item = item;
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("������ ŉ��!");
				Sleep(500);
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("                       ");


			}
			if (board[i][j] == 64 && made_64 == 0) {
				made_64 = 1;
				for (k = 0; k < 3; k++) {
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					printf("                                        ");
					Sleep(100);
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("Yon made 64 : ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("Great!   ");
					Sleep(100);
				}
				item++;
				p[usnum].item = item;
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("������ ŉ��!");
				Sleep(500);
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("                       ");
			}
			if (board[i][j] == 128 && made_128 == 0) {
				made_128 = 1;
				for (k = 0; k < 3; k++) {
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					printf("                                        ");
					Sleep(100);
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
					printf("Yon made 128 : ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("Great!");
					Sleep(100);
				}
				item++;
				p[usnum].item = item;
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("������ ŉ��!");
				Sleep(500);
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("                       ");
			}
			if (board[i][j] == 256 && made_256 == 0) {
				made_256 = 1;
				for (k = 0; k < 3; k++) {
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					printf("                                        ");
					Sleep(100);
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					printf("Yon made 256 : ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("Great!");
					Sleep(100);
				}
				item++;
				p[usnum].item = item;
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("������ ŉ��!");
				Sleep(500);
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("                       ");
			}
			if (board[i][j] == 512 && made_512 == 0) {
				made_512 = 1;
				for (k = 0; k < 3; k++) {
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					printf("                                        ");
					Sleep(100);
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					printf("Yon made 512 : ");

					Sleep(100);
				}
				item++;
				p[usnum].item = item;
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("������ ŉ��!");
				Sleep(500);
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("                       ");
			}
			if (board[i][j] == 1024 && made_1024 == 0) {
				made_1024 = 1;
				for (k = 0; k < 3; k++) {
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					printf("                                        ");
					Sleep(100);
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					printf("Yon made 1024!! : ");

					Sleep(100);
				}
			}
			if (board[i][j] == 2048 && made_2048 == 0) {
				made_2048 = 1;
				for (k = 0; k < 3; k++) {
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					printf("                                        ");
					Sleep(100);
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					printf("Congratulations! Yon made 2048 !!");
					Sleep(100);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("You can keep play for a high score;)");
			}
			if (board[i][j] == 4096 && made_4096 == 0) {
				made_4096 = 1;
				for (k = 0; k < 3; k++) {
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
					printf("                                        ");
					Sleep(100);
					gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);

					Sleep(100);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
				printf("You can keep play for a high score;)");
			}
		}
	}
}
//���ӿ������� üũ 
void check_game_over(int usnum) {
	int i, j;

	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) if (board[i][j] == 0) return;			 //�ϴ� ��ĭ�� ������ ���ӿ����� �ƴ� 
	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1]) return;
	//0,0���� 2,2���� �����ʰ� �Ʒ��� �˻� 
	for (i = 0; i < 3; i++) if (board[i][3] == board[i + 1][3]) return;						//��������  �� �Ʒ��� �˻�(�����ʰ��� �����Ƿ�) 
	for (j = 0; j < 3; j++) if (board[3][j] == board[3][j + 1]) return;						//������������ �����ʸ� �˻�(�Ʒ��ʰ��� �����Ƿ�) 
	game_over_on = 1;																		 //���ӿ��� ������ 1

	gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
	printf("Game Over..                             ");
	gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
	printf("                                        ");
	draw();
	gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 4);
	printf("Restart? (Y/N:quit)                     ");											// ������ �ٽ��Ұ��� ��� 

	while (1) {
		switch (getch()) {
		case 121: // 'Y'
		case 89: // 'y'
			reset(us, usnum); //������ �ʱ�ȭ  
			break;
		case 110: // 'N'
		case 78: //'n'
		case ESC:
			gotoxy(0, 21); //ȭ�� ���� �Ʒ��� ���Ṯ���� ���� ���� Ŀ�� �̵� 
			system("cls");
			exit(0);
		}
		break;
	}
}


//ȸ������, �α���ȭ��
int menu() {
	int x = 0;
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   �� ����    ����");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ����������������");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   �� ����    ����");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
	printf(" ��ȸ������ : 0");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
	printf(" �޷α��� : 1");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
	printf(" ��ȸ��Ż�� : 2");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 8);
	scanf("%d", &x);
	system("cls");
	return x;
}
// �α���ȭ��
int login(void) {
	char ID1[50];	//���� 
	char PASS1[50]; //����
	int j = 0;
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   �� ����    ����");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ����������������");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   �� ����    ����");


	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
	printf(" ��ID : ");
	scanf("%s", ID1); //&ID1
	for (int i = 0; i < SIZE; i++) {
		if (strcmp(us[i].ID, ID1) == 0) {
			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
			printf(" ��PASS : ");
			while (1)	//��й�ȣ �Է¹�� ******
			{
				if (kbhit()) //kb hit  Ű���� ��Ʈ Ű���尡 ���� �Էµ� ���������� ����
				{
					PASS1[j] = getch();
					if (PASS1[j] == 13)	// 13 =ENTER
					{
						break;
					}
					j++;
					printf("*");
				}
			}
			PASS1[j] = '\0';

			if (strcmp(us[i].Pass, PASS1) == 0) {
				gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
				printf("�α��ο� �����Ͽ����ϴ�.");
				Sleep(500);
				system("cls"); //ȭ���� ���� 
			}
			else {
				gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
				printf("��й�ȣ�� Ʋ�ǽ��ϴ�.");
				Sleep(500);
				system("cls"); //ȭ���� ���� 
				main();
			}
			return i;
		}
	}
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
	printf("���� ���̵��Դϴ�. �ٽ��Է����ּ���");
	Sleep(500);
	system("cls");
	main();
}
// ȸ������ȭ��
int make(struct USER *p)
{
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   �� ����    ����");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ����������������");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   �� ����    ����");

	for (int i = 0; i < SIZE; i++)
	{

		if (*p[i].ID == 0) {		//id�� ���̾�����
			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
			printf(" ��ID : ");
			scanf("%s", &p[i].ID);
			for (int j = 0; j < i; j++) {

				if (strcmp(p[i].ID, p[j].ID) == 0) {		//���̵� �ߺ�üũ
					gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
					printf("�̹̻������ ���̵��Դϴ�.");
					//strcpy(us[i].ID, 0);
					*p[i].ID = 0;
					Sleep(500);
					system("cls");
					main();
				}
			}

			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
			printf(" ��PASS : ");
			scanf("%s", &p[i].Pass);
			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
			printf(" ȸ�������ϼ˽��ϴ�.");
			Sleep(500);
			system("cls");
			return i;
		}
	}
}
// ȸ��Ż��ȭ�� //�⸻�����ϼ�����
int del(struct USER *p) {
	char ID2[50];
	char PASS2[50];
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   �� ����    ����");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ����������������");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   �� ����    ����");



	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
	printf(" ��ID : ");
	scanf("%s", ID2);
	for (int j = 0; j < SIZE; j++)
	{
		if (strcmp(ID2, p[j].ID) == 0)
		{		//���̵� �ߺ�üũ
			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
			printf(" ��PASS : ");
			scanf("%s", PASS2);
			if (strcmp(PASS2, p[j].Pass) != 0) {
				gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
				printf(" ��й�ȣ�� Ʋ�Ƚ��ϴ�..");
				Sleep(500);
				system("cls");
				main();
			}
			Sleep(500);
			system("cls"); //ȭ���� ���� 
			return j;
		}
	}

	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
	printf(" ���¾��̵��Դϴ�.");
	Sleep(500);
	system("cls");
	main();

}
// �α��� ������ ȭ��
void login_dis(struct USER *p, int usnum) {
	char rank[10] = "";
	system("cls");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   �� ����    ����");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ����������������");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   �� ����    ����");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y);
	printf("�α��� �Ǿ����ϴ�.\n");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
	printf(" ��ID : %s ", p[usnum].ID);
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
	printf(" ��Pass : %s", p[usnum].Pass);
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
	printf(" ��Score : %5d", p[usnum].highscore);
	if (p[usnum].highscore < 500) {
		strcpy(rank, "�����");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}
	else if (p[usnum].highscore < 500) {
		strcpy(rank, "�ǹ�");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (p[usnum].highscore < 1000) {
		strcpy(rank, "���");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	}
	else {
		strcpy(rank, "���̾�");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	}
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 8);
	printf(" ��Rank : %5s", rank);
}
