#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h>
#define BITS ((int) sizeof(a) * 8)

void result(uint32_t a)
{
    printf("Result: ");
    a = (a << 1) | (a >> (BITS - 1));
    for (int i = 0; i < BITS; i++)
    {
        printf("%d", a % 2);
        a = (a << 1) | (a >> (BITS - 1));
    }
}

int main(void)
{
    uint32_t a;
    int n;

    printf("Input a: ");
    if (scanf("%"SCNu32, &a) != 1)
    {
        printf("Error: invalid input");
        return EXIT_FAILURE;
    }

    printf("Input n: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Error: invalid input");
        return EXIT_FAILURE;
    }

    if (n < 0)
    {
        printf("Error: n less zero");
        return EXIT_FAILURE;
    }

    n %= BITS;
    a = (a >> n) | (a << (BITS - n));
    result(a);

    return EXIT_SUCCESS;
}
