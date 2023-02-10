#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void llog(node_t *head, char *str)
{
	node_t *p = head;

	printf("%s\n", str);
	if (!p)
		return;

	while (p)
	{
		printf("%02d.%02d.%4d\n", ((date_t*)p->data)->day, ((date_t*)p->data)->month, ((date_t*)p->data)->year);
		p = p->next;
	}
}

int date_check(date_t *date)
{
	if (date->year > 2021 || date->year < 1)
		return EXIT_FAILURE;

	if (date->month > 12 || date->month < 1)
		return EXIT_FAILURE;

	if (date->day < 1)
		return EXIT_FAILURE;

	if (date->month == 1 && date->day > 31)
		return EXIT_FAILURE;
	else if (date->month == 2 && date->year % 4 == 0 && date->day > 29)
		return EXIT_FAILURE;
	else if (date->month == 2 && date->day > 28)
		return EXIT_FAILURE;
	else if (date->month == 3 && date->day > 31)
		return EXIT_FAILURE;
	else if (date->month == 4 && date->day > 30)
		return EXIT_FAILURE;
	else if (date->month == 5 && date->day > 31)
		return EXIT_FAILURE;
	else if (date->month == 6 && date->day > 30)
		return EXIT_FAILURE;
	else if (date->month == 7 && date->day > 31)
		return EXIT_FAILURE;
	else if (date->month == 8 && date->day > 31)
		return EXIT_FAILURE;
	else if (date->month == 9 && date->day > 30)
		return EXIT_FAILURE;
	else if (date->month == 10 && date->day > 31)
		return EXIT_FAILURE;
	else if (date->month == 11 && date->day > 30)
		return EXIT_FAILURE;
	else if (date->month == 12 && date->day > 31)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

// Manager

int push(node_t **head, void *data)
{
	node_t *tmp = (node_t*) malloc(sizeof(node_t)); 

	if (!tmp)
		return EXIT_FAILURE;

	tmp->data = data;
	tmp->next = *head;
	*head = tmp;

	return EXIT_SUCCESS;
}

int read(FILE *f, storage_t *storage, node_t **head)
{
	date_t tmp;

	while (fscanf(f, "%d %d %d\n", &tmp.day, &tmp.month, &tmp.year) == 3)
	{
		storage->array[storage->len] = tmp;

		if (date_check(&(tmp)))
			return EXIT_FAILURE;

		push(head, &(storage->array[storage->len]));
		storage->len += 1;
	}

	if (!feof(f))
		return EXIT_FAILURE;

	if (storage->len == 0)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

void write(FILE *f, node_t *head)
{
	node_t *p = head;

	while (p)
	{
		fprintf(f, "%02d.%02d.%4d\n", ((date_t*)p->data)->day, ((date_t*)p->data)->month, ((date_t*)p->data)->year);
		p = p->next;
	}
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

// Functions

void *pop_front(node_t **head)
{
	if (!head || !(*head))
		return NULL;

	node_t *prev = NULL;
	void *result;

	prev = (*head);
	result = prev->data;
	(*head) = (*head)->next;
	free(prev);

	return result;
}

void insert(node_t **head, node_t *elem, node_t *before)
{
	if (!head || !elem)
		return;

	node_t *tmp = NULL;

	if (before == *head)
	{
		tmp = *head;
		*head = elem;
		elem->next = tmp;
		return;
	}

	node_t *p = *head;

	while (p)
	{
		if (before == p->next)
		{
			tmp = p->next;
			p->next = elem;
			elem->next = tmp;
		}

		p = p->next;
	}
}

void append(node_t **head_a, node_t **head_b)
{
	if (!head_a || !head_b)
		return;

	node_t *p = *head_a;
	node_t *tmp = *head_b;

	while (p)
	{
		if (p->next == NULL)
		{
			p->next = tmp;
			*head_b = NULL;
			return;
		}

		p = p->next;
	}

	*head_a = *head_b;
	*head_b = NULL;
}

int cmp(const void *a, const void *b)
{
	date_t *date_a = (date_t *) a;
	date_t *date_b = (date_t *) b;

	if (date_a->year > date_b->year)
		return 1;
	else if (date_a->year < date_b->year)
		return -1;
	else
	{
		if (date_a->month > date_b->month)
			return 1;
		else if (date_a->month < date_b->month)
			return -1;
		else
		{
			if (date_a->day > date_b->day)
				return 1;
			else if (date_a->day < date_b->day)
				return -1;
			else
				return 0;
		}
	}
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
	if (!head || !element || !comparator)
		return;

	if (*head == NULL)
	{
		*head = element;
		element->next = NULL;
		return;
	}

	node_t *p = *head;

	while (p)
	{
		if (comparator(p->data, element->data) > 0)
		{
			insert(head, element, p);
			return;
		}

		p = p->next;
	}

	insert(head, element, NULL);
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
	if (!comparator || !head)
		return NULL;

	node_t *result = NULL;
	node_t *p = head;

	while (p)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = p->data;
		sorted_insert(&result, tmp, comparator);
		p = p->next;
	}

	return result;
}