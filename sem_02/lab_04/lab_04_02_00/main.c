#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words.h"

#define INPUT_ERROR 100
#define TOO_MANY_CHARS 200
#define SPLIT_ERROR 300

void print_result(words_t words, array_t num, size_t len)
{
	for (size_t i = 0; i < len; i++)
		printf("%s %d\n", words[i], num[i]);
}

int main(void)
{
	setbuf(stdout, NULL);
	
	str_t str;
	words_t words;
	char sep[] = " ,;:-.!?\n";
    
	if (!(fgets(str, MAX_LEN_STR, stdin)))
		return INPUT_ERROR;
		
	if (strlen(str) > LEN_STR)
		return TOO_MANY_CHARS;
	
	size_t n = split(str, sep, words);
	if (n == 0)
		return SPLIT_ERROR;
	
	words_t arr_words;
	array_t arr_num = { 0 };
	size_t arr_len = count_word(words, n, arr_words, arr_num);
	
	printf("Result: ");
	print_result(arr_words, arr_num, arr_len);
	return EXIT_SUCCESS;
}



