#include "stdio.h"
#include "string.h"

char tracks[][80] ={"Моя бабушка курит трубку", "Постой, паровоз", "Пистолетное мясо"};

void find_track(char search_for[])
{
	int i;
	for (i = 0; i < 3; ++i)
	{
		if (strstr(tracks[i], search_for))
			printf("Песня номер %i: '%s'\n", i, tracks[i]);
	}
}

void print_reverse(char *s)
{
	size_t len = strlen(s);
	char *t = s + len - 1;
	while(t >= s){
		printf("%c", *t);
		t = t - 1;
	}
	puts("");
}

int main()
{
	char search_for[80];
	printf("искать: ");
	fgets(search_for, 80, stdin);
	search_for[strlen(search_for)-1] = '\0';
	find_track(search_for);
	printf("%s\n", search_for);
	print_reverse(search_for);
	return 0;
}