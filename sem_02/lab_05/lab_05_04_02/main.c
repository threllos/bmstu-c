#include <stdlib.h>
#include <stdio.h>
#include "product.h"

#define KEY_ERROR 53

#define NO_FILE_ERROR 201

#define ADD_PRODUCT_ERROR 300
#define PRINT_PRODUCT_ERROR 301
#define SORT_PRODUCT_ERROR 302
#define DEBUG_ERROR 303

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    int key;
    
    if (check_key(argc, argv, &key))
        return KEY_ERROR;

    if (key == 3)
    {
        FILE *f;

        f = fopen(argv[2], "rb+");

        if (f == NULL)
        {
            f = fopen(argv[2], "wb+"); // TODO: как-то не очень
            if (f == NULL)
                return NO_FILE_ERROR;
        }

        if (product_add(f))
        {
            fclose(f);
            return ADD_PRODUCT_ERROR;
        }

        fclose(f);
    }
    else if (key == 2)
    {
        FILE *f;

        f = fopen(argv[2], "rb");

        if (f == NULL)
            return NO_FILE_ERROR;

        if (product_sub_print(f, argv[3]))
        {
            fclose(f);
            return PRINT_PRODUCT_ERROR;
        }

        fclose(f);
    }
    else if (key == 1)
    {
        FILE *f_src, *f_dst;

        f_src = fopen(argv[2], "rb");
        
        if (f_src == NULL)
            return NO_FILE_ERROR;

        f_dst = fopen(argv[3], "wb+");

        if (f_dst == NULL)
        {
            fclose(f_src);
            return NO_FILE_ERROR;
        }

        if (product_sort(f_src, f_dst))
        {
            fclose(f_src);
            fclose(f_dst);
            return SORT_PRODUCT_ERROR;
        }

        fclose(f_src);
        fclose(f_dst);
    }
    else if (key == 4)
    {
        FILE *f;

        f = fopen(argv[2], "wb+");

        if (debug_create_bin(f))
        {
            fclose(f);
            return DEBUG_ERROR;
        }

        fclose(f);
    }
    else if (key == 5)
    {
        FILE *f;
        
        f = fopen(argv[2], "rb+");

        if (debug_print_file(f))
        {
            fclose(f);
            return DEBUG_ERROR;
        }

        fclose(f);
    }
    else
        return KEY_ERROR;

    return EXIT_SUCCESS;
}