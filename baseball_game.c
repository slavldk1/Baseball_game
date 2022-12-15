#include "common.h"
#include <time.h>
#include "baseball_game.h"
#include "Score_Boad.h"
#include "visual.h"
static int check;
static int answer[3];
static int answer2[3];
static int strike, ball, out;
static int count;
static int round;
static int win_p1, win_p2;

enum{Yes=1,No};
void baseball_start_solo()
{
	int player_answer[3]={0};
	printf("1인 모드는 숫자 3개를 맟출때 까지 시도한 횟수를 점수로 산정하여,\n횟수가 높아지는 방삭입니다.");
	baseball_setup_solo();

	while (1)
	{
		baseball_check_solo(player_answer);
		if (check == 1)
		{
			printf("정답을 맞추셨습니다.\n%d번만에 맟추셨습니다.",count);
			while (1)
			{
				printf("점수를 저장하시겠습니까?(Yes:1,No:2)\n:");
				scanf("%d", &check);
				if (check == 1 || check == 2)
				{
					if (check == 1)
					{
						Score_Save(count);
					}
					else if (check == 2)
					{
						printf("메뉴로 돌아갑니다.");
					}
				}
				else
				{
					printf("잘못 입력하셨습니다.\n");
				}
			}
			
			break;
		}
		else
		{
			continue;
		}
	}
}

void baseball_setup_solo()
{
	int rnd;
	printf("게임 세팅시작.\n");
	printf("숫자 생성중.\n");
	srand((unsigned int)time(NULL));
	rnd = rand() % 9 + 1;
	answer[0] = rnd;
	for (int i = 1; i < 3; i++)
	{
		rnd = rand() % 9 + 1;
		if (answer[i - 1] != rnd)
		{
			answer[i] = rnd;
		}
		else
		{
			i--;
		}
	}
	printf("숫자 생성 완료.\n");
}

void baseball_setup_duo()
{
	int rnd;
	printf("게임 세팅시작.\n");
	printf("숫자 생성중.\n");
	srand((unsigned int)time(NULL));
	rnd = rand() % 9 + 1;
	answer[0] = rnd;
	for (int i = 1; i < 3; i++)
	{
		rnd = rand() % 9 + 1;
		if (answer[i - 1] != rnd)
		{
			answer[i] = rnd;
		}
		else
		{
			i--;
		}
	}
	answer2[0] = rnd;
	for (int i = 1; i < 3; i++)
	{
		rnd = rand() % 9 + 1;
		if (answer2[i - 1] != rnd)
		{
			answer2[i] = rnd;
		}
		else
		{
			i--;
		}
	}
	printf("1p와2p의 숫자가 배정되었습니다.");
}




void baseball_check_solo(int *player)
{
	int i, j;
	int temp;
	printf("숫자(1~9)를 3개 입력해 주세요.\n");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &temp);
		if (temp > 9 || temp < 0)
		{
			printf("0부터 9사이의 숫자를 입력하여 주세요.\n");
			return;
		}
		*(player + i) = temp;
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (answer[i] == *(player + j))
			{
				if (i == j)
				{
					strike++;
				}
				else
				{
					ball++;
				}
			}
		}
	out = 3 - (strike + ball);
	baseball_result_solo();
}


void baseball_result_solo()
{
	printf("%d번째 결과:\n",count);
	baseball_visual_(strike,ball,out);
	count++;
	if (strike == 3)
	{
		check = 1;
	}
	strike = 0;
	ball = 0;
	out = 0;
}


void baseball_start_duo_same()
{
	int result;
	int p1_answer[3] = { 0 };
	int p2_answer[3] = { 0 };
	char player;
	printf("2인단일 정답 모드를 시작합니다.\n");
	printf("2인단일 정답 모드는\n두명의 플레이어가 하나의 정답을 가지고 먼저 맟추는쪽이 승리하는\n방식입니다.");
	if ((result = first_scond()) == 1)
	{
		printf("1p가 선공입니다.\n");
	}
	else
	{
		printf("2p가 선공입니다.");
	}
	baseball_setup_solo();
	while (1)
	{
		baseball_check_duo_same(result, p1_answer, p2_answer);
		result++;
		if (check == 1)
		{
			player = (result % 2 + 1 == 1 ? "1p" : "2p");
			printf("%c가 승리하였습니다!",player);
			break;
		}
	}

}

void baseball_check_duo_same(int firset_turn,int *p1,int *p2)
{
	int i, j;
	int temp;
	int turn = firset_turn;
	if (turn%2+1 == 1)
	{
		printf("1p의 차례입니다.");
		printf("숫자(1~9)를 3개 입력해 주세요.\n");
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &temp);
			if (temp > 9 || temp < 0)
			{
				printf("0부터 9사이의 숫자를 입력하여 주세요.\n");
				return;
			}
			*(p1 + i) = temp;
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (answer[i] == *(p1 + j))
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}
				}
			}
		out = 3 - (strike + ball);
		baseball_result_duo_same(turn);
	}
	else if (turn%2+1 == 2)
	{
		printf("2p의 차례입니다.");
		printf("숫자(1~9)를 3개 입력해 주세요.\n");
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &temp);
			if (temp > 9 || temp < 0)
			{
				printf("0부터 9사이의 숫자를 입력하여 주세요.\n");
				return;
			}
			*(p2 + i) = temp;
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (answer[i] == *(p2 + j))
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}
				}
			}
		out = 3 - (strike + ball);
		baseball_result_duo_same(turn);
	}
}

void baseball_result_duo_same(int turn)
{
	if (turn % 2 + 1 == 1)
	{
		printf("1p의 결과");
	}
	else if (turn % 2 + 1 == 2)
	{
		printf("2p의 결과");
	}
	baseball_visual_(strike, ball, out);
	count++;
	if (strike == 3)
	{
		check = 1;
	}
	strike = 0;
	ball = 0;
	out = 0;
}



int first_scond()
{
	int n1=0, n2=0;
	int result;
	printf("선/후 공을 정하겠습니다.\n");
	srand((unsigned int)time(NULL));
	n1 = rand() % 6 + 1;
	n2 = rand() % 6 + 1;
	result = (n1 > n2 ? 1 : 2);
	return result;
}

void baseball_start_duo_diff()
{
	int result;
	int p1_answer[3] = { 0 };
	int p2_answer[3] = { 0 };
	char player;
	printf("2인 개인 정답 모드를 시작합니다.\n");
	printf("2인 개인 정답 모드는\n각 플레이어가 각자의 정답을 가지고\n먼저 맞추는 쪽이 승리하는 방식입니다.\n");
	if ((result = first_scond()) == 1)
	{
		printf("1p가 선공입니다.\n");
	}
	else
	{
		printf("2p가 선공입니다.");
	}
	baseball_setup_duo();
	while (1)
	{
		baseball_check_duo_same(result, p1_answer, p2_answer);
		result++;
		if (check == 1)
		{
			player = (result % 2 + 1 == 1 ? "1p" : "2p");
			printf("%c가 승리하였습니다!", player);
			break;
		}
	}
}

void baseball_check_duo_diff(int firset_turn, int* p1, int* p2)
{
	int i, j;
	int temp;
	int turn = firset_turn;
	if (turn % 2 + 1 == 1)
	{
		printf("1p의 차례입니다.\n");
		printf("숫자(1~9)를 3개 입력해 주세요.\n");
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &temp);
			if (temp > 9 || temp < 0)
			{
				printf("0부터 9사이의 숫자를 입력하여 주세요.\n");
				return;
			}
			*(p1 + i) = temp;
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (answer[i] == *(p1 + j))
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}
				}
			}
		}
		out = 3 - (strike + ball);
		baseball_result_duo_same(turn);
	}
	else if (turn % 2 + 1 == 2)
	{
		printf("2p의 차례입니다.\n");
		printf("숫자(1~9)를 3개 입력해 주세요.\n");
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &temp);
			if (temp > 9 || temp < 0)
			{
				printf("0부터 9사이의 숫자를 입력하여 주세요.\n");
				return;
			}
			*(p2 + i) = temp;
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (answer2[i] == *(p2 + j))
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}

				}
			}
		}
		out = 3 - (strike + ball);

		baseball_result_duo_same(turn);
	}
}

void baseball_solo_time_attack()
{

	int player_answer[3] = { 0 };
	int first_timer=0;
	int second_timer = 0;


	printf("1인 타임어택 모드를 시작합니다.\n");
	printf("1인 타임어택 모드는\n 시도 횟수는 상관없이, 맞춘 시간을 기반으로\n점수를 측정하는 방식입니다.\n");
	baseball_setup_solo();
	first_timer = timer();
	while (1)
	{
		baseball_check_solo(player_answer);

		if (check == 1)
		{
			second_timer = timer();
			printf(" %d분 %d초 만에 정답을 맞추셨습니다. ",(second_timer-first_timer)/60,(second_timer-first_timer)%60);
			while (1)
			{
				printf("점수를 저장하시겠습니까?(Yes:1,No:2)\n:");
				scanf("%d", &check);
				if (check == 1 || check == 2)
				{
					if (check == 1)
					{
						Score_Time_Save(second_timer - first_timer);
					}
					else if (check == 2)
					{
						printf("메뉴로 돌아갑니다.");
					}
					else
					{
						printf("잘못 입력하셨습니다.\n");
					}
				}
			}

			break;
		}
		else
			continue;
	}

}

int timer()
{
	int re;
	time_t start = time(NULL);
	struct tm *timer;

	timer = localtime(&start);
	re=(timer->tm_min) * 60 + (timer->tm_sec);
	return re;
}


void baseball_start_duo_round_mode()
{
	int result;
	int p1_answer[3] = { 0 };
	int p2_answer[3] = { 0 };
	char player;
	int chose=0;
	printf("2인 라운드 모드를 시작합니다.\n");
	baseball_setup_duo();
	while (1)
	{
		printf("3판 2선승제를 원하시면 1번을, 5판3승제를 원하시면 2번을 입력해주십시오.");
		scanf("%d", &chose);
		if (chose == 1)
		{
			printf("3판 2선승제를 진행합니다.");
			break;
		}
		else if (chose == 2)
		{
			printf("5판 3선승제를 진행합니다.");
			break;
		}
		else
		{
			printf("잘 못 입력하셨습니다.");
		}
	}
	if ((result = first_scond()) == 1)
	{
		printf("1p가 선공입니다.\n");
	}
	else
	{
		printf("2p가 선공입니다.");
	}
	baseball_setup_duo();
	while (1)
	{
		baseball_check_duo_same(result, p1_answer, p2_answer);
		result++;
		if (check == 1)
		{
			round++;
			player = (result % 2 + 1 == 1 ? "1p" : "2p");
			printf("%c가 %d번째 라운드를 승리하셨습니다.",player,round);
			if (round == chose)
			{
				if (win_p1 > win_p2)
				{
					printf("1p가 %d:%d로 승리하였습니다.", win_p1, win_p2);
					break;
				}
				else if (win_p1 < win_p2)
				{
					printf("2p가 %d:%d로 승리하였습니다.", win_p1, win_p2);
					break;
				}
			}
			_round(result);
		}
	}

}

void _round(int player)
{

	if (player % 2 + 1 == 1)
	{
		win_p1++;
	}
	else if (player % 2 + 1 == 2)
	{
		win_p2++;
	}
}

void baseball_start_com()
{
	int com_answer[3] = { 0 };
	printf("이 모드는 컴퓨터가 맞출떄 까지의 횟수를 출력하는 모드입니다.");
	baseball_setup_solo();

	while (1)
	{
		baseball_check_solo(com_answer);
		if (check == 1)
		{
			printf("컴퓨터가 %d번만에 정답을 맞췄습니다.", count);
			system("pause");
			break;
		}
		else
		{
			continue;
		}
	}
}
void baseball_check_com(int *com)
{
	int i, j;
	int temp;
	int rnd;
	for (i = 0; i < 3; i++)
	{
		rnd = rand() % 9 + 1;
		com[0] = rnd;
		for (int i = 1; i < 3; i++)
		{
			rnd = rand() % 9 + 1;
			if (answer[i - 1] != rnd)
			{
				answer[i] = rnd;
			}
			else
			{
				i--;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (answer[i] == *(com + j))
			{
				if (i == j)
				{
					strike++;
				}
				else
				{
					ball++;
				}
			}
		}
	}
	out = 3 - (strike + ball);
	baseball_result_solo();
}