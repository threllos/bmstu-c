#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define ARGC_ERR 100
#define READ_ERR 101
#define POP_FRONT_ERR 200
#define SORT_ERR 201

// app.exe pf in.txt out.txt
// app.exe i in_head.txt in_elem.txt out.txt
// app.exe a head_1.txt head_2.txt out.txt
// app.exe s in.txt out.txt
int main(int argc, char **argv)
{
	setbuf(stdout, NULL);

	FILE *f_in_1, *f_out;
	storage_t storage = { .len = 0 };
	node_t *head_1 = NULL;

	if (argc > 5 || argc < 4)
		return ARGC_ERR;

	if (!strcmp(argv[1], "pf") && argc == 4)
	{
		f_in_1 = fopen(argv[2], "r");

		if (read(f_in_1, &storage, &head_1))
		{
			free_list(&head_1);
			fclose(f_in_1);
			return READ_ERR;
		}

		if (!pop_front(&head_1))
		{
			free_list(&head_1);
			fclose(f_in_1);
			return POP_FRONT_ERR;
		}

		f_out = fopen(argv[3], "w");
		write(f_out, head_1);

		free_list(&head_1);
		fclose(f_in_1);
		fclose(f_out);
	}
	else if (!strcmp(argv[1], "a") && argc == 5)
	{
		FILE *f_in_2;
		node_t *head_2 = NULL;

		f_in_1 = fopen(argv[2], "r");
		if (read(f_in_1, &storage, &head_1))
		{
			free_list(&head_1);
			fclose(f_in_1);
			return READ_ERR;
		}

		f_in_2 = fopen(argv[3], "r");
		if (read(f_in_2, &storage, &head_2))
		{
			free_list(&head_1);
			free_list(&head_2);
			fclose(f_in_1);
			fclose(f_in_2);
			return READ_ERR;
		}

		append(&head_1, &head_2);

		f_out = fopen(argv[4], "w");
		write(f_out, head_1);

		free_list(&head_1);
		free_list(&head_2);
		fclose(f_in_1);
		fclose(f_in_2);
		fclose(f_out);
	}
	else if (!strcmp(argv[1], "s") && argc == 4)
	{
		node_t *sorted = NULL;

		f_in_1 = fopen(argv[2], "r");
		if (read(f_in_1, &storage, &head_1))
		{
			free_list(&head_1);
			fclose(f_in_1);
			return READ_ERR;
		}

		sorted = sort(head_1, cmp);

		if (!sorted)
		{
			free_list(&head_1);
			fclose(f_in_1);
			return SORT_ERR;
		}
		
		f_out = fopen(argv[3], "w");
		write(f_out, sorted);

		free_list(&head_1);
		free_list(&sorted);
		fclose(f_in_1);
		fclose(f_out);
	}
	else
		return ARGC_ERR;

	return EXIT_SUCCESS;
}
