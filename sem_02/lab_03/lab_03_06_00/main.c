#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 10

#define INPUT_SIZE_MATRIX_ERROR 100

void matrix_fill_bull(int m[][MATRIX_SIZE], size_t r, size_t c)
{
    int num = 1;
    for (size_t i = 0; i < c; i++)
    {
        if (i % 2 == 0)
            for (size_t j = 0; j < r; j++)
                m[j][i] = num++;
        else
            for (int j = r - 1; j >= 0; j--)
                m[j][i] = num++;
    }
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

    matrix_fill_bull(m, r, c);

    matrix_print(m, r, c);
    
    return EXIT_SUCCESS;
}