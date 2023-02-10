#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 10

#define INPUT_SIZE_MATRIX_ERROR 100
#define INPUT_MATRIX_ERROR 101
#define MATRIX_FIND_ERROR 200

int matrix_input(int m[][MATRIX_SIZE], size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (scanf("%d", &m[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int matrix_find_min(int m[][MATRIX_SIZE], size_t n)
{
    int result = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if (m[i][j] % 2 != 0 && i > j)
            {
                if (result == 0)
                    result = m[i][j];
                else if (result > m[i][j])
                    result = m[i][j];
            }
    return result;
}

int main(void)
{
    int m[MATRIX_SIZE][MATRIX_SIZE];
    size_t r, c;
    int min;
    
    if (scanf("%zu", &r) != 1 || r == 0 || r > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;

    if (scanf("%zu", &c) != 1 || c == 0 || c > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;
        
    if (r != c)
        return INPUT_SIZE_MATRIX_ERROR;

    if (matrix_input(m, r, c))
        return INPUT_MATRIX_ERROR;
    
    min = matrix_find_min(m, r);
    
    if (min == 0)
        return MATRIX_FIND_ERROR;
    
    printf("%d", min);
    
    return EXIT_SUCCESS;
}