#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp;
	char buff[200];
	int line = 1;
	int error;

	error = fopen_s(&fp, "d:\\file.txt", "r");

	if (fp == NULL)
	{
		perror("�����б� ���� ����");
		return 1;
	}

	while (fgets(buff, sizeof(buff), fp) != NULL)
	{
		if (strstr(buff, "���ѹα�"))
		{
			printf("Line(%2d) : %s", line, buff);
		}
		line++;
	}

	_fcloseall();

	return 0;
}
