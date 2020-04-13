#include <iostream>

using namespace std;

enum Status
{
	normal = 0,
	abnormal,
	disconnet = 100,
	close
};

int main()
{
	Status number = close;

	if (number == Status::normal)
	{
		cout << "Status : normal" << endl;
	}
	else if (number == abnormal)
	{
		cout << "Status : abnormal" << endl;
	}
	else if (number == 100)
	{
		cout << "Status : disconnet" << endl;
	}
	else
	{
		cout << "Status : close" << endl;
	}

	return 0;
}