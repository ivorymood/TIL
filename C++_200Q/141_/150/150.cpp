#include "pch.h"
#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
	tuple<int, string> data1(1, "def");
	tuple<int, string> data2(1, "abc");

	if (data1 > data2)
	{
		cout << "data1 > data2" << endl;
	}
	else
	{
		cout << "data1 < data2" << endl;
	}

	tuple<double, string> data3(1.0, "def");
	tuple<double, string, int> data4(2.0, "abc", 3);

	// 에러 발생: 튜플 크기가 다르기 때문에 비교할 수 없음
	/*
	if (data3 == data4)
	{
		cout << "data3 == data4" << endl;
	}
	else
	{
		cout << " X " << endl;
	}
	*/

	return 0;
}