#include <stdio.h>
#include <string.h>

int NUM_ADS = 4;

char *ADS[] = {"Уильям: любит спорт, перекусить", "Мэттью: любит кино", "Майк: любит спорт и Джастина Бибера", 
			"Джош: любит спорт, кино и театр"};

int sports_not_biber(char *s)
{
	return strstr(s, "спорт") && !strstr(s, "Бибер");
}

int kino(char *s)
{
	return strstr(s, "кино");
}

int teatr_or_food(char *s)
{
	return strstr(s, "театр") || strstr(s, "перекусить");
}


void find(int (*match_fn)(char*))
{
	int i;
	puts("Результаты поиска:");
	puts("---------------------------------");
	for(i = 0; i < NUM_ADS; i++){
		if(match_fn(ADS[i])) {
			printf("%s\n", ADS[i]);
		}
	}
	puts("---------------------------------");
} 

int main(int argc, char const *argv[])
{
	/* code */
	find(sports_not_biber);
	find(kino);
	find(teatr_or_food);
	return 0;
}