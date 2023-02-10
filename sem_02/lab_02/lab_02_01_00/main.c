#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N_MAX 1024
#define N 10

#define INPUT_ARRAY_ERROR 100
#define INPUT_SIZE_ERROR 101
#define NO_EVEN 200

int input(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int count_even(int arr[], size_t n)
{
    int count = 0;
	
    for (size_t i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            count += 1;
		
    return count;
}

int sum_even(int arr[], size_t n)
{
    int sum = 0;

    for (size_t i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            sum += arr[i];

    return sum;
}


int main(void)
{
    int arr[N_MAX];
    size_t n;
    int count;
    int sum;

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

    count = count_even(arr, n);
    if (count == 0)
    {
        printf("no even!!");
        return NO_EVEN;
    }
	
    sum = sum_even(arr, n);
    printf("sum is %d\n", sum);

    return EXIT_SUCCESS;
}