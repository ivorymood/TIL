#include <iostream>

using namespace std;

class Info
{
public:
	Info()
	{
		data = new int;
		data_arr = new int[3];
	}
	~Info()
	{
		delete data;
		delete[] data_arr;
	}

	void Dispose()
	{
		delete data;
		delete[] data_arr;
	}

private:
	int* data;
	int* data_arr;
};

int main()
{
	Info* info = new Info();

	// 에러발생 : 이미 해제된 메모리를 다시 해제하려 시도하므로 
	info->Dispose();
	delete info;

	return 0;
}