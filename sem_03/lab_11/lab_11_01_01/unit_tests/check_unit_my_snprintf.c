#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "my_snprintf.h"

// POS TESTS

START_TEST(test_specifier_d_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%d", 13);
	reference_result = snprintf(reference_str, size - 1, "%d", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_d_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%d %d %d", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%d %d %d", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_d_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%d%d%d", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%d%d%d", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_d_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %d asd", 13);
	reference_result = snprintf(reference_str, size - 1, "asd - %d asd", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_d_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%d is digit", 12345);
	reference_result = snprintf(reference_str, size, "%d is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_d_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%d is digit", 12345);
	reference_result = snprintf(reference_str, size, "%d is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_d_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%d is digit", 12345);
	reference_result = snprintf(reference_str, size, "%d is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_d_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%d is digit", 12345);
	reference_result = snprintf(reference_str, size, "%d is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_i_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%i", 13);
	reference_result = snprintf(reference_str, size - 1, "%i", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_i_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%i %i %i", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%i %i %i", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_i_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%i%i%i", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%i%i%i", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_i_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %i asd", 13);
	reference_result = snprintf(reference_str, size - 1, "asd - %i asd", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_i_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%i is digit", 12345);
	reference_result = snprintf(reference_str, size, "%i is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_i_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%i is digit", 12345);
	reference_result = snprintf(reference_str, size, "%i is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_i_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%i is digit", 12345);
	reference_result = snprintf(reference_str, size, "%i is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_i_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%i is digit", 12345);
	reference_result = snprintf(reference_str, size, "%i is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_o_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%o", 13);
	reference_result = snprintf(reference_str, size - 1, "%o", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_o_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%o %o %o", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%o %o %o", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_o_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%o%o%o", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%o%o%o", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_o_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %o asd", 13);
	reference_result = snprintf(reference_str, size - 1, "asd - %o asd", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_o_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%o is digit", 012345);
	reference_result = snprintf(reference_str, size, "%o is digit", 012345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_o_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%o is digit", 012345);
	reference_result = snprintf(reference_str, size, "%o is digit", 012345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_o_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%o is digit", 012345);
	reference_result = snprintf(reference_str, size, "%o is digit", 012345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_o_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%o is digit", 12345);
	reference_result = snprintf(reference_str, size, "%o is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_x_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%x", 13);
	reference_result = snprintf(reference_str, size - 1, "%x", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_x_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%x %x %x", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%x %x %x", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_x_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%x%x%x", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%x%x%x", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_x_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %x asd", 13);
	reference_result = snprintf(reference_str, size - 1, "asd - %x asd", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_x_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%x is digit", 0x12345);
	reference_result = snprintf(reference_str, size, "%x is digit", 0x12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_x_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%x is digit", 0x12345);
	reference_result = snprintf(reference_str, size, "%x is digit", 0x12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_x_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%x is digit", 0x12345);
	reference_result = snprintf(reference_str, size, "%x is digit", 0x12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_x_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%x is digit", 12345);
	reference_result = snprintf(reference_str, size, "%x is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_c_only_1_symbol)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%c", 'a');
	reference_result = snprintf(reference_str, size - 1, "%c", 'a');

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_c_some_symbols_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%c %c %c", 'a', 'b', 'c');
	reference_result = snprintf(reference_str, size - 1, "%c %c %c", 'a', 'b', 'c');

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_c_some_symbols_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%c%c%c", 'a', 'b', 'c');
	reference_result = snprintf(reference_str, size - 1, "%c%c%c", 'a', 'b', 'c');

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_c_symbol_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %c asd", 'a');
	reference_result = snprintf(reference_str, size - 1, "asd - %c asd", 'a');

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_c_size_equal)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size, "%c is symb", 'a');
	reference_result = snprintf(reference_str, size, "%c is symb", 'a');

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_c_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%c is symb", 'a');
	reference_result = snprintf(reference_str, size, "%c is symb", 'a');

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_c_size_less)
{
	char str[5] = { 0 }, reference_str[5] = { 0 };
	size_t size = 5;
	int result, reference_result;

	result = my_snprintf(str, size, "%c is symb", 'a');
	reference_result = snprintf(reference_str, size, "%c is symb", 'a');

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_c_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%c is digit", 'a');
	reference_result = snprintf(reference_str, size, "%c is digit", 'a');

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_s_only_1_string)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%s", "abcd");
	reference_result = snprintf(reference_str, size - 1, "%s", "abcd");

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_s_some_strings_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%s %s %s", "abcd", "defg", "kcfg");
	reference_result = snprintf(reference_str, size - 1, "%s %s %s", "abcd", "defg", "kcfg");

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_s_some_strings_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%s%s%s", "abcd", "defg", "kcfg");
	reference_result = snprintf(reference_str, size - 1, "%s%s%s", "abcd", "defg", "kcfg");

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_s_string_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %s asd", "bcd");
	reference_result = snprintf(reference_str, size - 1, "asd - %s asd", "bcd");

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_s_size_equal)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%s is string", "abc");
	reference_result = snprintf(reference_str, size, "%s is string", "abc");

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_s_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%s is", "abcd");
	reference_result = snprintf(reference_str, size, "%s is", "abcd");

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_s_size_less)
{
	char str[5] = { 0 }, reference_str[5] = { 0 };
	size_t size = 5;
	int result, reference_result;

	result = my_snprintf(str, size, "%s is", "asdasdassd");
	reference_result = snprintf(reference_str, size, "%s is", "asdasdassd");

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_s_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%s is", "asd");
	reference_result = snprintf(reference_str, size, "%s is", "asd");

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_ld_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%ld", 13L);
	reference_result = snprintf(reference_str, size - 1, "%ld", 13L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ld_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%ld %ld %ld", 13L, 10L, 13L-10L);
	reference_result = snprintf(reference_str, size - 1, "%ld %ld %ld", 13L, 10L, 13L-10L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ld_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%ld%ld%ld", 13L, 10L, 13L-10L);
	reference_result = snprintf(reference_str, size - 1, "%ld%ld%ld", 13L, 10L, 13L-10L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ld_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %ld asd", 13L);
	reference_result = snprintf(reference_str, size - 1, "asd - %ld asd", 13L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ld_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%ld is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%ld is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ld_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%ld is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%ld is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ld_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%ld is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%ld is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ld_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%ld is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%ld is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_li_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%li", 13L);
	reference_result = snprintf(reference_str, size - 1, "%li", 13L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_li_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%li %li %li", 13L, 10L, 13L-10L);
	reference_result = snprintf(reference_str, size - 1, "%li %li %li", 13L, 10L, 13L-10L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_li_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%li%li%li", 13L, 10L, 13L-10L);
	reference_result = snprintf(reference_str, size - 1, "%li%li%li", 13L, 10L, 13L-10L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_li_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %li asd", 13L);
	reference_result = snprintf(reference_str, size - 1, "asd - %li asd", 13L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_li_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%li is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%li is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_li_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%li is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%li is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_li_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%li is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%li is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_li_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%li is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%li is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_lo_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%lo", 13L);
	reference_result = snprintf(reference_str, size - 1, "%lo", 13L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lo_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%lo %lo %lo", 13L, 10L, 13L-10L);
	reference_result = snprintf(reference_str, size - 1, "%lo %lo %lo", 13L, 10L, 13L-10L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lo_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%lo%lo%lo", 13L, 10L, 13L-10L);
	reference_result = snprintf(reference_str, size - 1, "%lo%lo%lo", 13L, 10L, 13L-10L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lo_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %lo asd", 13L);
	reference_result = snprintf(reference_str, size - 1, "asd - %lo asd", 13L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lo_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%lo is digit", 012345L);
	reference_result = snprintf(reference_str, size, "%lo is digit", 012345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lo_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%lo is digit", 012345L);
	reference_result = snprintf(reference_str, size, "%lo is digit", 012345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lo_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%lo is digit", 012345L);
	reference_result = snprintf(reference_str, size, "%lo is digit", 012345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lo_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%lo is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%lo is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_lx_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%lx", 13L);
	reference_result = snprintf(reference_str, size - 1, "%lx", 13L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lx_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%lx %lx %lx", 13L, 10L, 13L-10L);
	reference_result = snprintf(reference_str, size - 1, "%lx %lx %lx", 13L, 10L, 13L-10L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lx_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%lx%lx%lx", 13L, 10L, 13L-10L);
	reference_result = snprintf(reference_str, size - 1, "%lx%lx%lx", 13L, 10L, 13L-10L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lx_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %lx asd", 13L);
	reference_result = snprintf(reference_str, size - 1, "asd - %lx asd", 13L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lx_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%lx is digit", 0x12345L);
	reference_result = snprintf(reference_str, size, "%lx is digit", 0x12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lx_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%lx is digit", 0x12345L);
	reference_result = snprintf(reference_str, size, "%lx is digit", 0x12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lx_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%lx is digit", 0x12345L);
	reference_result = snprintf(reference_str, size, "%lx is digit", 0x12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_lx_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%lx is digit", 12345L);
	reference_result = snprintf(reference_str, size, "%lx is digit", 12345L);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_hd_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%hd", 13);
	reference_result = snprintf(reference_str, size - 1, "%hd", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hd_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%hd %hd %hd", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%hd %hd %hd", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hd_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%hd%hd%hd", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%hd%hd%hd", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hd_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %hd asd", 13);
	reference_result = snprintf(reference_str, size - 1, "asd - %hd asd", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hd_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%hd is digit", 12345);
	reference_result = snprintf(reference_str, size, "%hd is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hd_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%hd is digit", 12345);
	reference_result = snprintf(reference_str, size, "%hd is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hd_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%hd is digit", 12345);
	reference_result = snprintf(reference_str, size, "%hd is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hd_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%hd is digit", 12345);
	reference_result = snprintf(reference_str, size, "%hd is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_hi_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%hi", 13);
	reference_result = snprintf(reference_str, size - 1, "%hi", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hi_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%hi %hi %hi", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%hi %hi %hi", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hi_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%hi%hi%hi", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%hi%hi%hi", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hi_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %hi asd", 13);
	reference_result = snprintf(reference_str, size - 1, "asd - %hi asd", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hi_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%hi is digit", 12345);
	reference_result = snprintf(reference_str, size, "%hi is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hi_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%hi is digit", 12345);
	reference_result = snprintf(reference_str, size, "%hi is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hi_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%hi is digit", 12345);
	reference_result = snprintf(reference_str, size, "%hi is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hi_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%hi is digit", 12345);
	reference_result = snprintf(reference_str, size, "%hi is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_ho_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%ho", 13);
	reference_result = snprintf(reference_str, size - 1, "%ho", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ho_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%ho %ho %ho", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%ho %ho %ho", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ho_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%ho%ho%ho", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%ho%ho%ho", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ho_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %ho asd", 13);
	reference_result = snprintf(reference_str, size - 1, "asd - %ho asd", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ho_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%ho is digit", 012345);
	reference_result = snprintf(reference_str, size, "%ho is digit", 012345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ho_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%ho is digit", 012345);
	reference_result = snprintf(reference_str, size, "%ho is digit", 012345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ho_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%ho is digit", 012345);
	reference_result = snprintf(reference_str, size, "%ho is digit", 012345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_ho_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%ho is digit", 12345);
	reference_result = snprintf(reference_str, size, "%ho is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

START_TEST(test_specifier_hx_only_1_number)
{
	char str[10] = { 0 }, reference_str[10] = { 0 };
	size_t size = 10;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%hx", 13);
	reference_result = snprintf(reference_str, size - 1, "%hx", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hx_some_numbers_with_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%hx %hx %hx", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%hx %hx %hx", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hx_some_numbers_without_space)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "%hx%hx%hx", 13, 10, 13-10);
	reference_result = snprintf(reference_str, size - 1, "%hx%hx%hx", 13, 10, 13-10);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hx_number_with_text)
{
	char str[30] = { 0 }, reference_str[30] = { 0 };
	size_t size = 30;
	int result, reference_result;

	result = my_snprintf(str, size - 1, "asd - %hx asd", 13);
	reference_result = snprintf(reference_str, size - 1, "asd - %hx asd", 13);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hx_size_equal)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 15;
	int result, reference_result;

	result = my_snprintf(str, size, "%hx is digit", 0x12345);
	reference_result = snprintf(reference_str, size, "%hx is digit", 0x12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hx_size_more)
{
	char str[16] = { 0 }, reference_str[16] = { 0 };
	size_t size = 16;
	int result, reference_result;

	result = my_snprintf(str, size, "%hx is digit", 0x12345);
	reference_result = snprintf(reference_str, size, "%hx is digit", 0x12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hx_size_less)
{
	char str[14] = { 0 }, reference_str[14] = { 0 };
	size_t size = 14;
	int result, reference_result;

	result = my_snprintf(str, size, "%hx is digit", 0x12345);
	reference_result = snprintf(reference_str, size, "%hx is digit", 0x12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
	for (size_t i = 0; str[i]; i++)
		ck_assert_int_eq(str[i], reference_str[i]);
}
END_TEST

START_TEST(test_specifier_hx_size_zero)
{
	char str[15] = { 0 }, reference_str[15] = { 0 };
	size_t size = 0;
	int result, reference_result;

	result = my_snprintf(str, size, "%hx is digit", 12345);
	reference_result = snprintf(reference_str, size, "%hx is digit", 12345);

	ck_assert_int_eq(result, reference_result);
	ck_assert_int_eq(strlen(str), strlen(reference_str));
}
END_TEST

// MAIN

Suite *my_snprintf_suite(void)
{
	Suite *s;
	TCase *tc_d, *tc_i, *tc_o, *tc_x, *tc_c, *tc_s, *tc_ld, *tc_li, *tc_lo, *tc_lx,
	*tc_hd, *tc_hi, *tc_ho, *tc_hx;

	s = suite_create("my snprintf");

	tc_d = tcase_create("specifier d");
	tcase_add_test(tc_d, test_specifier_d_only_1_number);
	tcase_add_test(tc_d, test_specifier_d_some_numbers_with_space);
	tcase_add_test(tc_d, test_specifier_d_some_numbers_without_space);
	tcase_add_test(tc_d, test_specifier_d_number_with_text);
	tcase_add_test(tc_d, test_specifier_d_size_equal);
	tcase_add_test(tc_d, test_specifier_d_size_more);
	tcase_add_test(tc_d, test_specifier_d_size_less);
	tcase_add_test(tc_d, test_specifier_d_size_zero);
	suite_add_tcase(s, tc_d);

	tc_i = tcase_create("specifier i");
	tcase_add_test(tc_i, test_specifier_i_only_1_number);
	tcase_add_test(tc_i, test_specifier_i_some_numbers_with_space);
	tcase_add_test(tc_i, test_specifier_i_some_numbers_without_space);
	tcase_add_test(tc_i, test_specifier_i_number_with_text);
	tcase_add_test(tc_i, test_specifier_i_size_equal);
	tcase_add_test(tc_i, test_specifier_i_size_more);
	tcase_add_test(tc_i, test_specifier_i_size_less);
	tcase_add_test(tc_i, test_specifier_i_size_zero);
	suite_add_tcase(s, tc_i);

	tc_o = tcase_create("specifier o");
	tcase_add_test(tc_o, test_specifier_o_only_1_number);
	tcase_add_test(tc_o, test_specifier_o_some_numbers_with_space);
	tcase_add_test(tc_o, test_specifier_o_some_numbers_without_space);
	tcase_add_test(tc_o, test_specifier_o_number_with_text);
	tcase_add_test(tc_o, test_specifier_o_size_equal);
	tcase_add_test(tc_o, test_specifier_o_size_more);
	tcase_add_test(tc_o, test_specifier_o_size_less);
	tcase_add_test(tc_o, test_specifier_o_size_zero);
	suite_add_tcase(s, tc_o);

	tc_x = tcase_create("specifier x");
	tcase_add_test(tc_x, test_specifier_x_only_1_number);
	tcase_add_test(tc_x, test_specifier_x_some_numbers_with_space);
	tcase_add_test(tc_x, test_specifier_x_some_numbers_without_space);
	tcase_add_test(tc_x, test_specifier_x_number_with_text);
	tcase_add_test(tc_x, test_specifier_x_size_equal);
	tcase_add_test(tc_x, test_specifier_x_size_more);
	tcase_add_test(tc_x, test_specifier_x_size_less);
	tcase_add_test(tc_x, test_specifier_x_size_zero);
	suite_add_tcase(s, tc_x);

	tc_c = tcase_create("specifier c");
	tcase_add_test(tc_x, test_specifier_c_only_1_symbol);
	tcase_add_test(tc_x, test_specifier_c_some_symbols_with_space);
	tcase_add_test(tc_x, test_specifier_c_some_symbols_without_space);
	tcase_add_test(tc_x, test_specifier_c_symbol_with_text);
	tcase_add_test(tc_x, test_specifier_c_size_equal);
	tcase_add_test(tc_x, test_specifier_c_size_more);
	tcase_add_test(tc_x, test_specifier_c_size_less);
	tcase_add_test(tc_x, test_specifier_c_size_zero);
	suite_add_tcase(s, tc_c);

	tc_s = tcase_create("specifier c");
	tcase_add_test(tc_s, test_specifier_s_only_1_string);
	tcase_add_test(tc_s, test_specifier_s_some_strings_with_space);
	tcase_add_test(tc_s, test_specifier_s_some_strings_without_space);
	tcase_add_test(tc_s, test_specifier_s_string_with_text);
	tcase_add_test(tc_s, test_specifier_s_size_equal);
	tcase_add_test(tc_s, test_specifier_s_size_more);
	tcase_add_test(tc_s, test_specifier_s_size_less);
	tcase_add_test(tc_s, test_specifier_s_size_zero);
	suite_add_tcase(s, tc_s);

	tc_ld = tcase_create("specifier ld");
	tcase_add_test(tc_ld, test_specifier_ld_only_1_number);
	tcase_add_test(tc_ld, test_specifier_ld_some_numbers_with_space);
	tcase_add_test(tc_ld, test_specifier_ld_some_numbers_without_space);
	tcase_add_test(tc_ld, test_specifier_ld_number_with_text);
	tcase_add_test(tc_ld, test_specifier_ld_size_equal);
	tcase_add_test(tc_ld, test_specifier_ld_size_more);
	tcase_add_test(tc_ld, test_specifier_ld_size_less);
	tcase_add_test(tc_ld, test_specifier_ld_size_zero);
	suite_add_tcase(s, tc_ld);

	tc_li = tcase_create("specifier li");
	tcase_add_test(tc_li, test_specifier_li_only_1_number);
	tcase_add_test(tc_li, test_specifier_li_some_numbers_with_space);
	tcase_add_test(tc_li, test_specifier_li_some_numbers_without_space);
	tcase_add_test(tc_li, test_specifier_li_number_with_text);
	tcase_add_test(tc_li, test_specifier_li_size_equal);
	tcase_add_test(tc_li, test_specifier_li_size_more);
	tcase_add_test(tc_li, test_specifier_li_size_less);
	tcase_add_test(tc_li, test_specifier_li_size_zero);
	suite_add_tcase(s, tc_li);

	tc_lo = tcase_create("specifier lo");
	tcase_add_test(tc_lo, test_specifier_lo_only_1_number);
	tcase_add_test(tc_lo, test_specifier_lo_some_numbers_with_space);
	tcase_add_test(tc_lo, test_specifier_lo_some_numbers_without_space);
	tcase_add_test(tc_lo, test_specifier_lo_number_with_text);
	tcase_add_test(tc_lo, test_specifier_lo_size_equal);
	tcase_add_test(tc_lo, test_specifier_lo_size_more);
	tcase_add_test(tc_lo, test_specifier_lo_size_less);
	tcase_add_test(tc_lo, test_specifier_lo_size_zero);
	suite_add_tcase(s, tc_lo);

	tc_lx = tcase_create("specifier lx");
	tcase_add_test(tc_lx, test_specifier_lx_only_1_number);
	tcase_add_test(tc_lx, test_specifier_lx_some_numbers_with_space);
	tcase_add_test(tc_lx, test_specifier_lx_some_numbers_without_space);
	tcase_add_test(tc_lx, test_specifier_lx_number_with_text);
	tcase_add_test(tc_lx, test_specifier_lx_size_equal);
	tcase_add_test(tc_lx, test_specifier_lx_size_more);
	tcase_add_test(tc_lx, test_specifier_lx_size_less);
	tcase_add_test(tc_lx, test_specifier_lx_size_zero);
	suite_add_tcase(s, tc_lx);

	tc_hd = tcase_create("specifier hd");
	tcase_add_test(tc_hd, test_specifier_hd_only_1_number);
	tcase_add_test(tc_hd, test_specifier_hd_some_numbers_with_space);
	tcase_add_test(tc_hd, test_specifier_hd_some_numbers_without_space);
	tcase_add_test(tc_hd, test_specifier_hd_number_with_text);
	tcase_add_test(tc_hd, test_specifier_hd_size_equal);
	tcase_add_test(tc_hd, test_specifier_hd_size_more);
	tcase_add_test(tc_hd, test_specifier_hd_size_less);
	tcase_add_test(tc_hd, test_specifier_hd_size_zero);
	suite_add_tcase(s, tc_hd);

	tc_hi = tcase_create("specifier hi");
	tcase_add_test(tc_hi, test_specifier_hi_only_1_number);
	tcase_add_test(tc_hi, test_specifier_hi_some_numbers_with_space);
	tcase_add_test(tc_hi, test_specifier_hi_some_numbers_without_space);
	tcase_add_test(tc_hi, test_specifier_hi_number_with_text);
	tcase_add_test(tc_hi, test_specifier_hi_size_equal);
	tcase_add_test(tc_hi, test_specifier_hi_size_more);
	tcase_add_test(tc_hi, test_specifier_hi_size_less);
	tcase_add_test(tc_hi, test_specifier_hi_size_zero);
	suite_add_tcase(s, tc_hi);

	tc_ho = tcase_create("specifier ho");
	tcase_add_test(tc_ho, test_specifier_ho_only_1_number);
	tcase_add_test(tc_ho, test_specifier_ho_some_numbers_with_space);
	tcase_add_test(tc_ho, test_specifier_ho_some_numbers_without_space);
	tcase_add_test(tc_ho, test_specifier_ho_number_with_text);
	tcase_add_test(tc_ho, test_specifier_ho_size_equal);
	tcase_add_test(tc_ho, test_specifier_ho_size_more);
	tcase_add_test(tc_ho, test_specifier_ho_size_less);
	tcase_add_test(tc_ho, test_specifier_ho_size_zero);
	suite_add_tcase(s, tc_ho);

	tc_hx = tcase_create("specifier hx");
	tcase_add_test(tc_hx, test_specifier_hx_only_1_number);
	tcase_add_test(tc_hx, test_specifier_hx_some_numbers_with_space);
	tcase_add_test(tc_hx, test_specifier_hx_some_numbers_without_space);
	tcase_add_test(tc_hx, test_specifier_hx_number_with_text);
	tcase_add_test(tc_hx, test_specifier_hx_size_equal);
	tcase_add_test(tc_hx, test_specifier_hx_size_more);
	tcase_add_test(tc_hx, test_specifier_hx_size_less);
	tcase_add_test(tc_hx, test_specifier_hx_size_zero);
	suite_add_tcase(s, tc_hx);

    return s;
}
