#ifndef _LIST_H_
#define _LIST_H_

typedef struct date
{
	int day;
	int month;
	int year;
} date_t;

typedef struct storage
{
	date_t array[50];
	size_t len;
} storage_t;

typedef struct node node_t;

struct node
{
	void *data;
	node_t *next;
};

int read(FILE *f, storage_t *storage, node_t **head);
void write(FILE *f, node_t *head);
void free_list(node_t **head);

void *pop_front(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);
void append(node_t **head_a, node_t **head_b);
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void sorted_insert(node_t **head, node_t *element,
int (*comparator)(const void *, const void *));

int cmp(const void *a, const void *b);

void llog(node_t *head, char *str);
#endif //_LIST_H_