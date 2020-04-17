/*
	비표준. 
	for each 는 마이크로소프트 Visual C++에서만 사용가능. 
	컨테이너를 사용할 수 없다. 
*/
#include <iostream>

using namespace std;

int main()
{
	int data[] = { 10, 20, 30, 40 };

	for each (int& i in data)
	{
		i += 10;
	}

	for each (const int i in data1)
	{
		cout << i << ", ";
	}

	cout << endl;

	return 0;
}