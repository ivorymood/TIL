#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sentense = "i hate coding";
	sentense.erase(0, 7);
	cout <<"i like " << sentense << endl;

	return 0;
}