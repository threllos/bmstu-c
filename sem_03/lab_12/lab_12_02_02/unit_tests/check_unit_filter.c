#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "array.h"

START_TEST(test_filter_basic)
{
	int a[] = {1, 1, 1, 2, 2, 3};
	int a_size = 6;
	int *b = malloc(sizeof(int) * a_size);
	int b_size;
	int reference[] = {1, 2, 3};
	int ref_size = 3;

	filter(a, a_size, b, &b_size);

	ck_assert_int_eq(b_size, ref_size);
	for (int i = 0; i < ref_size; i++)
		ck_assert_int_eq(reference[i], b[i]);

	free(b);
}
END_TEST

START_TEST(test_filter_equal_size)
{
	int a[] = {1, 2, 3};
	int a_size = 3;
	int *b = malloc(sizeof(int) * a_size);
	int b_size;
	int reference[] = {1, 2, 3};
	int ref_size = 3;

	filter(a, a_size, b, &b_size);

	ck_assert_int_eq(b_size, ref_size);
	for (int i = 0; i < ref_size; i++)
		ck_assert_int_eq(reference[i], b[i]);

	free(b);
}
END_TEST

START_TEST(test_filter_one_elem)
{
	int a[] = {1};
	int a_size = 1;
	int *b = malloc(sizeof(int) * a_size);
	int b_size;
	int reference[] = {1};
	int ref_size = 1;

	filter(a, a_size, b, &b_size);

	ck_assert_int_eq(b_size, ref_size);
	for (int i = 0; i < ref_size; i++)
		ck_assert_int_eq(reference[i], b[i]);

	free(b);
}
END_TEST

START_TEST(test_filter_neg_size)
{
	int a[] = {1};
	int a_size = 1;
	int *b = malloc(sizeof(int) * a_size);
	int b_size;
	int ref_size = 0;

	filter(a, -10, b, &b_size);

	ck_assert_int_eq(b_size, ref_size);

	free(b);
}
END_TEST

START_TEST(test_filter_null_src)
{
	int a_size = 1;
	int *b = malloc(sizeof(int) * a_size);
	int b_size;
	int ref_size = 0;

	filter(NULL, a_size, b, &b_size);

	ck_assert_int_eq(b_size, ref_size);

	free(b);
}
END_TEST

START_TEST(test_filter_null_dst)
{
	int a[] = {1};
	int a_size = 1;
	int *b = malloc(sizeof(int) * a_size);
	int b_size;
	int ref_size = 0;

	filter(a, a_size, NULL, &b_size);

	ck_assert_int_eq(b_size, ref_size);

	free(b);
}
END_TEST

Suite *filter_suite(void)
{
	Suite *s;
	TCase *tc_pos, *tc_neg;

	s = suite_create("filter");

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_filter_basic);
    tcase_add_test(tc_pos, test_filter_equal_size);
    tcase_add_test(tc_pos, test_filter_one_elem);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_filter_neg_size);
    tcase_add_test(tc_neg, test_filter_null_src);
    tcase_add_test(tc_neg, test_filter_null_dst);
    suite_add_tcase(s, tc_neg);

    return s;
}
