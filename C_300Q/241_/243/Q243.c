#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int main(void)
{
	FILE* fpR, * fpW;
	char buff[200];
	char* pbuf, * dup;
	int len, pos1, pos2;
	int error;

	// ���� ����
	error = fopen_s(&fpR, "d:\\file.txt", "r");

	if (fpR == NULL)
	{
		perror("���� �б� ���� ����");
		return 1;
	}

	error = fopen_s(&fpW, "d:\\file_change.txt", "w+");
	
	if (fpW == NULL)
	{
		perror("���� ���� ���� ����");
		_fcloseall();
		return 1;
	}

	// ���ڿ� ��ü
	while (!feof(fpR))
	{
		fgets(buff, 200, fpR);
		
		pbuf = strstr(buff, "���ѹα�");

		if (pbuf)
		{
			len = strlen(buff);
			pos1 = pbuf - buff;

			dup = strdup(buff);
			strnset(&buff[pos1], 0, len - pos1);
			strcat(buff, "�ѱ�");
			
			pos1 = pbuf - buff + strlen("���ѹα�");
			pos2 = pbuf - buff + strlen("�ѱ�");
		
			strcpy(&buff[pos2], &dup[pos1]);
			free(dup);
		}

		if (!feof(fpR))
		{
			fputs(buff, fpW);
		}
	}

	_fcloseall();
	puts("���ѹα��� �ѱ����� ��� ��ü�Ͽ����ϴ�.");

	return 0;
}