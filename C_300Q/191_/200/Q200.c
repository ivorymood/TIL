#include <stdio.h>

int main(void)
{
	printf("���ϸ� : %s \n", __FILE__);
	printf("��  ¥ : %s \n", __DATE__);
	printf("��  �� : %s \n", __TIME__);
	printf("��  �� : %d \n", __LINE__);

	return 0;
}