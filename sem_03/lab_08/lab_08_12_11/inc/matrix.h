#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef struct 
{
	double **matrix;
	size_t rows;
	size_t columns;
} matrix_t;

int key_check(int size, char **array);
int fsize_input(FILE *f, size_t *rows, size_t *columns);
int finput(FILE *f, matrix_t *matrix);
void foutput(FILE *f, matrix_t matrix);

void free_memory(matrix_t *matrix);
matrix_t create(size_t rows, size_t columns);

int addition(matrix_t matrix1, matrix_t matrix2, matrix_t *result);
int multiplication(matrix_t matrix1, matrix_t matrix2, matrix_t *result);
int determinant(matrix_t matrix, double *result);

#endif // _MATRIX_H_ 