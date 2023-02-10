#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N_MAX 1024
#define N 10
#define TRUE 1
#define FALSE 0

#define INPUT_ARRAY_ERROR 100
#define INPUT_SIZE_ERROR 101

int input(int *pa, int *pb)
{
    while (pa < pb)
    {
        if (scanf("%d", pa) != 1)
            return EXIT_FAILURE;
        pa += 1;
    }
    return EXIT_SUCCESS;
}

int sum_of_multiplication(int *pa, int *pb)
{
    int flag = TRUE;
    int result = 0;
    int multy = 1;

    while (flag)
    {
        multy *= *pa;
        result += multy;

        if (*pa < 0 || pa + 1 == pb)
            flag = FALSE;
        else
            pa += 1;
    }

    return result;
}

int main(void)
{
    int arr[N_MAX];
    size_t n;
    int res;

    printf("Input size: ");
    if (scanf("%zu", &n) != 1 || n == 0 || n > N)
    {
        printf("input size error!!");
        return INPUT_SIZE_ERROR;
    }

    printf("Input array: ");
    if (input(arr, arr + n))
    {
        printf("input array error!!");
        return INPUT_ARRAY_ERROR;
    }

    res = sum_of_multiplication(arr, arr + n);
    printf("result is %d", res);

    return EXIT_SUCCESS;
}
