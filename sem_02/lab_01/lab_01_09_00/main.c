#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double i = 1.0;
    double x;
    double sum = 0.0;
	
    if (scanf("%lf", &x) != 1)
        return EXIT_FAILURE;

    while (x >= 0)
    {
        sum += x / i;
        i += 1;

        if (scanf("%lf", &x) != 1)
            return EXIT_FAILURE;
    }
	
    printf("%.6lf", sqrt(sum));
    return EXIT_SUCCESS;
}