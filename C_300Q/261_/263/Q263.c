#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

int main(void)
{
	int com[3] = { 0, };
	int gamer[3] = { 0, };
	int guess[10] = { 0, };
	int count;
	int strike, ball;
	char yesno;

	srand(time(NULL));
	
	puts("�߱����� ����");

	while (1)
	{
		com[0] = rand() % 10;
		com[1] = rand() % 10;
		com[2] = rand() % 10;
		count = 1;

		if (com[0] == com[1] || com[0] == com[2] || com[1] == com[2])
		{
			continue;
		}

		puts("���� 0~9�� �������� �и��Ͽ� 3�� �Է��ϰ� ����Ű�� ġ����!");

		memset(guess, 0, sizeof(guess));

		while (1)
		{
			strike = 0;
			ball = 0;

			for (int i = 0; i < 10; i++)
			{
				printf("%d", guess[i]);
			}
			printf("\n 3���� ����[0~9]�� �Է��ϼ��� : ");

			scanf("%d %d %d", &gamer[0], &gamer[1], &gamer[2]);

			if (com[0] == gamer[0])
			{
				strike++;
			}
			else if (com[0] == gamer[1] || com[0] == gamer[2])
			{
				ball++;
			}

			if (com[1] == gamer[1])
			{
				strike++;
			}
			else if (com[1] == gamer[0] || com[1] == gamer[2])
			{
				ball++;
			}

			if (com[2] == gamer[2])
			{
				strike++;
			}
			else if (com[2] == gamer[0] || com[2] == gamer[1])
			{
				ball++;
			}

			if (gamer[0] > 9 || gamer[1] > 9 || gamer[2] > 9)
			{
				puts("�Է��� ���ڰ� �ʹ� Ů�ϴ�. 0~9�� �Է��ϼ���");
				continue;
			}

			guess[gamer[0]] = 1;
			guess[gamer[1]] = 1;
			guess[gamer[2]] = 1;

			printf("\n[%2dȸ] %d��Ʈ����ũ %d�� \n\n", count, strike, ball);
			
			if (strike == 3)
			{
				break;
			}
			count++;

		}

		fflush(stdin);

		printf("������ ��� �Ͻðڽ��ϱ�?(y/n)");
		scanf("%c", &yesno);
		if (yesno == 'N' || yesno == 'n')
		{
			break;
		}
	}

	return 0;
}