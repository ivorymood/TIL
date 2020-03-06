#include <stdio.h>

int main()
{
	long long int lldData = 4294967295LL;

	printf("%d\n", lldData);
	printf("%u\n", lldData);

	printf("%u\n", lldData + 1);
	printf("%u\n", lldData + 2);
	printf("%u\n", lldData + 3);

	printf("%lld\n", lldData + 1);
	printf("%lld\n", lldData + 2);
	printf("%lld\n", lldData + 3);

	return 0;
}