#include <stdio.h>

int add(int value1, int value2);
int subtract(int value1, int value2);
int do_it(int (*pfunc_pointer)(int, int), int value1, int value2);

int main()
{
	int result = 0;
	int value1 = 10, value2 = 20;

	result = do_it(add, value1, value2);
	printf("°á±£°ª : %d\n", result);

	result = do_it(subtract, value1, value2);
	printf("°á±£°ª : %d", result);

	return 0;
}

int do_it(int (*pfunc_pointer)(int, int), int value1, int value2)
{
	return pfunc_pointer(value1, value2);
}

int add(int value1, int value2)
{
	return value1 + value2;
}

int subtract(int value1, int value2)
{
	return value1 - value2;
}