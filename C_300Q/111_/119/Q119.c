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

	strcpy_s(ad.name, sizeof(ad.name), "ȫ�浿");
	strcpy_s(ad.phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s(ad.address, sizeof(ad.address), "����� ������ ������Ʈ 13����");

	printf("�̸� : %s  %d\n", ad.name, sizeof(ad.name));
	printf("��ȭ : %s  %d\n", ad.phone, sizeof(ad.phone));
	printf("�ּ� : %s  %d\n", ad.address, sizeof(ad.address));
}