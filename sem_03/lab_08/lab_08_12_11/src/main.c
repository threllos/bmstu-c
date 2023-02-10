#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"

#define ERROR_KEY 100
#define ERROR_OPEN_FILE 200
#define ERROR_INPUT_FILE 201
#define ERROR_CREATE_MATRIX 300
#define ERROR_ADDITION 400
#define ERROR_MULTIPLICATION 401

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);

	if (key_check(argc, argv))
		return ERROR_KEY;

	if (strcmp(argv[1], "a") == 0)
	{
		FILE *f_matrix1, *f_matrix2;
		FILE *f_result;
		matrix_t matrix1, matrix2;
		matrix_t result;
		size_t tmp_rows, tmp_columns;

		f_matrix1 = fopen(argv[2], "r");
		if (!f_matrix1)
			return ERROR_OPEN_FILE;

		if (fsize_input(f_matrix1, &tmp_rows, &tmp_columns))
		{
			fclose(f_matrix1);
			return ERROR_INPUT_FILE;
		}

		matrix1 = create(tmp_rows, tmp_columns);
		if (!matrix1.matrix)
		{
			fclose(f_matrix1);
			return ERROR_CREATE_MATRIX;
		}

		if (finput(f_matrix1, &matrix1))
		{
			free_memory(&matrix1);
			fclose(f_matrix1);
			return ERROR_INPUT_FILE;
		}

		fclose(f_matrix1);

		f_matrix2 = fopen(argv[3], "r");
		if (!f_matrix2)
		{
			free_memory(&matrix1);
			return ERROR_OPEN_FILE;
		}

		if (fsize_input(f_matrix2, &tmp_rows, &tmp_columns))
		{
			free_memory(&matrix1);
			fclose(f_matrix2);
			return ERROR_INPUT_FILE;
		}

		matrix2 = create(tmp_rows, tmp_columns);
		if (!matrix2.matrix)
		{
			free_memory(&matrix1);
			fclose(f_matrix2);
			return ERROR_CREATE_MATRIX;
		}

		if (finput(f_matrix2, &matrix2))
		{
			free_memory(&matrix1);
			free_memory(&matrix2);
			fclose(f_matrix2);
			return ERROR_INPUT_FILE;
		}

		fclose(f_matrix2);

		result = create(tmp_rows, tmp_columns);
		if (!result.matrix)
		{
			free_memory(&matrix1);
			free_memory(&matrix2);
			return ERROR_CREATE_MATRIX;
		}

		if (addition(matrix1, matrix2, &result))
		{
			free_memory(&matrix1);
			free_memory(&matrix2);
			free_memory(&result);
			return ERROR_ADDITION;
		}

		free_memory(&matrix1);
		free_memory(&matrix2);

		f_result = fopen(argv[4], "w");
		if (!f_result)
		{
			free_memory(&result);
			return ERROR_OPEN_FILE;
		}

		foutput(f_result, result);

		free_memory(&result);
		fclose(f_result);
	} 
	else if (strcmp(argv[1], "m") == 0)
	{
		FILE *f_matrix1, *f_matrix2;
		FILE *f_result;
		matrix_t matrix1, matrix2;
		matrix_t result;
		size_t tmp_rows, tmp_columns;

		f_matrix1 = fopen(argv[2], "r");
		if (!f_matrix1)
			return ERROR_OPEN_FILE;

		if (fsize_input(f_matrix1, &tmp_rows, &tmp_columns))
		{
			fclose(f_matrix1);
			return ERROR_INPUT_FILE;
		}

		matrix1 = create(tmp_rows, tmp_columns);
		if (!matrix1.matrix)
		{
			fclose(f_matrix1);
			return ERROR_CREATE_MATRIX;
		}

		if (finput(f_matrix1, &matrix1))
		{
			free_memory(&matrix1);
			fclose(f_matrix1);
			return ERROR_INPUT_FILE;
		}

		fclose(f_matrix1);

		f_matrix2 = fopen(argv[3], "r");
		if (!f_matrix2)
		{
			free_memory(&matrix1);
			return ERROR_OPEN_FILE;
		}

		if (fsize_input(f_matrix2, &tmp_rows, &tmp_columns))
		{
			free_memory(&matrix1);
			fclose(f_matrix2);
			return ERROR_INPUT_FILE;
		}

		matrix2 = create(tmp_rows, tmp_columns);
		if (!matrix2.matrix)
		{
			free_memory(&matrix1);
			fclose(f_matrix2);
			return ERROR_CREATE_MATRIX;
		}

		if (finput(f_matrix2, &matrix2))
		{
			free_memory(&matrix1);
			free_memory(&matrix2);
			fclose(f_matrix2);
			return ERROR_INPUT_FILE;
		}

		fclose(f_matrix2);

		result = create(matrix1.rows, matrix2.columns);
		if (!result.matrix)
		{
			free_memory(&matrix1);
			free_memory(&matrix2);
			return ERROR_CREATE_MATRIX;
		}

		if (multiplication(matrix1, matrix2, &result))
		{
			free_memory(&matrix1);
			free_memory(&matrix2);
			free_memory(&result);
			return ERROR_MULTIPLICATION;
		}

		free_memory(&matrix1);
		free_memory(&matrix2);

		f_result = fopen(argv[4], "w");
		if (!f_result)
		{
			free_memory(&result);
			return ERROR_OPEN_FILE;
		}

		foutput(f_result, result);

		free_memory(&result);
		fclose(f_result);
	}
	else if (strcmp(argv[1], "o") == 0)
	{
		FILE *f_matrix;
		FILE *f_result;
		matrix_t matrix;
		double result;
		size_t tmp_rows, tmp_columns;

		f_matrix = fopen(argv[2], "r");
		if (!f_matrix)
			return ERROR_OPEN_FILE;

		if (fsize_input(f_matrix, &tmp_rows, &tmp_columns))
		{
			fclose(f_matrix);
			return ERROR_INPUT_FILE;
		}

		matrix = create(tmp_rows, tmp_columns);
		if (!matrix.matrix)
		{
			fclose(f_matrix);
			return ERROR_CREATE_MATRIX;
		}

		if (finput(f_matrix, &matrix))
		{
			free_memory(&matrix);
			fclose(f_matrix);
			return ERROR_INPUT_FILE;
		}

		fclose(f_matrix);

		if (determinant(matrix, &result))
		{
			free_memory(&matrix);
			return ERROR_ADDITION;
		}

		free_memory(&matrix);

		f_result = fopen(argv[3], "w");
		if (!f_result)
			return ERROR_OPEN_FILE;

		fprintf(f_result, "%.6lf \n", result);

		fclose(f_result);
	}

	return EXIT_SUCCESS;
}