#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "words.h"

int is_sep(char ch, char sep[])
{
    for (size_t i = 0; sep[i]; i++)
        if (sep[i] == ch)
            return 1;
    return 0;
}

int equal_str(char str1[], char str2[])
{
    if (strlen(str1) != strlen(str2))
        return 0;

    for (size_t i = 0; str1[i]; i++)
        if (str1[i] != str2[i])
            return 0;

    return 1;
}

size_t split(str_t str, char sep[], words_t words)
{
    size_t i = 0, j = 0, k = 0;
    size_t n = 0;
    words[0][0] = 0;
    int flag = 0;
    int word_len = 0;
    
    while (str[k])
    {
        if (is_sep(str[k], sep) == 0)
        {
            words[i][j++] = str[k];
            flag = 1;
            word_len += 1;
        }
        else if (flag == 1)
        {
            if (word_len > MAX_LEN_WORD)
                return 0;
                
            words[i++][j] = 0;
            j = 0;
            n += 1;
            flag = 0;
            word_len = 0;
        }
        k += 1;
    }
    words[i][j] = 0;

    return n;
}

size_t count_word(words_t words, size_t n, words_t a_words, array_t a_num)
{
    size_t arr_len = 0;
    for (size_t i = 0; i < n; i++)
    {
        int first_occur = 0;
        
        for (size_t j = 0; j < arr_len; j++)
            if (equal_str(words[i], a_words[j]) == 1)
            {
                first_occur = 1;
                a_num[j] += 1;
            }

        if (first_occur == 0)
        {
            strcpy(a_words[arr_len], words[i]);
            a_num[arr_len] += 1;
            arr_len += 1;
        }
    }
    return arr_len;
}