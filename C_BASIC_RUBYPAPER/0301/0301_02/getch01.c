#include <stdio.h>
#include <conio.h>

int main()
{
	char ch = 0;

	printf("아무키나 ㄱㄱ");
	ch = _getch();

	printf("입력키는 [");
	putchar(ch);
	printf("]입니다.");

	return 0;
}