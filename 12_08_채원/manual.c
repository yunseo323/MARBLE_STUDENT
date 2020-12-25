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
#define HIGH SetConsoleTextAttribute(COL,0x00a); // 연두색
#define GREEN SetConsoleTextAttribute(COL, 0x0002);
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);
#define BLUE SetConsoleTextAttribute(COL, 0x0001);
#define PURPLE SetConsoleTextAttribute(COL, 0x000d);
#define WHITE SetConsoleTextAttribute(COL, 0x000f);

/* 계이름 정의 */
#define _C 1046.502
#define _D 1174.659
#define _E 1318.510
#define _F 1396.913
#define _G 1567.982

void manualDraw() {
	SetConsoleTitle("사용자 매뉴얼");
	system("mode con: cols=90 lines=60");	//콘솔창 크기
	system("title 사용자 매뉴얼");

	SetCurrentCursorPos(22, 2);
	SetConsoleTextAttribute(COL, 6);
	printf(" << 사용자 매뉴얼 >>");

	SetConsoleTextAttribute(COL, 7);
	SetCurrentCursorPos(5, 5);
	printf("┌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐ ");
	SetCurrentCursorPos(5, 6);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 7);
	printf("│                     [게임설명]                     │ ");
	SetCurrentCursorPos(5, 8);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 9);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 10);
	printf("│   간단하게 '구슬 굴리기와 같이 벽을 이용하여       │ ");
	SetCurrentCursorPos(5, 11);
	printf("│   구슬을 굴려 미로를 탈출하는 게임입니다.          │ ");
	SetCurrentCursorPos(5, 12);
	printf("│   구슬인 '학생'은 과제를 제출하기 위하여           │ ");
	SetCurrentCursorPos(5, 13);
	printf("│   3단계 stage를 clear하여 교수님을 만나야 합니다.  │ ");
	SetCurrentCursorPos(5, 14);
	printf("│   미로에 있는 방해물(NPC,PC방)과 아이템을          │ ");
	SetCurrentCursorPos(5, 15);
	printf("│   잘 활용하여 시간 내에 과제를 제출해봅시다!       │ ");
	SetCurrentCursorPos(5, 16);
	printf("│ 스토리 모드를 완수했다면 랜덤 모드도 도전해봅시다! │ ");
	SetCurrentCursorPos(5, 17);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 18);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 19);
	printf("│                     [조작방법]                     │ ");
	SetCurrentCursorPos(5, 20);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 21);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 22);
	printf("│   미로 상자 안의 구슬을 굴리는 방법과 같습니다.    │ ");
	SetCurrentCursorPos(5, 23);
	printf("│   상하좌우(↑↓←→)를 누르면 해당 방향으로        │ ");
	SetCurrentCursorPos(5, 24);
	printf("│   상자를 기울입니다. (중력 이용)                   │ ");
	SetCurrentCursorPos(5, 25);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 26);
	printf("│   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	printf("▩");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("(PC방), ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("Ψ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("(NPC)에 닿으면 해당 Stage Over됩니다.│ ");
	SetCurrentCursorPos(5, 27);
	printf("│   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("？");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("(아이템)을 획득하면 4가지 아이템들 중에서      │ ");
	SetCurrentCursorPos(5, 28);
	printf("│   선택 됩니다.                                     │ ");
	SetCurrentCursorPos(5, 29);
	printf("│   4가지 아이템 : ⓢ (쉴드) / ♨ (NPC속도 증가)     │ ");
	SetCurrentCursorPos(5, 30);
	printf("│                  ⇔(방향키 혼동) / ⓖ(게이지 증가) │ ");
	SetCurrentCursorPos(5, 31);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 32);
	printf("│   ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("★");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("(목표 item)을 획득하면 해당 Stage Clear됩니다. │ ");
	SetCurrentCursorPos(5, 33);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 34);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 35);
	printf("│                     [조작TIP]                      │ ");
	SetCurrentCursorPos(5, 36);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 37);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 38);
	printf("│   캐릭터의 방향을 바꿀 때마다 게이지가 줄어듭니다. │ ");
	SetCurrentCursorPos(5, 39);
	printf("│   Stage마다 게이지 양이 다르기 때문에 꼭 확인하면서│ ");
	SetCurrentCursorPos(5, 40);
	printf("│   플레이 해주세요!!                                │ ");
	SetCurrentCursorPos(5, 41);
	printf("│   좋은 아이템과 나쁜 아이템이 있으니 ,             │ ");
	SetCurrentCursorPos(5, 42);
	printf("│   아이템을 획득할 때는 고민해봅시다.               │ ");
	SetCurrentCursorPos(5, 43);
	printf("│   게임 전체 시간이 종료되면 Game Over 되니         │ ");
	SetCurrentCursorPos(5, 44);
	printf("│   시간 체크 하면서 재미있게 게임해 볼까요?         │ ");
	SetCurrentCursorPos(5, 45);
	printf("│                                                    │ ");
	SetCurrentCursorPos(5, 46);
	printf("└━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┘ ");

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