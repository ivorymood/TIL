#include <stdio.h>

int card_conv(unsigned x, int n, char d[]);
void reverse(char d[], int size);

int main(void)
{
	int i, cd, dno, retry;
	unsigned no;
	char cno[512] = { 0 };

	puts("10진수를 기수 변환합니다. ");

	do 
	{
		printf("변환하는 음이 아닌 정수 : ");
		scanf_s("%d", &no);

		do 
		{
			printf("어떤 진수로 변환할까요? (2-36)");
			scanf_s("%d", &cd);
		} while ( cd < 2 || cd > 36);

		dno = card_conv(no, cd, cno); 
		printf("%d진수로는 ", cd);
		for (i = 0; i < dno; i++)
		{
			printf("%c", cno[i]);
		}
		printf("입니다.\n");

		printf("한번 더 할까요? (1 - 예 \\ 0 - 아니오) : ");
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