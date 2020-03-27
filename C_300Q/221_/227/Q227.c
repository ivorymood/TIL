#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char buff[] = "boy is a man", *pos = buff;
	
	while (pos)
	{
		// 문장의 첫번째 글자 대문자로 바꾸기
		if (isalpha(buff[0]) && pos == buff)
		{
			buff[0] &= 0xDF;
			pos++;
		}
		// 공백 뒤 글자 대문자로 바꾸기
		else if(pos = strpbrk(pos, " "))
		{
			*++pos &= 0xDF;
		}
	}

	printf(buff);

	return 0;
}