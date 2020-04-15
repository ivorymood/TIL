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
	GoodKing() { achieve = "백제 중흥 군주 근초고왕"; };

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
		// private 변수 접근 권한 없음
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