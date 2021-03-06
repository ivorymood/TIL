﻿#pragma warning(disable:4996)
#include <fstream>
#include <iostream>
#include "json/json.h"

using namespace std;
using namespace Json;

int main()
{
	ofstream json_write;
	json_write.open("test.json");

	Value root;
	root["Title"] = "Array Exam";
	root["ZTest"] = "testtest";

	Value array1;
	array1.append("C#");
	array1.append("C++");

	Value array2;
	array2.append("Q#");
	array2.append("Qt");

	root["Language"]["Sample1"] = array1;
	root["Language"]["Sample2"] = array2;

	json_write << root;
	json_write.close();

	ifstream json_open("test.json");
	Reader reader;
	Value value;
	reader.parse(json_open, value);

	cout << value << endl << endl;

	for (auto i : value["Language"]["Sample1"])
	{
		cout << "Language Sample1 : " << i << endl;
	}

	return 0;
}