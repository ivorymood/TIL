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
	struct tagAddress ad;
	struct tagAddress* pad;

	pad = &ad;

	strcpy_s((*pad).name, sizeof(ad.name), "ȫ�浿");
	strcpy_s((*pad).phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s((*pad).address, sizeof(ad.address), "����� ������ ������Ʈ 13����");

	printf("�̸� : %s  %d\n", pad->name, sizeof(pad->name));
	printf("��ȭ : %s  %d\n", pad->phone, sizeof(pad->phone));
	printf("�ּ� : %s  %d\n", pad->address, sizeof(pad->address));
}