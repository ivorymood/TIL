
/* ���ڿ����� ���� �˻��ϴ� ���α׷� */
#include <stdio.h>
#include <string.h>

/*--- ���ڿ� s���� ���� c�� �˻��ϴ� �Լ� ---*/
char* str_chr(const char* s, int c)
{
	int i = 0;
	c = (char)c;
	while (s[i] != c) 
	{
		if (s[i] == '\0')
		{
			return NULL;	/* �˻� ���� */
		}
		i++;
	}
	return (char*)(s + i);			/* �˻� ���� */
}

int main(void)
{
	char str[64];	/* �� ���ڿ����� �˻�*/
	char tmp[64];
	int ch;			/* �˻��� ���� */
	char* pidx;
	char* pidx_2;

	printf("���ڿ� : ");
	scanf_s("%s", str, 64);

	printf("�˻��� ���� : ");
	scanf_s("%s", tmp, 64);		/* ���� ���ڿ��� �˻��� ���ڸ� �о� ���Դϴ�. */
	ch = tmp[0];				/* ù ��° ���ڸ� �˻��� ���ڷ� �����մϴ�. */

	pidx_2 = strchr(str, ch);
	
	if ((pidx = str_chr(str, ch)) == NULL)		/* ó�� ������ ���ڸ� �˻��մϴ�. */
	{
		printf("���� '%c'�� ���ڿ��� �����ϴ�.\n", ch);
	}
	else
	{
		printf("1: ���� '%c'��(��) %d ��°�� �ֽ��ϴ�.\n", ch, (pidx - str) + 1);
		printf("2: ���� '%c'��(��) %d ��°�� �ֽ��ϴ�.\n", ch, (pidx_2 - str) + 1);
	}

	return 0;
}