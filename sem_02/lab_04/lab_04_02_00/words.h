#ifndef _WORDS_H_
#define _WORDS_H_

#include <stdlib.h>

#define MAX_LEN_STR 300
#define LEN_STR 257
#define WORD_COUNT 128
#define MAX_LEN_WORD 17

typedef char str_t[MAX_LEN_STR];
typedef char word_t[MAX_LEN_WORD];
typedef word_t words_t[WORD_COUNT];
typedef int array_t[WORD_COUNT];

int is_sep(char ch, char sep[]);
int equal_str(char str1[], char str2[]);
size_t split(str_t str, char sep[], words_t words);
size_t count_word(words_t words, size_t n, words_t a_words, array_t a_num);
#endif