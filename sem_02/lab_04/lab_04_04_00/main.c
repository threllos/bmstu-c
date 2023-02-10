#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

#define INPUT_ERROR 100
#define TOO_MANY_CHARS 200

int main(void)
{
    setbuf(stdout, NULL);
    
    str_t str;
    
    if (!(fgets(str, MAX_LEN_STR, stdin)))
        return INPUT_ERROR;
    
    int len = strlen(str);
    
    if (len > LEN_STR - 1)
        return TOO_MANY_CHARS;
    
    if (find_ip(str, len) == 1)
        printf("YES\n");
    else
        printf("NO\n");
    
    return EXIT_SUCCESS;
}