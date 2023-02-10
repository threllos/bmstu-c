#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../inc/dynamic_array.h"

START_TEST(test_count_len_no_elements)
{
	int rc;
	size_t len;
	FILE *f = fopen("./func_tests/shared/n_01_in.txt", "r");

	rc = count_len(f, &len);
	fclose(f);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_count_len_line_with_string)
{
	int rc;
	size_t len;
	FILE *f = fopen("./func_tests/shared/n_03_in.txt", "r");

	rc = count_len(f, &len);
	fclose(f);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_count_len_basic)
{
	int rc;
	size_t len;
	FILE *f = fopen("./func_tests/shared/p_01_in.txt", "r");

	rc = count_len(f, &len);
	fclose(f);

	ck_assert_int_eq(rc, 0);
	ck_assert_int_eq(len, 5);
}

START_TEST(test_count_len_one_element)
{
	int rc;
	size_t len;
	FILE *f = fopen("./func_tests/shared/p_06_in.txt", "r");

	rc = count_len(f, &len);
	fclose(f);

	ck_assert_int_eq(rc, 0);
	ck_assert_int_eq(len, 1);
}

Suite *count_len_suite(void)
{
	Suite *s;
	TCase *tc_neg;
	TCase *tc_pos;

	s = suite_create("count_len");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_count_len_no_elements);
	tcase_add_test(tc_neg, test_count_len_line_with_string);
	suite_add_tcase(s, tc_neg);

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_count_len_basic);
    tcase_add_test(tc_pos, test_count_len_one_element);
    suite_add_tcase(s, tc_pos);

    return s;
}