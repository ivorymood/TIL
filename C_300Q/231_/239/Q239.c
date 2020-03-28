#include <stdio.h>

int main(void)
{
	char* filename = "d:\\file.txt";
	char* movename = "d:\\temp\\file.txt";

	if (rename(filename, movename) != 0)
	{
		perror("파일 이동 에러");
	}
	else
	{
		puts("파일이 이동되었습니다");
	}

	return 0;
}