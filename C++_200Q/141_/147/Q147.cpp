#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
	typedef tuple<string, int, double> Data;

	Data data1("¹®ÀÚ¿­", 10, 1.2);

	string my_str = "";
	int my_int = 0;

	tie(my_str, my_int, ignore) = data1;

	cout << my_str << ", " << my_int << endl;
	cout << get<0>(data1) << ", " << get<1>(data1) << ", " << get<2>(data1) << endl;

	return 0;
}