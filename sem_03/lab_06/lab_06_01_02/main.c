#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

#define ARGC_ERROR 100
#define NO_FILE_ERROR 200
#define READ_FILE_ERROR 201

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);

	FILE *f;
	items_t data;

	if (argc < 2 || argc > 3)
		return ARGC_ERROR;

	f = fopen(argv[1], "r");

	if (f == NULL)
		return NO_FILE_ERROR;

	if (make_array(f, &data))
	{
		fclose(f);
		return READ_FILE_ERROR;
	}

	fclose(f);

	if (argc == 2)
	{
		sort_array(&data);
		write_items(data);
	}
	else if (!strcmp(argv[2], "ALL"))
		write_items(data);
	else
		write_items_by_str(data, argv[2]);

	return EXIT_SUCCESS;
}
