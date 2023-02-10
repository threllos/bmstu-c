#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#define N_MAX 100000
#define N 100000
#define TRUE 1
#define FALSE 0

int input(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return EXIT_SUCCESS;
}

int sum_of_multiplication(int arr[], size_t n)
{
    int result = 0;

    for (size_t i = 0; i < n; i++)
    {
        int multy = 1;
        for (size_t j = 0; j <= i; j++)
            multy *= *(arr + j);
        result += multy;
    }
    return result;
}

int64_t process(int arr[], size_t n)
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time;

    gettimeofday(&tv_start, NULL);
    sum_of_multiplication(arr, n);
    gettimeofday(&tv_stop, NULL);

    elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
            (tv_stop.tv_usec - tv_start.tv_usec);

    return elapsed_time;
}

int main(void)
{
    int arr[N_MAX];
    size_t n;
    int64_t time;

    scanf("%zu", &n);
    input(arr, n);
    
    time = process(arr, n);
    printf("%"PRId64"\n", time);

    return EXIT_SUCCESS;
}
