#include <stdio.h>

void main(void)
{
	char* oldname = "D:\\file.txt";
	char* newname = "D:\\file_1.txt";

	if (rename(oldname, newname) != 0)
	{
		perror("파일명 변경 에러");
	}
	else
	{
		puts("파일명을 성공적으로 변경함");
	}
}