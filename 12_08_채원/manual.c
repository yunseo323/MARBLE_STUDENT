#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "manual.h"

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define RED SetConsoleTextAttribute(COL, 0x000c);
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);
#define HIGH SetConsoleTextAttribute(COL,0x00a); // ���λ�
#define GREEN SetConsoleTextAttribute(COL, 0x0002);
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);
#define BLUE SetConsoleTextAttribute(COL, 0x0001);
#define PURPLE SetConsoleTextAttribute(COL, 0x000d);
#define WHITE SetConsoleTextAttribute(COL, 0x000f);

/* ���̸� ���� */
#define _C 1046.502
#define _D 1174.659
#define _E 1318.510
#define _F 1396.913
#define _G 1567.982

void manualDraw() {
	SetConsoleTitle("����� �Ŵ���");
	system("mode con: cols=90 lines=60");	//�ܼ�â ũ��
	system("title ����� �Ŵ���");

	SetCurrentCursorPos(22, 2);
	SetConsoleTextAttribute(COL, 6);
	printf(" << ����� �Ŵ��� >>");

	SetConsoleTextAttribute(COL, 7);
	SetCurrentCursorPos(5, 5);
	printf("������������������������������������������������������������������������������������������������������������ ");
	SetCurrentCursorPos(5, 6);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 7);
	printf("��                     [���Ӽ���]                     �� ");
	SetCurrentCursorPos(5, 8);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 9);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 10);
	printf("��   �����ϰ� '���� ������� ���� ���� �̿��Ͽ�       �� ");
	SetCurrentCursorPos(5, 11);
	printf("��   ������ ���� �̷θ� Ż���ϴ� �����Դϴ�.          �� ");
	SetCurrentCursorPos(5, 12);
	printf("��   ������ '�л�'�� ������ �����ϱ� ���Ͽ�           �� ");
	SetCurrentCursorPos(5, 13);
	printf("��   3�ܰ� stage�� clear�Ͽ� �������� ������ �մϴ�.  �� ");
	SetCurrentCursorPos(5, 14);
	printf("��   �̷ο� �ִ� ���ع�(NPC,PC��)�� ��������          �� ");
	SetCurrentCursorPos(5, 15);
	printf("��   �� Ȱ���Ͽ� �ð� ���� ������ �����غ��ô�!       �� ");
	SetCurrentCursorPos(5, 16);
	printf("�� ���丮 ��带 �ϼ��ߴٸ� ���� ��嵵 �����غ��ô�! �� ");
	SetCurrentCursorPos(5, 17);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 18);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 19);
	printf("��                     [���۹��]                     �� ");
	SetCurrentCursorPos(5, 20);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 21);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 22);
	printf("��   �̷� ���� ���� ������ ������ ����� �����ϴ�.    �� ");
	SetCurrentCursorPos(5, 23);
	printf("��   �����¿�(�����)�� ������ �ش� ��������        �� ");
	SetCurrentCursorPos(5, 24);
	printf("��   ���ڸ� ����Դϴ�. (�߷� �̿�)                   �� ");
	SetCurrentCursorPos(5, 25);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 26);
	printf("��   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	printf("��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("(PC��), ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("(NPC)�� ������ �ش� Stage Over�˴ϴ�.�� ");
	SetCurrentCursorPos(5, 27);
	printf("��   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("(������)�� ȹ���ϸ� 4���� �����۵� �߿���      �� ");
	SetCurrentCursorPos(5, 28);
	printf("��   ���� �˴ϴ�.                                     �� ");
	SetCurrentCursorPos(5, 29);
	printf("��   4���� ������ : �� (����) / �� (NPC�ӵ� ����)     �� ");
	SetCurrentCursorPos(5, 30);
	printf("��                  ��(����Ű ȥ��) / ��(������ ����) �� ");
	SetCurrentCursorPos(5, 31);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 32);
	printf("��   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("(��ǥ item)�� ȹ���ϸ� �ش� Stage Clear�˴ϴ�. �� ");
	SetCurrentCursorPos(5, 33);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 34);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 35);
	printf("��                     [����TIP]                      �� ");
	SetCurrentCursorPos(5, 36);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 37);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 38);
	printf("��   ĳ������ ������ �ٲ� ������ �������� �پ��ϴ�. �� ");
	SetCurrentCursorPos(5, 39);
	printf("��   Stage���� ������ ���� �ٸ��� ������ �� Ȯ���ϸ鼭�� ");
	SetCurrentCursorPos(5, 40);
	printf("��   �÷��� ���ּ���!!                                �� ");
	SetCurrentCursorPos(5, 41);
	printf("��   ���� �����۰� ���� �������� ������ ,             �� ");
	SetCurrentCursorPos(5, 42);
	printf("��   �������� ȹ���� ���� ����غ��ô�.               �� ");
	SetCurrentCursorPos(5, 43);
	printf("��   ���� ��ü �ð��� ����Ǹ� Game Over �Ǵ�         �� ");
	SetCurrentCursorPos(5, 44);
	printf("��   �ð� üũ �ϸ鼭 ����ְ� ������ �����?         �� ");
	SetCurrentCursorPos(5, 45);
	printf("��                                                    �� ");
	SetCurrentCursorPos(5, 46);
	printf("������������������������������������������������������������������������������������������������������������ ");

	for (int i = 5; i > 0; i--)
	{
		SetCurrentCursorPos(65, 5);
		printf("Show in .. %d", i);
		if (i == 5)
			Beep(_G, 100);
		else if (i == 4)
			Beep(_F, 100);
		else if (i == 3)
			Beep(_E, 100);
		else if (i == 2)
			Beep(_D, 100);
		else if (i == 1)
			Beep(_C, 100);
		Sleep(1000);
	}

	titleDraw();
}