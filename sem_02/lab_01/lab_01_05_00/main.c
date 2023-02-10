#include <stdio.h>
#include <stdlib.h>

int power(int a, int n)
{
    int result = a;

    for (int i = 1; i < n; i++)
        result = result * a;

    return result;
}

int main(void)
{
    int a;
    int n;
    long long result;

    setbuf(stdout, NULL);

    printf("Input a: ");
    if (scanf("%d", &a) != 1)
    {
        printf("Input error\n");
        return EXIT_FAILURE;
    }

    printf("Input n: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Input error\n");
        return EXIT_FAILURE;
    }

    if (n <= 0)
    {
        printf("Input error\n");
        return EXIT_FAILURE;
    }
    result = power(a, n);
    printf("a**n is %lld\n", result);


    return EXIT_SUCCESS;
}
