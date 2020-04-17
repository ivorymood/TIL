#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> data = { 8, 27, 35, 49 };

	bool is_small = none_of(data.begin(), data.end(), [](int i) {return i > 100; });

	bool is_zero = none_of(data.begin(), data.end(), [](int i) {return i == 0; });

	if (is_small && is_zero)
	{
		cout << "data 자료는 모두 100보다 작고 0이 아닙니다" << endl;
	}

	return 0;
}