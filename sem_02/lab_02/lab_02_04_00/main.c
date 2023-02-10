#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N_MAX 1024
#define N 10
#define TRUE 1
#define FALSE 0

#define OVERFLOW 100
#define EMPTY_ARRAY 101

size_t input(int arr[])
{
    size_t n = 0;
    while (n < N && scanf("%d", &arr[n]) == 1)
        n += 1;
    return n;
}

void bubble_sort(int arr[], size_t n)
{
    int temp;
    for (size_t i = 1; i < n; i++)
        for (size_t j = 1; j <= n - i; j++)
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
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
    int temp;
    int flag = FALSE;

    n = input(arr);

    if (n == 10 && scanf("%d", &temp) == 1)
        flag = TRUE;

    if (n == 0)
    {
        printf("empty array!!");
        return EMPTY_ARRAY;
    }

    bubble_sort(arr, n);
    output(arr, n);

    if (flag)
        return OVERFLOW;
    else
        return EXIT_SUCCESS;
}
