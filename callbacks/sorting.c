#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_scores_desc(const void* score_a, const void* score_b)
{
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return b-a;
}

int compare_names(const void* name_a, const void* name_b)
{
	char** sa = (char**)name_a;
	char** sb = (char**)name_b;
	return strcmp(*sa, *sb);
}

int main(int argc, char const *argv[])
{
	int scores[] = {543, 674, 5, 8, 3, 28};
	int i;
	qsort(scores, 6, sizeof(int), compare_scores_desc);

	puts("Это упорядоченные оценки:");
	for (i = 0; i < 6; i++)	{
		printf("Оценка = %i\n", scores[i]);
	}

	char *names[] = {"Вася", "Дима", "Валя", "Александра"};

	qsort(names, 4, sizeof(char*), compare_names);
	puts("Это упорядоченные имена:");
	for (i = 0; i < 4; i++)	{
		printf("Имя = %s\n", names[i]);
	}


	return 0;
}