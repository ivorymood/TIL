#include <stdio.h>

int main()
{
	double dData = 123.456;
	printf("%f, %f\n", dData, -123.456);
	printf("%.1f\n", dData);
	printf("%.2f\n", dData);
	printf("%.3f\n", dData);
	
	printf("%8d\n", 123);
	printf("%12.3f\n", dData);
	printf("%012.3f\n", dData);

	return 0;
}