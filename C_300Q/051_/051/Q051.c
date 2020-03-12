#include <stdio.h>
#include <conio.h>

#define ENTER 13

void main(void)
{
	int ch;

	printf("아스키 코드로 변환할 키를 누르세요 \n");
	printf("Enter 키를 누르면 프로그램은 종료됩니다 \n");

	do
	{
		ch = _getch();

		printf("문자 : (%c) , 아스키코드 = (%d) \n", ch, ch);

	} while (ch != ENTER);
}