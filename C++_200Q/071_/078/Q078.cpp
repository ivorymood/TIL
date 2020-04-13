#include <iostream>

using namespace std;

int main()
{
	int number1 = 10;
	int number2 = 20;

	// 가리키는 대상 : 변경 가능
	// 가리키는 대상의 값 : 변경 불가능
	int const* ptr1 = &number1;
	ptr1 = &number2;
	//*ptr1 = number1;


	// 가리키는 대상 : 변경 불가능
	// 가리키는 대상의 값 : 변경 가능
	int* const ptr2 = &number1;
	//ptr2 = &number2;
	*ptr2 = number2;

	return 0;
}