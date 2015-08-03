#include <stdio.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};
typedef struct {
	char *name;
	enum response_type type;
} response;

void dump(response r)
{
	printf("Дорогой, %s,\n", r.name);
	puts("К сожалению");
	puts("Вы с ним не увидитесь");
}

void second_chance(response r)
{
	printf("Дорогой, %s,\n", r.name);
	puts("Хорошие новости");
	puts("Вы с ним увидитесь");
}

void marriage(response r)
{
	printf("Дорогой, %s,\n", r.name);
	puts("Поздравляю");
	puts("У вас будет свадьба");
}

int main(int argc, char const *argv[])
{
	response r[] = {
		{"Майк", DUMP}, {"Луис", SECOND_CHANCE}, {"Мэттью", SECOND_CHANCE}, {"Уильям", MARRIAGE}
	};

	int i;
	for (i = 0; i < 4; i++) {
		switch (r[i].type) {
			case DUMP :
				dump(r[i]);
				break;
			case SECOND_CHANCE :
				second_chance(r[i]);
				break;
			default :
				marriage(r[i]);
				break;
		}
	}

	void (*replies[])(response) = {dump, second_chance, marriage};
	for (i = 0; i < 4; i++)
	{
		(replies[r[i].type])(r[i]);
		/* code */
	}
	return 0;
}