#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 10
#define ARRAY_SIZE 100

#define INPUT_SIZE_MATRIX_ERROR 100
#define INPUT_MATRIX_ERROR 101
#define PRIME_ARRAY_ERROR 200

int matrix_input(int m[][MATRIX_SIZE], size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (scanf("%d", &m[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int is_prime(int num)
{
    if (num > 1)
    {
        for (int i = 2; i < num; i++)
            if (num % i == 0)
                return 0;
        return 1;
    }
    else
        return 0;
}

size_t array_make_prime(int m[][MATRIX_SIZE], size_t r, size_t c, int a[ARRAY_SIZE])
{
    size_t n = 0;
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (is_prime(m[i][j]))
            {
                a[n] = m[i][j];
                n += 1;
            }
    return n;
}

void array_reverse(int a[ARRAY_SIZE], size_t n)
{
    for (size_t i = 0; i < n / 2; i++)
    {
        int tmp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = tmp;
    }
}

void matrix_reverse_prime(int m[][MATRIX_SIZE], size_t r, size_t c,
int a[ARRAY_SIZE], size_t n)
{
    size_t k = 0;
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (m[i][j] == a[n - 1])
            {
                m[i][j] = a[k];
                n -= 1;
                k += 1;
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
    int a[ARRAY_SIZE];
    size_t n;
    
    if (scanf("%zu", &r) != 1 || r == 0 || r > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;

    if (scanf("%zu", &c) != 1 || c == 0 || c > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;

    if (matrix_input(m, r, c))
        return INPUT_MATRIX_ERROR;
    
    n = array_make_prime(m, r, c, a);
    if (n == 0)
        return PRIME_ARRAY_ERROR;
        
    array_reverse(a, n);
    matrix_reverse_prime(m, r, c, a, n);
    
    matrix_print(m, r, c);
    
    return EXIT_SUCCESS;
}