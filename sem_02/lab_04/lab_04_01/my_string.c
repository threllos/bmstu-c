#include <stddef.h>
#include "my_string.h"

char *my_strpbrk(const char str1[], const char str2[])
{
	for (size_t i = 0; str1[i]; i++)
		for (size_t j = 0; str2[j]; j++)
			if (str1[i] == str2[j])
				return (char *)&str1[i];
	return NULL;
}

size_t my_strspn(const char str1[], const char str2[])
{	
	size_t len = 0;
	for (size_t i = 0; str1[i]; i++)
	{
		int flag = 0;
		for (size_t j = 0; str2[j]; j++)
			if (str1[i] == str2[j])
				flag = 1;
		if (flag == 0)
			return len;
		else
			len += 1;
	}
	return len;
}

size_t my_strcspn(const char str1[], const char str2[])
{
	size_t i;
	for (i = 0; str1[i]; i++)
		for (size_t j = 0; str2[j]; j++)
			if (str1[i] == str2[j])
				return i;
	return i;
}

char *my_strchr(const char str[], int ch)
{
	size_t i;
	for (i = 0; str[i]; i++)
		if (str[i] == ch)
			return (char *) &str[i];
	if (str[i] == ch)
		return (char *) &str[i];
	return NULL;
}

char *my_strrchr(const char str[], int ch)
{
	char *result = NULL;
	size_t i;
	for (i = 0; str[i]; i++)
		if (str[i] == ch)
			result = (char *)&str[i];
	if (str[i] == ch)
		result = (char *)&str[i];
	return result;
}