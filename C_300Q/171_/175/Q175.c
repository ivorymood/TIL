#include <stdio.h>
#include <time.h>

void main(void)
{
	time_t now;
	struct tm t;
	char buffer[30];

	now = time(NULL);
	localtime_s(&t, &now);

	asctime_s(buffer , sizeof(buffer), &t);
	printf("���� ��¥ �� �ð� : %s \n", buffer);
}