#include <iostream>
#include <string>

using namespace std;

class Kinginfo
{
public:
	void SetName(string name)
	{
		name_ = name;
	}

	string GetName() const
	{
		return name_;
	}

private:
	string name_;
};

int main()
{
	Kinginfo king_info;
	king_info.SetName("���� ���� ����");

	cout << king_info.GetName() << endl;

	return 0;
}