#include <iostream>

using namespace std;

class Temp {
	int no;
	bool is_on;
};

int main()
{
	cout << "char 农扁 : " << sizeof('p') << endl;
	cout << "int 农扁 : " << sizeof(10) << endl;
	cout << "double 农扁 : " << sizeof(10.0) << endl;
	cout << "class 农扁 : " << sizeof(Temp) << endl;

	return 0;
}