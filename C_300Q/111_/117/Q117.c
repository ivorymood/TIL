#include <stdio.h>

void main(void)
{
	int i, j;
	int jumsu[10][100][3];
	int total[3] = { 0, };
	int(*pjumsu)[100][3];

	pjumsu = jumsu;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			pjumsu[i][j][0] = 92;
			pjumsu[i][j][1] = 90;
			pjumsu[i][j][2] = 95;
		}
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			total[0] += pjumsu[i][j][0];
			total[1] += pjumsu[i][j][1];
			total[2] += pjumsu[i][j][2];
		}
	}

	printf("모든 반의 국어 점수의 총점 : %d \n", total[0]);
	printf("모든 반의 영어 점수의 총점 : %d \n", total[1]);
	printf("모든 반의 수학 점수의 총점 : %d \n", total[2]);
}