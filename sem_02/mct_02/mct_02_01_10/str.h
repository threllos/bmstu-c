#ifndef _STR_H_
#define _STR_H_

#include <stdio.h>

#define SIZE_STR 100

typedef char str_t[SIZE_STR];

int del_symb(str_t line, str_t new_line, char symb[], size_t *n);
int is_palin(str_t line, size_t n);
int print_palin(FILE *f, char symb[]);

#endif