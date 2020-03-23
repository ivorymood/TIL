#include <stdio.h>
#include <time.h>

void main(void)
{
	time_t s1, s2;
	double gop = 1;
	int i;

	time(&s1);
	printf("s1 : %lld\n", s1);

	for (i = 0; i < 10000000; i++)
	{
		gop = gop + 100;
	}

	time(&s2);
	printf("s2 : %lld\n", s2);
	printf("gop : %f\n", gop);

	printf("경과시간 : %g 초 \n", difftime(s2, s1));
}