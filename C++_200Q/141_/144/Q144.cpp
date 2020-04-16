#include <iostream>

using namespace std;

constexpr int Getnumber1()
{
	return 2;
}

constexpr int GetNumber2(int x, int y)
{
	return x + y;	
}

int main()
{
	int array1[Getnumber1()];
	int array2[GetNumber2(1, 2)];

	cout << sizeof(array1) << ", " << sizeof(array2) << endl;

	return 0;
}