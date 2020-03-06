#include <stdio.h>

// 이름은? ㅇㅇㅇ
// ㅇㅇㅇ 입니다. 
int main()
{
	char str_name[512] = { 0 };

	
	printf("이름은?");
	scanf_s("%s", str_name, 512);

	printf("이름은 %s 입니다\n", str_name);

	return 0;
}