#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "binary.h"

int check_key(int argc, char **argv, int *key)
{
    if (argc == 3)
    {
        if (strcmp(argv[1], KEY_PRINT) == 0)
            *key = 2;
        else if (strcmp(argv[1], KEY_SORT) == 0)
            *key = 3;
        else
            return EXIT_FAILURE;
    }
    else if (argc == 4 && strcmp(argv[1], KEY_CREATE) == 0)
        *key = 1;
    else
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}

int get_size(FILE *f, size_t *size)
{
    int sz;

    if (fseek(f, 0, SEEK_END))
        return EXIT_FAILURE;

    sz = ftell(f);
    if (sz < 0)
        return EXIT_FAILURE;

    *size = sz;

    return fseek(f, 0, SEEK_SET);
}

size_t get_len(size_t size_file)
{
    return size_file / SIZE;
}

int get_number_by_pos(FILE *f, size_t pos, int *x)
{
    if (fseek(f, pos * SIZE, SEEK_SET))
        return EXIT_FAILURE;
    if (fread(x, SIZE, 1, f) != 1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int put_number_by_pos(FILE *f, size_t pos, int *x)
{
    if (fseek(f, pos * SIZE, SEEK_SET))
        return EXIT_FAILURE;
    if (fwrite(x, SIZE, 1, f) != 1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int get_rndm()
{
    return RNDM_MIN + rand() % (RNDM_MAX - RNDM_MIN + 1);
}

int file_create(FILE *f, int count)
{
    srand(time(NULL));
    
    for (size_t i = 0; i < (size_t) count; i++)
    {
        int x = get_rndm();
        if (put_number_by_pos(f, i, &x))
            return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

int file_print(FILE *f)
{
    size_t size;
    size_t len;
    
    if (get_size(f, &size))
        return EXIT_FAILURE;
        
    if (size % SIZE != 0)
        return EXIT_FAILURE;
    
    len = get_len(size);
    
    if (fseek(f, 0, SEEK_SET))
        return EXIT_FAILURE;
    
    for (size_t i = 0; i < len; i++)
    {
        int x;
        
        if (fread(&x, SIZE, 1, f) != 1)
            return EXIT_FAILURE;
            
        printf("%d ", x);
    }
    
    return EXIT_SUCCESS;
}

int swap_numbers(FILE *f, size_t pos_max, size_t pos_min, int *x_max, int *x_min)
{
    if (put_number_by_pos(f, pos_min, x_max))
        return EXIT_FAILURE;
    if (put_number_by_pos(f, pos_max, x_min))
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}

int file_sort(FILE *f)
{
    size_t size;
    size_t len;
    
    if (get_size(f, &size))
        return EXIT_FAILURE;
    
    if (size % SIZE != 0)
        return EXIT_FAILURE;
    
    len = get_len(size);
    
    for (size_t i = 0; i < len - 1; i++)
        for (size_t j = 0; j < len - i - 1; j++)
        {
            int x1, x2;
            
            if (get_number_by_pos(f, j, &x1))
                return EXIT_FAILURE;
            if (get_number_by_pos(f, j + 1, &x2))
                return EXIT_FAILURE;

            if (x1 > x2)
                if (swap_numbers(f, j, j + 1, &x1, &x2))
                    return EXIT_FAILURE;
        }
    
    return EXIT_SUCCESS;
}
