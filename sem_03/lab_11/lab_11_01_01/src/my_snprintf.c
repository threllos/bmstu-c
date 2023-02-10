#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my_snprintf.h"

size_t len_str(char *s)
{
	size_t len = 0;

	while (*s++)
		len += 1;

	return len;
}

int len_signed(int num, size_t base)
{
	if (num == 0)
		return 1;

	int len = 0;

	while (num != 0)
	{
		len += 1;
		num /= (int) base;
	}

	return len;
}


int len_signed_long(long num, size_t base)
{
	if (num == 0)
		return 1;

	int len = 0;

	while (num != 0)
	{
		len += 1;
		num /= (int) base;
	}

	return len;
}


int len_signed_short(short num, size_t base)
{
	if (num == 0)
		return 1;

	int len = 0;

	while (num != 0)
	{
		len += 1;
		num /= (int) base;
	}

	return len;
}

int len_unsigned(unsigned int num, size_t base)
{
	if (num == 0)
		return 1;

	int len = 0;

	while (num != 0)
	{
		len += 1;
		num /= (int) base;
	}

	return len;
}

int len_unsigned_long(unsigned long num, size_t base)
{
	if (num == 0)
		return 1;

	int len = 0;

	while (num != 0)
	{
		len += 1;
		num /= (int) base;
	}

	return len;
}

int len_unsigned_short(unsigned short num, size_t base)
{
	if (num == 0)
		return 1;

	int len = 0;

	while (num != 0)
	{
		len += 1;
		num /= (int) base;
	}

	return len;
}

size_t insert_signed(char *s, size_t max_size, size_t curr_size, int number, char *alphabet)
{
	int base = len_str(alphabet);
	size_t len_number = len_signed(number, base);
	int neg_flag = 0;
	size_t len_insert;

	if (number < 0)
		neg_flag = -1;

	len_number -= neg_flag;

	if (curr_size > max_size)
		len_insert = 0;
	else if (curr_size + len_number > max_size)
		len_insert = max_size - curr_size;
	else
		len_insert = len_number;

	for (size_t i = 0; i < len_number - len_insert; i++)
		number /= base;

	char *reverse = s + len_insert - 1;

	for (size_t i = 0; i < len_insert; i++)
	{
		if (neg_flag)
			*(reverse - i) = alphabet[(number % base) * neg_flag];
		else
			*(reverse - i) = alphabet[(number % base)];

		number /= base;
	}

	if (neg_flag && len_insert > 0)
		*s = '-';

	return len_number;
}

size_t insert_signed_long(char *s, size_t max_size, size_t curr_size, long number, char *alphabet)
{
	int base = len_str(alphabet);
	size_t len_number = len_signed_long(number, base);
	int neg_flag = 0;
	size_t len_insert;

	if (number < 0)
		neg_flag = -1;

	len_number -= neg_flag;

	if (curr_size > max_size)
		len_insert = 0;
	else if (curr_size + len_number > max_size)
		len_insert = max_size - curr_size;
	else
		len_insert = len_number;

	for (size_t i = 0; i < len_number - len_insert; i++)
		number /= base;

	char *reverse = s + len_insert - 1;

	for (size_t i = 0; i < len_insert; i++)
	{
		if (neg_flag)
			*(reverse - i) = alphabet[(number % base) * neg_flag];
		else
			*(reverse - i) = alphabet[(number % base)];

		number /= base;
	}

	if (neg_flag && len_insert > 0)
		*s = '-';

	return len_number;
}

size_t insert_signed_short(char *s, size_t max_size, size_t curr_size, short number, char *alphabet)
{
	int base = len_str(alphabet);
	size_t len_number = len_signed_short(number, base);
	int neg_flag = 0;
	size_t len_insert;

	if (number < 0)
		neg_flag = -1;

	len_number -= neg_flag;

	if (curr_size > max_size)
		len_insert = 0;
	else if (curr_size + len_number > max_size)
		len_insert = max_size - curr_size;
	else
		len_insert = len_number;

	for (size_t i = 0; i < len_number - len_insert; i++)
		number /= base;

	char *reverse = s + len_insert - 1;

	for (size_t i = 0; i < len_insert; i++)
	{
		if (neg_flag)
			*(reverse - i) = alphabet[(number % base) * neg_flag];
		else
			*(reverse - i) = alphabet[(number % base)];

		number /= base;
	}

	if (neg_flag && len_insert > 0)
		*s = '-';

	return len_number;
}

size_t insert_unsigned(char *s, size_t max_size, size_t curr_size, unsigned int number, char *alphabet)
{
	int base = len_str(alphabet);
	size_t len_number = len_unsigned(number, base);
	size_t len_insert;

	if (curr_size > max_size)
		len_insert = 0;
	else if (curr_size + len_number > max_size)
		len_insert = max_size - curr_size;
	else
		len_insert = len_number;

	for (size_t i = 0; i < len_number - len_insert; i++)
		number /= base;

	char *reverse = s + len_insert - 1;

	for (size_t i = 0; i < len_insert; i++)
	{
		*(reverse - i) = alphabet[number % base];

		number /= base;
	}

	return len_number;
}

size_t insert_unsigned_long(char *s, size_t max_size, size_t curr_size, unsigned long number, char *alphabet)
{
	int base = len_str(alphabet);
	size_t len_number = len_unsigned_long(number, base);
	size_t len_insert;

	if (curr_size > max_size)
		len_insert = 0;
	else if (curr_size + len_number > max_size)
		len_insert = max_size - curr_size;
	else
		len_insert = len_number;

	for (size_t i = 0; i < len_number - len_insert; i++)
		number /= base;

	char *reverse = s + len_insert - 1;

	for (size_t i = 0; i < len_insert; i++)
	{
		*(reverse - i) = alphabet[number % base];

		number /= base;
	}

	return len_number;
}

size_t insert_unsigned_short(char *s, size_t max_size, size_t curr_size, unsigned short number, char *alphabet)
{
	int base = len_str(alphabet);
	size_t len_number = len_unsigned_short(number, base);
	size_t len_insert;

	if (curr_size > max_size)
		len_insert = 0;
	else if (curr_size + len_number > max_size)
		len_insert = max_size - curr_size;
	else
		len_insert = len_number;

	for (size_t i = 0; i < len_number - len_insert; i++)
		number /= base;

	char *reverse = s + len_insert - 1;

	for (size_t i = 0; i < len_insert; i++)
	{
		*(reverse - i) = alphabet[number % base];

		number /= base;
	}

	return len_number;
}

int insert_str(char *s, size_t max_size, size_t curr_size, char *str)
{
	size_t len = len_str(str);
	size_t len_insert;

	if (curr_size > max_size)
		len_insert = 0;
	else if (curr_size + len > max_size)
		len_insert = max_size - curr_size;
	else
		len_insert = len;

	for (size_t i = 0; i < len_insert; i++)
		s[i] = str[i];

	return len;
}

// d i o x c s
int my_snprintf(char *s, size_t n, const char *format, ...)
{
	va_list args;
	size_t size = 0;
	size_t size_append = 0;
	size_t format_append = 0;

	if (n == 0)
		n = 1;

	if (s == NULL)
	{
		char tmp[100];
		s = tmp;
	}

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			if (size < n - 1)
				s[size] = *format;

			size_append = 1;
			format_append = 1;
		}
		else
		{
			if (*(format + 1) == '%')
			{
				s[size] = '%';
				size_append = 1;
				format_append = 2;
			}
			if (*(format + 1) == 'd' || *(format + 1) == 'i')
			{
				size_append = insert_signed(s + size, n - 1, size, va_arg(args, int), ALPHABET_DEC);
				format_append = 2;
			}
			else if (*(format + 1) == 'o')
			{
				size_append = insert_unsigned(s + size, n - 1, size, va_arg(args, unsigned int), ALPHABET_OCT);
				format_append = 2;
			}
			else if (*(format + 1) == 'x')
			{
				size_append = insert_unsigned(s + size, n - 1, size, va_arg(args, unsigned int), ALPHABET_HEX);
				format_append = 2;
			}
			else if (*(format + 1) == 'c')
			{
				s[size] = va_arg(args, int);
				size_append = 1;
				format_append = 2;
			}
			else if (*(format + 1) == 's')
			{
				size_append = insert_str(s + size, n - 1, size, va_arg(args, char *));
				format_append = 2;
			}
			else if (*(format + 1) == 'l' && (*(format + 2) == 'd' || *(format + 2) == 'i'))
			{
				size_append = insert_signed_long(s + size, n - 1, size, va_arg(args, long), ALPHABET_DEC);
				format_append = 3;
			}
			else if (*(format + 1) == 'l' && *(format + 2) == 'o')
			{
				size_append = insert_unsigned_long(s + size, n - 1, size, va_arg(args, unsigned long), ALPHABET_OCT);
				format_append = 3;
			}
			else if (*(format + 1) == 'l' && *(format + 2) == 'x')
			{
				size_append = insert_unsigned_long(s + size, n - 1, size, va_arg(args, unsigned long), ALPHABET_HEX);
				format_append = 3;
			}
			else if (*(format + 1) == 'h' && (*(format + 2) == 'd' || *(format + 2) == 'i'))
			{
				size_append = insert_signed_short(s + size, n - 1, size, va_arg(args, long), ALPHABET_DEC);
				format_append = 3;
			}
			else if (*(format + 1) == 'h' && *(format + 2) == 'o')
			{
				size_append = insert_unsigned_short(s + size, n - 1, size, va_arg(args, unsigned long), ALPHABET_OCT);
				format_append = 3;
			}
			else if (*(format + 1) == 'h' && *(format + 2) == 'x')
			{
				size_append = insert_unsigned_short(s + size, n - 1, size, va_arg(args, unsigned long), ALPHABET_HEX);
				format_append = 3;
			}
		}

		format += format_append;
		size += size_append;
	}
	
	va_end(args);

	if (size >= n)
		s[n - 1] = 0;
	else
		s[size] = 0;

	return size;
}
