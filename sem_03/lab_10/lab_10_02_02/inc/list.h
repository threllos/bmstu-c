#ifndef _LIST_H_
#define _LIST_H_

#define MAX_STR_LEN 5
#define STR_LEN 3

typedef struct node node_t;

struct node
{
	int ratio;
	node_t *next;
};

void llog(node_t *head, char *str);

int input_list(node_t **head);
int input_command(char *str);
void free_list(node_t **head);
void write(node_t *head);
int push(node_t **head, int ratio);

int val(node_t *head, int a);
node_t *ddx(node_t *haed);
node_t *sum(node_t *head_1, node_t *head_2);
void dvd(node_t *head, node_t **head_even, node_t **haed_odd);

#endif //_LIST_H_