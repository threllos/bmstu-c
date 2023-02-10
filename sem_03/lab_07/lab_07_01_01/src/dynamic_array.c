#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../inc/dynamic_array.h"

int check_argv(const int argc, char **argv)
{
	if (argc < 3)
		return EXIT_FAILURE;
	else if (argc > 4)
		return EXIT_FAILURE;
	else if (argc == 4 && strcmp(argv[3], "f") != 0)
		return EXIT_FAILURE;
	else
		return EXIT_SUCCESS;
}

int count_len(FILE *f, size_t *len)
{
	if (!f)
		return EXIT_FAILURE;

	int tmp;
	int was_read = 1;
	*len = 0;

	while (was_read != EOF)
	{
		was_read = fscanf(f, "%d", &tmp);

		if (was_read == 1)
			*len += 1;
		else if (was_read == 0)
			return EXIT_FAILURE;
	}

	if (*len == 0)
		return EXIT_FAILURE;

	if (fseek(f, 0, SEEK_SET))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

int read_array(FILE *f, const int *pb_array, const int *pe_array)
{
	if (!pb_array || !pe_array)
		return EXIT_FAILURE;

	if (pb_array >= pe_array)
		return EXIT_FAILURE;

	if (!f)
		return EXIT_FAILURE;

	int tmp;

	for (int *p_i = (int *)pb_array; p_i < pe_array; p_i++)
	{
		if (fscanf(f, "%d", &tmp) == 1)
			*p_i = tmp;
		else
			return EXIT_FAILURE;
	}

	if (fseek(f, 0, SEEK_SET))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
	if (!pb_src || !pe_src)
		return EXIT_FAILURE;

	if (pb_src >= pe_src)
		return EXIT_FAILURE;

	int f_max = 1, f_min = 1;
	int *p_max, *p_min;
	int *p_left, *p_right;
	size_t len = 0;

	for (int *p_i = (int *)pb_src; p_i < pe_src; p_i++)
	{
		if (f_max || *p_i > *p_max)
		{
			p_max = p_i;
			f_max = 0;
		}
		if (f_min || *p_i < *p_min)
		{
			p_min = p_i;
			f_min = 0;
		}
	}

	if (p_min < p_max)
	{
		p_left = p_min + 1;
		p_right = p_max;
	}
	else
	{
		p_left = p_max + 1;
		p_right = p_min;
	}

	for (int *p_i = p_left; p_i < p_right; p_i++)
		len += 1;


	if (len == 0)
		return EXIT_FAILURE;

	*pb_dst = malloc(sizeof(int) * len);
	if (!*pb_dst)
		return EXIT_FAILURE;
	*pe_dst = *pb_dst + len;

	int *tmp_pb_dst = *pb_dst;
	for (int *p_i = p_left; p_i < p_right; p_i++, tmp_pb_dst++)
		*tmp_pb_dst = *p_i;

	return EXIT_SUCCESS;
}

int compare(const void *x1, const void *x2)
{
	return (*(int *)x1 - *(int *)x2);
}

void copy(char *src, char *dst, size_t size)
{
	for (size_t i = 0; i < size; i++)
		*(dst + i) = *(src + i);
}

void mysort(void *base, size_t nmemb, size_t size, int (*compare)(const void *, const void *))
{
	if (!base || !nmemb || !size || !compare)
		return;

	char *left, *right; // границы вставки
	char *mid;
	char *p_tmp;

	for (char *i = (char *)base + size; i < (char *)base + nmemb * size; i += size)
		if (compare(i - size, i) > 0)
		{	
			p_tmp = malloc(size);
			copy(i, p_tmp, size);

			// бинарный поиск
			left = base;
			right = i - size;
			do
			{
				mid = left + ((right - left) / size + 1) / 2 * size;

				if (compare(mid, p_tmp) < 0)
					left = mid + size;
				else
					right = mid - size;
			}
			while (left <= right);

			// сдвиг массива
			for (char *j = i - size; j >= left; j -= size)
				copy(j, j + size, size);

			copy(p_tmp, left, size);
			free(p_tmp);
		}
}

int write_array(FILE *f, const int *pb_array, const int *pe_array)
{
	if (!pb_array || !pe_array)
		return EXIT_FAILURE;

	if (pb_array >= pe_array)
		return EXIT_FAILURE;

	if (!f)
		return EXIT_FAILURE;

	for (int *p_i = (int *)pb_array; p_i < pe_array; p_i++)
		if (fprintf(f, "%d ", *p_i) < 0)
			return EXIT_FAILURE;
	
	return EXIT_SUCCESS;
}

