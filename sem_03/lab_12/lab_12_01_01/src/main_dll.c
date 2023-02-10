#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define ARGV_ERROR 100
#define INPUT_FILE_ERROR 200
#define OUTPUT_FILE_ERROR 201
#define COUNT_LEN_ERROR 300
#define CREATE_ARRAY_ERROR 400
#define READ_ARRAY_ERROR 401
#define FILTER_ERROR 500
#define LIBRARY_ERROR 600

typedef int (__cdecl *fn_count_len_t) (FILE*, size_t*);
typedef int (__cdecl *fn_read_array_t) (FILE*, const int*, const int*);
typedef int (__cdecl *fn_key_len_t) (const int*, const int*, size_t*);
typedef int (__cdecl *fn_key_t) (const int*, const int*, int*);
typedef int (__cdecl *fn_compare_t) (const void*, const void*);
typedef void (__cdecl *fn_mysort_t) (void*, size_t, size_t, int (compare)(const void *, const void *));
typedef int (__cdecl *fn_write_array_t) (FILE*, const int*, const int*);

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);

	HMODULE hlib;
	fn_count_len_t count_len;
	fn_read_array_t read_array;
	fn_key_len_t key_len;
	fn_key_t key;
	fn_compare_t compare;
	fn_mysort_t mysort;
	fn_write_array_t write_array;

	hlib = LoadLibrary("arr.dll");
	if (hlib == NULL)
	{
		FreeLibrary(hlib);
		return LIBRARY_ERROR;
	}

	count_len = (fn_count_len_t) GetProcAddress(hlib, "count_len");
	if (count_len == NULL)
	{
		FreeLibrary(hlib);
		return LIBRARY_ERROR;
	}

	read_array = (fn_read_array_t) GetProcAddress(hlib, "read_array");
	if (read_array == NULL)
	{
		FreeLibrary(hlib);
		return LIBRARY_ERROR;
	}

	key_len = (fn_key_len_t) GetProcAddress(hlib, "key_len");
	if (key_len == NULL)
	{
		FreeLibrary(hlib);
		return LIBRARY_ERROR;
	}

	key = (fn_key_t) GetProcAddress(hlib, "key");
	if (key == NULL)
	{
		FreeLibrary(hlib);
		return LIBRARY_ERROR;
	}

	compare = (fn_compare_t) GetProcAddress(hlib, "compare");
	if (compare == NULL)
	{
		FreeLibrary(hlib);
		return LIBRARY_ERROR;
	}

	mysort = (fn_mysort_t) GetProcAddress(hlib, "mysort");
	if (mysort == NULL)
	{
		FreeLibrary(hlib);
		return LIBRARY_ERROR;
	}

	write_array = (fn_write_array_t) GetProcAddress(hlib, "write_array");
	if (write_array == NULL)
	{
		FreeLibrary(hlib);
		return LIBRARY_ERROR;
	}

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
		FreeLibrary(hlib);
		return COUNT_LEN_ERROR;
	}

	// выделение памяти под исходный массив
	pb_array = malloc(sizeof(int) * len);
	if (pb_array == NULL)
	{
		fclose(f_in);
		FreeLibrary(hlib);
		return CREATE_ARRAY_ERROR;
	}
	pe_array = pb_array + len;

	// считывание чисел из файла в исходный массив
	if (read_array(f_in, pb_array, pe_array))
	{
		fclose(f_in);
		free(pb_array);
		FreeLibrary(hlib);
		return READ_ARRAY_ERROR;
	}

	fclose(f_in);

	f_out = fopen(argv[2], "w");
	if (f_out == NULL)
	{
		free(pb_array);
		FreeLibrary(hlib);
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
			FreeLibrary(hlib);
			return FILTER_ERROR;
		}

		pb_result = malloc(sizeof(int) * result_len);
		if (pb_result == NULL)
		{
			fclose(f_out);
			free(pb_array);
			FreeLibrary(hlib);
			return FILTER_ERROR;
		}
		pe_result = pb_result + result_len;

		if (key(pb_array, pe_array, pb_result))
		{
			fclose(f_out);
			free(pb_array);
			free(pb_result);
			FreeLibrary(hlib);
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
	FreeLibrary(hlib);

	return EXIT_SUCCESS;
}
