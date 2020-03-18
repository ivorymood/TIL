// ��� �ҽ� �״�� ������
#include <stdio.h>
#include <string.h>

int kmp_match(const char txt[], const char pat[])
{
	int pt = 1;
	int pp = 0;
	int skip[1024];
	int i = 0, j = 0, k = 0;
	int tlen = strlen(txt);
	int plen = strlen(pat);
	int count = 0;

	printf("�ǳʶٱ� ǥ ����\n");
	skip[pt] = 0;
	while (pat[pt] != '\0') {
		if (k == pt - pp)
			printf("    ");
		else {
			printf("%2d  ", pt - pp);
			k = pt - pp;
		}
		for (i = 0; i < plen; i++)
			printf("%c ", pat[i]);
		putchar('\n');

		printf("%*s%c\n", pt * 2 + 4, "", (pat[pt] == pat[pp]) ? '+' : '|');

		printf("%*s", (pt - pp) * 2 + 4, "");
		for (i = 0; i < plen; i++)
			printf("%c ", pat[i]);
		printf("\n\n");
		count++;
		if (pat[pt] == pat[pp])
			skip[++pt] = ++pp;
		else if (pp == 0)
			skip[++pt] = pp;
		else
			pp = skip[pp];
	}

	printf("�ǳʶٱ� ǥ\n");
	for (i = 1; i < plen; i++)
		printf(" %c", pat[i]);
	putchar('\n');

	for (i = 1; i < plen; i++)
		printf("--");
	printf("-\n");

	for (i = 1; i < plen; i++)
		printf("%2d", skip[i + 1]);
	printf("\n\n");

	printf("�˻�\n");
	pt = pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (k == pt - pp)
			printf("    ");
		else {
			printf("%2d  ", pt - pp);
			k = pt - pp;
		}
		for (i = 0; i < tlen; i++)
			printf("%c ", txt[i]);
		putchar('\n');

		printf("%*s%c\n", pt * 2 + 4, "", (txt[pt] == pat[pp]) ? '+' : '|');

		printf("%*s", (pt - pp) * 2 + 4, "");
		for (i = 0; i < plen; i++)
			printf("%c ", pat[i]);
		printf("\n\n");
		count++;

		if (txt[pt] == pat[pp]) {
			pt++; pp++;
		}
		else if (pp == 0)
			pt++;
		else
			pp = skip[pp];
	}

	printf("�񱳸� %dȸ �߽��ϴ�.\n", count);
	if (pat[pp] == '\0')
		return pt - pp;
	return -1;
}

int main(void)
{
	int idx;
	char s1[256];	// �ؽ�Ʈ
	char s2[256];	// ����

	puts("kmp��");
	printf("�ؽ�Ʈ : ");
	scanf_s("%s", s1, 256);
	printf("���� : ");
	scanf_s("%s", s2, 256);

	idx = kmp_match(s1, s2);	
	if (idx == -1)
	{
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	}
	else
	{
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);
	}

	return 0;


}