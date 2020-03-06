#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int count = 0;
	int* parray = NULL;
	int last_count = 0;


	do
	{
		for (int i = 0; i < last_count; i++)
		{
			printf("[%d] %d\n", i, *(parray + i));
		}
		printf("현재 원소의 개수는 %d개입니다.\n", count);
		
		// 배열 길이 입력
		while (count <= last_count)
		{
			printf("원소의 개수는(0이하 값 입력하면 종료됨)?\n");
			scanf_s("%d", &count);

			if (count <= 0) 
			{
				printf("0보다 작은 수 입력\n");
				return 0;
			}
			if (count <= last_count) 
			{
				printf("%d보다 커야 합니다.\n", last_count);
			}
		}

		// int배열 메모리 할당
		parray = (int*)realloc(parray, sizeof(int) * count);

		if (parray == NULL)
		{
			printf("메모리 할당 실패");
			return 0;
		}

		// 배열 원소 입력
		for (int i = last_count; i < count; i++)
		{
			printf("%d번째 원소의 값은?\n", i);
			scanf_s("%d", parray + i);
		}

		last_count = count;
	}
	while (count > 0);

	if (parray != NULL) free(parray);
	
	return 0;
}