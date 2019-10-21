#pragma once
#include "Console.h"
#include "sound.h"

class Init
{
private:	//접근 제한자(비공개)
	int consoleX = 80;
	int consoleY = 30;
public:	//접근 제한자(공개)
	Init();	//디폴트 생성자
	~Init();	//소멸자

	void init();
	void info();
	int setting();
	int menu();
	sound sound;
};