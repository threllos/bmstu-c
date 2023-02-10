#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include <stdlib.h>
#include <stdio.h> 

int check_argv(const int argc, char **argv);
int count_len(FILE *f, size_t *len);
int read_array(FILE *f, const int *pb_array, const int *pe_array);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int compare(const void *x1, const void *x2);
void mysort(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));
int write_array(FILE *f, const int *pb_array, const int *pe_array);

#endif
