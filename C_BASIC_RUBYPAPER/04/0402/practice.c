#include <stdio.h>

int main(void)
{
	int hour, min, second = 0;

	printf("�� �Է� : ");
	scanf_s("%d", &second);

	hour = second / 3600;
	min = second % 3600 / 60;
	second = second % 60;
	
	printf("%d �ʴ� %02d�ð� %02d�� %02d�� �Դϴ�. ", second, hour, min, second);


	return 0;
}