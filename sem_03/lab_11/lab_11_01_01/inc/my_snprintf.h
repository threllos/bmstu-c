#ifndef _MY_SNPRINTF_H_
#define _MY_SNPRINTF_H_

#include <stdlib.h>

#define ALPHABET_DEC "0123456789"
#define ALPHABET_OCT "01234567"
#define ALPHABET_HEX "0123456789abcdef"

int my_snprintf(char *s, size_t n, const char *format, ...);

#endif //_MY_SNPRINTF_H_