#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "matrix.h"

// POS TESTS

START_TEST(test_fill_basic)
{
	int src_test_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_src_test_matrix[2] = {
		src_test_matrix[0],
		src_test_matrix[1]
	};

	matrix_t src_test = {
		.matrix = p_src_test_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int dst_test_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_dst_test_matrix[3] = {
		dst_test_matrix[0],
		dst_test_matrix[1],
		dst_test_matrix[2]
	};

	matrix_t dst_test = {
		.matrix = p_dst_test_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int reference_matrix[][3] = {
		{1, 2, 2}, 
		{3, 7, 7},
		{2, 4, 4}
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

	fill(src_test, &dst_test);

	ck_assert_int_eq(reference.rows, dst_test.rows);
	ck_assert_int_eq(reference.columns, dst_test.columns);
	ck_assert_int_eq(reference.const_rows, dst_test.const_rows);
	ck_assert_int_eq(reference.const_columns, dst_test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], dst_test.matrix[i][j]);
}
END_TEST

START_TEST(test_fill_with_neg_elem)
{
	int src_test_matrix[][2] = {
		{-5, 2},
		{2, 4}
	};

	int *p_src_test_matrix[2] = {
		src_test_matrix[0],
		src_test_matrix[1]
	};

	matrix_t src_test = {
		.matrix = p_src_test_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int dst_test_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_dst_test_matrix[3] = {
		dst_test_matrix[0],
		dst_test_matrix[1],
		dst_test_matrix[2]
	};

	matrix_t dst_test = {
		.matrix = p_dst_test_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int reference_matrix[][3] = {
		{-5, 2, 2}, 
		{2, 4, 4},
		{-2, 3, 3}
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

	fill(src_test, &dst_test);

	ck_assert_int_eq(reference.rows, dst_test.rows);
	ck_assert_int_eq(reference.columns, dst_test.columns);
	ck_assert_int_eq(reference.const_rows, dst_test.const_rows);
	ck_assert_int_eq(reference.const_columns, dst_test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], dst_test.matrix[i][j]);
}
END_TEST

START_TEST(test_fill_more_1_iter)
{
	int src_test_matrix[][2] = {
		{1, 2},
		{2, 9}
	};

	int *p_src_test_matrix[2] = {
		src_test_matrix[0],
		src_test_matrix[1]
	};

	matrix_t src_test = {
		.matrix = p_src_test_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int dst_test_matrix[][5] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};

	int *p_dst_test_matrix[5] = {
		dst_test_matrix[0],
		dst_test_matrix[1],
		dst_test_matrix[2],
		dst_test_matrix[3],
		dst_test_matrix[4]
	};

	matrix_t dst_test = {
		.matrix = p_dst_test_matrix,
		.rows = 5,
		.columns = 5,
		.const_rows = 5,
		.const_columns = 5
	};

	int reference_matrix[][5] = {
		{1, 2, 2, 2, 2}, 
		{2, 9, 9, 9, 9},
		{1, 5, 5, 5, 5},
		{1, 5, 5, 5, 5},
		{1, 5, 5, 5, 5}
	};

	int *p_reference_matrix[5] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2],
		reference_matrix[3],
		reference_matrix[4]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 5,
		.columns = 5,
		.const_rows = 5,
		.const_columns = 5
	};

	fill(src_test, &dst_test);

	ck_assert_int_eq(reference.rows, dst_test.rows);
	ck_assert_int_eq(reference.columns, dst_test.columns);
	ck_assert_int_eq(reference.const_rows, dst_test.const_rows);
	ck_assert_int_eq(reference.const_columns, dst_test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], dst_test.matrix[i][j]);
}
END_TEST

START_TEST(test_fill_equal_size)
{
	int src_test_matrix[][2] = {
		{1, 2},
		{2, 9}
	};

	int *p_src_test_matrix[2] = {
		src_test_matrix[0],
		src_test_matrix[1]
	};

	matrix_t src_test = {
		.matrix = p_src_test_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int dst_test_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	int *p_dst_test_matrix[2] = {
		dst_test_matrix[0],
		dst_test_matrix[1]
	};

	matrix_t dst_test = {
		.matrix = p_dst_test_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int reference_matrix[][2] = {
		{1, 2}, 
		{2, 9}
	};

	int *p_reference_matrix[2] = {
		reference_matrix[0],
		reference_matrix[1]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	fill(src_test, &dst_test);

	ck_assert_int_eq(reference.rows, dst_test.rows);
	ck_assert_int_eq(reference.columns, dst_test.columns);
	ck_assert_int_eq(reference.const_rows, dst_test.const_rows);
	ck_assert_int_eq(reference.const_columns, dst_test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], dst_test.matrix[i][j]);
}
END_TEST

START_TEST(test_fill_all_elems_neg)
{
	int src_test_matrix[][2] = {
		{-2, -3},
		{-5, -1}
	};

	int *p_src_test_matrix[2] = {
		src_test_matrix[0],
		src_test_matrix[1]
	};

	matrix_t src_test = {
		.matrix = p_src_test_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int dst_test_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_dst_test_matrix[3] = {
		dst_test_matrix[0],
		dst_test_matrix[1],
		dst_test_matrix[2]
	};

	matrix_t dst_test = {
		.matrix = p_dst_test_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int reference_matrix[][3] = {
		{-2, -3, -2}, 
		{-5, -1, -1},
		{-4, -2, -2}
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

	fill(src_test, &dst_test);

	ck_assert_int_eq(reference.rows, dst_test.rows);
	ck_assert_int_eq(reference.columns, dst_test.columns);
	ck_assert_int_eq(reference.const_rows, dst_test.const_rows);
	ck_assert_int_eq(reference.const_columns, dst_test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], dst_test.matrix[i][j]);
}
END_TEST

// MAIN

Suite *fill_suite(void)
{
	Suite *s;
	TCase *tc_pos;

	s = suite_create("fill");

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_fill_basic);
    tcase_add_test(tc_pos, test_fill_with_neg_elem);
    tcase_add_test(tc_pos, test_fill_more_1_iter);
    tcase_add_test(tc_pos, test_fill_equal_size);
    tcase_add_test(tc_pos, test_fill_all_elems_neg);
    suite_add_tcase(s, tc_pos);

    return s;
}
