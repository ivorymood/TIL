#include <stdio.h>

#define swap(x, y) \
do {char *tmp = *x; *x = *y; *y = tmp;} while(0)

int main(void)
{
	char* s1 = "ABCD";
	char* s2 = "EFGH";

	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�. \n", s1);
	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�. \n", s2);

	swap(&s1, &s2);

	puts("\n ������ s1�� s2�� ���� ���� ��ȯ�߽��ϴ�. \n");

	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�. \n", s1);
	printf("������ s1�� \"%s\"�� ����ŵ�ϴ�. \n", s2);

	return 0;
}