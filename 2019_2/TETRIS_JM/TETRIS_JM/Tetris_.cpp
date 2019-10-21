#include "Tetris_.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>

Tetris_::Tetris_()
{
}

Tetris_::~Tetris_()
{
}

void Tetris_::resetboard()
{
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 12; j++)
		{
			if ((j == 0) || (j == 11))
				board[i][j] = WALL;
			else
				board[i][j] = EMPTY;
		}
	for (int i = 0; i < 12; i++)
		board[24][i] = WALL;
}

void Tetris_::boardset()
{
	SetConsoleSize(80, 35);

	for (int i = 4; i < 25; i++)
	{
		GotoXY(bx, by + i);
		for (int j = 0; j < 12; j++)
		{
			if (board[i][j] == WALL)
				printf("□");
			else
				printf("  ");
		}
	}
	GotoXY(40, 9);
	printf("Level");
	GotoXY(40, 11);
	printf("Score");
	GotoXY(40, 14);
	printf("Next Block");
}

void Tetris_::printblock(Tetris t)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GotoXY(t.curX + (j * 2), t.curY + i);	//특수문자는 2바이트 x->2칸이동, y->한칸이동
			switch (t.curblock) {
			case 0:
				SetColor(BLACK, BLUE);
				break;
			case 1:
				SetColor(BLACK, PINK);
				break;
			case 2:
				SetColor(BLACK, PURPLE);
				break;
			case 3:
				SetColor(BLACK, SKYBLUE);
				break;
			case 4:
				SetColor(BLACK, YELLOW);
				break;
			case 5:
				SetColor(BLACK, GRASSGREEN);
				break;
			case 6:
				SetColor(BLACK, RED);
				break;
			default:
				SetColor(BLACK, WHITE);
				break;
			}

			if (block[t.curblock][t.rotation][i][j] == BLOCK) {
				printf("■");
			}//0 파 1주 2보 3하늘 4노 5연두 6빨강
		}
	}
}

void Tetris_::removeblock(Tetris t)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GotoXY(t.curX + (j * 2), t.curY + i);
			if (block[t.curblock][t.rotation][i][j] == BLOCK)
				printf("  ");
		}
	}
}

void Tetris_::printnextblock(int next)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GotoXY(40 + (j * 2), 15 + i);	//특수문자는 2바이트 x->2칸이동, y->한칸이동
			switch (next) {
			case 0:
				SetColor(BLACK, BLUE);
				break;
			case 1:
				SetColor(BLACK, PINK);
				break;
			case 2:
				SetColor(BLACK, PURPLE);
				break;
			case 3:
				SetColor(BLACK, SKYBLUE);
				break;
			case 4:
				SetColor(BLACK, YELLOW);
				break;
			case 5:
				SetColor(BLACK, GRASSGREEN);
				break;
			case 6:
				SetColor(BLACK, RED);
				break;
			default:
				SetColor(BLACK, WHITE);
				break;
			}

			if (block[next][0][i][j] == BLOCK) {
				printf("■");
			}
		}
	}
}

void Tetris_::removenextblock(int next)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GotoXY(40 + (j * 2), 15 + i);
			if (block[next][0][i][j] == BLOCK || block[next][0][i][j] == EMPTY)
				printf("  ");
		}
	}
}

int Tetris_::CollisionCheck(Tetris t)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[t.curblock][t.rotation][i][j] == BLOCK) {
				if (board[t.curY + i - 5 + 1][((t.curX - 15) / 2) + j] > 0)
					return 1;
			}
			//board[t.curY + i - 5][((t.curX - 15) / 2) + j];	//각 블럭 배열의 보드에서의 상대적 위치
		}
	}
	return 0;
}

int Tetris_::CollisionCheck_R(Tetris t)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[t.curblock][t.rotation][i][j] == BLOCK) {
				if (board[t.curY + i - 5][(((t.curX - 15) / 2) + j) + 1] > 0)
					return 1;
			}
		}
	}
	return 0;
}

int Tetris_::CollisionCheck_L(Tetris t)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[t.curblock][t.rotation][i][j] == BLOCK) {
				if (board[t.curY + i - 5][(((t.curX - 15) / 2) + j) - 1] > 0)
					return 1;
			}
		}
	}
	return 0;
}

void Tetris_::merge_block_board(Tetris t)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (block[t.curblock][t.rotation][i][j] == BLOCK)
				board[t.curY + i - 5][((t.curX - 15) / 2) + j] |= block[t.curblock][t.rotation][i][j];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GotoXY(t.curX + (j * 2), t.curY + i);	//특수문자는 2바이트 x->2칸이동, y->한칸이동
			SetColor(BLACK, WHITE);
			if (block[t.curblock][t.rotation][i][j] == BLOCK) {
				printf("■");
			}
		}
	}
}

int Tetris_::Check_topline()
{
	for (int i = 1; i < 11; i++)
		if (board[3][i] == 1)
			return 1;
	return 0;
}

void Tetris_::printpreviewblock(Tetris t)
{
	while (CollisionCheck(t) != 1)
		++t.curY;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GotoXY(t.curX + (j * 2), t.curY + i);
			SetColor(BLACK, WHITE);
			if (block[t.curblock][t.rotation][i][j] == BLOCK)
				printf("□");
		}
	}
}

void Tetris_::removepreviewblock(Tetris t)
{
	while (CollisionCheck(t) != 1)
		++t.curY;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GotoXY(t.curX + (j * 2), t.curY + i);
			if (block[t.curblock][t.rotation][i][j] == BLOCK)
				printf("  ");
		}
	}
}

void Tetris_::previewblock(int dir, Tetris t)
{
	removepreviewblock(t);


	switch (dir) {
	case LEFT:
		removepreviewblock(t);
		if (CollisionCheck_L(t) == 1)
			t.curX = t.curX;
		else
			t.curX -= 2;
		printpreviewblock(t);
		break;
	case RIGHT:
		removepreviewblock(t);
		if (CollisionCheck_R(t) == 1)
			t.curX = t.curX;
		else
			t.curX += 2;
		printpreviewblock(t);
		break;
	case UP:
		removepreviewblock(t);
		if (CollisionCheck_L(t) == 1)
			t.curX += 2;
		if (CollisionCheck_R(t) == 1)
			t.curX -= 2;
		printpreviewblock(t);
		break;

	case 0:
		printpreviewblock(t);
	}
}

void Tetris_::array_down(int line)
{
	for (int i = line; i > 2; i--)
		for (int j = 0; j < 11; j++)
			board[i][j] = board[i - 1][j];

	for (int i = 4; i < 25; i++)
	{
		GotoXY(bx, by + i);
		SetColor(BLACK, WHITE);
		for (int j = 0; j < 12; j++)
		{
			if (board[i][j] == WALL)
				printf("□");
			else if (board[i][j] == BLOCK)
				printf("■");
			else
				printf("  ");
		}
	}
	sound.Sound_Play(1);
}

void Tetris_::Line_clear(Tetris t)
{
	int a;

	for (int i = 23; i > 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			a = 0;
			for (int k = 1; k < 11; k++)
			{
				if (board[i][k] == BLOCK)
				{
					a++;
					if (a == 10)
					{
						for (int x = 1; x < 11; x++)
						{
							GotoXY((x * 2) + bx, i + by);
							board[i][x] = 0;
							printf("  ");
						}

						score += 100;
						if (score % 1000 == 0)
						{
							level += 1;
							speed -= 50;
						}
						GotoXY(46, 9);
						printf("%d", level);
						GotoXY(46, 11);
						printf("%d", score);
						array_down(i);
					}
				}
			}
		}
	}
}

void Tetris_::pause(int key, Tetris t)
{
	while (1) {
		if (key == 1)
		{
			GotoXY(20, 15);
			SetColor(BLACK, WHITE);
			printf("PAUSE : PRESS ANY KEY TO CONTINUE");
		}
		
		if (_kbhit())
		{
					GotoXY(20, 15);
					printf("                             ");
					boardset();
					GotoXY(46, 9);
					printf("%d", level);
					GotoXY(46, 11);
					printf("%d", score);
					printnextblock(t.next);
					return;
		}
	}
	
	return;
}

void Tetris_::initblock(int* blockarr)
{
	int temp, x, y;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 7; i++)	blockarr[i] = i;

	for (int i = 0; i < 7; i++)
	{
		x = rand() % 7;
		y = rand() % 7;

		if (x != y)
		{
			temp = blockarr[x];
			blockarr[x] = blockarr[y];
			blockarr[y] = temp;
		}
	}
}

void Tetris_::Game()
{
	Tetris t;

	SetCursor(FALSE);
	t.gameover = FALSE;

	t.absX = 25;
	t.absY = 5;

	speed = 400;
	score = 0;
	level = 1;
	cnt = 0;

	resetboard();
	boardset();

	GotoXY(46, 9);
	printf("%d", level);
	GotoXY(46, 11);
	printf("%d", score);

	while (1)
	{
		SetColor(BLACK, WHITE);

		if (cnt == 0) {
			initblock(blockarr);
			t.curblock = blockarr[cnt];
			t.next = blockarr[cnt + 1];
		}
		else if (cnt == 6) {
			t.curblock = blockarr[cnt];
			cnt = 0;
			initblock(blockarr);
			t.next = blockarr[cnt + 1];
			
		}
		else {
			t.curblock = blockarr[cnt];
			t.next = blockarr[cnt + 1];
		}


		t.curX = t.absX;
		t.curY = t.absY;
		a = 0;
		t.rotation = a;

		removenextblock(t.next);
		printnextblock(t.next);

		while (1)
		{
			previewblock(0, t);

			while (_kbhit() == 0)
			{
				removeblock(t);
				t.curY += 1;
				printblock(t);
				Sleep(speed);
				if (CollisionCheck(t) == 1) {
					merge_block_board(t);
					if (Check_topline() == 1)
						t.gameover = TRUE;
					break;
				}
			}

			if (CollisionCheck(t) == 1) {
				Sleep(100);
				break;
			}
			key = _getch();
			if (key == 224) {
				key = _getch();
				switch (key)
				{
				case LEFT:
					previewblock(LEFT, t);
					removeblock(t);
					if (CollisionCheck_L(t) == 1)
						t.curX = t.curX;
					else
						t.curX -= 2;
					printblock(t);
					break;
				case RIGHT:
					previewblock(RIGHT, t);
					removeblock(t);
					if (CollisionCheck_R(t) == 1)
						t.curX = t.curX;
					else
						t.curX += 2;
					printblock(t);
					break;
				case DOWN:
					removeblock(t);
					if (CollisionCheck(t) != 1)
						t.curY += 1;
					printblock(t);
					break;
				case UP:
					removepreviewblock(t);
					removeblock(t);
					a++;
					t.rotation = a % 4;
					if (CollisionCheck_L(t) == 1)
						t.curX += 2;
					if (CollisionCheck_R(t) == 1)
						t.curX -= 2;
					printblock(t);
					printpreviewblock(t);
					sound.Sound_Play(4);
					break;
				}
			}
			else 
				switch (key)
				{
				case 'P':
				case 'p':
					pause(1, t);
					break;
				case SPACEBAR:
					removeblock(t);
					while (CollisionCheck(t) != 1)
						++t.curY;
					t.curY -= 1;
					printblock(t);
					key = NULL;
					break;
				case 'Z':
				case'z':
					removepreviewblock(t);
					removeblock(t);
					if (t.rotation == 0)
						t.rotation = 3;
					else t.rotation--;
					if (CollisionCheck_L(t) == 1)
						t.curX += 2;
					if (CollisionCheck_R(t) == 1)
						t.curX -= 2;
					printblock(t);
					printpreviewblock(t);
					break;
				}
		}
		Line_clear(t);
		cnt++;
		
		if (t.gameover == TRUE) {
			break;
		}
	}
	t.gameover = FALSE;
	return;
}