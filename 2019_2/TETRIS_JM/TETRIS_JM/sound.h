#pragma once
#include <stdio.h>
#include <fmod.h>
#include <conio.h>
#include "Tetris_.h"
#include "Console.h"

class sound
{
	

private:
public:
	sound();
	~sound();
	int i = 0;
	void Init(void);
	void StopSound(void);
	static void VolumeSetSound(void);
	void SoundUpdate(void);
	int Setting(void);
	void Sound_Play(int);
	void printSoundBar(float);
};

