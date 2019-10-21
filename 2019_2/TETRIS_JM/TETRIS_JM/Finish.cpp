#include "Finish.h"
#include "Console.h"
#include "Rank.h"
#include "Tetris_.h"
#include <stdio.h>
#include <conio.h>

Finish::Finish()
{
}

Finish::~Finish()
{
}

void Finish::initname(char* name)
{
	for (int i = 0; i < 20; i++)
		name[i] = 0;
}

void Finish::GameOver(int score, int level)
{
	Tetris_ tet;
	Rank rank;

	for (int i = 2; i < 25; i++)
		for (int j = 1; j < 11; j++) {
			GotoXY(15 + j * 2, 5 + i);
			if (tet.board[i][j] == tet.BLOCK)
				printf("▦");
		}

	for (int i = 0; i < 2; i++)
	{
		GotoXY(15, 4);
		printf(" ▩▩▩▩▩▩▩▩▩▩▩");
		GotoXY(15, 5);
		printf(" ▩ G A M E  O V E R ▩");
		GotoXY(15, 6);
		printf(" ▩▩▩▩▩▩▩▩▩▩▩");

		Sleep(500);

		GotoXY(15, 4);
		printf("                      ");
		GotoXY(15, 5);
		printf("                      ");
		GotoXY(15, 6);
		printf("                      ");

		Sleep(500);
	}
	GotoXY(15, 4);
	printf(" ▩▩▩▩▩▩▩▩▩▩▩");
	GotoXY(15, 5);
	printf(" ▩ G A M E  O V E R ▩");
	GotoXY(15, 6);
	printf(" ▩▩▩▩▩▩▩▩▩▩▩");

	Sleep(1000);

	system("cls");
	GotoXY(32, 6);
	printf("G A M E  O V E R");
	GotoXY(33, 8);
	printf("최종 레벨 : %d", level);
	GotoXY(33, 10);
	printf("최종 점수 : %d", score);
	GotoXY(33, 12);
	printf("이름 : ");
	GotoXY(40, 12);
	SetCursor(TRUE);
	scanf_s("%s", name, sizeof(name));

	rank.WriteRanking(name, score);
}

int Finish::GameOver_menu()
{
	SetCursor(FALSE);
	int x = 36;
	int y = 15;
	int key;

	GotoXY(x - 2, y);
	printf("> ReStart");
	GotoXY(x, y + 1);
	printf("Ranking");
	GotoXY(x, y + 2);
	printf("Info");
	GotoXY(x, y + 3);
	printf("Exit");

	while (1) {
		key = _getch();
		switch (key) {
		case UP:
			if (y > 15) {
				GotoXY(x - 2, y);
				printf("  ");
				GotoXY(x - 2, --y);
				printf(">");
			}
			break;
		case DOWN:
			if (y < 18) {
				GotoXY(x - 2, y);
				printf("  ");
				GotoXY(x - 2, ++y);
				printf(">");
			}
			break;
		case ENTER:
			return y - 15;
		}
	}
}