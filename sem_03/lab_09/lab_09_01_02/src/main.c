#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

#define ARGC_ERROR 100
#define NO_FILE_ERROR 200
#define COUNT_DATA_ERROR 300
#define CREATE_DATA_ERROR 301

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);

	FILE *f;
	items_t data;
	size_t count;

	if (argc < 2 || argc > 3)
		return ARGC_ERROR;

	f = fopen(argv[1], "r");

	if (!f)
		return NO_FILE_ERROR;

	if (count_items(f, &count))
	{
		fclose(f);
		return COUNT_DATA_ERROR;
	}
	
	if (create_data(f, &data, count))
	{
		fclose(f);
		return CREATE_DATA_ERROR;
	}

	fclose(f);

	if (argc == 2)
	{
		sort_data(&data);
		write_items(data);
	}
	else if (!strcmp(argv[2], "ALL"))
		write_items(data);
	else
		write_items_by_str(data, argv[2]);

	free_data(&data);

	return EXIT_SUCCESS;
}