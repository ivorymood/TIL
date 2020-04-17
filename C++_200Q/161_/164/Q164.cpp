#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	bitset<4> data1(6);
	bitset<4> data2(0x09);

	cout << "data1 = " << data1 << endl;
	cout << "data2 = " << data2 << endl;

	auto result = data1 | data2;
	cout << "data1 | data2 = " << result << endl;

	result = data1 & data2;
	cout << "data1 & data2 = " << result << endl;

	result = data1 ^ data2;
	cout << "data1 ^ data2 = " << result << endl;

	result = data1 << 1;
	cout << "data1 << 1 = " << result << endl;

	result = data1 >> 1;
	cout << "data1 >> 1 = " << result << endl;

	result = ~data1;
	cout << "~data1 = " << result << endl;

	return 0;
}