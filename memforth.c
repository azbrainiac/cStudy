#include "stdio.h"

int main()
{
	/* code */
	char name[20];
	char surname[20];
	int age;
	printf("Введите имя и фамилию и возраст: ");
	scanf("%19s %19s %i", name, surname, &age);
	printf("Имя: %s, Фамилия: %s Возраст: %i\n", name, surname, age);
	

	char food[6];
	printf("Введите еду: ");
	fgets(	food, 6, stdin);
	printf("Имя: %s\n", food);

	return 0;
}