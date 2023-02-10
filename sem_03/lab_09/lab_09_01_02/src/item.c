#define _GNU_SOURCE
#include <string.h>
#include "item.h"

#define EPS 1e-6

void write_items(const items_t data)
{
	for (size_t i = 0; i < data.len; i++)
	{
		printf("%s", data.array[i].name);
		printf("%.6lf\n", data.array[i].weight);
		printf("%.6lf\n", data.array[i].volume);
	}
}

void write_items_by_str(const items_t data, const char *substr)
{
	for (size_t i = 0; i < data.len; i++)
		if (strstr(data.array[i].name, substr) == data.array[i].name)
		{
			printf("%s", data.array[i].name);
			printf("%.6lf\n", data.array[i].weight);
			printf("%.6lf\n", data.array[i].volume);
		}
}

int create_item(item_t *item, char *name, double weight, double volume)
{
	char *p_name = strdup(name);

	if (!p_name)
		return EXIT_FAILURE;

	item->name = p_name;
	item->weight = weight;
	item->volume = volume;

	return EXIT_SUCCESS;
}

int read_item(FILE *f, item_t *item)
{
	// Ввод названия
	char *buf_name = NULL;
	double buf_weight;
	double buf_volume;
	size_t len = 0;
	ssize_t read;

	if ((read = getline(&buf_name, &len, f)) == -1)
	{
		free(buf_name);
		return EXIT_FAILURE;	
	}

	if (read)
	{
		if (fscanf(f, "%lf\n%lf\n", &buf_weight, &buf_volume) != 2)
		{
			free(buf_name);
			return EXIT_FAILURE;
		}

		if (buf_weight - EPS < 0 || buf_volume - EPS < 0)
		{
			free(buf_name);
			return EXIT_FAILURE;
		}

		if (create_item(item, buf_name, buf_weight, buf_volume))
		{
			free(buf_name);
			return EXIT_FAILURE;
		}
	}

	free(buf_name);

	return EXIT_SUCCESS;
}

void free_item(item_t *item)
{
	free(item->name);
	item->name = NULL;
}

int count_items(FILE *f, size_t *count)
{
	*count = 0;
	item_t tmp = {
		.name = NULL,
		.weight = 0,
		.volume = 0
	};

	while (!read_item(f, &tmp))
	{
		*count += 1;

		free_item(&tmp);
	}

	if (*count == 0)
		return EXIT_FAILURE;

	if (!feof(f))
		return EXIT_FAILURE;

	fseek(f, 0, SEEK_SET);
	return EXIT_SUCCESS;
}

int create_data(FILE *f, items_t *data, const size_t len)
{
	data->array = calloc(len, sizeof(item_t));

	if (!data->array)
		return EXIT_FAILURE;

	data->len = len;

	for (size_t i = 0; i < len; i++)
		if (read_item(f, &(data->array[i])))
			return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

void free_data(items_t *data)
{
	for (size_t i = 0; i < data->len; i++)
		free_item(&(data->array[i]));

	free(data->array);
}

double calc_density(item_t item)
{
	return item.weight / item.volume;
}

void sort_data(items_t *items)
{
	item_t tmp_item = { 0 };
	double density_1 = 0;
	double density_2 = 0;

	for (size_t i = 0; i < items->len - 1; i++)
		for (size_t j = 0; j < items->len - i - 1; j++)
		{
			density_1 = calc_density(items->array[j]);
			density_2 = calc_density(items->array[j + 1]);

			if (density_1 > density_2)
			{
				tmp_item = items->array[j];
				items->array[j] = items->array[j + 1];
				items->array[j + 1] = tmp_item;
			}
		}
}
