#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int y = 20;
	double a = 12.2;
	double b = 5.6;

	cout << boolalpha;
	cout << isgreater(20, 11) << endl;
	cout << isgreater(x, y) << endl;
	cout << isgreater(a, b) << endl;
	cout << isgreater(x, b) << endl;

	return 0;
}