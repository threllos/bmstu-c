#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

#define ERROR_INPUT 100

int main(void)
{
	setbuf(stdout, NULL);

	matrix_t *array;
	size_t n;

	printf("Введите N: ");
	if (scanf("%zu", &n) != 1)
		return ERROR_INPUT;

	array = calloc(n * 2, sizeof(matrix_t));

	if (!array)
		return ERROR_INPUT;

	if (input_array(array, n))
		return ERROR_INPUT;

	make_array(array, n);

	printf("\n");
	for (size_t i = 0; i < n; i++)
	{
		printf("Матрица %zu\n", i + 1);
		output(array[i * 2]);
		printf("Копия матрицы %zu\n", i + 1);
		output(array[i * 2 + 1]);
	}

	for (size_t j = 0; j < n * 2; j++)
		free_memory(&(array[j]));
	free(array);

	return EXIT_SUCCESS;
}