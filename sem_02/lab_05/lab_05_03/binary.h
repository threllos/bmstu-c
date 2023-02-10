#ifndef _BINARY_H_
#define _BINARY_H_

#include <stdio.h>

#define SIZE sizeof(int)

#define KEY_PRINT "p"
#define KEY_SORT "s"
#define KEY_CREATE "c"

#define RNDM_MIN 1
#define RNDM_MAX 100

int check_key(int argc, char **argv, int *key);
int get_size(FILE *f, size_t *size);
size_t get_len(size_t size);

int get_number_by_pos(FILE *f, size_t pos, int *x);
int put_number_by_pos(FILE *f, size_t pos, int *x);

int get_rndm();
int file_create(FILE *f, int count);

int file_print(FILE *f);

int swap_numbers(FILE *f, size_t pos_max, size_t pos_min, int *x_max, int *x_min);
int file_sort(FILE *f);

#endif