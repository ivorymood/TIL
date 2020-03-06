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
			printf("파일[%s], 모드[ab] fputs( ) 성공\n", file_path);
		}
		else
		{
			printf("파일[%s], 모드[ab], fputs( ) 실패, 오류번호 : %d\n", file_path, errno);
		}
	}
	else 
	{
		printf("파일[%s], 모드[ab], fopen( ) 실패, 오류번호 : %d\n", file_path, errno);
	}


	return 0;
}