#include <stdio.h>
#include <conio.h>

int print(char *string);

void main(void)
{
	print("This is a putch function!");
}

int print(char *string)
{
	int len = 0;

	while (*string != (char)NULL)
	{
		_putch(*string);
		string++;
		len++;
	}

	_putch('\r'); // 캐리지 리턴
	_putch('\n'); // 라인 피드

	return len;
}