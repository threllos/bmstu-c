#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(void)
{
	setbuf(stdout, NULL);

	queue_t queue;
	int val;

	init(&queue);
	fill(&queue, 3, 1, 2, 3);
	pop(&queue, &val)
	push(&queue, 4);

	printf("value - %d\n", val);

	printf("STACK 1\n");
	node_t *p = queue.stack1;
	while (p)
	{
		printf("%d\n", p->value);
		p = p->next;
	}

	printf("STACK 2\n");
	p = queue.stack2;
	while (p)
	{
		printf("%d\n", p->value);
		p = p->next;
	}

	free_queue(&queue);

	return EXIT_SUCCESS;
}