#include <stdio.h>

struct simple_point {
	int x;
	int y;
};

struct simple_rectangle {
	struct simple_point left_top;
	int width;
	int height;
};

int main()
{
	struct simple_rectangle rectangle = { 0 };

	printf("기준점 (left_top)의 위치 x는?");
	scanf_s("%d", &rectangle.left_top.x);
	printf("기준점 (left_top)의 위치 y는?");
	scanf_s("%d", &rectangle.left_top.y);
	printf("너비는?");
	scanf_s("%d", &rectangle.width);
	printf("높이는?");
	scanf_s("%d", &rectangle.height);

	printf("Left-top : (%d, %d)\n", rectangle.left_top.x, rectangle.left_top.y);
	printf("Right-top : (%d, %d)\n", rectangle.left_top.x + rectangle.width , rectangle.left_top.y);
	printf("Left-bottom : (%d, %d)\n", rectangle.left_top.x, rectangle.left_top.y + rectangle.height);
	printf("Right-bottom : (%d, %d)\n", rectangle.left_top.x + rectangle.width, rectangle.left_top.y + rectangle.height);

	return 0;
}