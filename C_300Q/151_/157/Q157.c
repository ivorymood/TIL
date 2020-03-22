#include <stdio.h>
#include <io.h>

void main(void)
{
	char* path = "D:\\file.txt";

	if (_access(path, 0) == 0)
	{
		puts("해당경로 파일이 존재합니다");
	}
}