#include <stdio.h>

int main(void)
{
	printf("파일명 : %s \n", __FILE__);
	printf("날  짜 : %s \n", __DATE__);
	printf("시  간 : %s \n", __TIME__);
	printf("줄  수 : %d \n", __LINE__);

	return 0;
}