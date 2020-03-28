#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp;
	char buff[100] = { 0, };
	int len;
	int error;

	error = fopen_s(&fp, "d:\\file.txt", "r");

	if (fp != NULL)
	{
		/*
		while (!feof(fp))
		{
			len = fread(buff, 1, 9, fp);

			if (ferror(fp) || len < 9)
			{
				break;
			}
			printf("1read : %d, %s", len, buff);
		}
		*/
		// 위 코드는 printf()의 위치에 따라 다르게 출력한다.

		while ((len = fread(buff, 1, 9, fp)))
		{
			if (ferror(fp) || len < 9)
			{
				break;
			}
			printf("read : %d, %s", len, buff);
		}
		fclose(fp);
	}

	printf("ERROR_CODE : %d \n", error);

	return 0;
}