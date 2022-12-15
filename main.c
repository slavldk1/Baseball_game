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
			printf("������ �����Ͻðڽ��ϱ�? \nYes:1 No:2\n:");
			scanf("%d", &answer);
			if (answer == 1)
			{
				printf("�̿��� �ּż� �����մϴ�.\n");
				break;
			}
			else
				continue;
		}
		switch (chose)
		{
		case Play_SOLO:
			printf("1��_���ϸ�带 �����ϼ̽��ϴ�. ����Ͻðڽ��ϱ�? \nYes:1 No:2\n:");
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
			printf("1��_Ÿ�Ӿ��� ��带 �����ϼ̽��ϴ�. ����Ͻðڽ��ϱ�> \nYes:1 No:2\n:");
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
			printf("2�� �������� ��带 �����ϼ̽��ϴ�. ����Ͻðڽ��ϱ�? \nYes:1 No:2\n:");
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
			printf("2��_�������� ��带 �����ϼ̽��ϴ�. ����Ͻðڽ��ϱ�? \nYes:1 No:2\n:");
			scanf("%d", &answer);
			if (answer == 2)
				break;
			else
			{
				system("cls");
				baseball_start_duo_diff();
			}
		case PLAY_DUO_ROUND:
			printf("2�� ����(3�� 2������)�� �����ϼ̽��ϴ�. ����Ͻðڽ��ϱ�? \nYes:1 No:2\n");
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
			printf("����� ��忡 �����մϴ�.\n");
			printf("1�� �Ϲݸ�� ���ھ�� �۵��� Ȯ���մϴ�.\n");
			printf("������ �Է��Ͽ� �ּ���:\n");
			scanf("%d", &try);
			Score_Save(try);
			ScoreBoad();
			printf("1�� Ÿ�Ӿ��� ���ھ�� �۵��� Ȯ���մϴ�.\n");
			printf("������ �Է��Ͽ� �ּ���:\n");
			scanf("%d", &try);
			Score_Time_Save(try);
			ScoreBoad2();
			printf("���� �߱� ���α׷��� �۵��� Ȯ���մϴ�.\n");
			baseball_start_com();
			printf("Ȯ���� �����մϴ�.");
			break;
		default:
			printf("�� �� ���� �ϼ̽��ϴ�.");
			break;
		}
	}
}


void credit()
{
	system("cls");
	printf("���ۿ� ������ �ֽ� ��.\n\n");
	printf("��ǻ�� ���к� ������.\n");
	printf("Google\n");
	Sleep(2000);
	printf("���̵�� ����\n\n");
	printf("�츮����.\n");
	printf("�׸��� �� ������ ģ���� �����Ƣ��.\n");
	Sleep(2000);
	printf("�׸��� �÷��� ���� ���!\n");
	Sleep(2500);
	system("cls");
}