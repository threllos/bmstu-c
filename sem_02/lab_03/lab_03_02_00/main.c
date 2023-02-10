#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 10
#define MATRIX_SIZE_MAX 100

#define INPUT_SIZE_MATRIX_ERROR 100
#define INPUT_MATRIX_ERROR 101
#define INPUT_DIGIT_ERROR 200
#define RESULT_MATRIX_ERROR 300

int matrix_input(int m[][MATRIX_SIZE], size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
        for (size_t j = 0; j < c; j++)
            if (scanf("%d", &m[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int last_digit(int num, int dig)
{
    if (abs(num % 10) == dig)
        return 1;
    return 0;
}

int first_digit(int num, int dig)
{
    while (abs(num) >= 10)
        num /= 10;
        
    if (abs(num) == dig)
        return 1;
    return 0;
}

int lds_equal_fds(int a[], size_t n, int dig)
{
    int count_last_digit = 0;
    int count_first_digit = 0;
    
    for (size_t i = 0; i < n; i ++)
    {
        if (last_digit(a[i], dig))
            count_last_digit += 1;
        if (first_digit(a[i], dig))
            count_first_digit += 1;
    }
    
    if (count_last_digit == count_first_digit && count_last_digit != 0)
        return 1;
    return 0;
}

void make_result_matrix(int m[][MATRIX_SIZE], size_t r, size_t c, int dig,
int rs_m[][MATRIX_SIZE_MAX], size_t *rs_r, size_t *rs_c)
{
    *rs_r = 0;
    *rs_c = 0;
    for (size_t n = 0; n < r; n++)
    {
        if (lds_equal_fds(m[n], c, dig))
        {
            size_t j;
            for (j = 0; j < c; j++)
                rs_m[*rs_r][j] = m[n][j];
            *rs_c = c;
            for (j = 0; j < c; j++)
                rs_m[*rs_r + 1][j] = 100;
            *rs_r += 2;
        }
        else
        {
            for (size_t j = 0; j < c; j++)
                rs_m[*rs_r][j] = m[n][j];
            *rs_c = c;
            *rs_r += 1;
        }
    }
}

void matrix_print(int m[][MATRIX_SIZE_MAX], size_t r, size_t c)
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
    int digit;
    int rs_m[MATRIX_SIZE_MAX][MATRIX_SIZE_MAX];
    size_t rs_r, rs_c;
    
    if (scanf("%zu", &r) != 1 || r == 0 || r > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;

    if (scanf("%zu", &c) != 1 || c == 0 || c > MATRIX_SIZE)
        return INPUT_SIZE_MATRIX_ERROR;

    if (matrix_input(m, r, c))
        return INPUT_MATRIX_ERROR;
        
    if (scanf("%d", &digit) != 1 || digit > 9 || digit < 0)
        return INPUT_DIGIT_ERROR;
        
    make_result_matrix(m, r, c, digit, rs_m, &rs_r, &rs_c);
    
    if (rs_r != 0 && rs_c != 0)
        matrix_print(rs_m, rs_r, rs_c);
    else
        return RESULT_MATRIX_ERROR;
    
    return EXIT_SUCCESS;
}