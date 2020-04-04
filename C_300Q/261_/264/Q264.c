#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int push(int value);
int pop(int* value);

#define STACK_MAX 100

typedef struct tagStack
{
	int array[STACK_MAX];
	int top;
	int bottom;
} STACK;

STACK s;

int main(void)
{
	char buff[100], tmp[100];
	char* op = "+-*/%";
	int index;
	int value1 = 0, value2 = 0;

	s.top = STACK_MAX;

	puts("������ 1*2ó�� �Է��ϰ� ����Ű�� ġ����");
	puts("�ƹ��͵� �Է����� ������ ��� ����");

	for (;;)
	{
		printf("���� : ");
		gets(buff);

		if (strlen(buff) == 0)
		{
			break;
		}
		memset(tmp, 0, sizeof(tmp));

		index = strcspn(buff, op);

		memcpy(tmp, buff, index);

		value1 = atoi(tmp);
		value2 = atoi(&buff[index + 1]);

		switch (buff[index])
		{
			case '+': value1 += value2; break;
			case '-': value1 -= value2; break;
			case '*': value1 *= value2; break;
			case '/': value1 /= value2; break;
			case '%': value1 %= value2; break;
			default : 
				puts("�߸��� �����ڸ� �����");
				continue;
		}

		if (push(value1) == -1)
		{
			puts("���̻� ������ �� �����ϴ�. ");
		}

		printf("%s = %d, s.top = %d \n\n", buff, value1, s.top);
	}

	value1 = 0;

	for (;;)
	{
		if (pop(&value2) == -1)
		{
			break;
		}
		value1 += value2;
	}

	printf("����� ������ %d�Դϴ�. \n", value1);

	return 0;
}

int push(int value)
{
	if (s.top == 0)
	{
		return -1;
	}
	s.array[--s.top] = value;

	return 0;
}

int pop(int* value)
{
	if (s.top == STACK_MAX)
	{
		return -1;
	}

	*value = s.array[s.top++];

	return 0;
}