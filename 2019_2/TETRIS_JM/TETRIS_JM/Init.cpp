#include "Init.h"
#include <stdio.h>
#include <conio.h>

Init::Init()
{
}

Init::~Init()
{
}

void Init::init()
{
	SetConsoleSize(consoleX, consoleY);
	GotoXY(33, 9);
	printf("T E T R I S");
	GotoXY(36, 10);
	printf("v0.2");
	//GotoXY(28, 12);
	//printf("Press any key to start");
	GotoXY(25, 19);
	printf("Press ENTER/"); SetColor(BLACK, RED); printf("●"); SetColor(BLACK, WHITE); printf(" Key to Select");

	GotoXY(0, 29);
	printf("By JeongMin Heo");
}

void Init::info()
{
	int key;


	system("cls");
	printf("\n\n\n");
	printf("                                   [ 조작법 ]\n\n");
	printf("                             키보드          조이스틱\n\n");
	printf("                 메뉴 선택 : ENTER           YELLOW Button "); SetColor(BLACK, YELLOW); printf("●\n\n"); SetColor(BLACK, WHITE);
	printf("                      회전 : ↑              Joystick Up\n\n");
	printf("                 왼쪽 이동 : ←              Joystick Left\n\n");
	printf("               오른쪽 이동 : →              Joystick Right\n\n");
	printf("               소프트 드랍 : ↓              Joystick Down\n\n");
	printf("                 하드 드랍 : SPACEBAR        Green Button "); SetColor(BLACK, GREEN); printf("●\n\n"); SetColor(BLACK, WHITE);
	printf("                  일시정지 : P               White Button "); SetColor(BLACK, WHITE); printf("●\n\n\n");
	printf("           스페이스바/"); printf("●"); printf("를 누르면 이전 화면으로 돌아갑니다.\n");

	GotoXY(0, 29);
	printf("By JeongMin Heo");
	while (1) {
		key = _getch();
		if (key == SPACEBAR)
			break;
	}
}

int Init::setting()
{
	return 0;
}

int Init::menu()
{
	system("cls");
	SetCursor(FALSE);
	init();

	int x = 36;
	int y = 13;
	int key;

	GotoXY(x - 2, y);
	printf("> Start");
	GotoXY(x, y + 1);
	printf("Ranking");
	GotoXY(x, y + 2);
	printf("Info");
	GotoXY(x, y + 3);
	printf("Setting");
	GotoXY(x, y + 4);
	printf("Exit");

	while (1) {
		key = _getch();
		switch (key) {
		case UP:
			if (y > 13) {
				GotoXY(x - 2, y);
				printf("  ");
				GotoXY(x - 2, --y);
				printf(">");
				sound.Sound_Play(5);
			}
			break;
		case DOWN:
			if (y < 17) {
				GotoXY(x - 2, y);
				printf("  ");
				GotoXY(x - 2, ++y);
				printf(">");
				sound.Sound_Play(5);
			}
			break;
		case ENTER:
			return y - 13;
		}
	}
}