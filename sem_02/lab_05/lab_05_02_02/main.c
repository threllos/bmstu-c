#include <stdlib.h>
#include <stdio.h>
#include "variance.h"

#define ARGC_COUNT_ERROR 100
#define OPEN_FILE_ERROR 200
#define EMPTY_FILE_ERROR 201

int main(int argc, char **argv)
{
    FILE *f;
    double avg;
    int count;
    double variance;
    
    if (argc != 2)
        return ARGC_COUNT_ERROR;
    
    f = fopen(argv[1], "r");
    
    if (f == NULL)
        return OPEN_FILE_ERROR;
    
    avg = calc_avg(f, &count);
    
    if (count == 0)
    {
        fclose(f);
        return EMPTY_FILE_ERROR;
    }
    
    if (fseek(f, 0, SEEK_SET))
    {
        fclose(f);
        return EXIT_FAILURE;
    }
    
    variance = calc_variance(f, avg, count);
    
    fclose(f);
    
    printf("%.6lf\n", variance);
    
    return EXIT_SUCCESS;
}