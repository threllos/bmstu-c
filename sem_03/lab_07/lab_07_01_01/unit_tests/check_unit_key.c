#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../inc/dynamic_array.h"

// негативные тесты

START_TEST(test_key_no_src)
{
	int rc;
	int *pb_src = NULL, *pe_src = NULL;
	int *pb_dst, *pe_dst;

	rc = key(pb_src, pe_src, &pb_dst, &pe_dst);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_key_equal_elements)
{
	int rc;
	int pb_src[] = {1, 1, 1, 1, 1};
	int *pb_dst, *pe_dst;

	rc = key(pb_src, pb_src + 5, &pb_dst, &pe_dst);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_key_only_min_and_max)
{
	int rc;
	int pb_src[] = {1, 5};
	int *pb_dst, *pe_dst;

	rc = key(pb_src, pb_src + 2, &pb_dst, &pe_dst);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_key_no_elements_between_min_and_max)
{
	int rc;
	int pb_src[] = {3, 4, 1, 5, 2, 3};
	int *pb_dst, *pe_dst;

	rc = key(pb_src, pb_src + 6, &pb_dst, &pe_dst);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_key_pbsrc_bigger_pesrc)
{
	int rc;
	int pb_src[] = {3, 4, 1, 5, 2, 3};
	int *pb_dst, *pe_dst;

	rc = key(pb_src + 6, pb_src, &pb_dst, &pe_dst);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

START_TEST(test_key_pbsrc_equal_pesrc)
{
	int rc;
	int pb_src[] = {3, 4, 1, 5, 2, 3};
	int *pb_dst, *pe_dst;

	rc = key(pb_src, pb_src, &pb_dst, &pe_dst);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}

// позитивные тесты

START_TEST(test_key_basic)
{
	int rc;
	int pb_src[] = {1, 2, 3, 4, 5};
	int *pb_dst, *pe_dst;
	int test_pb_dst[] = {2, 3, 4};

	rc = key(pb_src, pb_src + 5, &pb_dst, &pe_dst);

	ck_assert_int_eq(rc, 0);
	for (size_t i = 0; i < 3; i++)
		ck_assert_int_eq(pb_dst[i], test_pb_dst[i]);

	free(pb_dst);
}

START_TEST(test_key_basic_2)
{
	int rc;
	int pb_src[] = {4, 1, 3, 2, 5, 2, 3};
	int *pb_dst, *pe_dst;
	int test_pb_dst[] = {3, 2};

	rc = key(pb_src, pb_src + 7, &pb_dst, &pe_dst);

	ck_assert_int_eq(rc, 0);
	for (size_t i = 0; i < 2; i++)
		ck_assert_int_eq(pb_dst[i], test_pb_dst[i]);

	free(pb_dst);
}

START_TEST(test_key_pmin_bigger_pmax)
{
	int rc;
	int pb_src[] = {5, 4, 3, 2, 1};
	int *pb_dst, *pe_dst;
	int test_pb_dst[] = {4, 3, 2};

	rc = key(pb_src, pb_src + 5, &pb_dst, &pe_dst);

	ck_assert_int_eq(rc, 0);
	for (size_t i = 0; i < 3; i++)
		ck_assert_int_eq(pb_dst[i], test_pb_dst[i]);

	free(pb_dst);
}

// мейн

Suite *key_suite(void)
{
	Suite *s;
	TCase *tc_neg;
	TCase *tc_pos;

	s = suite_create("key");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_key_no_src);
	tcase_add_test(tc_neg, test_key_equal_elements);
	tcase_add_test(tc_neg, test_key_only_min_and_max);
	tcase_add_test(tc_neg, test_key_no_elements_between_min_and_max);
	tcase_add_test(tc_neg, test_key_pbsrc_bigger_pesrc);
	tcase_add_test(tc_neg, test_key_pbsrc_equal_pesrc);
	suite_add_tcase(s, tc_neg);

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_basic);
    tcase_add_test(tc_pos, test_key_basic_2);
	tcase_add_test(tc_neg, test_key_pmin_bigger_pmax);
    suite_add_tcase(s, tc_pos);

    return s;
}