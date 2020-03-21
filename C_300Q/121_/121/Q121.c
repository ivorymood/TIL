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

	strcpy_s(ad.name, sizeof(ad.name), "홍길동");
	strcpy_s(ad.phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s(ad.address, sizeof(ad.address), "서울시 무무구 모모아파트 13단지");

	my_print(&ad);
}

void my_print(struct tagAddress *pad)
{
	printf("이름 : %s  %d\n", pad->name, sizeof(pad->name));
	printf("전화 : %s  %d\n", pad->phone, sizeof(pad->phone));
	printf("주소 : %s  %d\n", pad->address, sizeof(pad->address));
}