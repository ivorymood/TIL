#include <stdio.h>

// �̸���? ������
// ������ �Դϴ�. 
int main()
{
	char str_name[512] = { 0 };

	
	printf("�̸���?");
	scanf_s("%s", str_name, 512);

	printf("�̸��� %s �Դϴ�\n", str_name);

	return 0;
}