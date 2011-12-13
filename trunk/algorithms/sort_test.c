#include "sort.h"
#include <stdio.h>
#include <assert.h>

int cmp_int(void *first, void *second)
{
	return (int)first - (int)second;
}

static void quick_sort_test(void)
{
	int i = 0;
	int size = 10000;
	void **array = (void **)malloc(sizeof(void *) * size);
	for(i = 0; i < size; i++)
	{
		array[i] = (void *)rand();
		printf("o: %d\n", (int)(array[i]));
	}

	quick_sort(array, size, cmp_int);

	for(i = 0; i < size - 1; i++)
	{
		assert(cmp_int(array[i], array[i+1]) <= 0);
		printf("n: %d\n", (int)(array[i]));
	}
	printf("n: %d\n", (int)array[i]);

	free(array);
	return;
}

int main(int argc, char *argv[])
{
	printf("Start...\n");
	quick_sort_test();
	printf("Complete.\n");

	return 0;
} 
