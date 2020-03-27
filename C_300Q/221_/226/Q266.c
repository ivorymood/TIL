#include <stdio.h>
#include <string.h>

int main(void)
{
	char buff[] = "암호는 Korea입니다.";

	puts(buff);

	_strset_s(buff, sizeof(buff), 0);

	printf("[%s] \n", buff);

	return 0;
}