#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N_MAX 1024
#define N 10

#define INPUT_ARRAY_ERROR 100
#define INPUT_SIZE_ERROR 101
#define COUNT_ZERO 200

int input(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

double arithmetic_mean(int arr[], size_t n)
{
    double result = 0.0;
    for (size_t i = 0; i < n; i++)
        result += arr[i];
    return result / n;
}

int count_greater(int arr[], size_t n, double alpha)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
        if (arr[i] > alpha)
            count += 1;
    return count;
}

void copy_greater(int arr_a[], size_t n_a, int arr_b[], double alpha)
{
    size_t j = 0;
    for (size_t i = 0; i < n_a; i++)
        if (arr_a[i] > alpha)
        {
            arr_b[j] = arr_a[i];
            j += 1;
        }
}

void output(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
    int arr_a[N_MAX], arr_b[N_MAX];
    size_t n_a, n_b;

    printf("Input size: ");
    if (scanf("%zu", &n_a) != 1 || n_a == 0 || n_a > N)
    {
        printf("input size error!!");
        return INPUT_SIZE_ERROR;
    }

    printf("Input array: ");
    if (input(arr_a, n_a))
    {
        printf("input array error!!");
        return INPUT_ARRAY_ERROR;
    }

    double avg = arithmetic_mean(arr_a, n_a);
    n_b = count_greater(arr_a, n_a, avg);

    if (n_b == 0)
    {
        printf("count is zero!!");
        return COUNT_ZERO;
    }

    copy_greater(arr_a, n_a, arr_b, avg);
    printf("New array: ");
    output(arr_b, n_b);

    return EXIT_SUCCESS;
}
