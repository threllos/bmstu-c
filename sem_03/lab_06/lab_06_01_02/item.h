#ifndef _ITEM_H_
#define _ITEM_H_

#include <stdio.h>
#include <stdlib.h>

#define LEN_ARRAY 15
#define LEN_NAME 25

typedef struct
{
	char name[LEN_NAME];
	double weight;
	double volume;
} item_t;

typedef struct
{
	item_t array[LEN_ARRAY + 1];
	size_t len; 
} items_t;

void write_items(const items_t data);
void write_items_by_str(const items_t data, const char *substr);
int read_item(FILE *f, item_t *item);
int make_array(FILE *f, items_t *items);
void sort_array(items_t *items);

#endif