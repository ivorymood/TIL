#include <stdio.h>

void main()
{
	char cValue = 'a';
	int iValue = 1234567;
	long lValue = 7890123;
	float fValue = 3.141592f;
	double dValue = 3.141592;
	char* string = "korea";
	char buffer[100];

	sprintf_s(buffer, 100, "char 형은 %c", cValue);
	puts(buffer);

	sprintf_s(buffer, 100, "int 형은 %d", iValue);
	puts(buffer);

	sprintf_s(buffer, 100, "long 형은 %ld", lValue);
	puts(buffer);

	sprintf_s(buffer, 100, "float 형은 %f", fValue);
	puts(buffer);

	sprintf_s(buffer, 100, "double 형은 %e", dValue);
	puts(buffer);

	sprintf_s(buffer, 100, "char* 형은 %s", string);
	puts(buffer);

}