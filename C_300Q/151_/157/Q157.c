#include <stdio.h>
#include <io.h>

void main(void)
{
	char* path = "D:\\file.txt";

	if (_access(path, 0) == 0)
	{
		puts("�ش��� ������ �����մϴ�");
	}
}