#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef struct 
{
	int **matrix;
	size_t rows;
	size_t columns;
} matrix_t;

int size_input(size_t *rows, size_t *columns);
int input(matrix_t *matrix);
int input_array(matrix_t *array, size_t n);
void output(matrix_t matrix);

void free_memory(matrix_t *matrix);
matrix_t create(size_t rows, size_t columns);

void swap_columns(matrix_t matrix, size_t column1, size_t column2);
void make_array(matrix_t *array, size_t n);

#endif // _MATRIX_H_ 
