#include <iostream>
#include <string>
#include <vector>

using namespace std;

int PointerFunc(vector<string> *info)
{
	if (info->empty() == true)
	{
		return 0;
	}

	return sizeof(info);
}

int main()
{
	vector<string> message;
	message.push_back("A after");
	message.push_back("B afteer");
	message.push_back("C afteeer");
	message.push_back("D afteeeer");
	message.push_back("E afteeeeer");

	cout << "포인터 인자 크기 : " << PointerFunc(&message) << endl;
	cout << "원래 변수 크기 : " << sizeof(message) << endl;

	return 0;
}