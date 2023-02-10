#include <stdlib.h>
#include <string.h>
#include "str.h"

#define NO_CHANGES 300
#define INPUT_ERROR 400

int del_symb(str_t line, str_t new_line, char symb[], size_t *n)
{
    size_t k = 0;
    
    for (size_t i = 0; line[i]; i++)
        if (!strchr(symb, line[i]))
            new_line[k++] = line[i];
    
    if (k == 0)
        return NO_CHANGES;
    
    *n = k;
    
    return EXIT_SUCCESS;
}

int is_palin(str_t line, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (line[i] != line[n - i - 1])
            return 0;
    
    return 1;
}

int print_palin(FILE *f, char symb[SIZE_STR])
{
    int rc = EXIT_SUCCESS;
    
    while (!rc)
    {
        str_t curr_line;
        str_t new_line = "";
        size_t n;
    
        if (!fgets(curr_line, SIZE_STR, f))
            rc = INPUT_ERROR;
            
        if (curr_line[strlen(curr_line) - 1] == '\n')
            curr_line[strlen(curr_line) - 1] = 0;
            
        if (curr_line[SIZE_STR - 1] != 0)
            rc = INPUT_ERROR;
            
        if (!del_symb(curr_line, new_line, symb, &n) && !rc)
            if(is_palin(new_line, n))
                printf("%s\n", new_line);
    
        if (!rc)
            rc = feof(f);
            
        if (!rc)
            rc = ferror(f);
    }
    
    return rc;
}