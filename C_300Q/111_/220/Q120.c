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

	strcpy_s((*pad).name, sizeof(ad.name), "홍길동");
	strcpy_s((*pad).phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s((*pad).address, sizeof(ad.address), "서울시 무무구 모모아파트 13단지");

	printf("이름 : %s  %d\n", pad->name, sizeof(pad->name));
	printf("전화 : %s  %d\n", pad->phone, sizeof(pad->phone));
	printf("주소 : %s  %d\n", pad->address, sizeof(pad->address));
}