#include <stdio.h>
#include <direct.h>

void main(void)
{
	char* pathname = "D:\\ccc";

	if (_rmdir(pathname) == -1)
	{
		perror("디렉터리 삭제 에러");
	}
	else
	{
		perror("디렉터리 성공적으로 삭제하였습니다. ");
	}
}