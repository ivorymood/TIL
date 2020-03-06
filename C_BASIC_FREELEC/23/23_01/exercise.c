#include <stdio.h>

int main()
{
	FILE* pfile = NULL;
	int result = 0;
	char* file_path = "d:\\example.txt";

	result = fopen_s(&pfile, file_path, "w");

	if (result == 0)
	{
		fputs("1번째 내용이 파일에 쓰였나요?\n", pfile);
		fputs("2번째 내용이 파일에 쓰였나요?\n", pfile);
		fflush(pfile);
		fputs("3번째 내용이 파일에 쓰였나요?\n", pfile);
		fclose(pfile);
	}

	return 0;
}