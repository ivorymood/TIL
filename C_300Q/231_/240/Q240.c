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
		perror("파일 읽기 개방 에러");
		return 1;
	}

	error = fopen_s(&fpW, "d:\\file_copy.bin", "w+b");
	if (fpW == NULL)
	{
		perror("파일 쓰기 개방 에러");
		fclose(fpR);
		return 1;
	}

	while (!feof(fpR))
	{
		len = fread(&buff, 1, 1, fpR);
		if (ferror(fpR))
		{
			perror("파일 읽기 에러");
			_fcloseall();
			return 1;
		}

		if (len > 0)
		{
			fwrite(&buff, 1, 1, fpW);
			if (ferror(fpW))
			{
				perror("파일 쓰기 에러");
				_fcloseall();
				return 1;
			}
		}
	}

	_fcloseall();

	puts("파일을 성공적으로 복사하였습니다.");

	return 0;
}