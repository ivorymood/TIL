#include <iostream>

using namespace std;

// ���� ������ �����ϴ� ���� ����
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

	cout << "���� �Լ� number : " << number << endl;
	cout << "Func1 �Լ� number : " << Func1() << endl;
	cout << "Func2 �Լ� number : " << Func2() << endl;

	return 0;
}