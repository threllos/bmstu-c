#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary.h"

#define KEY_ERROR 100

#define OPEN_FILE_ERROR 200
#define EMPTY_FILE_ERROR 201
#define NUMBERS_FILE_ERROR 202

#define CREATE_FILE_ERROR 300
#define PRINT_FILE_ERROR 301
#define SORT_FILE_ERROR 302

int main(int argc, char **argv)
{
    int key;
    
    if (check_key(argc, argv, &key))
        return KEY_ERROR;
        
    FILE *f;
    
    if (key == 1)
    {
        int count = atoi(argv[2]);
        
        if (count <= 0)
            return NUMBERS_FILE_ERROR;
            
        f = fopen(argv[3], "wb");
        
        if (file_create(f, count))
        {
            fclose(f);
            return CREATE_FILE_ERROR;
        }
        
        fclose(f);
    }
    else if (key == 2)
    {
        f = fopen(argv[2], "rb");
        
        if (f == NULL)
            return EMPTY_FILE_ERROR;
        
        if (file_print(f))
        {
            fclose(f);
            return PRINT_FILE_ERROR;
        }
        
        fclose(f);
    }
    else if (key == 3)
    {
        f = fopen(argv[2], "rb+");
        
        if (f == NULL)
            return EMPTY_FILE_ERROR;
        
        if (file_sort(f))
        {
            fclose(f);
            return SORT_FILE_ERROR;
        }
        
        fclose(f);
    }
    else
        return KEY_ERROR;

    return EXIT_SUCCESS;
}