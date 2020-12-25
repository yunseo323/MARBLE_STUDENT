#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "title.h"
/* 음악 */
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(COL, 0x000c);
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);
#define HIGH SetConsoleTextAttribute(COL,0x00a); // 연두색
#define GREEN SetConsoleTextAttribute(COL, 0x0002);
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);
#define BLUE SetConsoleTextAttribute(COL, 0x0001);
#define PURPLE SetConsoleTextAttribute(COL, 0x000d);
#define WHITE SetConsoleTextAttribute(COL, 0x000f);

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define SPACE 32

/* 계이름 정의 */
#define _CC 4186.009
#define _B 1975.533

int titleDraw(int *saveMapNumber) {
	int x = 5; int y = 5;
	int SELECT;

	system("mode con: cols=103 lines=35");   //참고로 cols 2단위가 특수문자 또는 한글 1글자다.
	system("title 시작 화면");
	PlaySound(TEXT("Comedy.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	SetCurrentCursorPos(x, y);
	RED;
	puts("┌──────────────────────────────────────────────────────────────────────────────────────┐ ");
	SetCurrentCursorPos(x, y + 1);
	puts("│          ■       ■       ■       ■■■     ■■■    ■         ■■■■         │ ");
	SetCurrentCursorPos(x, y + 2);
	puts("│          ■■   ■■     ■  ■     ■   ■    ■   ■   ■         ■               │ ");
	YELLOW;
	SetCurrentCursorPos(x, y + 3);
	puts("│          ■  ■■ ■    ■■■■    ■■■     ■■■    ■         ■■■■         │ ");
	SetCurrentCursorPos(x, y + 4);
	puts("│          ■   ■  ■   ■      ■   ■   ■    ■   ■   ■         ■               │ ");
	HIGH;
	SetCurrentCursorPos(x, y + 5);
	puts("│          ■   ■  ■   ■      ■   ■    ■   ■■■    ■■■■   ■■■■         │ ");
	SetCurrentCursorPos(x, y + 6);
	puts("│                                                                                      │ ");
	GREEN;
	SetCurrentCursorPos(x, y + 7);
	puts("│    ■■■    ■■■■   ■      ■    ■■■     ■■■■   ■      ■   ■■■■    │ ");
	SKY_BLUE;
	SetCurrentCursorPos(x, y + 8);
	puts("│   ■            ■      ■      ■    ■    ■   ■         ■■    ■      ■       │ ");
	SetCurrentCursorPos(x, y + 9);
	BLUE;
	puts("│    ■■■       ■      ■      ■    ■     ■  ■■■■   ■  ■  ■      ■       │ ");
	SetCurrentCursorPos(x, y + 10);
	puts("│         ■      ■       ■    ■     ■    ■   ■         ■    ■■      ■       │ ");
	PURPLE;
	SetCurrentCursorPos(x, y + 11);
	puts("│    ■■■       ■         ■■       ■■■     ■■■■   ■      ■      ■       │ ");
	SetCurrentCursorPos(x, y + 12);
	puts("└──────────────────────────────────────────────────────────────────────────────────────┘ ");
	WHITE;

	SetCurrentCursorPos(10, 20);
	printf("┌─────────  HOW TO PLAY ?────────┐ ");
	SetCurrentCursorPos(10, 21);
	printf("│                                │ ");
	SetCurrentCursorPos(10, 22);
	printf("│                                │ ");
	SetCurrentCursorPos(10, 23);
	printf("│  # MOVE      # UP, DOWN KEY    │ ");
	SetCurrentCursorPos(10, 24);
	printf("│              # LEFT, RIGHT KEY │ ");
	SetCurrentCursorPos(10, 25);
	printf("│                                │ ");
	SetCurrentCursorPos(10, 26);
	printf("│  # SELECT    # ENTER KEY       │ ");
	SetCurrentCursorPos(10, 27);
	printf("│                                │ ");
	SetCurrentCursorPos(10, 28);
	printf("│                                │ ");
	SetCurrentCursorPos(10, 29);
	printf("│  # Click  Manual               │ ");
	SetCurrentCursorPos(10, 30);
	printf("│                                │ ");
	SetCurrentCursorPos(10, 31);
	printf("│                                │ ");
	SetCurrentCursorPos(10, 32);
	printf("└─────────────  - - ─────────────┘ ");

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	//시작 시간 저장
	start_sec = tm.tm_sec;
	start_min = tm.tm_min;
	start_hour = tm.tm_hour;

	end_sec = start_sec;
	end_min = start_min + 5;
	end_hour = start_hour;

	if (end_min >= 60) {
		end_min -= 60;
		end_hour += 1;
	}

	while (1)
	{
		SELECT = menu();
		switch (SELECT)
		{
		case 0:
			PlaySound(NULL, 0, 0);
			for (int i = 3; i > 0; i--)
			{
				SetCurrentCursorPos(65, 20);
				printf("Start in .. %d", i);
				Beep(_CC, 100);
				Sleep(1000);
			}

			PlaySound(TEXT("Lifestyle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			game(0);
		case 1:
			//Random Stage
			PlaySound(NULL, 0, 0);
			for (int i = 3; i > 0; i--)
			{
				SetCurrentCursorPos(65, 20);
				printf("Start in .. %d", i);
				Beep(_CC, 100);
				Sleep(1000);
			}
			*saveMapNumber = 0;
			PlaySound(TEXT("Lifestyle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			game(3);
		case 2:
			if (*saveMapNumber >= 3) {
				// Recent Random Stage
				PlaySound(NULL, 0, 0);
				for (int i = 3; i > 0; i--)
				{
					SetCurrentCursorPos(65, 20);
					printf("Start in .. %d", i);
					Beep(_CC, 100);
					Sleep(1000);
				}
				PlaySound(TEXT("Lifestyle.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				game(*saveMapNumber);
			}
			break;

		case 3:
			SetCurrentCursorPos(75, 28);
			SetConsoleTextAttribute(COL, 112);
			printf("세종대학교 sw설계기초 15조");
			SetCurrentCursorPos(75, 29);
			printf("       은솔 채원 상현 윤서");
			WHITE;
			Sleep(3000);
			SetCurrentCursorPos(75, 28);
			printf("                          ");
			SetCurrentCursorPos(75, 29);
			printf("                          ");
			break;

		case 4:
			PlaySound(NULL, 0, 0);
			manualDraw();

		case 5:
			return 0;
		}
	}
}

int menu(void) {
	const x = 60;
	int y = 25;
	int key;

	SetCurrentCursorPos(x, y);
	printf(">");
	printf(" Story Mode");
	SetCurrentCursorPos(x, y + 1);
	printf("  Random Mode");
	SetCurrentCursorPos(x, y + 2);
	printf("  Recent Random Map");
	SetCurrentCursorPos(x, y + 3);
	printf("  Developer");
	SetCurrentCursorPos(x, y + 4);
	printf("  Manual");
	SetCurrentCursorPos(x, y + 5);
	printf("  EXIT");

	while (1)
	{
		SetCurrentCursorPos(x, y);
		printf("");
		key = getch();
		printf(" ");

		switch (key)
		{
		case UP:
			Beep(_B, 100);
			if (y > 25) y--;
			break;

		case DOWN:
			Beep(_B, 100);
			if (y < 30) y++;
			break;

		case ENTER:
			return y - 25;
		}
		SetCurrentCursorPos(x, y);
		printf(">");
	}

}