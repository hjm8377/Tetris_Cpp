#pragma once
#include "Tetris_.h"

class Finish
{
private:
public:
	Finish();
	~Finish();
	char name[20] = { '\0', };
	void initname(char* name);
	void GameOver(int score, int level);
	int GameOver_menu();
};