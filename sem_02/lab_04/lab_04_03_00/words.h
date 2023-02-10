#ifndef _WORDS_H_
#define _WORDS_H_

#define MAX_LEN_STR 300
#define LEN_STR 257
#define MAX_LEN_WORD 20
#define LEN_WORD 17

typedef char str_t[MAX_LEN_STR];
typedef char word_t[MAX_LEN_WORD];
typedef char *words_t[MAX_LEN_WORD];

int string_input(str_t str);
int split(str_t str, char sep[], words_t words, size_t *n_words);
int chars_del_duplicate(word_t word);
int is_equal_str(str_t str1, str_t str2);
int string_make_new(words_t words, size_t n_words, str_t str);

#endif
