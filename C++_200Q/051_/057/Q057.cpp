#include <iostream>
#include <string>

using namespace std;

int main()
{
	string king = "���� ����";
	string favorite1 = "���";
	string favorite2 = "�߱�";

	string king_info = "";

	king_info += king;
	king_info += "�� ";
	king_info += favorite1;
	king_info.append("�� ");
	king_info.append(favorite2);
	king_info.append("�� �����߽��ϴ�. ");

	king_info.append("ABC", 2);
	king_info.append("DEF", 1, 2);

	king_info.insert(2, "GHI", 2);
	king_info.insert(0, "JKL", 1, 2);

	cout << king_info << endl;

	return 0;
}