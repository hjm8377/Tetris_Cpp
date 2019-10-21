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
	printf("Press ENTER/"); SetColor(BLACK, RED); printf("��"); SetColor(BLACK, WHITE); printf(" Key to Select");

	GotoXY(0, 29);
	printf("By JeongMin Heo");
}

void Init::info()
{
	int key;


	system("cls");
	printf("\n\n\n");
	printf("                                   [ ���۹� ]\n\n");
	printf("                             Ű����          ���̽�ƽ\n\n");
	printf("                 �޴� ���� : ENTER           YELLOW Button "); SetColor(BLACK, YELLOW); printf("��\n\n"); SetColor(BLACK, WHITE);
	printf("                      ȸ�� : ��              Joystick Up\n\n");
	printf("                 ���� �̵� : ��              Joystick Left\n\n");
	printf("               ������ �̵� : ��              Joystick Right\n\n");
	printf("               ����Ʈ ��� : ��              Joystick Down\n\n");
	printf("                 �ϵ� ��� : SPACEBAR        Green Button "); SetColor(BLACK, GREEN); printf("��\n\n"); SetColor(BLACK, WHITE);
	printf("                  �Ͻ����� : P               White Button "); SetColor(BLACK, WHITE); printf("��\n\n\n");
	printf("           �����̽���/"); printf("��"); printf("�� ������ ���� ȭ������ ���ư��ϴ�.\n");

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