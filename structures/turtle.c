#include <stdio.h>

typedef struct {
	const char *name;
	const char *species;
	int age;
} turtle;

void happy_birthday(turtle t)
{
	t.age = t.age + 1;
	printf("С днюхой, %s! Сегодня тебе %i\n", t.name, t.age);
}
void happy_birthday_sec(turtle *t)
{
	t->age = t->age + 1;
	printf("С днюхой, %s! Сегодня тебе %i\n", t->name, t->age);
}

int main()
{
	/* code */
	turtle tt = {"Тортилла", "Кожистая черепаха", 99};
	happy_birthday(tt);
	printf("%s прожила %i лет\n", tt.name, tt.age);
	happy_birthday_sec(&tt);
	printf("%s прожила %i лет\n", tt.name, tt.age);
	return 0;
}