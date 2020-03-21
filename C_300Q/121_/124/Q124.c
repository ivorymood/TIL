#include <stdio.h>
#include <string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};

void my_print(struct tagAddress *pad);

void main(void)
{
	struct tagAddress ad[3];
	struct tagAddress* pad;
	int i;

	pad = ad;

	for (i = 0; i < 3; i++)
	{
		sprintf_s(ad[i].name, sizeof(ad[i].name), "ȫ�浿 %d", i);
		strcpy_s(ad[i].phone, sizeof(ad[i].phone), "02-1234-5678");
		strcpy_s(ad[i].address, sizeof(ad[i].address), "����� ������ ������Ʈ 13����");
	}

	my_print(ad);
}

void my_print(struct tagAddress* pad)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("�̸� : %s  %d\n", pad[i].name, sizeof(pad[i].name));
		printf("��ȭ : %s  %d\n", pad[i].phone, sizeof(pad[i].phone));
		printf("�ּ� : %s  %d\n", pad[i].address, sizeof(pad[i].address));
	}
}