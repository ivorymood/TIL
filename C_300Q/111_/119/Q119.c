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

	strcpy_s(ad.name, sizeof(ad.name), "홍길동");
	strcpy_s(ad.phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s(ad.address, sizeof(ad.address), "서울시 무무구 모모아파트 13단지");

	printf("이름 : %s  %d\n", ad.name, sizeof(ad.name));
	printf("전화 : %s  %d\n", ad.phone, sizeof(ad.phone));
	printf("주소 : %s  %d\n", ad.address, sizeof(ad.address));
}