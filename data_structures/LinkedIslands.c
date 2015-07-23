#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
	char *name;
	char *opens;
	char *closes;
	struct island *next;
} island;

void display(island *start)
{
	island *i = start;
	for(; i != NULL; i = i->next){
		printf("Название: %s открыт: %s - %s\n", i->name, i->opens, i->closes);
	}

}

island* create(char *name)
{
	island *i = malloc(sizeof(island));
	i->name = strdup(name);
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;
	return i;

}

int main(int argc, char const *argv[])
{
	/* code */
	island amity = {"Дружбы", "09:00", "17:00", NULL };
	island craggy = {"Скалистый", "09:00", "17:00", NULL };
	island nublar = {"Туманный", "09:00", "17:00", NULL };
	island shutter = {"Проклятых", "09:00", "17:00", NULL };
	


	amity.next = &craggy;
	craggy.next = &nublar;
	nublar.next = &shutter;
	display(&amity);

	island skull = {"Черепа", "09:00", "17:00", NULL };
	nublar.next = &skull;
	skull.next = &shutter;

	display(&nublar);

	char name[80];
	fgets(name, 80, stdin);
	island *p_island0 = create(name);
	fgets(name, 80, stdin);
	island *p_island1 = create(name);
	p_island0->next = p_island1;

	display(p_island0);


	return 0;
}