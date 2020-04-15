#include <iostream>
#include <string>

using namespace std;

class GoodKing;
class BadKing;

class Info
{
	friend class GoodKing;

public:
	Info() {};

private:
	string achieve;
};

class GoodKing : Info
{
public:
	GoodKing() { achieve = "���� ���� ���� ���ʰ��"; };

	void DisPlay()
	{
		cout << achieve << endl;
	}
};

class BadKing : public Info
{
public:
	BadKing() {};

	void DisPlay()
	{
		// private ���� ���� ���� ����
		//cout << achieve << endl;
	}
};

int main()
{
	GoodKing king1;
	king1.DisPlay();

	BadKing king2;
	king2.DisPlay();

	return 0;
}