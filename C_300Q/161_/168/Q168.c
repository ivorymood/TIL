#include <stdio.h>
#include <time.h>

void main(void)
{
	time_t now;

	time(&now);
	printf("1970�� 1�� 1�Ϻ��� ������� ����� �� : %d \n", now);
}