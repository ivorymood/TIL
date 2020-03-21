#include <stdio.h>
#include <string.h>

void print1(int (*X)(const char*));
void print2(int (*X[2])(const char*));

void main(void)
{
	int (*myfunc[2])(const char*);

	myfunc[0] = puts;
	myfunc[1] = strlen;

	print1(myfunc[0]);
	print2(myfunc);
}

void print1(int (*X)(const char*))
{
	X("ø√√¨¿Ã∞° æ¶ ~~");
}

void print2(int (*X[2])(const char*))
{
	X[0]("øÔ√¨¿Ã∞° æ¶ ~~");
	printf("πÆ¿⁄ø≠¿« ±Ê¿Ã : %d \n", X[1]("aa"));
}