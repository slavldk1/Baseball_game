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
	printf("1�� ���� ���� 3���� ���⶧ ���� �õ��� Ƚ���� ������ �����Ͽ�,\nȽ���� �������� ����Դϴ�.");
	baseball_setup_solo();

	while (1)
	{
		baseball_check_solo(player_answer);
		if (check == 1)
		{
			printf("������ ���߼̽��ϴ�.\n%d������ ���߼̽��ϴ�.",count);
			while (1)
			{
				printf("������ �����Ͻðڽ��ϱ�?(Yes:1,No:2)\n:");
				scanf("%d", &check);
				if (check == 1 || check == 2)
				{
					if (check == 1)
					{
						Score_Save(count);
					}
					else if (check == 2)
					{
						printf("�޴��� ���ư��ϴ�.");
					}
				}
				else
				{
					printf("�߸� �Է��ϼ̽��ϴ�.\n");
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
	printf("���� ���ý���.\n");
	printf("���� ������.\n");
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
	printf("���� ���� �Ϸ�.\n");
}

void baseball_setup_duo()
{
	int rnd;
	printf("���� ���ý���.\n");
	printf("���� ������.\n");
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
	printf("1p��2p�� ���ڰ� �����Ǿ����ϴ�.");
}




void baseball_check_solo(int *player)
{
	int i, j;
	int temp;
	printf("����(1~9)�� 3�� �Է��� �ּ���.\n");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &temp);
		if (temp > 9 || temp < 0)
		{
			printf("0���� 9������ ���ڸ� �Է��Ͽ� �ּ���.\n");
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
	printf("%d��° ���:\n",count);
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
	printf("2�δ��� ���� ��带 �����մϴ�.\n");
	printf("2�δ��� ���� ����\n�θ��� �÷��̾ �ϳ��� ������ ������ ���� ���ߴ����� �¸��ϴ�\n����Դϴ�.");
	if ((result = first_scond()) == 1)
	{
		printf("1p�� �����Դϴ�.\n");
	}
	else
	{
		printf("2p�� �����Դϴ�.");
	}
	baseball_setup_solo();
	while (1)
	{
		baseball_check_duo_same(result, p1_answer, p2_answer);
		result++;
		if (check == 1)
		{
			player = (result % 2 + 1 == 1 ? "1p" : "2p");
			printf("%c�� �¸��Ͽ����ϴ�!",player);
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
		printf("1p�� �����Դϴ�.");
		printf("����(1~9)�� 3�� �Է��� �ּ���.\n");
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &temp);
			if (temp > 9 || temp < 0)
			{
				printf("0���� 9������ ���ڸ� �Է��Ͽ� �ּ���.\n");
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
		printf("2p�� �����Դϴ�.");
		printf("����(1~9)�� 3�� �Է��� �ּ���.\n");
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &temp);
			if (temp > 9 || temp < 0)
			{
				printf("0���� 9������ ���ڸ� �Է��Ͽ� �ּ���.\n");
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
		printf("1p�� ���");
	}
	else if (turn % 2 + 1 == 2)
	{
		printf("2p�� ���");
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
	printf("��/�� ���� ���ϰڽ��ϴ�.\n");
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
	printf("2�� ���� ���� ��带 �����մϴ�.\n");
	printf("2�� ���� ���� ����\n�� �÷��̾ ������ ������ ������\n���� ���ߴ� ���� �¸��ϴ� ����Դϴ�.\n");
	if ((result = first_scond()) == 1)
	{
		printf("1p�� �����Դϴ�.\n");
	}
	else
	{
		printf("2p�� �����Դϴ�.");
	}
	baseball_setup_duo();
	while (1)
	{
		baseball_check_duo_same(result, p1_answer, p2_answer);
		result++;
		if (check == 1)
		{
			player = (result % 2 + 1 == 1 ? "1p" : "2p");
			printf("%c�� �¸��Ͽ����ϴ�!", player);
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
		printf("1p�� �����Դϴ�.\n");
		printf("����(1~9)�� 3�� �Է��� �ּ���.\n");
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &temp);
			if (temp > 9 || temp < 0)
			{
				printf("0���� 9������ ���ڸ� �Է��Ͽ� �ּ���.\n");
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
		printf("2p�� �����Դϴ�.\n");
		printf("����(1~9)�� 3�� �Է��� �ּ���.\n");
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &temp);
			if (temp > 9 || temp < 0)
			{
				printf("0���� 9������ ���ڸ� �Է��Ͽ� �ּ���.\n");
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


	printf("1�� Ÿ�Ӿ��� ��带 �����մϴ�.\n");
	printf("1�� Ÿ�Ӿ��� ����\n �õ� Ƚ���� �������, ���� �ð��� �������\n������ �����ϴ� ����Դϴ�.\n");
	baseball_setup_solo();
	first_timer = timer();
	while (1)
	{
		baseball_check_solo(player_answer);

		if (check == 1)
		{
			second_timer = timer();
			printf(" %d�� %d�� ���� ������ ���߼̽��ϴ�. ",(second_timer-first_timer)/60,(second_timer-first_timer)%60);
			while (1)
			{
				printf("������ �����Ͻðڽ��ϱ�?(Yes:1,No:2)\n:");
				scanf("%d", &check);
				if (check == 1 || check == 2)
				{
					if (check == 1)
					{
						Score_Time_Save(second_timer - first_timer);
					}
					else if (check == 2)
					{
						printf("�޴��� ���ư��ϴ�.");
					}
					else
					{
						printf("�߸� �Է��ϼ̽��ϴ�.\n");
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
	printf("2�� ���� ��带 �����մϴ�.\n");
	baseball_setup_duo();
	while (1)
	{
		printf("3�� 2�������� ���Ͻø� 1����, 5��3������ ���Ͻø� 2���� �Է����ֽʽÿ�.");
		scanf("%d", &chose);
		if (chose == 1)
		{
			printf("3�� 2�������� �����մϴ�.");
			break;
		}
		else if (chose == 2)
		{
			printf("5�� 3�������� �����մϴ�.");
			break;
		}
		else
		{
			printf("�� �� �Է��ϼ̽��ϴ�.");
		}
	}
	if ((result = first_scond()) == 1)
	{
		printf("1p�� �����Դϴ�.\n");
	}
	else
	{
		printf("2p�� �����Դϴ�.");
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
			printf("%c�� %d��° ���带 �¸��ϼ̽��ϴ�.",player,round);
			if (round == chose)
			{
				if (win_p1 > win_p2)
				{
					printf("1p�� %d:%d�� �¸��Ͽ����ϴ�.", win_p1, win_p2);
					break;
				}
				else if (win_p1 < win_p2)
				{
					printf("2p�� %d:%d�� �¸��Ͽ����ϴ�.", win_p1, win_p2);
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
	printf("�� ���� ��ǻ�Ͱ� ���⋚ ������ Ƚ���� ����ϴ� ����Դϴ�.");
	baseball_setup_solo();

	while (1)
	{
		baseball_check_solo(com_answer);
		if (check == 1)
		{
			printf("��ǻ�Ͱ� %d������ ������ ������ϴ�.", count);
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