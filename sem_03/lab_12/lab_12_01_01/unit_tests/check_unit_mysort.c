#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../inc/dynamic_array.h"

START_TEST(test_mysort_basic)
{
	int pb_src[] = {3, 1, 4, 2, 5};
	size_t len = 5;
	int test_pb_src[] = {1, 2, 3, 4, 5};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_one_element)
{
	int pb_src[] = {1};
	size_t len = 1;
	int test_pb_src[] = {1};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_sorted_array)
{
	int pb_src[] = {1, 2, 3, 4, 5};
	size_t len = 5;
	int test_pb_src[] = {1, 2, 3, 4, 5};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_sorted_array_hight_to_low)
{
	int pb_src[] = {5, 4, 3, 2, 1};
	size_t len = 5;
	int test_pb_src[] = {1, 2, 3, 4, 5};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_equal_elements)
{
	int pb_src[] = {1, 1, 1, 1, 1};
	size_t len = 5;
	int test_pb_src[] = {1, 1, 1, 1, 1};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_max_number_4_byte)
{
	int pb_src[] = {3, 2, 2147483647, 1, 4};
	size_t len = 5;
	int test_pb_src[] = {1, 2, 3, 4, 2147483647};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_max_number_2_byte)
{
	int pb_src[] = {3, 2, 32767, 1, 4};
	size_t len = 5;
	int test_pb_src[] = {1, 2, 3, 4, 32767};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_max_number_1_byte)
{
	int pb_src[] = {3, 2, 127, 1, 4};
	size_t len = 5;
	int test_pb_src[] = {1, 2, 3, 4, 127};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_special)
{
	int pb_src[] = {1, 2, 1, 2, 1};
	size_t len = 5;
	int test_pb_src[] = {1, 1, 1, 2, 2};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_special_2)
{
	int pb_src[] = {2, 2, 1, 1, 1};
	size_t len = 5;
	int test_pb_src[] = {1, 1, 1, 2, 2};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_special_3)
{
	int pb_src[] = {7, 5, 6, 1};
	size_t len = 4;
	int test_pb_src[] = {1, 5, 6, 7};

	mysort(pb_src, len, sizeof(int), compare);

	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_null_len)
{
 	int pb_src[] = {7, 5, 6, 1};
 	size_t len = 0;
 	int test_pb_src[] = {7, 5, 6, 1};

 	mysort(pb_src, len, sizeof(int), compare);

 	for (size_t i = 0; i < 4; i++)
 		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

START_TEST(test_mysort_null_size)
{
 	int pb_src[] = {7, 5, 6, 1};
 	size_t len = 4;
 	int test_pb_src[] = {7, 5, 6, 1};

 	mysort(pb_src, len, 0, compare);

 	for (size_t i = 0; i < len; i++)
 		ck_assert_int_eq(pb_src[i], test_pb_src[i]);
}

Suite *mysort_suite(void)
{
	Suite *s;
	TCase *tc_pos;

	s = suite_create("mysort");

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mysort_basic);
    tcase_add_test(tc_pos, test_mysort_one_element);
    tcase_add_test(tc_pos, test_mysort_sorted_array);
    tcase_add_test(tc_pos, test_mysort_sorted_array_hight_to_low);
    tcase_add_test(tc_pos, test_mysort_equal_elements);
    tcase_add_test(tc_pos, test_mysort_max_number_4_byte);
    tcase_add_test(tc_pos, test_mysort_max_number_2_byte);
    tcase_add_test(tc_pos, test_mysort_max_number_1_byte);
    tcase_add_test(tc_pos, test_mysort_special);
    tcase_add_test(tc_pos, test_mysort_special_2);
    tcase_add_test(tc_pos, test_mysort_special_3);
    tcase_add_test(tc_pos, test_mysort_null_len);
    tcase_add_test(tc_pos, test_mysort_null_size);
    suite_add_tcase(s, tc_pos);

    return s;
}