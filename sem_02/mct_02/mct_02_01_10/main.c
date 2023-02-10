#include <stdlib.h>
#include <stdio.h>
#include "str.h"

#define ARGC_COUNT_ERROR 100
#define FILEE_OPEN_ERROR 200

int main (int argc, char **argv)
{
    int rc;
    FILE *f;
    char *symb;
    char *file_name;
    
    if (argc != 3)
        return ARGC_COUNT_ERROR;
        
    file_name = argv[1];
    symb = argv[2];
    
    f = fopen(file_name, "r");
    
    if (f == NULL)
        return FILEE_OPEN_ERROR;
    
    rc = print_palin(f, symb);
    
    fclose(f);
    
    return rc;
}