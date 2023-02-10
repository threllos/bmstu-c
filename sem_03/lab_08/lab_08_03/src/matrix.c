#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int size_input(size_t *rows, size_t *columns)
{
	int tmp;

	// printf("input size:\n");

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

int power_input(size_t *power)
{
	int tmp;

	// printf("input power:\n");

	if (scanf("%d", &tmp) != 1)
		return EXIT_FAILURE;
	
	if (tmp < 0)
		return EXIT_FAILURE;

	*power = tmp;

	return EXIT_SUCCESS;
}

int input(matrix_t *matrix)
{
	// printf("input matrix:\n");

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
	// printf("matrix:\n");
	
	for (size_t i = 0; i < matrix.rows; i++)
	{
		for (size_t j = 0; j < matrix.columns; j++)
			printf("%d ", matrix.matrix[i][j]);
		printf("\n");
	}
}

void free_memory(matrix_t *matrix)
{
	for (size_t i = 0; i < matrix->const_rows; i++)
		free(matrix->matrix[i]);

	free(matrix->matrix);
}

matrix_t create(size_t rows, size_t columns)
{
	matrix_t tmp = { .matrix = NULL, .rows = rows, .columns = columns, 
		.const_rows = rows, .const_columns = columns };

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

int size_equal(matrix_t m1, matrix_t m2)
{
	if (m1.rows != m2.rows || m1.columns != m2.columns)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

int matrix_is_square(matrix_t matrix)
{
	if (matrix.rows != matrix.columns)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

int copy(matrix_t src, matrix_t *dst)
{
	if (size_equal(src, *dst))
		return EXIT_FAILURE;

	for (size_t i = 0; i < src.rows; i++)
		for (size_t j = 0; j < src.columns; j++)
			dst->matrix[i][j] = src.matrix[i][j];

	return EXIT_SUCCESS;
}

void max_for_columns(matrix_t matrix, size_t *row_max, size_t *column_max)
{
	int max = matrix.matrix[0][0];
	*row_max = 0;
	*column_max = 0;

	for (size_t i = 0; i < matrix.columns; i++)
		for (size_t j = 0; j < matrix.rows; j++)
			if (matrix.matrix[j][i] > max)
			{
				max = matrix.matrix[j][i];
				*row_max = j;
				*column_max = i;
			}
}

void swap_rows(matrix_t *matrix, size_t row1, size_t row2)
{
	int *tmp = matrix->matrix[row1];

	for (size_t i = row1; i < row2; i++)
		matrix->matrix[i] = matrix->matrix[i + 1];

	matrix->matrix[row2] = tmp;
}

void swap_columns(matrix_t *matrix, size_t column1, size_t column2)
{
	int tmp;

	for (size_t i = 0; i < matrix->rows; i++)
	{
		tmp = matrix->matrix[i][column1];

		for (size_t j = column1; j < column2; j++)
			matrix->matrix[i][j] = matrix->matrix[i][j + 1];

		matrix->matrix[i][column2] = tmp;
	}
}

void make_square(matrix_t *matrix)
{
	size_t row_max;
	size_t column_max;

	while (matrix->rows != matrix->columns)
	{
		max_for_columns(*matrix, &row_max, &column_max);
		if (matrix->rows > matrix->columns)
		{
			swap_rows(matrix, row_max, matrix->rows - 1);
			matrix->rows -= 1;
		}
		else
		{
			swap_columns(matrix, column_max, matrix->columns - 1);
			matrix->columns -= 1;
		}
	}
}

int arithmetic_mean(matrix_t matrix, size_t size, size_t column)
{
	size_t i;
	int sum = 0;

	for (i = 0; i < size; i++)
		sum += matrix.matrix[i][column];

	return sum / i;
}

int max(matrix_t matrix, size_t size, size_t row)
{
	int max = matrix.matrix[row][0];

	for (size_t i = 0; i < size; i++)
		if (matrix.matrix[row][i] > max)
			max = matrix.matrix[row][i];

	return max;
}

void fill(matrix_t src, matrix_t *dst)
{
	for (size_t i = 0; i < src.rows; i++)
		for (size_t j = 0; j < src.columns; j++)
			dst->matrix[i][j] = src.matrix[i][j];

	for (size_t i = src.rows; i < dst->rows; i++)
		for (size_t j = 0; j < src.columns; j++)
			dst->matrix[i][j] = arithmetic_mean(*dst, i, j);

	for (size_t i = 0; i < dst->rows; i++)
		for (size_t j = src.columns; j < dst->columns; j++)
			dst->matrix[i][j] = max(*dst, j, i);
}

void reset(matrix_t *matrix)
{
	for (size_t i = 0; i < matrix->rows; i++)
		for (size_t j = 0; j < matrix->columns; j++)
		{
			if (i == j)
				matrix->matrix[i][j] = 1;
			else
				matrix->matrix[i][j] = 0;
		}
}

int multiplication(matrix_t matrix1, matrix_t matrix2, matrix_t *result)
{
	if (size_equal(matrix1, matrix2))
		return EXIT_FAILURE;
	if (size_equal(matrix1, *result))
		return EXIT_FAILURE;
	if (matrix_is_square(matrix1))
		return EXIT_FAILURE;
	if (matrix_is_square(matrix2))
		return EXIT_FAILURE;
	if (matrix_is_square(*result))
		return EXIT_FAILURE;

	for (size_t i = 0; i < matrix1.rows; i++)
		for (size_t j = 0; j < matrix2.columns; j++)
		{
			result->matrix[i][j] = 0;
			for (size_t k = 0; k < result->rows; k++)
				result->matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
		}

	return EXIT_SUCCESS;
}

int power(matrix_t src, matrix_t *dst, size_t power)
{
	if (power == 0)
	{
		reset(dst);
		return EXIT_SUCCESS;
	}
	else if (power == 1)
	{
		if (copy(src, dst))
			return EXIT_FAILURE;
		return EXIT_SUCCESS;
	}

	matrix_t tmp;

	tmp = create(src.rows, src.columns);
	if (!tmp.matrix)
		return EXIT_FAILURE;

	if (copy(src, &tmp))
	{
		free_memory(&tmp);
		return EXIT_FAILURE;
	}

	for (size_t i = 0; i < power - 1; i++)
	{
		if (multiplication(src, tmp, dst))
		{
			free_memory(&tmp);
			return EXIT_FAILURE;
		}


		if (copy(*dst, &tmp))
		{
			free_memory(&tmp);
			return EXIT_FAILURE;
		}
	}

	free_memory(&tmp);

	return EXIT_SUCCESS;
}
