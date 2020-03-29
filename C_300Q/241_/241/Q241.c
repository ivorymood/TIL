#include <stdio.h>

#define FILEREAD 4096

int main(void)
{
	FILE* fpR1, * fpR2, * fpW;
	char buff[FILEREAD];
	int len;
	int error;

	// 파일 오픈
	error = fopen_s(&fpR1, "d:\\file.bin", "rb");
	
	if (fpR1 == NULL)
	{
		perror("파일 읽기 개방 에러");
		return 1;
	}

	error = fopen_s(&fpR2, "d:\\file_copy.bin", "rb");

	if (fpR2 == NULL)
	{
		perror("파일 읽기 개방 에러");
		_fcloseall();
		return 1;
	}

	error= fopen_s(&fpW, "d:\\file2.bin", "w+b");

	if (fpW == NULL)
	{
		perror("파일 쓰기 개방 에러");
		_fcloseall();
		return 1;
	}

	// 파일 2개 합치기
	while (!feof(fpR1))
	{
		len = fread(buff, 1, FILEREAD, fpR1);
		if (ferror(fpR1))
		{
			perror("파일 읽기 에러1");
			_fcloseall();
			return 1;
		}

		if (len > 0)
		{
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW))
			{
				perror("파일 쓰기 에러1");
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
			perror("파일 읽기 에러2");
			_fcloseall();
			return 1;
		}

		if (len > 0)
		{
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW))
			{
				perror("파일 쓰기 에러2");
				_fcloseall();
				return 1;
			}
		}
	}

	_fcloseall();

	puts("파일이 성공적으로 합쳐졌습니다.");

	return 0;
}