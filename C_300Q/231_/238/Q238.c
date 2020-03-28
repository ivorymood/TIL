#include <stdio.h>

int main(void)
{
	FILE* fp;
	char buff;
	int error;

	error = fopen_s(&fp, "d:\\file.bin", "rb");

	if (fp != NULL)
	{
		/*
		while (!feof(fp))
		{
			fread(&buff, 1, 1, fp);
			if (!feof(fp))
			{
				printf("%d (%#x)\n", buff, buff);
			}
		}
		*/
		// 아래코드가 더 간결하다.

		while (!feof(fp))
		{
			if (fread(&buff, 1, 1, fp))
			{
				printf("%d (%#x)\n", buff, buff);
			}
		}
	}

	printf("ERROR_CODE : %d \n", error);

	return 0;
}