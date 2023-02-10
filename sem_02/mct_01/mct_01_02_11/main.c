#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N_MAX 1024

size_t input(int arr[], size_t n)
{
    size_t count = 0;
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1)
            return count;
        else
            count += 1;
    return count;
}

void output(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int is_square(int x)
{
    int i = 1;
    if (x < 0)
        return 0;
    else if (x == 0 || x == 1)
        return 1;
    else
    {
        while (i * i < x)
            i += 1;

        if (i * i == x)
            return 1;
        else
            return 0;
    }
}

void del_element(int arr[], size_t *n, size_t index)
{
    for (size_t i = index; i < *n - 1; i++)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

int new_arr(int a_arr[], size_t *a_n, int b_arr[])
{
    size_t j = 0;
    for (size_t i = 0; i < *a_n; i++)
        if (is_square(a_arr[i]))
        {
            b_arr[j] = a_arr[i];
            j += 1;
            del_element(a_arr, a_n, i);
            i -= 1;
            *a_n -= 1;
        }
    return j;
}

int main(void)
{
    int arr[N_MAX], b_arr[N_MAX];
    size_t n, b_n;

    printf("input n: ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > N_MAX)
    {
        printf("input n error");
        return EXIT_FAILURE;
    }

    printf("input arr: ");
    if (input(arr, n) != n)
    {
        printf("input arr error");
        return EXIT_FAILURE;
    }

    b_n = new_arr(arr, &n, b_arr);

    printf("array A: ");
    output(arr, n);
    printf("array B: ");
    output(b_arr, b_n);

    return EXIT_SUCCESS;
}
