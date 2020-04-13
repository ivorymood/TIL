#include <iostream>

using namespace std;

enum Status
{
	normal = 0,
	abnormal,
	disconnet = 100,
	close
};

enum class MachineStatus : char
{
	normal = 'n',
	abnormal,
	disconnet = 100,
	close
};

int main()
{
	MachineStatus machine = MachineStatus::abnormal;

	if (machine == MachineStatus::normal)
	{
		cout << "Status : normal" << endl;
	}
	else if (machine == MachineStatus::abnormal)
	{
		cout << "Status : abnormal" << endl;
	}
	else if (machine == MachineStatus::disconnet)
	{
		cout << "Status : disconnet" << endl;
	}
	else
	{
		cout << "Status : close" << endl;
	}

	cout << "machine : " << static_cast<int>(machine) << ", " << static_cast<char>(machine) << endl;

	return 0;
}