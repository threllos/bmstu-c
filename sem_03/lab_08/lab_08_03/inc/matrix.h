#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef struct 
{
	int **matrix;
	size_t rows;
	size_t columns;
	size_t const_rows;
	size_t const_columns;
} matrix_t;

int size_input(size_t *rows, size_t *columns);
int power_input(size_t *power);
int input(matrix_t *matrix);
void output(matrix_t matrix);

void free_memory(matrix_t *matrix);
matrix_t create(size_t rows, size_t columns);
int copy(matrix_t src, matrix_t *dst);

void make_square(matrix_t *matrix);
void fill(matrix_t src, matrix_t *dst);
int multiplication(matrix_t matrix1, matrix_t matrix2, matrix_t *result);
int power(matrix_t src, matrix_t *dst, size_t power);

#endif // _MATRIX_H_ 
