#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void showNpc(int posX, int posY)
{
	SetCurrentCursorPos(posX, posY);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("¥×");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void deleteNpc(int posX, int posY)
{
	SetCurrentCursorPos(posX, posY);
	printf("  ");
}

void showPlayer(int posX, int posY) {
	SetCurrentCursorPos(posX, posY);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("¡Ý");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void DeletePlayer(int posX, int posY) {
	SetCurrentCursorPos(posX, posY);
	printf("  ");
}