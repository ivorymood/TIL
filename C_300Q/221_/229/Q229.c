#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
	char buff[] = "��ȣ�� Korea�Դϴ�";
	char* dup;

	dup = _strdup(buff);

	if (dup)
	{
		strcpy_s(buff, sizeof(buff), "�ٸ� ���ڿ�");
		puts(buff);
		puts(dup);
		free(dup);
	}

	return 0;
}