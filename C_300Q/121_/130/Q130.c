#include <stdio.h>

void main(void)
{
	char* animal[3];
	char** ppanimal;

	animal[0] = "호랑이";
	animal[1] = "호양이";
	animal[2] = "홍아지";

	ppanimal = animal;

	puts(animal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);
}