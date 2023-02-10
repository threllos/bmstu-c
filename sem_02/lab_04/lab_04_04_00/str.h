#ifndef _STR_H_
#define _STR_H_

#define MAX_LEN_STR 300
#define LEN_STR 257

typedef char str_t[MAX_LEN_STR];

int find_ip(str_t str, const int size);
int is_digit_ip(str_t str, size_t *i);
#endif