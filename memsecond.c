#include "stdio.h"

void go_south_east(int *lat, int *lon)
{
	*lat = *lat - 1;
	*lon = *lon + 1;
}

void fortune_cookie(char msg[])
{
	printf("%s\n", msg);
	printf("%i\n", sizeof(msg));
}

int main()
{
	/* code */
	int latitude = 32;
	int longitude = -64;

	go_south_east(&latitude, &longitude);
	printf("And coordinates is [%i, %i]\n", latitude, longitude);

	char quote[] = "Печенье Вас полнит";

	fortune_cookie(quote);

	printf("msg at addess %p\n", quote);

	return 0;
}