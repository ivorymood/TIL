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
	
	printf("����ü addr�� ũ�� : %d \n", len);

	memset(&ad, 0, len);
}