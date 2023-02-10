#include <stdlib.h>
#include "variance.h"

double calc_avg(FILE *f, int *count)
{
    double x;
    double sum = 0;
    *count = 0;
    
    if (fscanf(f, "%lf", &x) != 1)
        return EXIT_FAILURE;
    
    sum += x;
    *count += 1;
    
    while (fscanf(f, "%lf", &x) == 1)
    {
        sum += x;
        *count += 1;
    }
    
    return sum / *count;
}

double calc_variance(FILE *f, double avg, int count)
{
    double x;
    double variance_n = 0;
    
    while (fscanf(f, "%lf", &x) == 1)
        variance_n += (x - avg) * (x - avg);
    
    return variance_n / count;
}
