#include <stdlib.h>
#include <string.h>
#include "product.h"

/*
Функции для дебага
*/

void debug_print_struct(product_t product)
{
    printf("Name : %s\n", product.name);
    printf("Maker: %s\n", product.maker);
    printf("Price: %"PRIu32"\n", product.price);
    printf("Count: %"PRIu32"\n", product.count);
}

int debug_print_file(FILE *f)
{
    size_t size, len;
    
    if (get_size(f, &size))
        return EXIT_FAILURE;
    
    len = get_len(size);
    
    for (size_t i = 0; i < len; i++)
    {
        product_t tmp = { 0 };
    
        if (get_product_by_pos(f, i, &tmp))
            return EXIT_FAILURE;
        debug_print_struct(tmp);
    }
    
    return EXIT_SUCCESS;
}

int debug_create_bin(FILE *f)
{
    size_t n = 0;
    printf("Input n: ");
    if (scanf("%zu", &n) != 1)
        return EXIT_FAILURE;

    for (size_t i = 0; i < n; i++)
    {
        product_t product = { 0 };

        if (get_product(&product))
            return EXIT_FAILURE;

        if (put_product_by_pos(f, i, &product))
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/*
Основные функции
*/

int check_key(int argc, char **argv, int *key)
{
    if (argc == 4)
    {
        if (strcmp(argv[1], KEY_SORT) == 0)
            *key = 1;
        else if (strcmp(argv[1], KEY_PRINT) == 0)
            *key = 2;
        else
            return EXIT_FAILURE;
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], KEY_ADD) == 0)
            *key = 3;
        else if (strcmp(argv[1], DEBUG_KEY_WRITE) == 0)
            *key = 4;
        else if (strcmp(argv[1], DEBUG_KEY_PRINT) == 0)
            *key = 5;
        else
            return EXIT_FAILURE;
    }
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

int get_product_by_pos(FILE *f, size_t pos, product_t *product)
{
    if (fseek(f, pos * SIZE, SEEK_SET))
        return EXIT_FAILURE;
    
    if (fread(product, SIZE, 1, f) != 1)
        return EXIT_FAILURE;
    
    return fseek(f, 0, SEEK_SET);
}

int put_product_by_pos(FILE *f, size_t pos, product_t *product)
{
    if (fseek(f, pos * SIZE, SEEK_SET))
        return EXIT_FAILURE;
    
    if (fwrite(product, SIZE, 1, f) != 1)
        return EXIT_FAILURE;
    
    return fseek(f, 0, SEEK_SET);
}

/*
Функции для добавления товара в файл
*/

int get_product(product_t *product)
{
    char buf[MAX_LEN];

    if (!fgets(buf, MAX_LEN, stdin))
        return EXIT_FAILURE;

    if (strlen(buf) > NAME_LEN)
        return EXIT_FAILURE;

    if (buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = 0;
    else
        return EXIT_FAILURE;

    if (strlen(buf) == 0)
        return EXIT_FAILURE;
    else
        strcpy(product->name, buf);

    if (!fgets(buf, MAX_LEN, stdin))
        return EXIT_FAILURE;

    if (strlen(buf) > MAKER_LEN)
        return EXIT_FAILURE;

    if (buf[strlen(buf) - 1] == '\n')
        buf[strlen(buf) - 1] = 0;
    else
        return EXIT_FAILURE;

    if (strlen(buf) == 0)
        return EXIT_FAILURE;
    else
        strcpy(product->maker, buf);

    if (scanf("%"SCNu32, &product->price) != 1)
        return EXIT_FAILURE;
    if (scanf("%"SCNu32, &product->count) != 1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int get_pos(FILE *f, product_t product, size_t *pos)
{
    size_t size;
    
    if (get_size(f, &size))
        return EXIT_FAILURE;
    
    if (size % SIZE != 0)
        return EXIT_FAILURE;
    
    if (size == 0)
        *pos = 0;
    else
    {
        product_t tmp = { 0 };
        size_t i = 0;
        size_t len = get_len(size);
        
        get_product_by_pos(f, i, &tmp);
        
        while (product.price < tmp.price && i < len)
        {
            i += 1;
            get_product_by_pos(f, i, &tmp);
        }
        
        while (product.count < tmp.count && product.price == tmp.price && i < len)
        {
            i += 1;
            get_product_by_pos(f, i, &tmp);
        }
        
        *pos = i;
    }

    return EXIT_SUCCESS;
}

int move_to_end(FILE *f, size_t start, product_t product)
{
    size_t size;
    
    if (get_size(f, &size))
        return EXIT_FAILURE;
    
    if (size % SIZE != 0)
        return EXIT_FAILURE;
    
    size_t end = get_len(size);

    for (size_t i = start; i < end; i++)
    {
        product_t tmp = { 0 };
        
        if (get_product_by_pos(f, i, &tmp))
            return EXIT_FAILURE;
        if (put_product_by_pos(f, i, &product))
            return EXIT_FAILURE;
        
        product = tmp;
    }

    if (put_product_by_pos(f, end, &product))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int product_add(FILE *f)
{
    product_t product = { 0 };
    size_t pos;
    
    if (get_product(&product))
        return EXIT_FAILURE;
    
    if (get_pos(f, product, &pos))
        return EXIT_FAILURE;
    
    if (move_to_end(f, pos, product))
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}

/*
Функции для вывода товаров по подстроке
*/

int is_str_in_name(char name[], char str[])
{
    size_t len_name = strlen(name);
    size_t len_str = strlen(str);
    size_t j = 0;
    
    if (len_str > len_name)
        return 0;

    for (size_t i = len_name - len_str; name[i]; i++)
    {
        if (name[i] == str[j])
            j += 1;
        else
            return 0;
    }
    
    return 1;
}

void print_product(product_t product)
{
    printf("%s\n", product.name);
    printf("%s\n", product.maker);
    printf("%"PRIu32"\n", product.price);
    printf("%"PRIu32"\n", product.count);
}

int product_sub_print(FILE *f, char str[])
{
    size_t size;
    size_t count = 0;
    
    if (get_size(f, &size))
        return EXIT_FAILURE;
    
    if (size % SIZE != 0)
        return EXIT_FAILURE;
    
    if (strlen(str) > NAME_LEN || strlen(str) == 0)
        return EXIT_FAILURE;
    
    size_t len = get_len(size);
    
    if (len <= 0)
        return EXIT_FAILURE;
    
    for (size_t i = 0; i < len; i++)
    {
        product_t product = { 0 };
        
        if (get_product_by_pos(f, i, &product))
            return EXIT_FAILURE;
        
        if (is_str_in_name(product.name, str) == 1)
        {
            count += 1;
            print_product(product);
        }
    }
    
    if (count == 0)
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}

/*
Функции для сортировки товаров
*/

int copy_file(FILE *src, FILE *dst, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        product_t product = { 0 };
        
        if (get_product_by_pos(src, i, &product))
            return EXIT_FAILURE;
        
        if (put_product_by_pos(dst, i, &product))
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int swap_product(FILE *f, size_t pos_min, product_t *prd_min,
size_t pos_max, product_t *prd_max)
{
    if (put_product_by_pos(f, pos_min, prd_max))
        return EXIT_FAILURE;
    if (put_product_by_pos(f, pos_max, prd_min))
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}

int sort_by_price(FILE *f, size_t len)
{
    for (size_t i = 0; i < len - 1; i++)
        for (size_t j = 0; j < len - i - 1; j++)
        {
            product_t prd1 = { 0 }, prd2 = { 0 };
            
            if (get_product_by_pos(f, j, &prd1))
                return EXIT_FAILURE;
            if (get_product_by_pos(f, j + 1, &prd2))
                return EXIT_FAILURE;
            
            if (prd1.price < prd2.price)
                if (swap_product(f, j, &prd1, j + 1, &prd2))
                    return EXIT_FAILURE;
        }
    
    return EXIT_SUCCESS;
}

int sort_by_count(FILE *f, size_t len)
{
    for (size_t i = 0; i < len - 1; i++)
        for (size_t j = 0; j < len - i - 1; j++)
        {
            product_t prd1 = { 0 }, prd2 = { 0 };
            
            if (get_product_by_pos(f, j, &prd1))
                return EXIT_FAILURE;
            if (get_product_by_pos(f, j + 1, &prd2))
                return EXIT_FAILURE;
            
            if (prd1.count < prd2.count && prd1.price == prd2.price)
                if (swap_product(f, j, &prd1, j + 1, &prd2))
                    return EXIT_FAILURE;
        }
    
    return EXIT_SUCCESS;
}

int product_sort(FILE *f_src, FILE *f_dst)
{
    size_t size;
    
    if (get_size(f_src, &size))
        return EXIT_FAILURE;
    
    if (size % SIZE != 0)
        return EXIT_FAILURE;
    
    size_t len = get_len(size);
    
    if (len <= 0)
        return EXIT_FAILURE;
    
    if (copy_file(f_src, f_dst, len))
        return EXIT_FAILURE;
    
    if (sort_by_price(f_dst, len))
        return EXIT_FAILURE;
    
    if (sort_by_count(f_dst, len))
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}