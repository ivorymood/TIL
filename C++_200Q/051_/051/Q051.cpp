#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	time_t now = time(NULL);
	tm tm;
	localtime_s(&tm, &now);

	char buffer[128];
	strftime(buffer, sizeof(buffer), "���� �����ϴ� ������ %Y�� %m�� %d��, %H�� %M�� %S�� �Դϴ�. (%p) \n", &tm);
	cout << buffer;

	return 0;
}