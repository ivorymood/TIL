#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream stream;
	//stream.open("C:\\BOOTNXT");
	stream.open("D:\\file.");

	if (stream.good() == true)
	{
		cout << "������ �����մϴ�" << endl;
	}
	else
	{
		cout << "������ �����ϴ�" << endl;
	}

	stream.close();

	return 0;
}