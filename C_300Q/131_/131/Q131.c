#include <stdio.h>

void my_print(char **ppanimal);

void main(void)
{
	char* animal[3];

	animal[0] = "호랑이";
	animal[1] = "호양이";
	animal[2] = "홍아지";

	my_print(animal);
}

void my_print(char** ppanimal)
{
	puts(ppanimal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);
}