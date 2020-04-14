#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream read;

	read.open("093.txt", ifstream::in);

	char c = read.get();

	while (read.eof() == false)
	{
		cout << c;
		c = read.get();
	}

	cout << endl;

	read.close();

	return 0;
}