#include <iostream>

using namespace std;

class Rent
{
public:
	void Payment() { cout << "�Ӵ�Ḧ �޽��ϴ�. " << endl; }
};

class Landlad : public Rent
{
public:
	void GetMoney()
	{
		cout << "�ǹ��ֶ� ";
		Payment();
	}
};

int main()
{
	Landlad master;
	master.GetMoney();

	return 0;
}