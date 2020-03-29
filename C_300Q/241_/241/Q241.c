#include <stdio.h>

#define FILEREAD 4096

int main(void)
{
	FILE* fpR1, * fpR2, * fpW;
	char buff[FILEREAD];
	int len;
	int error;

	// ���� ����
	error = fopen_s(&fpR1, "d:\\file.bin", "rb");
	
	if (fpR1 == NULL)
	{
		perror("���� �б� ���� ����");
		return 1;
	}

	error = fopen_s(&fpR2, "d:\\file_copy.bin", "rb");

	if (fpR2 == NULL)
	{
		perror("���� �б� ���� ����");
		_fcloseall();
		return 1;
	}

	error= fopen_s(&fpW, "d:\\file2.bin", "w+b");

	if (fpW == NULL)
	{
		perror("���� ���� ���� ����");
		_fcloseall();
		return 1;
	}

	// ���� 2�� ��ġ��
	while (!feof(fpR1))
	{
		len = fread(buff, 1, FILEREAD, fpR1);
		if (ferror(fpR1))
		{
			perror("���� �б� ����1");
			_fcloseall();
			return 1;
		}

		if (len > 0)
		{
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW))
			{
				perror("���� ���� ����1");
				_fcloseall();
				return 1;
			}
		}
	}

	while (!feof(fpR2))
	{
		len = fread(buff, 1, FILEREAD, fpR2);
		if (ferror(fpR2))
		{
			perror("���� �б� ����2");
			_fcloseall();
			return 1;
		}

		if (len > 0)
		{
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW))
			{
				perror("���� ���� ����2");
				_fcloseall();
				return 1;
			}
		}
	}

	_fcloseall();

	puts("������ ���������� ���������ϴ�.");

	return 0;
}