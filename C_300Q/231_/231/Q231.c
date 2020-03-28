#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MEGA_BYTE 1048576

int main(void)
{
	char* pbuf;

	pbuf = malloc(100 * MEGA_BYTE);

	if (pbuf)
	{
		memset(pbuf, 0, 100 * MEGA_BYTE);

		strcpy_s(&pbuf[0], 100 * MEGA_BYTE, "����� ��õ�� ��");
		puts(&pbuf[0]);

		strcpy_s(&pbuf[100 * (MEGA_BYTE - 1)], 100, "�λ�� ������ ������");
		puts(&pbuf[100 * (MEGA_BYTE - 1)]);
	
		free(pbuf);
	}

	return 0;
}