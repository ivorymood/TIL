#include <stdio.h>
#include <errno.h>

int main()
{
	FILE* pfile = NULL;
	int result = 0;

	char* file_path = "c:\\temp\\2.txt";
	result = fopen_s(&pfile, file_path, "rb");

	if (result == 0)
	{
		printf("파일[%s], 모드[rb] fopen( ) 성공\n", file_path);
		fclose(pfile);
	}
	else
	{
		printf("파일[%s], 모드[rb], fopen( ) 실패, 오류번호 : %d\n", file_path, errno);
	}

	return 0;
}