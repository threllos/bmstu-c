#include <stdlib.h>
#include <stdio.h>
#include "student.h"


int main(int argc, char **argv)
{
    if (argc != 2)
        return EXIT_FAILURE;
    
    FILE *src;
    
    src = fopen(argv[1], "rb+");
    
    if (src == NULL)
        return EXIT_FAILURE;
    
    if (del_students(src))
    {
        fclose(src);
        return EXIT_FAILURE;
    }
    
    fclose(src);
    
    return EXIT_SUCCESS;
}