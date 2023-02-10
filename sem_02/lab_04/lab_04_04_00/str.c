#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "str.h"

#define ALL_SYMBOLS "0123456789."
#define ALL_DIGS "0123456789"

int is_digit_ip(str_t str, size_t *pos)
{
	size_t curr_pos = *pos;
	char tmp[4];
	
	if (strchr(ALL_DIGS, str[curr_pos]) == NULL)
		return 0;
	
	size_t j = 0;
	while (strchr(ALL_DIGS, str[curr_pos]) != NULL)
	{
		if (j == 3)
		{
			*pos = curr_pos;
			return 0;
		}
		
		tmp[j] = str[curr_pos];
		j += 1;
		curr_pos += 1;
	}
	
	tmp[j] = '\0';
	*pos = curr_pos;
	int num = atoi(tmp);
	
	if (num > 255)
		return 0;
		
	return 1;
}

int find_ip(str_t str, const int size)
{
	size_t i = 0;
	
	while (strchr(" \t", str[i]) != NULL)
		i++;

	for (int j = i; j < size - 1; j++)
		if (strchr(ALL_SYMBOLS, str[j]) == NULL &&
			strchr(ALL_SYMBOLS, str[j + 1]) != NULL)
			return 0;
		
	if (is_digit_ip(str, &i) == 0)
		return 0;
		
	if (str[i] != '.')
		return 0;
	i += 1;
	
	if (is_digit_ip(str, &i) == 0)
		return 0;
	
	if (str[i] != '.')
		return 0;
	i += 1;
	
	if (is_digit_ip(str, &i) == 0)
		return 0;
		
	if (str[i] != '.')
		return 0;
	i += 1;
	
	if (is_digit_ip(str, &i) == 0)
		return 0;
		
	if (strchr("\n\t ", str[i]) || str[i] == '\0')
		return 1;
	return 0;
}