#include <stdio.h>

void main(void)
{
	char* animal[3];
	char** ppanimal;

	animal[0] = "ȣ����";
	animal[1] = "ȣ����";
	animal[2] = "ȫ����";

	ppanimal = animal;

	puts(animal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);
}