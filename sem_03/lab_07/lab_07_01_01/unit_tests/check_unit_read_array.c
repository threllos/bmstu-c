#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../inc/dynamic_array.h"

START_TEST(test_read_array_empty_file)
{
	int rc;
	size_t len = 5;
	int arr[] = {1, 2, 3, 4, 5};
	FILE *f = fopen("./func_tests/shared/n_01_in.txt", "r");

	rc = read_array(f, arr, arr + len);
	fclose(f);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_read_array_no_file)
{
	int rc;
	size_t len = 5;
	int arr[] = {1, 2, 3, 4, 5};
	FILE *f = fopen("./func_tests/shared/n_02_in.txt", "r");

	rc = read_array(f, arr, arr + len);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_read_array_no_src)
{
	int rc;
	size_t len = 0;
	int *arr = NULL;
	FILE *f = fopen("./func_tests/shared/p_01_in.txt", "r");

	rc = read_array(f, arr, arr + len);
	fclose(f);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_read_array_string_in_array)
{
	int rc;
	size_t len = 5;
	int arr[] = {1, 2, 3, 4, 5};
	FILE *f = fopen("./func_tests/shared/n_03_in.txt", "r");

	rc = read_array(f, arr, arr + len);
	fclose(f);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_read_array_basic)
{
	int rc;
	size_t len = 5;
	int arr[] = {1, 3, 4, 2, 5};
	int test_arr[5];
	FILE *f = fopen("./func_tests/shared/p_01_in.txt", "r");

	rc = read_array(f, test_arr, test_arr + len);
	fclose(f);

	ck_assert_int_eq(rc, 0);
	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(arr[i], test_arr[i]);
}

START_TEST(test_read_array_one_element)
{
	int rc;
	size_t len = 1;
	int arr[] = {5};
	int test_arr[1];
	FILE *f = fopen("./func_tests/shared/p_06_in.txt", "r");

	rc = read_array(f, test_arr, test_arr + len);
	fclose(f);

	ck_assert_int_eq(rc, 0);
	for (size_t i = 0; i < len; i++)
		ck_assert_int_eq(arr[i], test_arr[i]);
}

Suite *read_array_suite(void)
{
	Suite *s;
	TCase *tc_neg;
	TCase *tc_pos;

	s = suite_create("read_array");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_read_array_empty_file);
	tcase_add_test(tc_neg, test_read_array_no_file);
	tcase_add_test(tc_neg, test_read_array_no_src);
	tcase_add_test(tc_neg, test_read_array_string_in_array);
	suite_add_tcase(s, tc_neg);

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_read_array_basic);
    tcase_add_test(tc_pos, test_read_array_one_element);
    suite_add_tcase(s, tc_pos);

    return s;
}