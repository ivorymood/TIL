/*
	��ǥ��. 
	for each �� ����ũ�μ���Ʈ Visual C++������ ��밡��. 
	�����̳ʸ� ����� �� ����. 
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