#include <iostream>
#include <string>

using namespace std;

int main()
{						//0123456789012345678901234567
	string backhap_war = "���չ� ���� : aaaa�ο�âaaaa";

	int rtn = backhap_war.find("�ο�â");

	if (rtn > 0)
	{
		cout << "���ڿ��� ã�ҽ��ϴ�. ��ġ�� " << rtn << "�Դϴ�. " << endl;
	}
	else
	{
		cout << "���ڿ��� ã�� �� �����ϴ�" << endl;
	}

	return 0;
}