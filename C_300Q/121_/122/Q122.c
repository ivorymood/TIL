#include <stdio.h>
#include <string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};

void main(void)
{
	struct tagAddress ad[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		sprintf_s(ad[i].name, sizeof(ad[i].name), "ȫ�浿 %d", i);
		strcpy_s(ad[i].phone, sizeof(ad[i].phone), "02-1234-5678");
		strcpy_s(ad[i].address, sizeof(ad[i].address), "����� ������ ������Ʈ 13����");
	}

	for (i = 0; i < 3; i++)
	{
		printf("�̸� : %s  %d\n", ad[i].name, sizeof(ad[i].name));
		printf("��ȭ : %s  %d\n", ad[i].phone, sizeof(ad[i].phone));
		printf("�ּ� : %s  %d\n", ad[i].address, sizeof(ad[i].address));
	}
}