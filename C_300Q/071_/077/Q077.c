#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int count;
	int total = 0;
	char string[100];

	for (count = 1; count <= 3; count++)
	{
		printf("%d ��° ���ڿ��� �Է��� �� EnterŰ�� �������� \n", count);
	
		gets_s(string, 100);
	
		total += atoi(string);

		printf("�Է� �� = %d, �� �� = %d \n", atoi(string), total);
	}
	printf("���� ���ڿ��� �� ���� %d�Դϴ�. \n", total);
}