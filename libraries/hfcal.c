#include <stdio.h>
#include "hfcal.h"

void display_calories(float weight, float distance, float coeff)
{
	printf("Вес: %3.2f кг\n", weight);
	printf("Расстояние: %3.2f\n", distance);
	printf("Сожжено: %4.2f калл\n", coeff * weight * distance);
}