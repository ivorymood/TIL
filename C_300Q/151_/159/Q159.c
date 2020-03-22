#include <stdio.h>
#include <io.h>
#include <sys/stat.h>

void main(void)
{
	char* filename = "D:\\file_1.txt";

	if (_chmod(filename, _S_IWRITE) != 0)
	{
		perror("파일 속성 설정 에러");
	}
	else
	{
		puts("파일 속성을 성공적으로 변경함");
	}
}