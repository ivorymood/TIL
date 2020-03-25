#include <stdio.h>

#define scan(d, x, y) printf( #d "형 (%"#x")을 입력하세요 \n"); \
						scanf( #x, &y); \
						printf("scanf %"#x" : " #x "\n\n", y)

int main(void)
{
	char ch = 0;
	short int si = 0;
	int i = 0;
	int o8 = 0;
	int x16 = 0;
	unsigned ui = 0;
	long l = 0;
	float f = 0;
	char s[100] = { 0, };

	scan(char, %c, ch);
	scan(short, %hd, si);
	scan(int, %d, i);
	scan(unsigned, %u, ui);
	scan(long, %d, l);
	scan(8진수, %o, o8);
	scan(16진수, %x, x16);
	scan(고정소수점, %f, f);
	scan(문자열, %s, s);

	scanf("%4d %3d, &i, &o8");
	printf("%d, %d \n", i, o8);

	return 0;
}