#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string sentence = "i like coding";
	
	// algorithm | remove�Լ� : �����̳ʿ��� 3��° �μ��� ������ ��, 
	//							���� ���ĵ� �����̳��� ������ ���� iterator�� ��ȯ.
	sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());

	cout << sentence << endl;

	return 0;
}