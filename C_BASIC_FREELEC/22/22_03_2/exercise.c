#include <stdio.h>
#include <errno.h>

int main()
{
	FILE* pfile = NULL;
	int result = 0;

	char* file_path = "c:\\temp\\2.txt";
	result = fopen_s(&pfile, file_path, "rb");

	if (result == 0)
	{
		printf("����[%s], ���[rb] fopen( ) ����\n", file_path);
		fclose(pfile);
	}
	else
	{
		printf("����[%s], ���[rb], fopen( ) ����, ������ȣ : %d\n", file_path, errno);
	}

	return 0;
}