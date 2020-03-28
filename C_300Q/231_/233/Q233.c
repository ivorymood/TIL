#include <stdio.h>

int main(void)
{
	FILE* fp;
	int error;

	error = fopen_s(&fp, "d:\\file.txt", "w+");

	if (fp != NULL)
	{
		fputs("¥Î«—πŒ±π1 \n", fp);
		fputs("¥Î«—πŒ±π2 \n", fp);
		fputs("¥Î«—πŒ±π3 \n", fp);
		fputs("¥Î«—πŒ±π4 \n", fp);
		fputs("¥Î«—πŒ±π5 \n", fp);
		fclose(fp);
	}

	printf("ERROR_CODE : %d \n", error);

	return 0;
}