#include <stdio.h>
#include <string.h>

void my_print(struct tagAddress *pad);

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};

void main(void)
{
	struct tagAddress ad;

	strcpy_s(ad.name, sizeof(ad.name), "ȫ�浿");
	strcpy_s(ad.phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s(ad.address, sizeof(ad.address), "����� ������ ������Ʈ 13����");

	my_print(&ad);
}

void my_print(struct tagAddress *pad)
{
	printf("�̸� : %s  %d\n", pad->name, sizeof(pad->name));
	printf("��ȭ : %s  %d\n", pad->phone, sizeof(pad->phone));
	printf("�ּ� : %s  %d\n", pad->address, sizeof(pad->address));
}