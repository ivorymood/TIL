#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> data1;
	list<int> data2{ 3, 4, 5 };

	data1.push_back(2);
	data1.push_back(7);

	data1.merge(data2);

	cout << "== List Merge ==" << endl;
	for (list<int>::iterator it = data1.begin(); it != data1.end(); ++it)
	{
		cout << ' ' << *it;
	}
	cout << endl;

	data2 = { 3, 4, 5 };
	data1.splice(data1.begin(), data2);

	cout << "== List Splice ==" << endl;
	for (auto it = data1.begin(); it != data1.end(); ++it)
	{
		cout << ' ' << *it;
	}


	return 0;
}