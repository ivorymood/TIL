#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sentense = "i coding";
	sentense.insert(2, "hate ");
	cout << sentense << endl;

	sentense.insert(7, "or like ");
	cout << sentense << endl;

	return 0;
}