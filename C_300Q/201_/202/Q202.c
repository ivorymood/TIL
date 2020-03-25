#include <stdio.h>

int main(void)
{
	int i;
	char* pi;
	char* string = "books";

	// ����, ������
	printf("[%c] \n", 'A');
	printf("[%d] \n", 7);
	printf("[%i] \n", 7);
	printf("[%5d] \n", 7);
	printf("[%05d] \n", 7);
	printf("[%+d] \n", -12345);
	printf("[%+d] \n", 12345);
	printf("[% d] \n", -12345);
	printf("[%u] \n", 12345);
	printf("[%u] \n", -12345);

	// 8����, 16����
	printf("[%x] \n", 0xFF);
	printf("[%X] \n", 0xFF);
	printf("[%#x] \n", 0xFF);
	printf("[%#x] \n", 12345);
	printf("[%o] \n", 0123);
	printf("[%#o] \n", 0123);

	// �����Ҽ���
	printf("[%f] \n", 3.141592);
	printf("[%5f] \n", 3.141592);
	printf("[%.f] \n", 3.141592);
	printf("[%.2f] \n", 3.141592);
	printf("[%2.2f] \n", 3.141592);
	printf("[%5.5f] \n", 3.141592);
	printf("[%20.5f] \n", 3.141592);
	printf("[%-20.5f] \n", 3.141592);

	// �ε��Ҽ���
	printf("[%e] \n", 3.141592);
	printf("[%E] \n", 3.141592);
	printf("[%5e] \n", 3.141592);
	printf("[%.e] \n", 3.141592);
	printf("[%.2e] \n", 3.141592);
	printf("[%2.2e] \n", 3.141592);
	printf("[%5.5e] \n", 3.141592);
	printf("[%20.5e] \n", 3.141592);
	printf("[%20.5E] \n", 1.2e+10);
	printf("[%-20.2E] \n", 1.2e+10);

	// ����Ʈ��
	printf("[%g] \n", 3.141592);

	// ���ڿ���
	printf("[%s] \n", string);
	printf("[%10s] \n", string);
	printf("[%-10s] \n", string);
	printf("[%2s] \n", string);
	printf("[%2.2s] \n", string);
	printf("[%3.2s] \n", string);
	printf("[%010s] \n", string);

	// ����Ʈ��
	printf("[%p] \n", &i);
	printf("[%p] \n", &pi);

	return 0;
}