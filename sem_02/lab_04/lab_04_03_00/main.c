#include <stdio.h>
#include <stdlib.h>
#include "words.h"

int main(void)
{
    setbuf(stdout, NULL);

    int rc;
    str_t str;
    str_t new_str;
    words_t words;
    size_t n_words;
    char sep[] = " ,;:-.!?\n";
    
    rc = string_input(str);
    
    if (rc == 0)
        rc = split(str, sep, words, &n_words);
    
    if (rc == 0)
        rc = string_make_new(words, n_words, new_str);
    
    if (rc == 0)
        printf("Result:%s\n", new_str);
    
    return rc;
}