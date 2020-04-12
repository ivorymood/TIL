#include <iostream>
#include <string>

using namespace std;

int main()
{						//0123456789012345678901234567
	string backhap_war = "백합벌 전투 : aaaa부여창aaaa";

	int rtn = backhap_war.find("부여창");

	if (rtn > 0)
	{
		cout << "문자열을 찾았습니다. 위치는 " << rtn << "입니다. " << endl;
	}
	else
	{
		cout << "문자열을 찾을 수 없습니다" << endl;
	}

	return 0;
}