#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "cursor.h"

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(COL, 0x000c);
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);
#define HIGH SetConsoleTextAttribute(COL,0x00a); // 연두색
#define GREEN SetConsoleTextAttribute(COL, 0x0002);
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);
#define BLUE SetConsoleTextAttribute(COL, 0x0001);
#define PURPLE SetConsoleTextAttribute(COL, 0x000d);
#define WHITE SetConsoleTextAttribute(COL, 0x000f);

#define MARGIN_LEFT 8
#define MARGIN_TOP 5

char stage_number[4] = { '1', '2', '3', '?' };
char stage_title[4][100] = { "어린이 대공원역", "세종대 정문", "ai센터", "랜덤 스테이지" };


void showUi(int stageNumber, int mapSize[], int randomMapCount) {

	SetCurrentCursorPos(8, 2);

	if (stageNumber >= 3) {
		printf("stage : %d", randomMapCount);
	}
	else {
		printf("stage %c", stage_number[stageNumber]);
	}
	SetCurrentCursorPos(8, 3);
	if (stageNumber >= 3) {
		printf("%s", "랜덤 스테이지");
	}
	else {
		printf("%s", stage_title[stageNumber]);
	}

	if (stageNumber < 3) {
		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 2);
		printf("┌━━━━━━━━━━━━━━━━━┐ \n");
		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 3);
		printf("│    Item 목록    │ \n");
		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 4);
		printf("│                 │ \n");

		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 5);
		printf("│                 │ \n");
		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 6);
		printf("│                 │ \n");
		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 7);
		printf("│                 │ \n");
		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 8);
		printf("│                 │ \n");

		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 9);
		printf("└━━━━━━━━━━━━━━━━━┘ ");
		
	}

	SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 10);
	printf("┌━━━━━━┐ \n");
	SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 11);
	printf("│ Gauge│ ");
	for (int i = 0; i < 8; i++)
	{
		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, i + 12);
		printf("│      │ ");

	}

	SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 3, 20);
	printf("└━━━━━━┘ ");


	SetCurrentCursorPos(MARGIN_LEFT + 2, MARGIN_TOP + 13);

}



void ShowBlock(char blockInfo[100][100], int stageNumber, int mapSize[], int saveMapNumber)
{
	int y, x;
	COORD curPos = GetCurrentCursorPos();
	for (y = 0; y < mapSize[stageNumber]; y++)
	{
		for (x = 0; x < mapSize[stageNumber]; x++)
		{
			SetCurrentCursorPos(MARGIN_LEFT + curPos.X + x * 2, MARGIN_TOP + curPos.Y + y);
			if (blockInfo[y][x] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				printf("■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (blockInfo[y][x] == 0) printf("  ");
			else if (blockInfo[y][x] == 2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				printf("▩");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (blockInfo[y][x] == 3) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("Ψ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (4 <= blockInfo[y][x] && blockInfo[y][x] <= 7) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				printf("？");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (blockInfo[y][x] == 8) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("★");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (blockInfo[y][x] < 0) {
				 if ( stageNumber == saveMapNumber) printf("%2d", blockInfo[y][x] * -1);
			}
			else if (blockInfo[y][x] == 9) printf("◎");
		}
	}
	SetCurrentCursorPos(curPos.X, curPos.Y);
}


void printTime(int start_hour, int start_min, int start_sec) {

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);


	SetCurrentCursorPos(25, 2);
	if (stage_number < 3) {
		printf("now ☞ %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	}
	
	SetCurrentCursorPos(25, 3);
	if (start_min + 5 > 60) {
		start_hour++;
		start_min -= 60;
	}
	if (stage_number < 3) {
		printf("end ☞ %02d:%02d:%02d\n", start_hour, start_min + 5, start_sec);
	}
	
}

void showGauge(int * gauge, int stageNumber, int mapSize[]) {
	int gauge_num = 0;
	if (stageNumber == 0) gauge_num = 3;
	else if (stageNumber == 1) gauge_num = 4;
	else if (stageNumber == 2) gauge_num = 6;
	else if (stageNumber >= 3) gauge_num = 6;

	for (int i = (*gauge + gauge_num - 1) / gauge_num; i <= 6; i++)
	{
		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 7, 12 + (6 - i));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		printf("  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	for (int i = 0; i < (*gauge + gauge_num - 1) / gauge_num; i++)
	{
		SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 7, 18 - i);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		printf("■");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		//curPosY++;
	}
	SetCurrentCursorPos(MARGIN_LEFT + (mapSize[stageNumber] * 2) + 7, 19);
	printf("%2d", *gauge);

}