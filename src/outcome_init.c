#include "my.h"

int lte(int a, int b) {
	return (a <= b);
}

int gte(int a, int b) {
	return (a >= b);
}

void init_cond(int(**comp)(int, int), int *inc1, int a, int b)
{
	if (a < b)
	{
		*comp = lte;
		*inc1 = 1;
	}
	else
	{
		*comp = gte;
		*inc1 = -1;
	}
}
