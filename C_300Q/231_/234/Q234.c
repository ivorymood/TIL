#include <stdio.h>

int main(void)
{
	FILE* fp;
	char buff[100];
	int error;

	error = fopen_s(&fp, "d:\\file.txt", "r");

	if (fp != NULL)
	{

		/*
		while (!feof(fp))				
		{
			fgets(buff, 100, fp);
			printf(buff);
		}
		*/
		// �� �ڵ� ���� : �������� fgets()�� �����ص�, ���۸� �ѹ� �� �о���� �ȴ�

		while(fgets(buff, 100, fp))
		{
			printf(buff);
		}

		fclose(fp);
	}

	printf("ERROR_CODE : %d \n", error);

	return 0;
}