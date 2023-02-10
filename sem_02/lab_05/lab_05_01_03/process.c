#include <stdlib.h>
#include "process.h"

#define NO_NUMBERS -1
#define NOT_ENOUGH_NUMBERS -2

int is_sign_changed(int prev, int curr)
{
    if (prev >= 0)
    {
        if (curr < 0)
            return 1;
        else
            return 0;
    }
    else
    {
        if (curr >= 0)
            return 1;
        else
            return 0;
    }
}

int process(FILE *f, int *result)
{
    int left_x;
    int curr_x;
    *result = 0;
    
    if (fscanf(f, "%d", &left_x) != 1)
        return NO_NUMBERS;
        
    if (fscanf(f, "%d", &curr_x) != 1)
        return NOT_ENOUGH_NUMBERS;
        
    do
    {
        *result += is_sign_changed(left_x, curr_x);
        left_x = curr_x;
    }
    while (fscanf(f, "%d", &curr_x) == 1);
    
    return EXIT_SUCCESS;
}