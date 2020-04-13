#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string sentence = "i like coding";
	
	// algorithm | remove함수 : 컨테이너에서 3번째 인수를 제거한 후, 
	//							새로 정렬된 컨테이너의 마지막 이후 iterator를 반환.
	sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());

	cout << sentence << endl;

	return 0;
}