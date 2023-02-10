#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamic_array_static.h"

#define ARGV_ERROR 100
#define INPUT_FILE_ERROR 200
#define OUTPUT_FILE_ERROR 201
#define COUNT_LEN_ERROR 300
#define CREATE_ARRAY_ERROR 400
#define READ_ARRAY_ERROR 401
#define FILTER_ERROR 500

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);

	FILE *f_in = NULL, *f_out = NULL;
	int *pb_array = NULL, *pe_array = NULL;
	size_t len = 0;

	// проверка ключей коммандной строки
	if (argc < 3)
		return ARGV_ERROR;
	else if (argc > 4)
		return ARGV_ERROR;
	else if (argc == 4 && strcmp(argv[3], "f") != 0)
		return ARGV_ERROR;

	f_in = fopen(argv[1], "r");
	if (f_in == NULL)
		return INPUT_FILE_ERROR;

	// подсчет количества элементов в файле
	if (count_len(f_in, &len))
	{
		fclose(f_in);
		return COUNT_LEN_ERROR;
	}

	// выделение памяти под исходный массив
	pb_array = malloc(sizeof(int) * len);
	if (pb_array == NULL)
	{
		fclose(f_in);
		return CREATE_ARRAY_ERROR;
	}
	pe_array = pb_array + len;

	// считывание чисел из файла в исходный массив
	if (read_array(f_in, pb_array, pe_array))
	{
		fclose(f_in);
		free(pb_array);
		return READ_ARRAY_ERROR;
	}

	fclose(f_in);

	f_out = fopen(argv[2], "w");
	if (f_out == NULL)
	{
		free(pb_array);
		return INPUT_FILE_ERROR;
	}

	if (argc == 4)
	{
		size_t result_len = 0;
		int *pb_result = NULL, *pe_result = NULL;
		
		// фильтрация исходного массива и 
		// выделение памяти под результирующий массив
		if (key_len(pb_array, pe_array, &result_len))
		{
			fclose(f_out);
			free(pb_array);
			return FILTER_ERROR;
		}

		pb_result = malloc(sizeof(int) * result_len);
		if (pb_result == NULL)
		{
			fclose(f_out);
			free(pb_array);
			return FILTER_ERROR;
		}
		pe_result = pb_result + result_len;

		if (key(pb_array, pe_array, pb_result))
		{
			fclose(f_out);
			free(pb_array);
			free(pb_result);
			return FILTER_ERROR;
		}

		// сортировка результирующего массива и вывод результата в файл
		mysort(pb_result, pe_result - pb_result, sizeof(int), compare);
		write_array(f_out, pb_result, pe_result);

		free(pb_result);
	}
	else
	{
		// сортировка исходного массива и вывод результата в файл
		mysort(pb_array, pe_array - pb_array, sizeof(int), compare);
		write_array(f_out, pb_array, pe_array);
	}

	fclose(f_out);
	free(pb_array);

	return EXIT_SUCCESS;
}
