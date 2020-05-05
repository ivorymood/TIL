#pragma warning(disable:4996)
#include <iostream>
#include <cstring>

using namespace std;

class String
{
	char* str;
public:
	String(const char* s)
	{
		str = new char[strlen(s) + 1];
	}
	~String()
	{
		delete[] str;
	}
	const String& operator=(const String& arg)
	{
		delete[] str;
		str = new char[strlen(arg.str) + 1];
		strcpy(str, arg.str);

		return *this;
	}
};

int main()
{
	const char* sz = "Hello!";
	String s("Hi~!");
	s = sz;

	return 0;
}