#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "matrix.h"

int key_check(int size, char **array)
{
	if (size < 4 || size > 5)
		return EXIT_FAILURE;

	if (strcmp(array[1], "a") == 0 || strcmp(array[1], "m") == 0)
	{
		if (size != 5)
			return EXIT_FAILURE;
	}
	else if (strcmp(array[1], "o") == 0)
	{
		if (size != 4)
			return EXIT_FAILURE;
	}
	else
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

int fsize_input(FILE *f, size_t *rows, size_t *columns)
{
	int tmp;

	if (fscanf(f, "%d", &tmp) != 1)
		return EXIT_FAILURE;

	if (tmp <= 0)
		return EXIT_FAILURE;

	*rows = tmp;

	if (fscanf(f, "%d", &tmp) != 1)
		return EXIT_FAILURE;

	if (tmp <= 0)
		return EXIT_FAILURE;

	*columns = tmp;

	return EXIT_SUCCESS;
}

int finput(FILE *f, matrix_t *matrix)
{
	for (size_t i = 0; i < matrix->rows; i++)
		for (size_t j = 0; j < matrix->columns; j++)
			if (fscanf(f, "%lf", &(matrix->matrix[i][j])) != 1)
				return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

void foutput(FILE *f, matrix_t matrix)
{
	fprintf(f, "%zu %zu \n", matrix.rows, matrix.columns);

	for (size_t i = 0; i < matrix.rows; i++)
	{
		for (size_t j = 0; j < matrix.columns; j++)
			fprintf(f, "%.6lf ", matrix.matrix[i][j]);
		fprintf(f, "\n");
	}
}

void output(matrix_t matrix)
{
	printf("matrix:\n");
	
	for (size_t i = 0; i < matrix.rows; i++)
	{
		for (size_t j = 0; j < matrix.columns; j++)
			printf("%lf ", matrix.matrix[i][j]);
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

	tmp.matrix = calloc(rows, sizeof(double*));

	if (!tmp.matrix)
		return tmp;

	for (size_t i = 0; i < rows; i++)
	{
		tmp.matrix[i] = malloc(columns * sizeof(double));

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

int addition(matrix_t matrix1, matrix_t matrix2, matrix_t *result)
{
	if (size_equal(matrix1, matrix2))
		return EXIT_FAILURE;
	if (size_equal(matrix1, *result))
		return EXIT_FAILURE;

	for (size_t i = 0; i < result->rows; i++)
		for (size_t j = 0; j < result->columns; j++)
			result->matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];

	return EXIT_SUCCESS;
}

int multiplication(matrix_t matrix1, matrix_t matrix2, matrix_t *result)
{
	if (matrix1.columns != matrix2.rows)
		return EXIT_FAILURE;
	if (matrix1.rows != result->rows)
		return EXIT_FAILURE;
	if (matrix2.columns != result->columns)
		return EXIT_FAILURE;

	for (size_t i = 0; i < result->rows; i++)
		for (size_t j = 0; j < result->columns; j++)
		{
			result->matrix[i][j] = 0;

			for (size_t k = 0; k < matrix1.columns; k++)
				result->matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
		}

	return EXIT_SUCCESS;
}

void find_min_row(matrix_t matrix, size_t *min_row)
{
	*min_row = 0;
	int count;
	int max = 0;

	for (size_t i = 0; i < matrix.rows; i++)
	{
		count = 0;

		for (size_t j = 0; j < matrix.columns; j++)
			if (fabs(matrix.matrix[i][j]) < 1e-8)
				count += 1;

		if (count > max)
		{
			*min_row = i;
			max = count;
		}
	}
}

void minor_matrix(matrix_t src, matrix_t *dst, size_t row, size_t column)
{
	*dst = create(src.rows - 1, src.columns - 1);
	size_t n = 0, m = 0;

	for (size_t i = 0; i < src.rows; i++)
	{
		if (i == row)
			continue;

		for (size_t j = 0; j < src.columns; j++)
		{
			if (j == column)
				continue;

			dst->matrix[n][m] = src.matrix[i][j];

			m += 1;
		}

		m = 0;
		n += 1;
	}
}

double determinant_calc(matrix_t matrix)
{
	if (matrix.rows == 1)
		return matrix.matrix[0][0];
	else if (matrix.rows == 2)
		return matrix.matrix[0][0] * matrix.matrix[1][1] - matrix.matrix[0][1] * matrix.matrix[1][0];
	else
	{
		size_t min_row = 0;
		double result = 0;
		int degree = 1;

		//find_min_row(matrix, &min_row);

		for (size_t i = 0; i < matrix.columns; i++)
		{
			matrix_t new_matrix;
			minor_matrix(matrix, &new_matrix, min_row, i);

			result += degree * matrix.matrix[min_row][i] * determinant_calc(new_matrix);

			degree *= -1;

			free_memory(&new_matrix);
		}

		return result;
	}
}

int determinant(matrix_t matrix, double *result)
{
	if (matrix.rows != matrix.columns)
		return EXIT_FAILURE;

	*result = determinant_calc(matrix);

	return EXIT_SUCCESS;
}