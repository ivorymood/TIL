#include <stdio.h>

int main()
{
	FILE* pfile = NULL;
	int success = 0;
	char* file_path = "c:\\temp\\1.txt";
	success = fopen_s(&pfile, file_path, "wb");

	if (success == 0)
	{
		printf("����[%s], ���[wb] fopen( ) ����\n", file_path);
		fclose(pfile);
	}
	else
	{
		printf("����[%s], ���[wb] fopen( ) ����\n", file_path);
	}

	success = fopen_s(&pfile, file_path, "rb");
	if (success == 0)
	{
		printf("����[%s], ���[rb] fopen( ) ����\n", file_path);
		fclose(pfile);
	}
	else
	{
		printf("����[%s], ���[rb] fopen( ) ����\n", file_path);
	}

	return 0;
}
