#include <stdio.h>

// 프로그램은 컴파일 되지 않고 아래와 같은 컴파일 에러가 발생함. 
#if !defined COUNT
#error "COUNT MACRO is not defiend!"
#endif

int main(void)
{
	printf("COUNT : %d \n", COUNT);

	return 1;
}