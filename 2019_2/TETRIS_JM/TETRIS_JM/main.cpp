#include <stdio.h>
#include "Init.h"
#include "Tetris_.h"
#include "Rank.h"
#include "Finish.h"
#include "sound.h"
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

//#define SOUND_FILE_NAME "D:\\GIt\\Baram\\TETRIS_JM\\TETRIS_JM\\BGM\\BGM-Tetris-Bradinsky.wav"

int main()
{
	Init init;
	Tetris_ tet;
	Rank rank;
	Finish fin;
	sound sound;
	int menucode;
	

	//PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	sound.Init();
	sound.Sound_Play(sound.i % 2);
	sound.VolumeSetSound();


	while (1) {
		menucode = init.menu();
		if (menucode == 0)
			break;
		else if (menucode == 1)
			rank.Ranking(rank.Read_Ranking());
		else if (menucode == 2)
			init.info();
		else if (menucode == 3) {
			sound.Setting();
			SetColor(BLACK, WHITE);
		}
		else if(menucode == 4)
			return 0;
		system("cls");
	}
	while (1) {
		tet.Game();
		fin.GameOver(tet.score, tet.level);
		while (1) {
			menucode = fin.GameOver_menu();
			if (menucode == 0)
				break;
			else if (menucode == 1) {
				rank.Ranking(rank.Read_Ranking());
				system("cls");
			}
			else if (menucode == 2) {
				init.info();
				system("cls");
			}
			else if (menucode == 3)
				return 0;
		}

	}

	system("pause");
	return 0;
}