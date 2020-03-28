#include <stdio.h>

int main(void)
{
	FILE* fp;
	char buff[5];
	int error;

	error = fopen_s(&fp, "d:\\file.bin", "w+b");

	buff[0] = '@';
	buff[1] = 0;
	buff[2] = 0x01;
	buff[3] = 0x03;
	buff[4] = 0x61;

	if (fp != NULL)
	{
		fwrite(buff, sizeof(char), sizeof(buff), fp);
		fclose(fp);
	}

	printf("ERROR_CODE : %d \n", error);

	return 0;
}