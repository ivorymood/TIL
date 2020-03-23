#include <stdio.h>
#include <direct.h>

void main(void)
{
	char* pathname = "D:\\ccc";

	if (_mkdir(pathname) == -1)
	{
		perror("디렉터리 생성 에러");
	}
	else
	{
		perror("디렉터리 성공적으로 생성하였습니다. ");
	}
}