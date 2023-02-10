#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct node
{
	int value;
	struct node *next;
} node_t;

typedef struct queue
{
	node_t *stack1;
	node_t *stack2;
} queue_t;

void init(queue_t *q);
void free_queue(queue_t *q);
int push(queue_t *q, int value);
int pop(queue_t	*q, int *value);
int peek(queue_t *q, int *value);
int fill(queue_t *q, size_t len, ...);

#endif // _QUEUE_H_