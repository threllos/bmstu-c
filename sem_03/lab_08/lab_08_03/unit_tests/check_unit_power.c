#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "matrix.h"

// NEG TESTS

START_TEST(test_power_size_not_equal)
{
	int rc;
	size_t p = 1;
	
	int src_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_src_matrix[2] = {
		src_matrix[0],
		src_matrix[1]
	};

	matrix_t src = {
		.matrix = p_src_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int dst_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_dst_matrix[3] = {
		dst_matrix[0],
		dst_matrix[1],
		dst_matrix[2]
	};

	matrix_t dst = {
		.matrix = p_dst_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	rc = power(src, &dst, p);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_power_src_not_square)
{
	int rc;
	size_t p = 1;
	
	int src_matrix[][3] = {
		{1, 2, 3},
		{3, 7, 4}
	};

	int *p_src_matrix[2] = {
		src_matrix[0],
		src_matrix[1]
	};

	matrix_t src = {
		.matrix = p_src_matrix,
		.rows = 2,
		.columns = 3,
		.const_rows = 2,
		.const_columns = 3
	};

	int dst_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_dst_matrix[3] = {
		dst_matrix[0],
		dst_matrix[1],
		dst_matrix[2]
	};

	matrix_t dst = {
		.matrix = p_dst_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	rc = power(src, &dst, p);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_power_dst_not_square)
{
	int rc;
	size_t p = 1;
	
	int src_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_src_matrix[2] = {
		src_matrix[0],
		src_matrix[1]
	};

	matrix_t src = {
		.matrix = p_src_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int dst_matrix[][2] = {
		{0, 0},
		{0, 0},
		{0, 0}
	};

	int *p_dst_matrix[3] = {
		dst_matrix[0],
		dst_matrix[1],
		dst_matrix[2]
	};

	matrix_t dst = {
		.matrix = p_dst_matrix,
		.rows = 3,
		.columns = 2,
		.const_rows = 3,
		.const_columns = 2
	};

	rc = power(src, &dst, p);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

// POS TESTS

START_TEST(test_power_basic)
{
	int rc;
	size_t p = 3;
	
	int src_matrix[][3] = {
		{1, 2, 5},
		{3, 7, 9},
		{-2, 0, 2}
	};

	int *p_src_matrix[3] = {
		src_matrix[0],
		src_matrix[1],
		src_matrix[2]
	};

	matrix_t src = {
		.matrix = p_src_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int dst_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_dst_matrix[3] = {
		dst_matrix[0],
		dst_matrix[1],
		dst_matrix[2]
	};

	matrix_t dst = {
		.matrix = p_dst_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int reference_matrix[][3] = {
		{-21, 106, 195}, 
		{-21, 397, 717},
		{-6, -40, -78}
	};

	int *p_reference_matrix[3] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	rc = power(src, &dst, p);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, dst.rows);
	ck_assert_int_eq(reference.columns, dst.columns);
	ck_assert_int_eq(reference.const_rows, dst.const_rows);
	ck_assert_int_eq(reference.const_columns, dst.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], dst.matrix[i][j]);
}
END_TEST

START_TEST(test_power_zero)
{
	int rc;
	size_t p = 0;
	
	int src_matrix[][3] = {
		{1, 2, 5},
		{3, 7, 9},
		{-2, 0, 2}
	};

	int *p_src_matrix[3] = {
		src_matrix[0],
		src_matrix[1],
		src_matrix[2]
	};

	matrix_t src = {
		.matrix = p_src_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int dst_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_dst_matrix[3] = {
		dst_matrix[0],
		dst_matrix[1],
		dst_matrix[2]
	};

	matrix_t dst = {
		.matrix = p_dst_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int reference_matrix[][3] = {
		{1, 0, 0}, 
		{0, 1, 0},
		{0, 0, 1}
	};

	int *p_reference_matrix[3] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	rc = power(src, &dst, p);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, dst.rows);
	ck_assert_int_eq(reference.columns, dst.columns);
	ck_assert_int_eq(reference.const_rows, dst.const_rows);
	ck_assert_int_eq(reference.const_columns, dst.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], dst.matrix[i][j]);
}
END_TEST

START_TEST(test_power_identity)
{
	int rc;
	size_t p = 1;
	
	int src_matrix[][3] = {
		{1, 2, 5},
		{3, 7, 9},
		{-2, 0, 2}
	};

	int *p_src_matrix[3] = {
		src_matrix[0],
		src_matrix[1],
		src_matrix[2]
	};

	matrix_t src = {
		.matrix = p_src_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int dst_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_dst_matrix[3] = {
		dst_matrix[0],
		dst_matrix[1],
		dst_matrix[2]
	};

	matrix_t dst = {
		.matrix = p_dst_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int reference_matrix[][3] = {
		{1, 2, 5},
		{3, 7, 9},
		{-2, 0, 2}
	};

	int *p_reference_matrix[3] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	rc = power(src, &dst, p);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, dst.rows);
	ck_assert_int_eq(reference.columns, dst.columns);
	ck_assert_int_eq(reference.const_rows, dst.const_rows);
	ck_assert_int_eq(reference.const_columns, dst.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], dst.matrix[i][j]);
}
END_TEST

// MAIN

Suite *power_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("power");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_power_size_not_equal);
	tcase_add_test(tc_neg, test_power_src_not_square);
	tcase_add_test(tc_neg, test_power_dst_not_square);
	suite_add_tcase(s, tc_neg);


	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_power_basic);
    tcase_add_test(tc_pos, test_power_zero);
    tcase_add_test(tc_pos, test_power_identity);
    suite_add_tcase(s, tc_pos);

    return s;
}
