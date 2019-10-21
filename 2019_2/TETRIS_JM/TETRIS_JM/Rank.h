#pragma once
#include "Console.h"

class Rank
{
private:

public:
	Rank();
	~Rank();
	/*랭킹 파일 정렬을 위한 구조체*/
	typedef struct {
		char name[20] = "\0";
		int score = 0;
	}RANK;
	void WriteRanking(char* name, int score);
	int Read_Ranking();
	void Ranking(int size);
};