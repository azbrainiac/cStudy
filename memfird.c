#include "stdio.h"

void skip(char *msg)
{
	puts(msg + 3);
}

int main()
{
	int drinks[] = {4, 2, 3};

	printf("%i\n", drinks[0]);
	printf("%i\n", *drinks);

	printf("%i\n", *(drinks+2));

	char *m = "Не звони";
	skip(m);

	printf("%i\n", *m);
	/*printf("%p\n", m);
	printf("%p\n", &m);*/

	printf("%p\n", drinks);
	printf("%p\n", drinks + 1);
}