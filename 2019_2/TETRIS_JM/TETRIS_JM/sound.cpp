#include "sound.h"

FMOD_SYSTEM* g_System; //FMOD system 변수선언
FMOD_SOUND* g_Sound[6];
FMOD_CHANNEL* channel[6] = { 0, };

FMOD_BOOL IsPlaying;


float volume = 0.5; //볼륨 0~1 

sound::sound()
{
}

sound::~sound()
{
}

void sound::Init(void)
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 10, FMOD_INIT_NORMAL, NULL); //최대 10개의 소리재생가능 

	/*사운드 생성*/
	FMOD_System_CreateSound(g_System, "D:\\GIt\\Baram\\TETRIS_JM\\TETRIS_JM\\BGM\\BGM-Tetris-Bradinsky.wav", FMOD_LOOP_NORMAL, 0, &g_Sound[0]);
	FMOD_System_CreateSound(g_System, "D:\\GIt\\Baram\\TETRIS_JM\\TETRIS_JM\\BGM\\line-remove.mp3", FMOD_LOOP_OFF, 0, &g_Sound[1]);
	FMOD_System_CreateSound(g_System, "D:\\GIt\\Baram\\TETRIS_JM\\TETRIS_JM\\BGM\\gameover.mp3", FMOD_LOOP_OFF, 0, &g_Sound[2]);
	FMOD_System_CreateSound(g_System, "D:\\GIt\\Baram\\TETRIS_JM\\TETRIS_JM\\BGM\\pause.mp3", FMOD_LOOP_OFF, 0, &g_Sound[3]);
	FMOD_System_CreateSound(g_System, "D:\\GIt\\Baram\\TETRIS_JM\\TETRIS_JM\\BGM\\block-rotate.mp3", FMOD_LOOP_OFF, 0, &g_Sound[4]);
	FMOD_System_CreateSound(g_System, "D:\\GIt\\Baram\\TETRIS_JM\\TETRIS_JM\\BGM\\whoosh.mp3", FMOD_LOOP_OFF, 0, &g_Sound[5]);
}

void sound::StopSound(void)
{
	FMOD_Channel_Stop(channel[0]); //채널의 소리 모두정지 
}

void sound::VolumeSetSound(void)
{
	FMOD_Channel_SetVolume(channel[0], volume); //설정 볼륨으로 소리크기 지정 
}

void sound::SoundUpdate(void)
{
	if (IsPlaying == 1)
		FMOD_System_Update(g_System);
}

int sound::Setting(void)
{
	system("cls");
	SetCursor(FALSE);
	GotoXY(36, 12);
	printf("# Settings #");

	int x = 36;
	int y = 13;
	int key;

	//GotoXY(x - 5, y);
	//SetColor(WHITE, BLACK); printf("Volume "); printSoundBar(volume);
	GotoXY(x - 10, y + 2);
	SetColor(BLACK, WHITE); printf("← : Volume Down / → : Volume Up "); 
	GotoXY(x - 16, y + 3);
	printf("스페이스바/"); printf("●"); printf("를 누르면 이전 화면으로 돌아갑니다.\n");


	while (1) {
		GotoXY(x - 7, y + 1);
		SetColor(WHITE, BLACK); printf("Volume "); printSoundBar(volume);

		key = _getch();
		//if (key == 224) {
			if (GetAsyncKeyState(VK_LEFT) && volume > 0.1) {
				volume -= 0.1;
				VolumeSetSound();
				Sleep(500);
			}
			else if (GetAsyncKeyState(VK_RIGHT) && volume < 1.0) {
				volume += 0.1;
				VolumeSetSound();
				Sleep(500);
			}
		//}
		if (key == SPACEBAR)
			break;
	}

	SetColor(WHITE, BLACK);
	return 0;
}


void sound::printSoundBar(float n)
{
	if (n > 0.0 && n < 0.1)
		printf("□□□□□□□□□□");
	if (n >= 0.1 && n < 0.2)
		printf("■□□□□□□□□□");
	else if (n >= 0.2 && n < 0.3)
		printf("■■□□□□□□□□");
	else if (n >= 0.3 && n < 0.4)
		printf("■■■□□□□□□□");
	else if (n >= 0.4 && n < 0.5)
		printf("■■■■□□□□□□");
	else if (n >= 0.5 && n < 0.6)
		printf("■■■■■□□□□□");
	else if (n >= 0.6 && n < 0.7)
		printf("■■■■■■□□□□");
	else if (n >= 0.7 && n < 0.8)
		printf("■■■■■■■□□□");
	else if (n >= 0.8 && n < 0.9)
		printf("■■■■■■■■□□");
	else if (n >= 0.9 && n < 1.0)
		printf("■■■■■■■■■□");
	else if (n >= 1.0)
		printf("■■■■■■■■■■");
}


/*-----해당 사운드 재생-----*/

void sound::Sound_Play(int n)
{
	FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[n], 0, &channel[n]);
}