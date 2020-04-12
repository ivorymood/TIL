#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	time_t now = time(NULL);
	tm tm;
	localtime_s(&tm, &now);

	char buffer[128];
	strftime(buffer, sizeof(buffer), "예제 연습하는 지금은 %Y년 %m월 %d일, %H시 %M분 %S초 입니다. (%p) \n", &tm);
	cout << buffer;

	return 0;
}