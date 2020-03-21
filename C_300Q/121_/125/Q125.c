#include <stdio.h>
#include <string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};

typedef struct tagAddress addr;

void main()
{
	addr ad;
	int len;

	len = sizeof(addr);
	
	printf("구조체 addr의 크기 : %d \n", len);

	memset(&ad, 0, len);
}