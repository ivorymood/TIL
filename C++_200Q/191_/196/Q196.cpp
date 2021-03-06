﻿#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <iostream>
#include "json/json.h"

using namespace std;
using namespace Json;

int main()
{
	ofstream json_file;
	json_file.open("json_exam1.json");

	Value main;
	main["Job1"] = "developer";
	main["Job2"] = "author";

	Value sub1;
	sub1["Sub1"] = "Sub1";
	sub1["Sub2"] = "Sub2";
	main["SubItems"] = sub1;

	main["Sub3"] = "blogger";

	Json::StyledWriter writer;
	string str = writer.write(main);

	cout << str << endl << endl;

	json_file << writer.write(main);
	json_file.close();

	return 0;
}