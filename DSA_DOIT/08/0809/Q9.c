#include <stdio.h>

int bf_match(const char txt[], const char pat[])
{
	int pt = 0; // txtĿ��
	int pp = 0; // patĿ��
	int count = 0;
	int right = 0;

	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		printf("%3d %s\n", count, txt);

		if (txt[pt] == pat[pp])
		{
			printf("%*c\n", (pp + count + 5), '+');
			pt++;
			pp++;
			right = 1;
		}
		else
		{
			printf("%*c\n", (pp + count + 5), '|');
			pt = pt - pp + 1;
			pp = 0;
			right = 0;
			count++;
		}
		
		printf("%*s%s\n", (right) ? (count + 4) : (count + 3), "", pat);
		
	}

	printf("�񱳸� %dȸ �õ��մϴ�.\n", count);

	if (pat[pp] == '\0')
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

	idx = bf_match(s1, s2);

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