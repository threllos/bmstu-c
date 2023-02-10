#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define INPUT_COMMAND_ERR 100
#define COMMAND_ERR 101
#define INPUT_A_ERR 102
#define INPUT_LIST_ERR 103
#define DDX_ERR 200
#define SUM_ERR 201
#define DVD_ERR 202

int main(void)
{
	setbuf(stdout, NULL);

	char command[5];

	if (input_command(command))
		return INPUT_COMMAND_ERR;

	if (!strcmp(command, "val"))
	{
		node_t *head = NULL;

		if (input_list(&head))
		{
			free_list(&head);
			return INPUT_LIST_ERR;
		}

		int a;
		if (scanf("%d", &a) != 1)
			return INPUT_A_ERR;

		int result = val(head, a);

		printf("%d\n", result);

		free_list(&head);
	}
	else if (!strcmp(command, "ddx"))
	{
		node_t *head = NULL;

		if (input_list(&head))
		{
			free_list(&head);
			return INPUT_LIST_ERR;
		}

		node_t *result = ddx(head);

		if (!result)
		{
			free_list(&head);
			return DDX_ERR;
		}

		write(result);

		free_list(&result);
		free_list(&head);
	}
	else if (!strcmp(command, "sum"))
	{
		node_t *head_1 = NULL, *head_2 = NULL;

		if (input_list(&head_1))
		{
			free_list(&head_1);
			return INPUT_LIST_ERR;
		}

		if (input_list(&head_2))
		{
			free_list(&head_1);
			free_list(&head_2);
			return INPUT_LIST_ERR;
		}

		node_t *result = sum(head_1, head_2);

		if (!result)
		{
			free_list(&head_1);
			free_list(&head_2);
			return SUM_ERR;
		}

		write(result);

		free_list(&result);
		free_list(&head_1);
		free_list(&head_2);
	}
	else if (!strcmp(command, "dvd"))
	{
		node_t *head = NULL;
		node_t *head_even = NULL, *head_odd = NULL;

		if (input_list(&head))
		{
			free_list(&head);
			return INPUT_LIST_ERR;
		}

		dvd(head, &head_even, &head_odd);

		if (!head_even && !head_odd)
		{
			free_list(&head);
			return DVD_ERR;
		}

		if (head_even)
			write(head_even);
		if (head_odd)
			write(head_odd);

		free_list(&head);
		free_list(&head_even);
		free_list(&head_odd);
	}
	else
		return COMMAND_ERR;

	return EXIT_SUCCESS;
}
