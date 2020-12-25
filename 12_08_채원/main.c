#include "block.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "manual.h"
#include "game_screen.h"
#include "cursor.h"
#include "show.h"
#include "title.h"
/* 음악 */
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib");
#define Good "C:\\Users\\Gram\\Timer.wav"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define SPACE 32

#define MARGIN_LEFT 8
#define MARGIN_TOP 5

/* 계이름 정의 */
#define _C 1046.502
#define _D 1174.659
#define _E 1318.510
#define _G 1567.982

/* 색깔 정의 */
#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(COL, 0x000c);
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);
#define HIGH SetConsoleTextAttribute(COL,0x00a); // 연두색
#define GREEN SetConsoleTextAttribute(COL, 0x0002);
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);
#define BLUE SetConsoleTextAttribute(COL, 0x0001);
#define PURPLE SetConsoleTextAttribute(COL, 0x000d);
#define WHITE SetConsoleTextAttribute(COL, 0x000f);


/* 게임 상태를 표시해주는 열거형 */
enum _GameState {
	STAGE_CLEAR,
	STAGE_OVER,
	GAME_CLEAR,
	GAME_INIT,
	GAME_OVER,
} GameState;

enum _Direction {
	dir_left,
	dir_right,
	dir_top,
	dir_down,
	horizontal,
	vertical
} Direction;

/* 현재 게임 스테이지를 표시해주는 변수*/
int currentStageNumber = 0;
/*게이지 상태*/
int gauge;

typedef struct _Player {
	int x;
	int y;
	int dir; // player 이동 방향
	bool moving; // player가 이동중인지 판단
} Player;

typedef struct _Npc {
	int x;
	int y;
	int horizontal;
	int vertical;
	int distance; // 최대 이동 거리
	int forward;
} Npc;

/*아이템 구조체*/
typedef struct _Shield {
	int Sec; //display 
	int startSec; //아이템 시작된 sec
	int flag;
	bool isUsedFirst;
	bool Active; //유효성
} Shield;

typedef struct _NpcBoost {
	int Sec;
	int startSec;
	int flag;
	bool isUsedFirst;
	bool Active;
} NpcBoost;

typedef struct _ChangeKey {
	int Sec;
	int startSec;
	int flag;
	bool isUsedFirst;
	bool Active;
} ChangeKey;

typedef struct _Gauge {
	int flag;
	bool Active;
} Gauge;


struct _Item {
	Shield shield;
	NpcBoost npcBoost;
	ChangeKey changeKey;
	Gauge gauge;
	// struct GaugeUp;
} itemBundle;

/*
 NPC 움직임
*/
Npc npcList[4][10] = {
	{
	   {MARGIN_LEFT + 4, MARGIN_TOP + 2, 0, 1, 3, 1},
	   {MARGIN_LEFT + 20, MARGIN_TOP + 2, 2, 0, 3, 1},
	   {MARGIN_LEFT + 2, MARGIN_TOP + 10, 2, 0, 3, 1},
	},
	{
	   {MARGIN_LEFT + 4, MARGIN_TOP + 1, 0, 1, 3, 1},
	   {MARGIN_LEFT + 22, MARGIN_TOP + 5, 2, 0, 3, 1},
	   {MARGIN_LEFT + 2, MARGIN_TOP + 12, 0, 1, 3, 1},
	   {MARGIN_LEFT + 22, MARGIN_TOP + 14, 2, 0, 3, 1},
	   {MARGIN_LEFT + 24, MARGIN_TOP + 18, 0, 1, 3, 1},
	   {MARGIN_LEFT + 26, MARGIN_TOP + 18, 0, 1, 3, 1},
	},
	{
	   {MARGIN_LEFT + 2, MARGIN_TOP + 16, 2, 0, 3, 1},
	   {MARGIN_LEFT + 2, MARGIN_TOP + 14, 2, 0, 3, 1},
	   {MARGIN_LEFT + 12, MARGIN_TOP + 1, 2, 0, 3, 1},
	   {MARGIN_LEFT + 18, MARGIN_TOP + 11, 2, 0, 3, 1},
	}
};

int npcCount[100] = { 3, 6, 4, 0, 0, };
int randomMapCount = 1;
int startX = 1, startY = 23, startDir;
int recentX, recentY, recentDir;
int dontHit = 0;

int curPosX, curPosY, stageNumber, speed;

int saveMapGauge, saveMapNumber = 0;

/*Game 모듈*/
void timeCheck(int end_min, int end_sec);
game(int currentStage);

/*Movement&Collision 모듈*/
keyInput(Player *player);
playerMove(Player *player, Npc **npcList);
int detectCollision(int posX, int posY, char blockModel[100][100]);

moveUp(Player *player, Npc *npcList);
moveDown(Player *player, Npc *npcList);
moveRight(Player *player, Npc *npcList);
moveLeft(Player *player, Npc *npcList);

void playerCollision(Player* player, Npc* npcList);
int trapCollision(Player* player, char blockModel[100][100]);
int goalCollision(Player* player, char blockModel[100][100]);
int itemCollision(Player* player, char blockModel[100][100]);
void playerDie(Player* player);

/* NPC 모듈*/
int moveNpc(Player *player, Npc *npc, int gameSpeedController);

/*아이템 모듈*/
void initItem();
void onChangeGauge(int changeValue);
int onChangeKey(int key);
void itemFirstState(int block_id);
void itemActiveCheck();
int getItemTime(int startSec);
void showItemList();

void initItem() {
	itemBundle.shield.Sec = 10;
	itemBundle.shield.flag = 0;
	itemBundle.shield.Active = false;
	itemBundle.shield.isUsedFirst = false;

	itemBundle.npcBoost.Sec = 10;
	itemBundle.npcBoost.flag = 0;
	itemBundle.npcBoost.Active = false;
	itemBundle.npcBoost.isUsedFirst = false;

	itemBundle.changeKey.Sec = 10;
	itemBundle.changeKey.flag = 0;
	itemBundle.changeKey.Active = false;
	itemBundle.changeKey.isUsedFirst = false;

	itemBundle.gauge.flag = 0;
	itemBundle.gauge.Active = false;
}

/*
 NPC 관련 모듈
*/

int npcCollision(Player *player, Npc *npcList) {
	for (Npc *npc = npcList; npc < npcList + 3; npc++) {
		if ((player->x == npc->x) && (player->y == npc->y))
			return 1;
		else return 0;
	}
}

int moveNpc(Player *player, Npc *npc, int gameSpeedController)
{


	if (detectCollision(npc->x + npc->horizontal * npc->forward, npc->y + npc->vertical * npc->forward, blockModel[stageNumber])) {
		npc->forward = npc->forward * -1;
		return;
	}


	// NPC 충돌이라면
	deleteNpc(npc->x, npc->y);
	if (gameSpeedController == 2 || itemBundle.npcBoost.Active == true) {

		npc->x += npc->horizontal * npc->forward;
		npc->y += npc->vertical * npc->forward;

	}
	showNpc(npc->x, npc->y);

	if (itemBundle.shield.Active == false && dontHit == 0) {//쉴드 비활성 중일 때
		if (npc->x == player->x && npc->y == player->y) {
			//게임 다시시작
			playerDie(player);
			game(stageNumber);

		}
	}
	else { //쉴드 활성 중일 때
		if (npc->x == player->x && npc->y == player->y) {
			//충돌하면 쉴드 비활성화
			itemBundle.shield.Active = false;
			dontHit = 1;

		}
	}
	if (dontHit >= 1) {
		dontHit++;
	}

	if (dontHit == 20) {
		dontHit = 0;
	}

}

/*
 Player 관련 모듈
*/

playerMove(Player *player, Npc **npcList) {
	switch (player->dir)
	{
	case dir_top:
		moveUp(player, npcList);
		break;
	case dir_down:
		moveDown(player, npcList);
		break;
	case dir_left:
		moveLeft(player, npcList);
		break;
	case dir_right:
		moveRight(player, npcList);
		break;
	}
	Sleep(speed);
}

keyInput(Player *player) {
	int i, key;
	player->moving = true;
	for (i = 0; i < 20; i++) {
		if (_kbhit() != 0) {
			key = getch();
			if (itemBundle.changeKey.Active == true) key = onChangeKey(key);
			switch (key)
			{
			case UP:
				if (player->dir != dir_top) {
					player->dir = dir_top;
					onChangeGauge(-1);
				}
				break;
			case DOWN:
				if (player->dir != dir_down) {
					player->dir = dir_down;
					onChangeGauge(-1);
				}
				break;
			case LEFT:
				if (player->dir != dir_left) {
					player->dir = dir_left;
					onChangeGauge(-1);
				}
				break;
			case RIGHT:
				if (player->dir != dir_right) {
					player->dir = dir_right;
					onChangeGauge(-1);
				}
				break;
			}
		}
	}
}

moveLeft(Player *player, Npc *npcList) {
	if (detectCollision(player->x - 2, player->y, blockModel[stageNumber])) {
		player->moving = false;
		return;
	}
	SetCurrentCursorPos(player->x, player->y);
	DeletePlayer(*player);
	player->x -= 2;
	showPlayer(player->x, player->y);
	playerCollision(player, npcList);
}
moveRight(Player *player, Npc *npcList) {
	if (detectCollision(player->x + 2, player->y, blockModel[stageNumber])) {
		player->moving = false;
		return;
	}
	SetCurrentCursorPos(player->x, player->y);
	DeletePlayer(*player);
	player->x += 2;
	showPlayer(player->x, player->y);
	playerCollision(player, npcList);
}
moveUp(Player *player, Npc *npcList) {
	if (detectCollision(player->x, player->y - 1, blockModel[stageNumber])) {
		player->moving = false;
		return;
	}
	SetCurrentCursorPos(player->x, player->y);
	DeletePlayer(*player);
	player->y -= 1;
	showPlayer(player->x, player->y);
	playerCollision(player, npcList);
}
moveDown(Player *player, Npc *npcList) {
	if (detectCollision(player->x, player->y + 1, blockModel[stageNumber])) {
		player->moving = false;
		return;
	}
	SetCurrentCursorPos(player->x, player->y);
	DeletePlayer(*player);
	player->y += 1;
	showPlayer(player->x, player->y);
	playerCollision(player, npcList);
}

int detectCollision(int posX, int posY, char blockModel[100][100]) {
	int x = (posX - MARGIN_LEFT) / 2;
	int y = posY - MARGIN_TOP;

	if (blockModel[y][x] == 1) {
		return 1;
	}
	return 0;
}

void playerCollision(Player *player, Npc *npcList) {

	// 아이템 충돌이라면
	if (itemCollision(player, blockModel[stageNumber]) != 0) {

		if (itemCollision(player, blockModel[stageNumber]) == 4) {

			if (itemBundle.shield.flag == 0) {
				itemFirstState(4);
			}
		}
		else if (itemCollision(player, blockModel[stageNumber]) == 5) {

			if (itemBundle.npcBoost.flag == 0) {
				itemFirstState(5);
			}
		}
		else if (itemCollision(player, blockModel[stageNumber]) == 6) {

			if (itemBundle.changeKey.flag == 0) {
				itemFirstState(6);
			}
		}
		else { // 7

			if (itemBundle.gauge.flag == 0) {
				itemFirstState(7);
				onChangeGauge(3);
			}
		}
	}

	// Trap 충돌이라면
	if (trapCollision(player, blockModel[stageNumber])) {
		// 함정 충돌!
		playerDie(player);
		game(stageNumber);
	}

	// 목표 충돌이라면
	if (goalCollision(player, blockModel[stageNumber])) {
		if (stageNumber == 2) {
			//마지막 stage일 때
			PlaySound(NULL, 0, 0);
			gameClear();
		}
		else if (stageNumber >= 3) {
			randomMapCount++;
			stageNumber++;
			stageGauge[stageNumber] = 0;

			startX = (player->x - MARGIN_LEFT) / 2;
			startY = player->y - MARGIN_TOP;
			startDir = player->dir;
			
			game(stageNumber);

		}
		else {	// 1,2 stage일 때
			//충돌!
			stageNumber++;
			game(stageNumber);
		}
	}

	// 게이지 0 되면
	if (gauge == 0) {
		/* 랜덤 모드라면*/

		playerDie(player);
		if (stageNumber >= 3) {
			
			recentX = startX;
			recentY = startY;
			recentDir = startDir;
			startDir = dir_down;
			startX = 1;
			startY = 23;
			randomMapCount = 1;
			saveMapNumber = stageNumber;
			saveMapGauge = stageGauge[stageNumber];
			titleDraw(&saveMapNumber);
		}
		game(stageNumber);
	}
}

void itemFirstState(int block_id) { //아이템 처음으로 충돌했을때 구조체 상태 바꾸기
	if (block_id == 4) {
		itemBundle.shield.isUsedFirst = true;
		itemBundle.shield.Active = true;
		itemBundle.shield.flag++;
	}
	else if (block_id == 5) {
		itemBundle.npcBoost.isUsedFirst = true;
		itemBundle.npcBoost.Active = true;
		itemBundle.npcBoost.flag++;
	}
	else if (block_id == 6) {
		itemBundle.changeKey.isUsedFirst = true;
		itemBundle.changeKey.Active = true;
		itemBundle.changeKey.flag++;
	}
	else if (block_id == 7) {
		itemBundle.gauge.Active = true;
		itemBundle.gauge.flag++;
	}
}

int trapCollision(Player *player, char blockModel[100][100]) {
	int x = (player->x - MARGIN_LEFT) / 2;
	int y = player->y - MARGIN_TOP;
	int blockNum;
	if (blockModel[y][x] == 2) {
		return 1;
	}
	return 0;
}

int goalCollision(Player *player, char blockModel[100][100]) {
	int x = (player->x - MARGIN_LEFT) / 2;
	int y = player->y - MARGIN_TOP;
	int blockNum;
	if (blockModel[y][x] == 8) {
		return 1;
	}
	return 0;
}

void playerDie(Player *player) {
	DeletePlayer(player->x, player->y);
	Beep(_G, 100);
	Sleep(100);
	showPlayer(player->x, player->y);
	Beep(_G, 100);
	Sleep(100);
	DeletePlayer(player->x, player->y);
	Beep(_G, 100);
	Sleep(100);
	showPlayer(player->x, player->y);
	Beep(_G, 100);
	Sleep(100);
	DeletePlayer(player->x, player->y);
	Beep(_G, 100);
	Sleep(100);
	showPlayer(player->x, player->y);
	Beep(_G, 100);
}

/*
Item 관련 모듈
*/
int itemCollision(Player *player, char blockModel[100][100]) {
	int x = (player->x - MARGIN_LEFT) / 2;
	int y = player->y - MARGIN_TOP;
	int blockNum;
	if (blockModel[y][x] == 4) {
		blockNum = 4;
	}
	else if (blockModel[y][x] == 5) {
		blockNum = 5;
	}
	else if (blockModel[y][x] == 6) {
		blockNum = 6;
	}
	else if (blockModel[y][x] == 7) {
		blockNum = 7;
	}
	//충돌이 일어나면 4,5,6,7
	else blockNum = 0;
	//아니면 0

	return blockNum;
}

void showItemList() {
	int x = MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3;
	int y;

	if (itemBundle.shield.Active == true && itemBundle.shield.flag == 1) {
		y = 5;
		SetCurrentCursorPos(x, y);
		printf("│ ⓢ     %02dsec", itemBundle.shield.Sec);
	}
	else if (itemBundle.shield.Active == false) {
		y = 5;
		SetCurrentCursorPos(x + 1, y);
		printf("               ");
	}

	if (itemBundle.npcBoost.Active == true && itemBundle.npcBoost.flag == 1) {
		y = 6;
		SetCurrentCursorPos(x, y);
		printf("│ ♨     %02dsec", itemBundle.npcBoost.Sec);
	}
	else if (itemBundle.npcBoost.Active == false) {
		y = 6;
		SetCurrentCursorPos(x + 1, y);
		printf("               ");
	}

	if (itemBundle.changeKey.Active == true && itemBundle.changeKey.flag == 1) {
		y = 7;
		SetCurrentCursorPos(x, y);
		printf("│ ⇔     %02dsec", itemBundle.changeKey.Sec);
	}
	else if (itemBundle.changeKey.Active == false) {
		y = 7;
		SetCurrentCursorPos(x + 1, y);
		printf("               ");
	}

	if (itemBundle.gauge.Active == true && itemBundle.gauge.flag == 1) {
		y = 8;
		SetCurrentCursorPos(x, y);
		printf("│ ⓖ              ");
	}
	else if (itemBundle.gauge.Active == false) {
		y = 8;
		SetCurrentCursorPos(x + 1, y);
		printf("               ");
	}
}

void itemActiveCheck() { //1초마다 active check
	time_t t = time(NULL);
	struct tm now = *localtime(&t);
	int secnum;

	if (itemBundle.shield.isUsedFirst == true && itemBundle.shield.Active == true) {
		itemBundle.shield.isUsedFirst = false;
		itemBundle.shield.startSec = now.tm_sec;
	}
	else if (itemBundle.shield.isUsedFirst == false && itemBundle.shield.Active == true) {
		secnum = 10 - getItemTime(itemBundle.shield.startSec);
		itemBundle.shield.Sec = secnum;
		if (secnum == 0) itemBundle.shield.Active = false;
	}
	////////////
	if (itemBundle.npcBoost.isUsedFirst == true && itemBundle.npcBoost.Active == true) {
		itemBundle.npcBoost.isUsedFirst = false;
		itemBundle.npcBoost.startSec = now.tm_sec;
	}
	else if (itemBundle.npcBoost.isUsedFirst == false && itemBundle.npcBoost.Active == true) {
		secnum = 10 - getItemTime(itemBundle.npcBoost.startSec);
		itemBundle.npcBoost.Sec = secnum;
		if (secnum == 0) itemBundle.npcBoost.Active = false;
	}
	//////////////
	if (itemBundle.changeKey.isUsedFirst == true && itemBundle.changeKey.Active == true) {
		itemBundle.changeKey.isUsedFirst = false;
		itemBundle.changeKey.startSec = now.tm_sec;
	}
	else if (itemBundle.changeKey.isUsedFirst == false && itemBundle.changeKey.Active == true) {
		secnum = 10 - getItemTime(itemBundle.changeKey.startSec);
		itemBundle.changeKey.Sec = secnum;
		if (secnum == 0) itemBundle.changeKey.Active = false;
	}
}

int getItemTime(int startSec) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	if (tm.tm_sec - startSec < 0) {
		return tm.tm_sec - startSec + 60;
	}
	return tm.tm_sec - startSec;
}

int onChangeKey(int key) { //키 입력 변환 아이템
	if (key == UP) return DOWN;
	else if (key == DOWN) return UP;
	else if (key == RIGHT)return LEFT;
	else if (key == LEFT) return RIGHT;
}

void onChangeGauge(int changeValue) { //게이지 아이템
	if (gauge > 0) {
		gauge += changeValue;
	}
	showGauge(&gauge, stageNumber, mapSize);
}

void timeCheck(int end_min, int end_sec) {	//게임 시간 오버 체크
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	if (stageNumber < 3) {
		if ((end_min == tm.tm_min) && (end_sec == tm.tm_sec)) {
			PlaySound(NULL, 0, 0);
			gameOver();
		}
	}
}

game(int currentStage) {
	system("cls");
	Player player[100] = {
		{ 2 + MARGIN_LEFT, 13 + MARGIN_TOP , dir_down, false },
		{ 4 + MARGIN_LEFT, 19 + MARGIN_TOP , dir_down, false },
		{ 2 + MARGIN_LEFT, 22 + MARGIN_TOP , dir_down, false },
		{ 2 + MARGIN_LEFT, 23 + MARGIN_TOP , dir_down, false }
	};
	;
	int gameSpeedController = 0;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	if (stageNumber >= 3) {
		player[stageNumber].x = startX * 2 + MARGIN_LEFT;
		player[stageNumber].y = startY + MARGIN_TOP;
		player[stageNumber].dir = startDir;
		mapSize[stageNumber] = 25;
	}
	if (stageNumber == saveMapNumber && stageNumber >= 3) {
		player[stageNumber].x = recentX * 2 + MARGIN_LEFT;
		player[stageNumber].y = recentY + MARGIN_TOP;
		player[stageNumber].dir = recentDir;
		mapSize[stageNumber] = 25;
	}

	speed = 50;
	stageNumber = currentStage;
	if (currentStage >= 3 && saveMapNumber != stageNumber) {
		randomStageDraw(&blockModel[stageNumber], mapSize[stageNumber], startX, startY, startDir, &stageGauge[stageNumber], randomMapCount);
	}
	initItem();
	gauge = stageGauge[stageNumber];
	if (stageNumber == saveMapNumber && stageNumber >= 3) {
		gauge = saveMapGauge;
	}

	ShowBlock(blockModel[stageNumber], stageNumber, mapSize, saveMapNumber);
	showUi(stageNumber, mapSize, randomMapCount);
	showGauge(&gauge, stageNumber, mapSize);

	while (1) {
		CursorView(0);
		printTime(start_hour, start_min, start_sec);
		if (dontHit != 0) {
			showPlayer(player[stageNumber].x, player[stageNumber].y);
		}
		if (!player[stageNumber].moving) {
			keyInput(&player[stageNumber]);
		}
		else {
			// 리스트로 변경
			playerMove(&player[stageNumber], npcList);
		}
		for (int i = 0; i < npcCount[stageNumber]; i++) {
			moveNpc(&player[stageNumber], &npcList[stageNumber][i], gameSpeedController);
		}
		timeCheck(end_min, end_sec);
		itemActiveCheck();
		showItemList();
		gameSpeedController++;
		if (gameSpeedController == 3) {
			gameSpeedController = 0;
		}
	}
}



int main() {
	CursorView(0);
	system("mode con cols=80 lines=25");
	system("COLOR 0F");
	titleDraw(&saveMapNumber);
	return 0;
}