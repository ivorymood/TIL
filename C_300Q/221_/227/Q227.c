#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char buff[] = "boy is a man", *pos = buff;
	
	while (pos)
	{
		// ������ ù��° ���� �빮�ڷ� �ٲٱ�
		if (isalpha(buff[0]) && pos == buff)
		{
			buff[0] &= 0xDF;
			pos++;
		}
		// ���� �� ���� �빮�ڷ� �ٲٱ�
		else if(pos = strpbrk(pos, " "))
		{
			*++pos &= 0xDF;
		}
	}

	printf(buff);

	return 0;
}