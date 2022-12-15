#include "common.h"
#include "baseball_game.h"
#include "Score_Boad.h"
#include "visual.h"
enum {Play_SOLO=1,PLAY_SOLO_TIME,
	PLAY_DUO_SAME,PLAY_DUO_DIFF,PLAY_DUO_ROUND,Boad,CREDIT,EXIT,test};
int try = 5;
int answer = 0;
int main()
{
	int chose;
	int answer = 0;

	while (1)
	{
		system("cls");
		baseball_title();
		scanf("%d", &chose);
		if (chose == EXIT)
		{
			printf("게임을 종료하시겠습니까? \nYes:1 No:2\n:");
			scanf("%d", &answer);
			if (answer == 1)
			{
				printf("이용해 주셔서 감사합니다.\n");
				break;
			}
			else
				continue;
		}
		switch (chose)
		{
		case Play_SOLO:
			printf("1인_단일모드를 선택하셨습니다. 계속하시겠습니까? \nYes:1 No:2\n:");
			scanf("%d", &answer);
			if (answer == 2)
				break;
			else
			{
				system("cls");
				baseball_start_solo();
			}
			break;
		case PLAY_SOLO_TIME:
			printf("1인_타임어택 모드를 선택하셨습니다. 계속하시겠습니까> \nYes:1 No:2\n:");
			scanf("%d", &answer);
			if (answer == 2)
				break;
			else
			{
				system("cls");
				baseball_solo_time_attack();
			}
			break;
		case PLAY_DUO_SAME:
			printf("2인 단일정답 모드를 선택하셨습니다. 계속하시겠습니까? \nYes:1 No:2\n:");
			scanf("%d", &answer);
			if (answer == 2)
				break;
			else
			{
				system("cls");
				baseball_start_duo_same();
			}
			break;
		case PLAY_DUO_DIFF:
			printf("2인_개인정답 모드를 선택하셨습니다. 계속하시겠습니까? \nYes:1 No:2\n:");
			scanf("%d", &answer);
			if (answer == 2)
				break;
			else
			{
				system("cls");
				baseball_start_duo_diff();
			}
		case PLAY_DUO_ROUND:
			printf("2인 라운드(3판 2선승제)를 선택하셨습니다. 계속하시겠습니까? \nYes:1 No:2\n");
			scanf("%d", &answer);
			if (answer == 2)
				break;
			else
			{
				system("cls");
				baseball_start_duo_round_mode();
			}
			break;
		case Boad:
		{
			system("cls");
			ScoreBoad();
		}
		case CREDIT:
			credit();
			break;
		case test:
			printf("디버깅 모드에 진입합니다.\n");
			printf("1인 일반모드 스코어보드 작동을 확인합니다.\n");
			printf("점수를 입력하여 주세요:\n");
			scanf("%d", &try);
			Score_Save(try);
			ScoreBoad();
			printf("1인 타임어택 스코어보드 작동을 확인합니다.\n");
			printf("점수를 입력하여 주세요:\n");
			scanf("%d", &try);
			Score_Time_Save(try);
			ScoreBoad2();
			printf("숫자 야구 프로그렘의 작동을 확인합니다.\n");
			baseball_start_com();
			printf("확인을 종료합니다.");
			break;
		default:
			printf("잘 못 선택 하셨습니다.");
			break;
		}
	}
}


void credit()
{
	system("cls");
	printf("제작에 도움을 주신 분.\n\n");
	printf("컴퓨터 공학부 교수님.\n");
	printf("Google\n");
	Sleep(2000);
	printf("아이디어 제공\n\n");
	printf("우리가족.\n");
	printf("그리고 내 소중한 친구인 오곡밥튀김.\n");
	Sleep(2000);
	printf("그리고 플래이 해준 당신!\n");
	Sleep(2500);
	system("cls");
}