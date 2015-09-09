#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	char *my_env[] = {"JUICE=яблоко и виноград", NULL};
	execle("diner_info", "diner_info", "4", NULL, my_env);
	return 0;
}