#include <string.h>
#include "item.h"

#define FAILURE_ITEM 2

void write_items(const items_t data)
{
	for (size_t i = 0; i < data.len; i++)
	{
		printf("%s\n", data.array[i].name);
		printf("%.6lf\n", data.array[i].weight);
		printf("%.6lf\n", data.array[i].volume);
	}
}

void write_items_by_str(const items_t data, const char *substr)
{
	for (size_t i = 0; i < data.len; i++)
		if (strstr(data.array[i].name, substr) == data.array[i].name)
		{
			printf("%s\n", data.array[i].name);
			printf("%.6lf\n", data.array[i].weight);
			printf("%.6lf\n", data.array[i].volume);
		}
}

int read_double(FILE *f, double *num)
{
	char buf_str_num[LEN_NAME];
	double buf_num;
	char *ptrend;

	if (!fgets(buf_str_num, LEN_NAME, f))
		return EXIT_FAILURE;

	buf_num = strtod(buf_str_num, &ptrend);

	if (buf_num <= 0)
		return EXIT_FAILURE;

	if (strlen(ptrend) > 1)
		return EXIT_FAILURE;

	*num = buf_num;

	return EXIT_SUCCESS;
}

int read_item(FILE *f, item_t *item)
{
	// Ввод названия
	char buf_name[LEN_NAME + 2];

	if (!fgets(buf_name, LEN_NAME + 2, f))
		return EXIT_FAILURE;

	if (buf_name[strlen(buf_name) - 1] == '\n')
		buf_name[strlen(buf_name) - 1] = 0;
	else
		return EXIT_FAILURE;

	if (strlen(buf_name) > LEN_NAME || strlen(buf_name) == 0)
		return EXIT_FAILURE;

	strcpy(item->name, buf_name);

	// Ввод массы
	if (read_double(f, &(item->weight)))
		return FAILURE_ITEM;

	// Ввод объема
	if (read_double(f, &(item->volume)))
		return FAILURE_ITEM;

	return EXIT_SUCCESS;
}

int make_array(FILE *f, items_t *items)
{
	int rc = 0;
	item_t buf_item = { 0 };
	items->len = 0;

	while (!(rc = read_item(f, &buf_item)) && items->len < LEN_ARRAY + 1)
	{
		items->array[items->len] = buf_item;
		items->len += 1;
	}

	if (rc == FAILURE_ITEM)
		return EXIT_FAILURE;

	if (items->len > LEN_ARRAY || items->len == 0)
		return EXIT_FAILURE;
	
	if (!feof(f))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

double calc_density(const double weight, const double volume)
{
	return weight / volume;
}

void sort_array(items_t *items)
{
	item_t tmp_item = { 0 };
	double density_1 = 0;
	double density_2 = 0;

	for (size_t i = 0; i < items->len - 1; i++)
		for (size_t j = 0; j < items->len - i - 1; j++)
		{
			density_1 = calc_density(items->array[j].weight, items->array[j].volume);
			density_2 = calc_density(items->array[j + 1].weight, items->array[j + 1].volume);

			if (density_1 > density_2)
			{
				tmp_item = items->array[j];
				items->array[j] = items->array[j + 1];
				items->array[j + 1] = tmp_item;
			}
		}
}