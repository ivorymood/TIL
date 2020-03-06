#include <stdio.h>

struct my_point {
	double x;
	double y;
};

int main()
{
	double sum_x = 0, sum_y = 0;
	double average_x = 0, average_y = 0;
	struct my_point points[3] = { 0 };
	int size = sizeof(points) / sizeof(struct my_point);

	for (int i = 0; i < size; i++)
	{
		printf("x 입력 : ");
		scanf_s("%lf", &points[i].x);
		printf("y 입력 : ");
		scanf_s("%lf", &points[i].y);
	}

	for (int i = 0; i < size; i++)
	{
		sum_x += points[i].x;
		sum_y += points[i].y;
	}
	average_x = sum_x / size;
	average_y = sum_y / size;

	printf("%d점의 중간 위치: (%.2lf, %.2lf)", size, average_x, average_y);

	return 0;
}