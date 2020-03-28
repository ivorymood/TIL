#include <stdio.h>

int main(void)
{
	FILE* fpR, * fpW;
	char buff;
	int len;
	int error;

	error = fopen_s(&fpR, "d:\\file.bin", "rb");
	if (fpR == NULL)
	{
		perror("���� �б� ���� ����");
		return 1;
	}

	error = fopen_s(&fpW, "d:\\file_copy.bin", "w+b");
	if (fpW == NULL)
	{
		perror("���� ���� ���� ����");
		fclose(fpR);
		return 1;
	}

	while (!feof(fpR))
	{
		len = fread(&buff, 1, 1, fpR);
		if (ferror(fpR))
		{
			perror("���� �б� ����");
			_fcloseall();
			return 1;
		}

		if (len > 0)
		{
			fwrite(&buff, 1, 1, fpW);
			if (ferror(fpW))
			{
				perror("���� ���� ����");
				_fcloseall();
				return 1;
			}
		}
	}

	_fcloseall();

	puts("������ ���������� �����Ͽ����ϴ�.");

	return 0;
}