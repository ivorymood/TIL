#include <stdio.h>

int main(void)
{
	FILE* fp;
	int error;

	error = fopen_s(&fp, "d:\\file.txt", "w+");

	if (fp != NULL)
	{
		fputs("���ѹα�1 \n", fp);
		fputs("���ѹα�2 \n", fp);
		fputs("���ѹα�3 \n", fp);
		fputs("���ѹα�4 \n", fp);
		fputs("���ѹα�5 \n", fp);
		fclose(fp);
	}

	printf("ERROR_CODE : %d \n", error);

	return 0;
}