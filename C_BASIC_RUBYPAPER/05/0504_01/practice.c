#include <stdio.h>

int main(void)
{
	int height = 0;

	printf("Ű �Է�");
	scanf_s("%d", &height);

	printf("%s", (height >= 150 ? "�հ�" : "���հ�"));

	return 0;
}