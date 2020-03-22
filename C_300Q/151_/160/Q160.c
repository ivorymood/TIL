#include <stdio.h>

void main(void)
{
	char* filename = "D:\\file_1.txt";

	if (remove(filename) != 0)
	{
		perror("파일 삭제 에러");
	}
	else
	{
		puts("파일을 성공적으로 삭제함");
	}
}