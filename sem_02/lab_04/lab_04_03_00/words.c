#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words.h"

#define INPUT_ERROR 100
#define TOO_MANY_CHARS 200
#define EMPTY_STRING_ERROR 201
#define WORD_LEN_ERROR 300
#define NO_SOLUTION 400

int string_input(str_t str)
{
    if (!(fgets(str, MAX_LEN_STR, stdin)))
        return INPUT_ERROR;
    
    if (strlen(str) > LEN_STR)
        return TOO_MANY_CHARS;
    
    if (strlen(str) == 1)
        return EMPTY_STRING_ERROR;
    
    return EXIT_SUCCESS;
}

int split(str_t str, char sep[], words_t words, size_t *n_words)
{
    if ((words[0] = strtok(str, sep)) == NULL)
        return INPUT_ERROR;
    
    if (strlen(words[0]) > LEN_WORD)
        return WORD_LEN_ERROR;
    
    size_t i = 1;
    while (1)
    {
        if ((words[i] = strtok(NULL , sep)) == NULL)
            break;
    
        if (strlen(words[i]) > LEN_WORD)
            return WORD_LEN_ERROR;
    
        i += 1;
    }
    
    *n_words = i;
    return EXIT_SUCCESS;
}

int chars_del_duplicate(word_t word)
{
    word_t new_word;
    size_t j = 0;
    
    for (size_t i = 0; word[i]; i++)
        if (word[i] != word[0] || i == 0)
            new_word[j++] = word[i];
    
    new_word[j] = 0;
    strcpy(word, new_word);
    
    return 1;
}

int is_equal_str(str_t str1, str_t str2)
{
    if (strlen(str1) != strlen(str2))
        return 0;

    for (size_t i = 0; str1[i]; i++)
        if (str1[i] != str2[i])
            return 0;

    return 1;
}

int string_make_new(words_t words, size_t n_words, str_t str)
{
    if (n_words == 1)
        return NO_SOLUTION;
    
    int counter = 0;
    size_t k = 0;
    for (size_t i = 0; i < n_words - 1; i++)
    {
        if (is_equal_str(words[n_words - i - 2], words[n_words - 1]) == 0)
        {
            counter += chars_del_duplicate(words[n_words - i - 2]);
            str[k++] = ' ';
            for (size_t j = 0; words[n_words - i - 2][j]; j++)
                str[k++] = words[n_words - i - 2][j];
        }
    }
    
    str[k] = 0;
    if (counter == 0)
        return NO_SOLUTION;
    return EXIT_SUCCESS;
}