#include <stdio.h>
#include <direct.h>

void main(void)
{
	int drive = 3;

	if (_chdrive(drive) == 0)
	{
		drive = _getdrive();
		printf("����� ����̺� : %c \n", 'A' + drive - 1);
	}
	else
	{
		puts("����!");
	}

}