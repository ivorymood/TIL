#include <stdio.h>
#include <string.h>

int main(void)
{
	char buff[] = "��ȣ�� Korea�Դϴ�.";

	puts(buff);

	_strset_s(buff, sizeof(buff), 0);

	printf("[%s] \n", buff);

	return 0;
}