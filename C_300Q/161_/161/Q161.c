#include <stdio.h>
#include <direct.h>

void main(void)
{
	char* pathname = "D:\\ccc";

	if (_mkdir(pathname) == -1)
	{
		perror("���͸� ���� ����");
	}
	else
	{
		perror("���͸� ���������� �����Ͽ����ϴ�. ");
	}
}