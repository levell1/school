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

//화살표등 아스키코드 DEFINE
#define LEFT 75		
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define L 76
#define l 108

//기준이될 X축 과 Y축 DEFINE
#define MAP_ADJ_X 10
#define MAP_ADJ_Y 5

//회원관련 SIZE
#define SIZE 100
//모니터상의 x,y 좌표로 이동시키는 함수 windows.h 에포함되어있다.
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef enum { NOCURSOR } CURSOR_TYPE;
//커서 표시를 지워주는 함수  
void setcursortype(CURSOR_TYPE c) {
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	}
	// SetConsoleCursorInfo(두께 or 노출여부) 를 설정하는 역할
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
// 게임판
int board[4][4] = {
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
};

int x = 0;
int game_over_on = 0;	//게임 오버 스위치 
int score;				//점수 저장함수 
int made_32;			// 각 해당하는 번호의 블록을 만들었을때  
int made_64;			// 메세지 띄워주기 위한 변수들
int made_128;
int made_256;
int made_512;
int made_1024;
int made_2048;
int made_4096;

//회원 구조체
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


void reset(struct USER *p, int usnum);				// 게임을 초기화 
void draw(void);				// 게임판을 그림 
void new_num(void);				// 새로운 숫자 2나 4를 게임판에 만듦 
int  get_key(struct USER *p, int usnum);				// 키입력받고 움직이는 함수 
void check_2048(struct USER *p, int usnum);			// 블록을 만들었을때 메세지 띄어주는 함수 
void check_game_over(int usnum);		// 게임오버를 판단하는 함수 


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
	printf("	  시연시 DB 참고자료\n\n");
	printf("	ID	PASS	SCORE	ITEM \n");
	int row1 = 0;
	while ((sql_row = mysql_fetch_row(sql_result)) != NULL) //db와 구조체 연결
	{
		strcpy(us[row1].ID, sql_row[0]);
		strcpy(us[row1].Pass, sql_row[1]);
		us[row1].highscore = atoi(sql_row[2]);
		us[row1].item = atoi(sql_row[3]);
		printf("%10s %9s %8d %6d \n", us[row1].ID, us[row1].Pass, us[row1].highscore, us[row1].item);

		row1++;
	}
	mysql_free_result(sql_result);

	setcursortype(NOCURSOR); //마우스 커서를 지우기 

	int usnum = 0;
	int log = menu();

	if (log == 0) {	//회원가입
		usnum = make(us);
		sprintf(buffer, "insert into login values" "('%s','%s','%d','%d')", us[usnum].ID, us[usnum].Pass, 0, 0);
		mysql_query(connection, buffer);

	}
	else  if (log == 1) {//로그인
		usnum = login();
	}
	else  if (log == 2) {//회원탈퇴
		usnum = del(us);
		sprintf(buffer, "DELETE FROM login WHERE ID = '%s'", us[usnum].ID);
		mysql_query(connection, buffer);
		gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
		printf("회원탈퇴 되었습니다.");
		gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 8);
		printf("게임을 다시실행해주세요.  ");
		Sleep(2000);
		system("cls"); //화면을 지움 
		exit(1);
	}

	else {
		gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
		printf(" 다시입력하세요  ");
		main();
	}
	login_dis(us, usnum);//로그인 기능
	getch();
	reset(us, usnum); //게임을 초기화 

	while (1) {
		if (get_key(us, usnum)) {//키 입력후 움직임이 있는 경우에만 
			sprintf(buffer, "UPDATE login set highscore = %d WHERE id = '%s'", us[usnum].highscore, us[usnum].ID);
			mysql_query(connection, buffer);

			sprintf(buffer, "UPDATE login set item = %d WHERE id = '%s'", us[usnum].item, us[usnum].ID);
			mysql_query(connection, buffer);

			check_2048(us, usnum);			// 블록체크 
			sprintf(buffer, "UPDATE login set item = %d WHERE id = '%s'", us[usnum].item, us[usnum].ID);

			mysql_query(connection, buffer);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			gotoxy(MAP_ADJ_X + 30, MAP_ADJ_Y - 3);
			printf("%3d ", us[usnum].item);

			new_num();				//새로운 숫자를 만듦 
		}
		check_game_over(usnum); // 게임오버판단 

	}

	mysql_close(&conn);
	return 0;
}

//게임화면 리셋
void reset(struct USER *p, int usnum) {
	int i, j; // for문을 돌리는 변수들 

	system("cls"); //화면을 지움 

	//게임판을 초기화 
	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) board[i][j] = 0;

	score = 0;	//각종변수 초기화 
	game_over_on = 0;
	made_32 = 0;
	made_64 = 0;
	made_128 = 0;
	made_256 = 0;
	made_512 = 0;
	made_1024 = 0;
	made_2048 = 0;
	made_4096 = 0;

	//배경을 그림     
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   ㅡ ┌┐    ┌┐            ┌ITEM┐");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(MAP_ADJ_X + 40, MAP_ADJ_Y - 4);
	printf("◇ ITEM : Q ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(MAP_ADJ_X + 40, MAP_ADJ_Y - 3);
	printf("◇ ITEM : W ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ┌┘││└╂├┤            │%3d │", p[usnum].item);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(MAP_ADJ_X + 30, MAP_ADJ_Y - 3);
	printf("%3d ", us[usnum].item);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   ─ └┘    └┘            └──┘  ");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 1);
	printf("┌────────────┐");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 1);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 2);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 3);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 4);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 5);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 6);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 7);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 8);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 9);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 10);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 11);
	printf("│                        │");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 12);
	printf("└────────────┘");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 14);
	printf(" ◇ ←,→,↑,↓ : Move");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 16);
	printf(" ◇ ESC : Quit");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 18);
	printf(" ◇ 다시로그인 : L");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 20);
	printf(" ◇ ITEM (Q): 왼쪽행을 삭제합니다. ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y + 22);
	printf(" ◇ ITEM (W): 랜덤위치 숫자를 한단계 업그레이드 합니다. ");

	//새로운 숫자를 2개 만듦 
	new_num();
	new_num();
}
//방향키 클릭시 이벤트
int get_key(struct USER *p, int usnum) {
	int i, j;
	int scorere;
	int key = 0; //입력받은 키를 저장하는 변수 
	int act = 0; //입력받은 키가 유효한 작용을 했을때 함수가 값을 return하는 것을 돕는 변수 
	int mov = -1; //입력받은 키가 유효한 작용을 했을때 반복문을 탈출할수 있게 하는 변수 

	gotoxy(0, 24); //ESC키를 눌렀을때 화면 제일 아래에 종료문구를 띄우기 위해 커서 이동 
	key = getch(); //키입력받음 
	if (key == ESC) {
		system("cls");
		gotoxy(0, 21); //화면 제일 아래에 종료문구를 띄우기 위해 커서 이동 
		printf("종료합니다.");
		Sleep(300);
		exit(0); // ESC키를 누르면 게임종료 
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
				printf("   ㅡ ┌┐    ┌┐            ┌ITEM┐");
				gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
				printf("  ┌┘││└╂├┤            │%3d │", p[usnum].item);
				gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
				printf("   ─ └┘    └┘            └──┘");
			}

		}
		else {
			gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 4);
			printf("아이탬이부족합니다.");
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
			board[ran][ran1] = 0;        //애니메이션 효과 두번깜박임 
			draw();		Sleep(100);
			board[ran][ran1] = rannum;
			draw();
			board[ran][ran1] = 0;        //애니메이션 효과 두번깜박임 
			draw();		Sleep(100);
			board[ran][ran1] = rannum;
			draw();		Sleep(100);
			board[ran][ran1] = rannum;
			draw();
			gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
			printf("   ㅡ ┌┐    ┌┐            ┌ITEM┐");
			gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
			printf("  ┌┘││└╂├┤            │%3d │", p[usnum].item);
			gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
			printf("   ─ └┘    └┘            └──┘");

		}
		else {
			gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 4);
			printf("아이탬이부족합니다.");
			Sleep(300);
			gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 4);
			printf("                   ");
		}
	}
	if (key == 't')
	{
		p[usnum].item++;
	}
	if (key == 0xE0 || key == 0) { // 0xE0 문자가 아닌 확장키라는 특이값인데 이 값을 ch로 입력받기 위해서
		key = getch();

		switch (key) {
		case LEFT:     //왼쪽방향키를 누른경우 
			for (; mov != 0;) {     //함수 실행시 mov값이 -1이므로 처음엔 반드시 실행되고 실행후 0으로 변경, 
				mov = 0;         //이후 게임판에 변화가 있는 경우에 수치 증가하여 게임판에 변화가 없을때까지 반복 
				for (i = 0; i < 4; i++) {  // 모든행을 검사 
					for (j = 1; j <= 3; j++) { //가장 왼쪽열(0번째열)은 검사할 필요가 없으므로 1~3번열을 순서대로 검사 
						if (board[i][j] == 0 || board[i][j] > 10000) continue; //자기 값이 0 혹은 10000보다 큰 경우,
						if (board[i][j - 1] != 0 && board[i][j - 1] != board[i][j]) continue;
						//자기 왼쪽값이 0이 아니고 자신과 다른 경우 다시 검사(j++은 적용됨)
						if (board[i][j - 1] == 0) board[i][j - 1] = board[i][j]; //자기 왼쪽값이 0인경우 자기값 복사 
						else if (board[i][j] == board[i][j - 1]) { //자기 왼쪽값과 동일한 경우에 
							board[i][j - 1] *= 2; //왼쪽값을 2배로(자기 값을 더하는것과 같음) 
							board[i][j - 1] += 10000; // 임시로 값증가 함수 마지막에 다시 값을 감소시킴  

							score += 2 * (board[i][j]); //점수를 증가     
						}
						board[i][j] = 0; //자기 값은 0으로 지움 
						act++; // action이 있음을 알림(get_key 함수 종료시 판단됨) 
						mov++; // mov가 있음을 알림(for문안에서만 사용되고 리셋됨) 

					}   // 10000을 안더하면 만약 한줄에 값이 2,2,2,2 인 경우 왼쪽키를 누르면 한번에
						//  8,0,0,0으로 바뀜.. 10000을 더하고, 값이 10000보다 큰 경우 연산을 하지 않게 하여
						// 2,2,2,2 에서 4,4,0,0으로 바뀜 
				}

				if (mov != 0) draw();// 게임판 변화가 있는 경우 
			}                        // 제일 바깥 for문을 한번 돌때마다 화면을 그려줌(애니메이션 효과) 
			break;

		case RIGHT: // 오른쪽 방향키를 누른경우. 작동원리는 동일 좌우만 바뀜 
			for (; mov != 0;) {
				mov = 0;
				for (j = 2; j >= 0; j--) { //2번열, 1번열, 0번열을 순서대로 검사. 
					for (i = 0; i < 4; i++) {  // 모든행을 검사
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

		case UP: // 위쪽 방향키를 누른경우. 작동원리는 동일 
			for (; mov != 0;) {
				mov = 0;
				for (i = 1; i <= 3; i++) { //1번행, 2번행, 3번행을 순서대로 검사 
					for (j = 0; j < 4; j++) { //모든 열을 검사 
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

		case DOWN: // 아래쪽 방향키를 누른경우. 작동원리는 동일
			for (; mov != 0;) {
				mov = 0;
				for (i = 2; i >= 0; i--) { //2번행, 1번행, 0번행을 순서대로 검사  
					for (j = 0; j < 4; j++) { //모든 열을 검사  
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


	for (i = 0; i < 4; i++) { //임시로 증가시켰던 10000을 빼줌. 
		for (j = 0; j < 4; j++) {
			if (board[i][j] > 10000)board[i][j] -= 10000;
		}
	}
	if (p[usnum].highscore < score) {
		p[usnum].highscore = score;
	}
	if ((key == L) || (key == l)) {
		system("cls"); //화면을 지움 
		main();
	}
	if (act == 0) return 0; //만약 키입력후 변화가 없으면 0을 return 
	else return 1;  //키입력후 변화가 있으면 1을 return 
}

//배경과 숫자색을 표현
void draw() {
	int i, j, k; // for문을 돌리기 위한 변수 
	int num; // 게임판의 값을 화면에 칸을 표시하기 위한 색깔을 검사하게 되는데 
			 // 10000이 더해진 경우,  이값을 임시로 뺀 숫자를 저장하는 변수 

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));
			if (board[i][j] == 0) {												//값이 0일때 달성한 블록flag에 따라 다른 배경을 보여줌 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);	//배경 색갈 8
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));				//각칸의 시작위치 X,Y MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3)
				printf("      ");
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);
				if (made_2048 == 1) printf("  ♥  ");
				else if (made_1024 == 1) printf("  ♡  ");
				else if (made_512 == 1) printf("  ♬  ");
				else if (made_256 == 1) printf("  ♪  ");
				else if (made_128 == 1) printf("  ♩  ");
				else if (made_64 == 1) printf("  ♣  ");
				else if (made_32 == 1) printf("  ♤  ");
				else printf("  ┿  ");
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);
				printf("      ");
			}
			else {
				num = ((board[i][j] > 10000) ? board[i][j] - 10000 : board[i][j]);					//10000이 더해진 경우 보정 
				if (game_over_on == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);//게임오버인 경우에는 회색으로 
				else {
					for (k = 0; k < 12;) if ((int)pow(2, ++k) == num) break;		//값에 따라 다른 색깔값을 구함	//pow ex) pow(2,3) 은 2의 3승 = 8을 나타낸다.
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k + 1);//색깔값 적용 
				}
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));
				printf("┌─┐");
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);
				printf(" %4d ", num);
				gotoxy(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);
				printf("└─┘");
				if (game_over_on == 1) Sleep(200);   //게임오버인 경우 한칸 그리고 0.2초의 딜레이 
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //원래 색깔로 고침 

	gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 11);
	printf("Score : %6d \n", score); //점수표시 
	Sleep(50);
}
//게임판에 랜덤으로 2,4 숫자생성
void new_num() {
	int i, j; //for문을 돌리는 변수

	int cnt; //게임판에 빈칸을 세어 저장하는 변수 
	int rdm; //난수표에 의해 생성된 값을 저장하는 변수 
	int n_num; // 새로운 숫자 2, 4를 저장하는 변수 
	int* p0[16] = { 0 }; //빈칸의 위치를 기억할 포인터 배열 

	for (i = 0, cnt = 0; i < 4; i++) { //전체 게임판을 검사
		for (j = 0; j < 4; j++) {
			if (board[i][j] == 0) { //빈칸이 있으면 
				p0[cnt++] = &board[i][j]; //그 위치를 포인터 배열에 저장, cnt값 증가 
			}
		}
	}

	srand(time(0)); //난수 생성 
	rdm = rand() % (cnt); //포인터 배열cnt수보다 작은 값으로 저장. 
	n_num = (rand() % 100 < 80) ? 2 : 4; //80%확률로 2을 만들고, 20%확률로 4를 만듦 

	*p0[rdm] = n_num; //빈칸에 수를 넣음 
	draw();
}
//일정점수달성시 이벤트 생성
void check_2048(struct USER *p, int usnum) { //32번부터 새로운 큰 수를 처음 만들었을때 메세지 표시. 
	int i, j, k;
	int item = us[usnum].item;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (board[i][j] == 32 && made_32 == 0) { //처음으로 판에 32가 있으면  이벤트 생성
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
				printf("아이탬 흭득!");
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
				printf("아이탬 흭득!");
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
				printf("아이탬 흭득!");
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
				printf("아이탬 흭득!");
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
				printf("아이탬 흭득!");
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
//게임오버인지 체크 
void check_game_over(int usnum) {
	int i, j;

	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) if (board[i][j] == 0) return;			 //일단 빈칸이 있으면 게임오버가 아님 
	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1]) return;
	//0,0부터 2,2까지 오른쪽과 아래를 검사 
	for (i = 0; i < 3; i++) if (board[i][3] == board[i + 1][3]) return;						//마지막열  은 아래만 검사(오른쪽값이 없으므로) 
	for (j = 0; j < 3; j++) if (board[3][j] == board[3][j + 1]) return;						//마지막번행은 오른쪽만 검사(아래쪽값이 없으므로) 
	game_over_on = 1;																		 //게임오버 변수값 1

	gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y);
	printf("Game Over..                             ");
	gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);
	printf("                                        ");
	draw();
	gotoxy(MAP_ADJ_X + 28, MAP_ADJ_Y + 4);
	printf("Restart? (Y/N:quit)                     ");											// 게임을 다시할건지 물어봄 

	while (1) {
		switch (getch()) {
		case 121: // 'Y'
		case 89: // 'y'
			reset(us, usnum); //게임을 초기화  
			break;
		case 110: // 'N'
		case 78: //'n'
		case ESC:
			gotoxy(0, 21); //화면 제일 아래에 종료문구를 띄우기 위해 커서 이동 
			system("cls");
			exit(0);
		}
		break;
	}
}


//회원가입, 로그인화면
int menu() {
	int x = 0;
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   ㅡ ┌┐    ┌┐");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ┌┘││└╂├┤");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   ─ └┘    └┘");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
	printf(" ◇회원가입 : 0");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
	printf(" ◇로그인 : 1");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
	printf(" ◇회원탈퇴 : 2");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 8);
	scanf("%d", &x);
	system("cls");
	return x;
}
// 로그인화면
int login(void) {
	char ID1[50];	//변수 
	char PASS1[50]; //변수
	int j = 0;
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   ㅡ ┌┐    ┌┐");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ┌┘││└╂├┤");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   ─ └┘    └┘");


	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
	printf(" ◇ID : ");
	scanf("%s", ID1); //&ID1
	for (int i = 0; i < SIZE; i++) {
		if (strcmp(us[i].ID, ID1) == 0) {
			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
			printf(" ◇PASS : ");
			while (1)	//비밀번호 입력방식 ******
			{
				if (kbhit()) //kb hit  키보드 히트 키보드가 지금 입력된 상태인지를 조사
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
				printf("로그인에 성공하였습니다.");
				Sleep(500);
				system("cls"); //화면을 지움 
			}
			else {
				gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
				printf("비밀번호가 틀렷습니다.");
				Sleep(500);
				system("cls"); //화면을 지움 
				main();
			}
			return i;
		}
	}
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
	printf("없는 아이디입니다. 다시입력해주세요");
	Sleep(500);
	system("cls");
	main();
}
// 회원가입화면
int make(struct USER *p)
{
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   ㅡ ┌┐    ┌┐");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ┌┘││└╂├┤");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   ─ └┘    └┘");

	for (int i = 0; i < SIZE; i++)
	{

		if (*p[i].ID == 0) {		//id에 값이없으면
			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
			printf(" ◇ID : ");
			scanf("%s", &p[i].ID);
			for (int j = 0; j < i; j++) {

				if (strcmp(p[i].ID, p[j].ID) == 0) {		//아이디 중복체크
					gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
					printf("이미사용중인 아이디입니다.");
					//strcpy(us[i].ID, 0);
					*p[i].ID = 0;
					Sleep(500);
					system("cls");
					main();
				}
			}

			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
			printf(" ◇PASS : ");
			scanf("%s", &p[i].Pass);
			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
			printf(" 회원가입하셧습니다.");
			Sleep(500);
			system("cls");
			return i;
		}
	}
}
// 회원탈퇴화면 //기말까지완성예정
int del(struct USER *p) {
	char ID2[50];
	char PASS2[50];
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   ㅡ ┌┐    ┌┐");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ┌┘││└╂├┤");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   ─ └┘    └┘");



	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
	printf(" ◇ID : ");
	scanf("%s", ID2);
	for (int j = 0; j < SIZE; j++)
	{
		if (strcmp(ID2, p[j].ID) == 0)
		{		//아이디 중복체크
			gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
			printf(" ◇PASS : ");
			scanf("%s", PASS2);
			if (strcmp(PASS2, p[j].Pass) != 0) {
				gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
				printf(" 비밀번호가 틀렸습니다..");
				Sleep(500);
				system("cls");
				main();
			}
			Sleep(500);
			system("cls"); //화면을 지움 
			return j;
		}
	}

	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
	printf(" 없는아이디입니다.");
	Sleep(500);
	system("cls");
	main();

}
// 로그인 성공시 화면
void login_dis(struct USER *p, int usnum) {
	char rank[10] = "";
	system("cls");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);
	printf("   ㅡ ┌┐    ┌┐");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);
	printf("  ┌┘││└╂├┤");
	gotoxy(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);
	printf("   ─ └┘    └┘");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y);
	printf("로그인 되었습니다.\n");
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 2);
	printf(" ◇ID : %s ", p[usnum].ID);
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 4);
	printf(" ◇Pass : %s", p[usnum].Pass);
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 6);
	printf(" ◇Score : %5d", p[usnum].highscore);
	if (p[usnum].highscore < 500) {
		strcpy(rank, "브론즈");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}
	else if (p[usnum].highscore < 500) {
		strcpy(rank, "실버");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (p[usnum].highscore < 1000) {
		strcpy(rank, "골드");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	}
	else {
		strcpy(rank, "다이아");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	}
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + 8);
	printf(" ◇Rank : %5s", rank);
}
