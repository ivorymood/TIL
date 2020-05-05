#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>

using namespace std;

class String
{
	char str[100];
public:
	String(const char* s)
	{
		strcpy(str, s);
	}
	operator const char* () const
	{
		return str;
	}
};

int main()
{
	String s("Hello!");
	const char* sz = s;

	cout << sz << endl;

	return 0;
}