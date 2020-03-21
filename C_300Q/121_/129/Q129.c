#include <stdio.h>
#include <string.h>

typedef struct tagPoint
{
	int x;
	int y;
} point;

void my_memset(void* dest, int c, unsigned count);

void main(void)
{
	point pt = { 5, 10 };
	char array[10];

	printf("x, y : %d, %d \n", pt.x, pt.y);

	my_memset(&pt, 0, sizeof(pt));

	printf("x, y : %d, %d \n", pt.x, pt.y);

	my_memset(&pt, 1, sizeof(pt));

	printf("x, y : %d, %d \n", pt.x, pt.y);

	my_memset(array, '0', sizeof(array));

	printf("array[0] ~ array[9] : %c ~ %c \n", array[0], array[9]);
}

void my_memset(void* dest, int c, unsigned count)
{
	while (count--)
	{
		*(char*)dest = c;
		dest = (char*)dest + 1;
	}
}