#include <stdio.h>
#include <string.h>

#define SKY "sky"

void main(void)
{
	char string[100];
	int ret;

	printf("���ܾ �Է��� �� EnterŰ�� �������� \n");
	printf("sky�� �Է��ϸ� ���α׷��� ����˴ϴ�.\n");

	do
	{
		gets_s(string, sizeof(string));
		ret = strcmp(string, SKY);

		if (ret == 0)
		{
			printf("%s == %s, ret = %d \n", string, SKY, ret);
			break;
		}
		else if (ret < 0)
		{
			printf("%s < %s, ret = %d \n", string, SKY, ret);
		}
		else
		{
			printf("%s > %s, ret = %d \n", string, SKY, ret);
		}
	}
	while(1);
}