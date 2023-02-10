#ifndef _ITEM_H_
#define _ITEM_H_

#include <stdio.h>
#include <stdlib.h>

#define LEN_ARRAY 15
#define DOUBLE_LEN 35

typedef struct
{
	char *name;
	double weight;
	double volume;
} item_t;

typedef struct
{
	item_t *array;
	size_t len; 
} items_t;

int count_items(FILE *f, size_t *count);
int create_data(FILE *f, items_t *data, const size_t len);
void free_data(items_t *data);

void write_items(const items_t data);
void write_items_by_str(const items_t data, const char *substr);

void sort_data(items_t *items);

#endif
