#include <stdio.h>
#include <io.h>
#include <sys/stat.h>

void main(void)
{
	char* filename = "D:\\file_1.txt";

	if (_chmod(filename, _S_IWRITE) != 0)
	{
		perror("���� �Ӽ� ���� ����");
	}
	else
	{
		puts("���� �Ӽ��� ���������� ������");
	}
}