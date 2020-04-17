#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	regex re1(R"(\d+)");
	string str1("1234");
	string str3("1234d");

	bool is_match1 = regex_match(str1, re1);
	bool is_match2 = regex_match(str3, re1);

	cout << boolalpha;
	cout << "is_match1 = " << is_match1 << endl;
	cout << "is_match2 = " << is_match2 << endl;

	regex re2(R"(\d)");
	string str2 = "ab 123456 cd ef";

	smatch match_info;
	regex_search(str2, match_info, re2);

	cout << "number : " << match_info.str() << endl;

	return 0;
}