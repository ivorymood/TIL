#include <stdio.h>

int main()
{
	FILE* pfile = NULL;
	int success = 0;
	char* file_path = "c:\\temp\\1.txt";
	success = fopen_s(&pfile, file_path, "wb");

	if (success == 0)
	{
		printf("파일[%s], 모드[wb] fopen( ) 성공\n", file_path);
		fclose(pfile);
	}
	else
	{
		printf("파일[%s], 모드[wb] fopen( ) 실패\n", file_path);
	}

	success = fopen_s(&pfile, file_path, "rb");
	if (success == 0)
	{
		printf("파일[%s], 모드[rb] fopen( ) 성공\n", file_path);
		fclose(pfile);
	}
	else
	{
		printf("파일[%s], 모드[rb] fopen( ) 실패\n", file_path);
	}

	return 0;
}
