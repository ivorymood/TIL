#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp;
	char* string = "�츮����\n";
	int error;

	error = fopen_s(&fp, "d:\\file.txt", "w+");

	if (fp != NULL)
	{
		fwrite(string, sizeof(string[0]), strlen(string), fp);
		fwrite(string, sizeof(string[0]), strlen(string), fp);
		fwrite(string, sizeof(string[0]), strlen(string), fp);
		fclose(fp);
	}

	printf("ERROR_CODE : %d \n", error);

	return 0;
}