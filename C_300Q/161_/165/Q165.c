#include <stdio.h>
#include <direct.h>

void main(void)
{
	int drive;

	drive = _getdrive();

	printf("���� ����̺� : %c \n", 'A' + drive - 1);
}