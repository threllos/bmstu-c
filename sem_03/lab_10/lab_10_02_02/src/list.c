#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

void llog(node_t *head, char *str)
{
	node_t *p = head;

	printf("%s\n", str);
	if (!p)
		return;

	while (p)
	{
		printf("%d\n", p->ratio);
		p = p->next;
	}
}

// Manager

int input_command(char *str)
{
	if (!fgets(str, MAX_STR_LEN, stdin))
		return EXIT_FAILURE;

	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = 0;
	else
		return EXIT_FAILURE;

	if (strlen(str) != 3)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

int push(node_t **head, int ratio)
{
	node_t *tmp = (node_t*) malloc(sizeof(node_t)); 

	if (!tmp)
		return EXIT_FAILURE;

	tmp->ratio = ratio;
	tmp->next = *head;
	*head = tmp;

	return EXIT_SUCCESS;
}

int input_list(node_t **head)
{
	int n;

	if (scanf("%d", &n) != 1)
		return EXIT_FAILURE;

	if (n < 1)
		return EXIT_FAILURE;

	for (size_t i = 0; i < (size_t) n; i++)
	{
		int ratio;

		if (scanf("%d", &ratio) != 1)
			return EXIT_FAILURE;

		if (push(head, ratio))
			return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void free_list(node_t **head)
{
	node_t *prev = NULL;

	if (!*head)
		return;

	while ((*head)->next)
	{
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}

	free(*head);
}

void write(node_t *head)
{
	node_t *p = head;

	while (p)
	{
		printf("%d ", p->ratio);

		p = p->next;
	}

	printf("L\n");
}

// Operations

int val(node_t *head, int a)
{
	if (head->next == NULL)
		return head->ratio;
	else
		return head->ratio + a * val(head->next, a);
}

node_t *ddx(node_t *head)
{
	node_t *result = NULL;
	size_t i = 0;

	node_t *p = head;

	while (p)
	{
		if (i > 0)
			if (push(&result, i * p->ratio))
				return NULL;

		i += 1;
		p = p->next;
	}

	return result;
}

node_t *sum(node_t *head_1, node_t *head_2)
{
	node_t *result = NULL;

	node_t *p_1 = head_1;
	node_t *p_2 = head_2;

	while (p_1 && p_2)
	{
		if (push(&result, p_1->ratio + p_2->ratio))
			return NULL;

		p_1 = p_1->next;
		p_2 = p_2->next;
	}

	if (p_1)
		while (p_1)
		{
			if (push(&result, p_1->ratio))
				return NULL;

			p_1 = p_1->next;
		}

	if (p_2)
		while (p_2)
		{
			if (push(&result, p_2->ratio))
				return NULL;

			p_2 = p_2->next;
		}

	return result;
}

void dvd(node_t *head, node_t **head_even, node_t **head_odd)
{
	node_t *p = head;
	size_t i = 0;

	while (p)
	{
		if (i % 2 == 0)
		{
			if (push(head_even, p->ratio))
			{
				*head_even = NULL;
				*head_odd = NULL;
				return;
			}
		}
		else
		{
			if (push(head_odd, p->ratio))
			{
				*head_even = NULL;
				*head_odd = NULL;
				return;
			}
		}

		i += 1;
		p = p->next;
	}
}