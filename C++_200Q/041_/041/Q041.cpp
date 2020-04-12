#include <iostream>

using namespace std;

int  main()
{
	int n1 = 0;
	int n2 = 0;
	int s = 0;

	for (int i = 1; i < 10; ++i)
	{
		n1 = 0;
		s = 1;

		for (int j = 1; j <= i; ++j)
		{
			cout << s << ", ";

			n2 = s;
			s += n1;
			n1 = n2;
		}

		cout << endl;
	}

	return 0;
}