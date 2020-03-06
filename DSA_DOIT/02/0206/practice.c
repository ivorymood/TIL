#include <stdio.h>

int card_conv(unsigned x, int n, char d[]);
void reverse(char d[], int size);

int main(void)
{
	int i, cd, dno, retry;
	unsigned no;
	char cno[512] = { 0 };

	puts("10������ ��� ��ȯ�մϴ�. ");

	do 
	{
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		scanf_s("%d", &no);

		do 
		{
			printf("� ������ ��ȯ�ұ��? (2-36)");
			scanf_s("%d", &cd);
		} while ( cd < 2 || cd > 36);

		dno = card_conv(no, cd, cno); 
		printf("%d�����δ� ", cd);
		for (i = 0; i < dno; i++)
		{
			printf("%c", cno[i]);
		}
		printf("�Դϴ�.\n");

		printf("�ѹ� �� �ұ��? (1 - �� \\ 0 - �ƴϿ�) : ");
		scanf_s("%d", &retry);

	} while (retry == 1);

	return 0;
}

int card_conv(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUWXYZ";
	int digits = 0;

	if (x == 0)
	{
		d[digits++] = dchar[0];
	}
	else
	{
		while (x)
		{
			printf("%d | %10d ... %d\n", n, x, x % n);
			d[digits++] = dchar[x % n];
			x /= n;
			printf("  + --------------\n");
		}

		printf("     %10d\n", x);
		reverse(d, digits);
	}
	return digits;
}

void reverse(char d[], int size)
{
	for (int i = 0; i < size / 2; ++i)
	{
		char temp = d[i];
		d[i] = d[size - i - 1];
		d[size - i - 1] = temp;
	}
}