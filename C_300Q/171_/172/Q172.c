#include <stdio.h>
#include <time.h>

void main(void)
{
	time_t now;
	char buffer[30] = {0};

	time(&now);
	ctime_s(buffer, sizeof(buffer), &now);

	printf("���� ��¥ �� �ð� : %s", buffer);
}