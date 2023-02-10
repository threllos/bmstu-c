#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define NAME_LEN 30
#define MAKER_LEN 15
#define MAX_LEN 50

#define KEY_PRINT "fb"
#define KEY_SORT "sb"
#define KEY_ADD "ab"
#define DEBUG_KEY_WRITE "tb"
#define DEBUG_KEY_PRINT "pb"

typedef struct product
{
    char name[NAME_LEN + 1];
    char maker[MAKER_LEN + 1];
    uint32_t price;
    uint32_t count;
} product_t;

#define SIZE sizeof(product_t)

void debug_print_struct(product_t product);
int debug_print_file(FILE *f);
int debug_create_bin(FILE *f);

int check_key(int argc, char **argv, int *key);
int get_size(FILE *f, size_t *size);
size_t get_len(size_t size_file);
int get_product_by_pos(FILE *f, size_t pos, product_t *product);
int put_product_by_pos(FILE *f, size_t pos, product_t *product);

int get_product(product_t *product);
int get_pos(FILE *f, product_t product, size_t *pos);
int move_to_end(FILE *f, size_t start, product_t product);
int product_add(FILE *f);

int is_str_in_name(char name[], char str[]);
void print_product(product_t product);
int product_sub_print(FILE *f, char str[]);

int copy_file(FILE *src, FILE *dst, size_t len);
int swap_product(FILE *f, size_t pos_min, product_t *prd_min,
size_t pos_max, product_t *prd_max);
int sort_by_price(FILE *f, size_t len);
int sort_by_count(FILE *f, size_t len);
int product_sort(FILE *f_src, FILE *f_dst);

#endif