#pragma once
#ifndef __FILE_H__
#define __FILE_H__
#define Name_Len 30

typedef struct __ScroeData
{
	char name[Name_Len];
	int score;
	int rate;
}Score;
void Score_Save(int* count);
void over_check(int* count);

void ScoreBoad();
void bubble();
void rate();

void bubble2();
void rate2();
void Score_Time_Save(int count);
void over_check2(int* count);
void ScoreBoad2();


#endif // !__FILE_H__
