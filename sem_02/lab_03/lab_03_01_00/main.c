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

size_t array_make(int m[][MATRIX_SIZE], size_t r, size_t c, int a[])
{
    int n = 0;
    for (size_t i = 0; i < c; i++)
    {
        int flag;
        
        if (r == 1)
            flag = 1;
        else
        {
            int tmp = m[0][i];
            flag = 0;
            
            for (size_t j = 1; j < r; j++)
            {
                if (m[j][i] >= tmp)
                    flag = 1;
                tmp = m[j][i];
            }
        }
        
        if (!flag)
            a[i] = 1;
        else
            a[i] = 0;
        n += 1;
    }
    return n;
}

void array_print(int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main(void)
{
    int m[MATRIX_SIZE][MATRIX_SIZE];
    int a[MATRIX_SIZE];
    size_t r, c;
    size_t n;

    if (scanf("%zu", &r) != 1 || r == 0 || r > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;

    if (scanf("%zu", &c) != 1 || c == 0 || c > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;

    if (matrix_input(m, r, c))
        return INPUT_MATRIX_ERROR;

    n = array_make(m, r, c, a);

    array_print(a, n);

    return EXIT_SUCCESS;
}
