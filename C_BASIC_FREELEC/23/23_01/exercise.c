#include <stdio.h>

int main()
{
	FILE* pfile = NULL;
	int result = 0;
	char* file_path = "d:\\example.txt";

	result = fopen_s(&pfile, file_path, "w");

	if (result == 0)
	{
		fputs("1��° ������ ���Ͽ� ��������?\n", pfile);
		fputs("2��° ������ ���Ͽ� ��������?\n", pfile);
		fflush(pfile);
		fputs("3��° ������ ���Ͽ� ��������?\n", pfile);
		fclose(pfile);
	}

	return 0;
}