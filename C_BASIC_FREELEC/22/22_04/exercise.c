#include <stdio.h>
#include <errno.h>

int main()
{
	FILE* pfile = NULL;
	char* file_path = "c:\\temp\\1.txt";
	int result = 0;
	
	char msg[] = "AAC\r\nabc";
	msg[3] = '\0';

	result = fopen_s(&pfile, file_path, "ab");

	if (result == 0)
	{
		result = fputs(msg, pfile);
		if (result >= 0)
		{
			printf("����[%s], ���[ab] fputs( ) ����\n", file_path);
		}
		else
		{
			printf("����[%s], ���[ab], fputs( ) ����, ������ȣ : %d\n", file_path, errno);
		}
	}
	else 
	{
		printf("����[%s], ���[ab], fopen( ) ����, ������ȣ : %d\n", file_path, errno);
	}


	return 0;
}