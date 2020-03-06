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

	printf("������ (left_top)�� ��ġ x��?");
	scanf_s("%d", &rectangle.left_top.x);
	printf("������ (left_top)�� ��ġ y��?");
	scanf_s("%d", &rectangle.left_top.y);
	printf("�ʺ��?");
	scanf_s("%d", &rectangle.width);
	printf("���̴�?");
	scanf_s("%d", &rectangle.height);

	printf("Left-top : (%d, %d)\n", rectangle.left_top.x, rectangle.left_top.y);
	printf("Right-top : (%d, %d)\n", rectangle.left_top.x + rectangle.width , rectangle.left_top.y);
	printf("Left-bottom : (%d, %d)\n", rectangle.left_top.x, rectangle.left_top.y + rectangle.height);
	printf("Right-bottom : (%d, %d)\n", rectangle.left_top.x + rectangle.width, rectangle.left_top.y + rectangle.height);

	return 0;
}