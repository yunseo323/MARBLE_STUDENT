#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "manual.h"

/* └╜╛╟ */
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib");

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(COL, 0x000c);
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);
#define HIGH SetConsoleTextAttribute(COL,0x00a); // ┐м╡╬╗Ў
#define GREEN SetConsoleTextAttribute(COL, 0x0002);
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);
#define BLUE SetConsoleTextAttribute(COL, 0x0001);
#define PURPLE SetConsoleTextAttribute(COL, 0x000d);
#define WHITE SetConsoleTextAttribute(COL, 0x000f);

#define ENTER 13



void gameClear() {
	int x = 5; int y = 5;
	int key;
	system("mode con: cols=110 lines=25");
	system("title Game Over");
	PlaySound(TEXT("Lights-On.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	SetConsoleTextAttribute(COL, 224);
	SetCurrentCursorPos(x, y);
	printf("     бсбсбс       бс     бс    бс   бсбсбс       бсбсбс   бс       бсбсбс      бс       бсбсбс    ");
	SetCurrentCursorPos(x, y + 1);
	printf("   бс           бс бс    бс бс бс   бс         бс         бс       бс         бс бс     бс   бс   ");
	SetCurrentCursorPos(x, y + 2);
	printf("  бс  бсбсбс   бсбсбс    бс бс бс   бсбсбс    бс          бс       бсбсбс     бсбсбс    бсбсбс    ");
	SetCurrentCursorPos(x, y + 3);
	printf("  бс      бс  бс    бс   бс    бс   бс         бс         бс       бс        бс    бс   бс  бс    ");
	SetCurrentCursorPos(x, y + 4);
	printf("   бсбсбс    бс     бс   бс    бс   бсбсбс       бсбсбс   бсбсбс   бсбсбс   бс      бс  бс    бс  ");

	SetConsoleTextAttribute(COL, 8);
	SetCurrentCursorPos(x, y + 6);
	puts(" Do You Want to Play Again?   CLICK Everywhere !!!");

	WHITE;
	for (int i = 0; i <= 46; i += 2) {
		SetCurrentCursorPos(x + i, y + 9);
		printf("Student");
		SetCurrentCursorPos(x + i, y + 10);
		printf(" б▌    ");
		SetCurrentCursorPos(x + i, y + 11);
		printf("/жвж▒  ");
		SetCurrentCursorPos(x + i, y + 12);
		printf(" д╡    ");
		Sleep(70);
		SetCurrentCursorPos(x + i, y + 9);
		printf("       ");
		SetCurrentCursorPos(x + i, y + 10);
		printf("       ");
		SetCurrentCursorPos(x + i, y + 11);
		printf("       ");
		SetCurrentCursorPos(x + i, y + 12);
		printf("       ");
	}
	SetCurrentCursorPos(x + 46, y + 9);
	printf("Student");
	SetCurrentCursorPos(x + 46, y + 10);
	printf(" б▌   ");
	SetCurrentCursorPos(x + 46, y + 11);
	printf("/жвж▒ ");
	SetCurrentCursorPos(x + 46, y + 12);
	printf(" д╡   ");

	Sleep(200);

	SetCurrentCursorPos(x + 46, y + 9);
	printf("Student          Professor");
	SetCurrentCursorPos(x + 46, y + 10);
	printf(" б▌                 б▄");
	SetCurrentCursorPos(x + 46, y + 11);
	printf("/жвж▒ в╜           г┴ж░жв б╡ ");
	SetCurrentCursorPos(x + 46, y + 12);
	printf(" д╡                 д╡ ");
	YELLOW;
	SetCurrentCursorPos(x + 46, y + 14);
	printf("Yes!!!!!       You got an A в╛ ");
	SetCurrentCursorPos(x + 46, y + 15);
	printf("Thank you!     Congratulations! ");


	while (_kbhit() == 0) {
		SetConsoleTextAttribute(COL, 224);
		SetCurrentCursorPos(x, y);
		printf("     бсбсбс       бс     бс    бс   бсбсбс       бсбсбс   бс       бсбсбс      бс       бсбсбс    ");
		SetCurrentCursorPos(x, y + 1);
		printf("   бс           бс бс    бс бс бс   бс         бс         бс       бс         бс бс     бс   бс   ");
		SetCurrentCursorPos(x, y + 2);
		printf("  бс  бсбсбс   бсбсбс    бс бс бс   бсбсбс    бс          бс       бсбсбс     бсбсбс    бсбсбс    ");
		SetCurrentCursorPos(x, y + 3);
		printf("  бс      бс  бс    бс   бс    бс   бс         бс         бс       бс        бс    бс   бс  бс    ");
		SetCurrentCursorPos(x, y + 4);
		printf("   бсбсбс    бс     бс   бс    бс   бсбсбс       бсбсбс   бсбсбс   бсбсбс   бс      бс  бс    бс  ");

		Sleep(100);

		SetConsoleTextAttribute(COL, 160);
		SetCurrentCursorPos(x, y);
		printf("     бсбсбс       бс     бс    бс   бсбсбс       бсбсбс   бс       бсбсбс      бс       бсбсбс    ");
		SetCurrentCursorPos(x, y + 1);
		printf("   бс           бс бс    бс бс бс   бс         бс         бс       бс         бс бс     бс   бс   ");
		SetCurrentCursorPos(x, y + 2);
		printf("  бс  бсбсбс   бсбсбс    бс бс бс   бсбсбс    бс          бс       бсбсбс     бсбсбс    бсбсбс    ");
		SetCurrentCursorPos(x, y + 3);
		printf("  бс      бс  бс    бс   бс    бс   бс         бс         бс       бс        бс    бс   бс  бс    ");
		SetCurrentCursorPos(x, y + 4);
		printf("   бсбсбс    бс     бс   бс    бс   бсбсбс       бсбсбс   бсбсбс   бсбсбс   бс      бс  бс    бс  ");

		Sleep(100);
	}
	WHITE;
	key = getch();

	PlaySound(NULL, 0, 0);
	titleDraw();
}

void gameOver() {
	int x = 5; int y = 5;
	int key;
	system("mode con: cols=100 lines=25");
	system("title Game Over");
	PlaySound(TEXT("Scary-Horror.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	SetConsoleTextAttribute(COL, 64);
	SetCurrentCursorPos(x, y);
	printf("     бсбсбс       бс     бс    бс   бсбсбс       бсбс   бс       бс  бсбсбс  бсбсбс   ");
	SetCurrentCursorPos(x, y + 1);
	printf("   бс           бс бс    бс бс бс   бс          бс  бс   бс     бс   бс      бс   бс  ");
	SetCurrentCursorPos(x, y + 2);
	printf("  бс  бсбсбс   бсбсбс    бс бс бс   бсбсбс     бс    бс   бс   бс    бсбсбс  бсбсбс   ");
	SetCurrentCursorPos(x, y + 3);
	printf("  бс      бс  бс    бс   бс    бс   бс          бс  бс     бс бс     бс      бс  бс   ");
	SetCurrentCursorPos(x, y + 4);
	printf("   бсбсбс    бс     бс   бс    бс   бсбсбс       бсбс       бс       бсбсбс  бс   бс  ");

	SetConsoleTextAttribute(COL, 8);
	SetCurrentCursorPos(x, y + 6);
	puts(" Do You Want to Play Again?   CLICK Everywhere !!!");

	WHITE;
	for (int i = 0; i <= 40; i += 2) {
		SetCurrentCursorPos(x + i, y + 9);
		printf("Student");
		SetCurrentCursorPos(x + i, y + 10);
		printf(" б▌    ");
		SetCurrentCursorPos(x + i, y + 11);
		printf("/жвж▒  ");
		SetCurrentCursorPos(x + i, y + 12);
		printf(" д╡    ");
		Sleep(70);
		SetCurrentCursorPos(x + i, y + 9);
		printf("       ");
		SetCurrentCursorPos(x + i, y + 10);
		printf("       ");
		SetCurrentCursorPos(x + i, y + 11);
		printf("       ");
		SetCurrentCursorPos(x + i, y + 12);
		printf("       ");
	}
	SetCurrentCursorPos(x + 40, y + 9);
	printf("Student");
	SetCurrentCursorPos(x + 40, y + 10);
	printf(" б▌   ");
	SetCurrentCursorPos(x + 40, y + 11);
	printf("/жвж▒ ");
	SetCurrentCursorPos(x + 40, y + 12);
	printf(" д╡   ");

	Sleep(130);

	SetCurrentCursorPos(x + 40, y + 9);
	printf("Student");
	SetCurrentCursorPos(x + 40, y + 10);
	printf(" б▌   ");
	SetCurrentCursorPos(x + 40, y + 11);
	printf("/жвж▒ ");
	SetCurrentCursorPos(x + 40, y + 12);
	printf(" же   ");

	Sleep(130);

	SetCurrentCursorPos(x + 40, y + 9);
	printf("Student                            Professor");
	SetCurrentCursorPos(x + 40, y + 10);
	printf("                                       б▄");
	SetCurrentCursorPos(x + 40, y + 11);
	printf("  T б▌                               б┤жв б╡ ");
	SetCurrentCursorPos(x + 40, y + 12);
	printf(" же жж                                   д╡");
	RED;
	SetCurrentCursorPos(x + 40, y + 14);
	printf("Oh No!!!!!                        You got an F ");


	while (_kbhit() == 0) {
		SetConsoleTextAttribute(COL, 64);
		SetCurrentCursorPos(x, y);
		printf("     бсбсбс       бс     бс    бс   бсбсбс       бсбс   бс       бс  бсбсбс  бсбсбс   ");
		SetCurrentCursorPos(x, y + 1);
		printf("   бс           бс бс    бс бс бс   бс          бс  бс   бс     бс   бс      бс   бс  ");
		SetCurrentCursorPos(x, y + 2);
		printf("  бс  бсбсбс   бсбсбс    бс бс бс   бсбсбс     бс    бс   бс   бс    бсбсбс  бсбсбс   ");
		SetCurrentCursorPos(x, y + 3);
		printf("  бс      бс  бс    бс   бс    бс   бс          бс  бс     бс бс     бс      бс  бс   ");
		SetCurrentCursorPos(x, y + 4);
		printf("   бсбсбс    бс     бс   бс    бс   бсбсбс       бсбс       бс       бсбсбс  бс   бс  ");

		Sleep(100);

		SetConsoleTextAttribute(COL, 112);
		SetCurrentCursorPos(x, y);
		printf("     бсбсбс       бс     бс    бс   бсбсбс       бсбс   бс       бс  бсбсбс  бсбсбс   ");
		SetCurrentCursorPos(x, y + 1);
		printf("   бс           бс бс    бс бс бс   бс          бс  бс   бс     бс   бс      бс   бс  ");
		SetCurrentCursorPos(x, y + 2);
		printf("  бс  бсбсбс   бсбсбс    бс бс бс   бсбсбс     бс    бс   бс   бс    бсбсбс  бсбсбс   ");
		SetCurrentCursorPos(x, y + 3);
		printf("  бс      бс  бс    бс   бс    бс   бс          бс  бс     бс бс     бс      бс  бс   ");
		SetCurrentCursorPos(x, y + 4);
		printf("   бсбсбс    бс     бс   бс    бс   бсбсбс       бсбс       бс       бсбсбс  бс   бс  ");

		Sleep(100);
	}
	WHITE;
	key = getch();

	PlaySound(NULL, 0, 0);
	titleDraw();
}