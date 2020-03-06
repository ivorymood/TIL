#include <stdio.h>
void MyStrcpy(char* szBufferDst, int size, char* szBufferSrc);

int main(int argc, char* argv[])
{
	char szBufferSrc[12] = { "TestString" };
	char szBufferDst[12] = { 0 };

	MyStrcpy(szBufferDst, sizeof(szBufferDst), szBufferSrc);
	puts(szBufferDst);

	return 0;
}

void MyStrcpy(char* szBufferDst, int size, char* szBufferSrc) 
{
	//strcpy()와 같도록
	
	for (int i = 0; i < size; i++)
	{
		*(szBufferDst + i) = *(szBufferSrc + i);
	}
}