#include <iostream>

using namespace std;

// 전역 변수는 지양하는 것이 좋다
extern int g_number = 100;

int Func1()
{
	return g_number++;
}

int Func2()
{
	return g_number++;
}

int main()
{
	int number = g_number++;

	cout << "메인 함수 number : " << number << endl;
	cout << "Func1 함수 number : " << Func1() << endl;
	cout << "Func2 함수 number : " << Func2() << endl;

	return 0;
}