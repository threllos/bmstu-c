#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sum;
    int quan;

    setbuf(stdout, NULL);

    printf("Input sum: ");
    scanf("%d", &sum);

    quan = (sum - 45) / 25 + 1;
    printf("Quantity is %d\n", quan);

    return EXIT_SUCCESS;
}
