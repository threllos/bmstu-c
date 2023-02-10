#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <stdlib.h>

char *my_strpbrk(const char str1[], const char str2[]);
size_t my_strspn(const char str1[], const char str2[]);
size_t my_strcspn(const char str1[], const char str2[]);
char *my_strchr(const char str[], int ch);
char *my_strrchr(const char str[], int ch);

#endif