#include <stdio.h>

// ���α׷��� ������ ���� �ʰ� �Ʒ��� ���� ������ ������ �߻���. 
#if !defined COUNT
#error "COUNT MACRO is not defiend!"
#endif

int main(void)
{
	printf("COUNT : %d \n", COUNT);

	return 1;
}