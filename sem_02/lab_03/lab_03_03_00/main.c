#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 10

#define INPUT_SIZE_MATRIX_ERROR 100
#define INPUT_MATRIX_ERROR 101

int matrix_input(int m[][MATRIX_SIZE], size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (scanf("%d", &m[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int array_sum_numbers(int a[MATRIX_SIZE], size_t n)
{
    int sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void arrays_swap(int *a, int *b, size_t n)
{
    int tmp;
    for (size_t i = 0; i < n; i++)
    {
        tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

void matrix_sort_by_row(int m[][MATRIX_SIZE], size_t r, size_t c)
{
    size_t i;
    size_t j;
    for (i = 0; i < r - 1; i++)
        for (j = 0; j < r - i - 1; j++)
            if (array_sum_numbers(m[j], c) > array_sum_numbers(m[j + 1], c))
                arrays_swap(m[j], m[j + 1], c);
}

void matrix_print(int m[][MATRIX_SIZE], size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int m[MATRIX_SIZE][MATRIX_SIZE];
    size_t r, c;
    
    if (scanf("%zu", &r) != 1 || r == 0 || r > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;

    if (scanf("%zu", &c) != 1 || c == 0 || c > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;

    if (matrix_input(m, r, c))
        return INPUT_MATRIX_ERROR;
    
    matrix_sort_by_row(m, r, c);
    
    matrix_print(m, r, c);
    
    return EXIT_SUCCESS;
}