#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "matrix.h"

// POS TESTS

START_TEST(test_make_square_del_rows)
{
	int test_matrix[][2] = {
		{1, 2},
		{3, 7}, 
		{5, 6}
	};

	int *p_test_matrix[3] = {
		test_matrix[0],
		test_matrix[1],
		test_matrix[2]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 3,
		.columns = 2,
		.const_rows = 3,
		.const_columns = 2,
	};

	int reference_matrix[][2] = {
		{1, 2}, 
		{5, 6}
	};

	int *p_reference_matrix[2] = {
		reference_matrix[0],
		reference_matrix[1]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 3,
		.const_columns = 2,
	};

	make_square(&test);

	ck_assert_int_eq(reference.rows, test.rows);
	ck_assert_int_eq(reference.columns, test.columns);
	ck_assert_int_eq(reference.const_rows, test.const_rows);
	ck_assert_int_eq(reference.const_columns, test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

START_TEST(test_make_square_del_columns)
{
	int test_matrix[][3] = {
		{1, 2, 3},
		{3, 7, 5}
	};

	int *p_test_matrix[2] = {
		test_matrix[0],
		test_matrix[1]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 2,
		.columns = 3,
		.const_rows = 2,
		.const_columns = 3,
	};

	int reference_matrix[][2] = {
		{1, 3}, 
		{3, 5}
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
		.const_columns = 3,
	};

	make_square(&test);

	ck_assert_int_eq(reference.rows, test.rows);
	ck_assert_int_eq(reference.columns, test.columns);
	ck_assert_int_eq(reference.const_rows, test.const_rows);
	ck_assert_int_eq(reference.const_columns, test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

START_TEST(test_make_square_no_change)
{
	int test_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test_matrix[2] = {
		test_matrix[0],
		test_matrix[1]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2,
	};

	int reference_matrix[][2] = {
		{1, 2}, 
		{3, 7}
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
		.const_columns = 2,
	};

	make_square(&test);

	ck_assert_int_eq(reference.rows, test.rows);
	ck_assert_int_eq(reference.columns, test.columns);
	ck_assert_int_eq(reference.const_rows, test.const_rows);
	ck_assert_int_eq(reference.const_columns, test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

START_TEST(test_make_square_del_rows_all_elems_equal)
{
	int test_matrix[][2] = {
		{7, 7},
		{7, 7},
		{7, 7}
	};

	int *p_test_matrix[3] = {
		test_matrix[0],
		test_matrix[1],
		test_matrix[2]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 3,
		.columns = 2,
		.const_rows = 3,
		.const_columns = 2,
	};

	int reference_matrix[][2] = {
		{7, 7}, 
		{7, 7}
	};

	int *p_reference_matrix[2] = {
		reference_matrix[0],
		reference_matrix[1]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 3,
		.const_columns = 2,
	};

	make_square(&test);

	ck_assert_int_eq(reference.rows, test.rows);
	ck_assert_int_eq(reference.columns, test.columns);
	ck_assert_int_eq(reference.const_rows, test.const_rows);
	ck_assert_int_eq(reference.const_columns, test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

START_TEST(test_make_square_del_columns_all_elems_equal)
{
	int test_matrix[][3] = {
		{7, 7, 7},
		{7, 7, 7}
	};

	int *p_test_matrix[2] = {
		test_matrix[0],
		test_matrix[1]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 2,
		.columns = 3,
		.const_rows = 2,
		.const_columns = 3,
	};

	int reference_matrix[][2] = {
		{7, 7}, 
		{7, 7}
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
		.const_columns = 3,
	};

	make_square(&test);

	ck_assert_int_eq(reference.rows, test.rows);
	ck_assert_int_eq(reference.columns, test.columns);
	ck_assert_int_eq(reference.const_rows, test.const_rows);
	ck_assert_int_eq(reference.const_columns, test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

START_TEST(test_make_square_all_elem_neg)
{
	int test_matrix[][3] = {
		{-2, -1, -3},
		{-4, -5, -6}
	};

	int *p_test_matrix[2] = {
		test_matrix[0],
		test_matrix[1]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 2,
		.columns = 3,
		.const_rows = 2,
		.const_columns = 3,
	};

	int reference_matrix[][2] = {
		{-2, -3}, 
		{-4, -6}
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
		.const_columns = 3,
	};

	make_square(&test);

	ck_assert_int_eq(reference.rows, test.rows);
	ck_assert_int_eq(reference.columns, test.columns);
	ck_assert_int_eq(reference.const_rows, test.const_rows);
	ck_assert_int_eq(reference.const_columns, test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

START_TEST(test_make_square_del_more_1_row)
{
	int test_matrix[][2] = {
		{1, 2},
		{7, 8},
		{5, 6},
		{3, 4},
		{9, 9},
	};

	int *p_test_matrix[5] = {
		test_matrix[0],
		test_matrix[1],
		test_matrix[2],
		test_matrix[3],
		test_matrix[4]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 5,
		.columns = 2,
		.const_rows = 5,
		.const_columns = 2,
	};

	int reference_matrix[][2] = {
		{1, 2}, 
		{3, 4}
	};

	int *p_reference_matrix[2] = {
		reference_matrix[0],
		reference_matrix[1]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 5,
		.const_columns = 2,
	};

	make_square(&test);

	ck_assert_int_eq(reference.rows, test.rows);
	ck_assert_int_eq(reference.columns, test.columns);
	ck_assert_int_eq(reference.const_rows, test.const_rows);
	ck_assert_int_eq(reference.const_columns, test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

START_TEST(test_make_square_del_more_1_column)
{
	int test_matrix[][5] = {
		{1, 2, 2, 4, 5},
		{3, 7, 4, 9, 9}
	};

	int *p_test_matrix[2] = {
		test_matrix[0],
		test_matrix[1]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 2,
		.columns = 5,
		.const_rows = 2,
		.const_columns = 5,
	};

	int reference_matrix[][2] = {
		{1, 2}, 
		{3, 4}
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
		.const_columns = 5,
	};

	make_square(&test);

	ck_assert_int_eq(reference.rows, test.rows);
	ck_assert_int_eq(reference.columns, test.columns);
	ck_assert_int_eq(reference.const_rows, test.const_rows);
	ck_assert_int_eq(reference.const_columns, test.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

// MAIN

Suite *make_square_suite(void)
{
	Suite *s;
	TCase *tc_pos;

	s = suite_create("make_square");

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_make_square_del_rows);
    tcase_add_test(tc_pos, test_make_square_del_columns);
    tcase_add_test(tc_pos, test_make_square_no_change);
    tcase_add_test(tc_pos, test_make_square_del_rows_all_elems_equal);
    tcase_add_test(tc_pos, test_make_square_del_columns_all_elems_equal);
    tcase_add_test(tc_pos, test_make_square_all_elem_neg);
    tcase_add_test(tc_pos, test_make_square_del_more_1_row);
    tcase_add_test(tc_pos, test_make_square_del_more_1_column);
    suite_add_tcase(s, tc_pos);

    return s;
}
