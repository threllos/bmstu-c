#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "array.h"

START_TEST(test_fibonacci_fill_basic)
{
	int *a = malloc(sizeof(int) * 5);
	int reference[] = {0, 1, 1, 2, 3};

	int rc = fibonacci_fill(a, 5);

	ck_assert_int_eq(rc, SUCCESS);
	for (size_t i = 0; i < 5; i++)
		ck_assert_int_eq(reference[i], a[i]);

	free(a);
}
END_TEST

START_TEST(test_fibonacci_fill_1_elem)
{
	int *a = malloc(sizeof(int) * 1);
	int reference[] = {0};

	int rc = fibonacci_fill(a, 1);

	ck_assert_int_eq(rc, SUCCESS);
	for (size_t i = 0; i < 1; i++)
		ck_assert_int_eq(reference[i], a[i]);

	free(a);
}
END_TEST

START_TEST(test_fibonacci_fill_3_elems)
{
	int *a = malloc(sizeof(int) * 3);
	int reference[] = {0, 1, 1};

	int rc = fibonacci_fill(a, 3);

	ck_assert_int_eq(rc, SUCCESS);
	for (size_t i = 0; i < 3; i++)
		ck_assert_int_eq(reference[i], a[i]);

	free(a);
}
END_TEST

START_TEST(test_fibonacci_fill_neg_size)
{
	int *a = malloc(sizeof(int) * 3);

	int rc = fibonacci_fill(a, -10);

	ck_assert_int_eq(rc, FAILURE);

	free(a);
}
END_TEST

START_TEST(test_fibonacci_fill_zero_size)
{
	int *a = malloc(sizeof(int) * 3);

	int rc = fibonacci_fill(a, 0);

	ck_assert_int_eq(rc, FAILURE);

	free(a);
}
END_TEST

START_TEST(test_fibonacci_fill_null_arr)
{
	int *a = malloc(sizeof(int) * 3);

	int rc = fibonacci_fill(NULL, 3);

	ck_assert_int_eq(rc, FAILURE);

	free(a);
}
END_TEST

Suite *fibonacci_fill_suite(void)
{
	Suite *s;
	TCase *tc_pos, *tc_neg;

	s = suite_create("fibonacci_fill");

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_fibonacci_fill_basic);
    tcase_add_test(tc_pos, test_fibonacci_fill_1_elem);
    tcase_add_test(tc_pos, test_fibonacci_fill_3_elems);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_fibonacci_fill_neg_size);
    tcase_add_test(tc_neg, test_fibonacci_fill_zero_size);
    tcase_add_test(tc_neg, test_fibonacci_fill_null_arr);
    suite_add_tcase(s, tc_neg);

    return s;
}

