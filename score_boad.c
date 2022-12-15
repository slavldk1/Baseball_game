#include "common.h"
#include "Score_Boad.h"
static char name[Name_Len];
static Score *List[10];
static Score *Data;
static Score* List2[10];
static int Data_count1 = 0;
static int Data_count2 = 0;
void Score_Save(int *count)
{
	system("cls");
	Data = (Score*)malloc(sizeof(Score));
	printf("닉네임 입력:");
	scanf("%s", name);
	Data->score = count;
	strcpy(Data->name, name);
	if (Data_count1 >= 10)
	{
		over_check(count);
		bubble();
	}
	else
	{
		List[Data_count1] = Data;
		Data_count1++;
		bubble();
	}
	printf("저장이 완료되었습니다.\n");
}


void ScoreBoad()
{
	system("cls");
	printf("======================");
	for (int i = 0; i <Data_count1; i++)
	{
		printf("%d위:%s  %d번\n", List[i]->rate, List[i]->name, List[i]->score);
	}
	printf("======================");
}


void bubble()
{
	int i, j;
	Score *temp;
	for(i=0;i<Data_count1-1;i++)
		for (j = 0; j < Data_count1 - 1 - i; j++)
		{
			if (List[j]->score > List[j + 1]->score)
			{
				temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
			}
		}
	rate();
}

void over_check(int *count)
{
	if (List[9]->score < *count)
	{
		List[9] = Data;
	}

}

int Score_check(int count)
{
	for (int i = 0; i < count; i++)
	{
		if (List[i]->score < count)
			return 1;
		else
			return 0;
	}
}

void rate()
{
	for (int i = 0; i < Data_count1; i++)
	{
		List[i]->rate = i + 1;
	}
}

void Score_Time_Save(int count)
{
	system("cls");
	Data = (Score*)malloc(sizeof(Score));
	printf("닉네임 입력:");
	scanf("%s", name);
	Data->score = count;
	strcpy(Data->name, name);
	if (Data_count2 >= 10)
	{
		over_check2(count);
		bubble2();
	}
	else
	{
		List2[Data_count2] = Data;
		Data_count2++;
		bubble2();
	}
	printf("저장이 완료되었습니다.\n");
}
void bubble2()
{
	int i, j;
	Score* temp;
	for (i = 0; i < Data_count2 - 1; i++)
		for (j = 0; j < Data_count2 - 1 - i; j++)
		{
			if (List2[j]->score > List2[j + 1]->score)
			{
				temp = List2[j];
				List2[j] = List2[j + 1];
				List2[j + 1] = temp;
			}
		}
	rate2();
}
void rate2()
{
	for (int i = 0; i < Data_count2; i++)
	{
		List2[i]->rate = i + 1;
	}
}
void over_check2(int* count)
{
	if (List2[9]->score < *count)
	{
		List2[9] = Data;
	}

}
void ScoreBoad2()
{
	system("cls");
	printf("======================");
	for (int i = 0; i < Data_count2; i++)
	{
		printf("%d위:%s  %d분 %d초\n", List2[i]->rate, List2[i]->name, (List2[i]->score)/60,(List2[i]->score)%60);
	}
	printf("======================");
}