#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N_MAX 1024
#define N 10

#define INPUT_ARRAY_ERROR 100
#define INPUT_SIZE_ERROR 101
#define PALINDROME 200
#define NOT_PALINDROME 201
#define EMPTY_ARRAY 300

int input(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int is_palindrome(int num)
{
    int divisor = 1;

    if (num < 0)
        return NOT_PALINDROME;

    while (num / divisor >= 10)
        divisor *= 10;

    while (num != 0)
    {
        int leading = num / divisor;
        int trailing = num % 10;

        if (leading != trailing)
            return NOT_PALINDROME;

        num = (num % divisor) / 10;
        divisor /= 100;
    }

    return PALINDROME;
}

void del_palindrome(int arr[], size_t *n)
{
    size_t i = 0;
    while (i < *n)
    {
        if (is_palindrome(arr[i]) == PALINDROME)
        {
            for (size_t j = i + 1; j < *n; j++)
                arr[j - 1] = arr[j];
            *n -= 1;
        }
        else
            i += 1;
    }
}

void output(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
    int arr[N_MAX];
    size_t n;

    printf("Input size: ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > N)
    {
        printf("input size error!!");
        return INPUT_SIZE_ERROR;
    }

    printf("Input array: ");
    if (input(arr, n))
    {
        printf("input array error!!");
        return INPUT_ARRAY_ERROR;
    }

    del_palindrome(arr, &n);
    if (n == 0)
    {
        printf("empty array!!");
        return EMPTY_ARRAY;
    }

    printf("New array: ");
    output(arr, n);

    return EXIT_SUCCESS;
}
