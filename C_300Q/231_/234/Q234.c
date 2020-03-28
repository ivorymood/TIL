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
		// 위 코드 문제 : 마지막에 fgets()가 실패해도, 버퍼를 한번 더 읽어오게 된다

		while(fgets(buff, 100, fp))
		{
			printf(buff);
		}

		fclose(fp);
	}

	printf("ERROR_CODE : %d \n", error);

	return 0;
}