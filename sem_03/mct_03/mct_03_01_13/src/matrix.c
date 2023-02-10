#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int size_input(size_t *rows, size_t *columns)
{
	int tmp;

	printf("Введите размер: ");

	if (scanf("%d", &tmp) != 1)
		return EXIT_FAILURE;

	if (tmp <= 0)
		return EXIT_FAILURE;

	*rows = tmp;

	if (scanf("%d", &tmp) != 1)
		return EXIT_FAILURE;

	if (tmp <= 0)
		return EXIT_FAILURE;

	*columns = tmp;

	return EXIT_SUCCESS;
}

int input(matrix_t *matrix)
{
	printf("Введите матрицу:\n");

	if (!matrix->rows || !matrix->columns)
		return EXIT_FAILURE;

	for (size_t i = 0; i < matrix->rows; i++)
		for (size_t j = 0; j < matrix->columns; j++)
			if (scanf("%d", &(matrix->matrix[i][j])) != 1)
				return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

void output(matrix_t matrix)
{
	for (size_t i = 0; i < matrix.rows; i++)
	{
		for (size_t j = 0; j < matrix.columns; j++)
			printf("%d ", matrix.matrix[i][j]);
		printf("\n");
	}
}

void free_memory(matrix_t *matrix)
{
	for (size_t i = 0; i < matrix->rows; i++)
		free(matrix->matrix[i]);

	free(matrix->matrix);
}

matrix_t create(size_t rows, size_t columns)
{
	matrix_t tmp = { .matrix = NULL, .rows = rows, .columns = columns };

	if (!rows || !columns)
		return tmp;

	tmp.matrix = calloc(rows, sizeof(int*));

	if (!tmp.matrix)
		return tmp;

	for (size_t i = 0; i < rows; i++)
	{
		tmp.matrix[i] = malloc(columns * sizeof(int));

		if (!tmp.matrix[i])
		{
			free_memory(&tmp);
			tmp.matrix = NULL;
			return tmp;
		}
	}

	return tmp;
}

int input_array(matrix_t *array, size_t n)
{
	size_t tmp_r, tmp_c;

	for (size_t i = 0; i < n; i++)
	{
		if (size_input(&tmp_r, &tmp_c))
		{
			for (size_t j = 0; j < i; j++)
				free_memory(&(array[j*2]));

			free(array);
			return EXIT_FAILURE;
		}

		array[i*2] = create(tmp_r, tmp_c);

		if (input(&(array[i*2])))
		{
			for (size_t j = 0; j <= i; j++)
				free_memory(&(array[j*2]));

			free(array);
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

void copy_matrix(matrix_t src, matrix_t *dst)
{
	for (size_t i = 0; i < src.rows; i++)
		for (size_t j = 0; j < src.columns; j++)
			dst->matrix[i][j] = src.matrix[i][j];
}

size_t find_column_min(matrix_t matrix)
{
	int min = matrix.matrix[0][0];
	size_t column_min = 0;

	for (size_t i = 0; i < matrix.rows; i++)
		for (size_t j = 0; j < matrix.columns; j++)
			if (matrix.matrix[i][j] < min)
			{
				min = matrix.matrix[i][j];
				column_min = j;
			}

	return column_min;
}

size_t find_column_max(matrix_t matrix)
{
	int max = matrix.matrix[0][0];
	size_t column_max = 0;

	for (size_t i = 0; i < matrix.rows; i++)
		for (size_t j = 0; j < matrix.columns; j++)
			if (matrix.matrix[i][j] > max)
			{
				max = matrix.matrix[i][j];
				column_max = j;
			}

	return column_max;
}

void swap_columns(matrix_t matrix, size_t column1, size_t column2)
{
	for (size_t i = 0; i < matrix.rows; i++)
	{
		int tmp = matrix.matrix[i][column1];
		matrix.matrix[i][column1] = matrix.matrix[i][column2];
		matrix.matrix[i][column2] = tmp;
	}
}

void make_array(matrix_t *array, size_t n)
{
	matrix_t tmp;
	size_t min, max;

	for (size_t i = 0; i < n; i++)
	{
		tmp = create(array[i*2].rows, array[i*2].columns);
		copy_matrix(array[i*2], &tmp);

		min = find_column_min(tmp);
		max = find_column_max(tmp);
		if (min != max)
			swap_columns(tmp, min, max);

		array[i*2 + 1] = tmp;
	}
}