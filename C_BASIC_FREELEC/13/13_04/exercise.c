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
		printf("���� ������ ������ %d���Դϴ�.\n", count);
		
		// �迭 ���� �Է�
		while (count <= last_count)
		{
			printf("������ ������(0���� �� �Է��ϸ� �����)?\n");
			scanf_s("%d", &count);

			if (count <= 0) 
			{
				printf("0���� ���� �� �Է�\n");
				return 0;
			}
			if (count <= last_count) 
			{
				printf("%d���� Ŀ�� �մϴ�.\n", last_count);
			}
		}

		// int�迭 �޸� �Ҵ�
		parray = (int*)realloc(parray, sizeof(int) * count);

		if (parray == NULL)
		{
			printf("�޸� �Ҵ� ����");
			return 0;
		}

		// �迭 ���� �Է�
		for (int i = last_count; i < count; i++)
		{
			printf("%d��° ������ ����?\n", i);
			scanf_s("%d", parray + i);
		}

		last_count = count;
	}
	while (count > 0);

	if (parray != NULL) free(parray);
	
	return 0;
}