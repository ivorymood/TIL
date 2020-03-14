#include <stdio.h>
#include <string.h>

int bf_matchr(const char txt[], const char pat[])
{
	int pt = strlen(txt) - 1; // txtĿ��
	int pp = strlen(pat) - 1; // patĿ��

	while (pt >=0 && pp >= 0)
	{
		if (txt[pt] == pat[pp])
		{
			pt--;
			pp--;
		}
		else
		{
			pt = pt - pp + strlen(pat) - 2;
			pp = strlen(pat) - 1;;
		}
	}

	if (pp < 0)
	{
		return pt - pp;
	}
	return -1;
}

int main()
{
	int idx;
	char s1[256];
	char s2[256];
	puts("���Ʈ-������");
	printf("�ؽ�Ʈ : ");
	scanf_s("%s", s1, 256);
	printf("���� : ");
	scanf_s("%s", s2, 256);

	idx = bf_matchr(s1, s2);

	if (idx == -1)
	{
		puts("�ؽ�Ʈ�� ������ �����ϴ� ");
	}
	else
	{
		printf("%d��° ���ں��� match�մϴ�. \n", idx + 1);
	}

	return 0;
}