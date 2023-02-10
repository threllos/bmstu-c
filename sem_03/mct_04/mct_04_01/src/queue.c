#include <stdlib.h>
#include <stdarg.h>
#include "queue.h"

void init(queue_t *q)
{
	q->stack1 = NULL;
	q->stack2 = NULL;
}

int push_stack(node_t **stack, int value)
{
	node_t *tmp = (node_t*) malloc(sizeof(node_t));

	if (!tmp)
		return EXIT_FAILURE;

	tmp->value = value;
	tmp->next = *stack;
	*stack = tmp;

	return EXIT_SUCCESS;
}

int pop_stack(node_t **stack)
{
	node_t *prev = *stack;
	int value = prev->value;

	*stack = (*stack)->next;

	free(prev);

	return value;
}

int push(queue_t *q, int value)
{
	if (push_stack(&(q->stack1), value))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

int pop(queue_t	*q, int *value)
{
	if (!q)
		return EXIT_FAILURE;

	if (!q->stack1 && !q->stack2)
		return EXIT_FAILURE;

	if (!q->stack2)
	{
		int tmp;

		while (q->stack1)
		{
			tmp = pop_stack(&(q->stack1));
			push_stack(&(q->stack2), tmp);
		}
	}

	*value = pop_stack(&(q->stack2));

	return EXIT_SUCCESS;
}

int peek(queue_t *q, int *value)
{
	if (!q)
		return EXIT_FAILURE;

	if (!q->stack1 && !q->stack2)
		return EXIT_FAILURE;

	if (!q->stack2)
	{
		int tmp;

		while (q->stack1)
		{
			tmp = pop_stack(&(q->stack1));
			push_stack(&(q->stack2), tmp);
		}
	}

	*value = q->stack2->value;

	return EXIT_FAILURE;
}

int fill(queue_t *q, size_t len, ...)
{
	va_list args;
	va_start(args, len);

	for (size_t i = 0; i < len; i++)
		if (push_stack(&(q->stack1), va_arg(args, int)))
		{
			va_end(args);
			return EXIT_FAILURE;
		}

	va_end(args);
	return EXIT_SUCCESS;
}

void free_queue(queue_t *q)
{
	node_t *tmp;

   	while (q->stack1)
    {
		tmp = q->stack1;
       	q->stack1 = q->stack1->next;
       	free(tmp);
    }

    while (q->stack2)
    {
		tmp = q->stack2;
       	q->stack2 = q->stack2->next;
       	free(tmp);
    }
}