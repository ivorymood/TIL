#include <stdio.h>

void my_print(char **ppanimal);

void main(void)
{
	char* animal[3];

	animal[0] = "ȣ����";
	animal[1] = "ȣ����";
	animal[2] = "ȫ����";

	my_print(animal);
}

void my_print(char** ppanimal)
{
	puts(ppanimal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);
}