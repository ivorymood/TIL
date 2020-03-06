#include <stdio.h>

int main(void)
{
	int height = 0;

	printf("키 입력");
	scanf_s("%d", &height);

	printf("%s", (height >= 150 ? "합격" : "불합격"));

	return 0;
}