#include <stdio.h>

typedef struct _my_point
{
	int x;
	int y;
} my_point, * pmy_point, ** ppmy_point;

int main()
{
	my_point point1 = { 10, 10 };
	my_point point2 = { 90, 90 };

	pmy_point ppoint = NULL;

	ppoint = &point1;
	printf("포인터의 위치: (%d, %d)\n", ppoint->x, ppoint->y);

	ppoint = &point2;
	printf("포인터의 위치: (%d, %d)\n", ppoint->x, ppoint->y);

	return 0;
}