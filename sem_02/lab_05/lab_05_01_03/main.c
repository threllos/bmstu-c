#include <stdio.h>
#include "process.h"

int main(void)
{
    int rc;
    int result;
    
    rc = process(stdin, &result);
    
    if (rc == 0)
        printf("%d\n", result);
    
    return rc;
}