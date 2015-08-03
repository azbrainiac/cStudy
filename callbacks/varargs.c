#include <stdio.h>
#include <stdarg.h>

void print_ints(int args, ...)
{
	va_list ap;
	va_start(ap, args);
	int i;
	for (i = 0; i < args; i++)
	{
		printf("аргумент %i\n", va_arg(ap, int) );
	}
	va_end(ap);
}

int main(int argc, char const *argv[])
{
	print_ints(2, 7, -4);
	print_ints(4, 2, 6, 1032, -93);
	return 0;
}