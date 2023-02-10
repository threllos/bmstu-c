#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>
#include "matrix.h"

// NEG TESTS

START_TEST(test_multiplication_columns_not_equal_rows)
{
	int rc;
	
	double test1_matrix[][3] = {
		{1, 2, 2},
		{3, 7, 2}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 3
	};

	double test2_matrix[][3] = {
		{1, 2, 4},
		{3, 7, 5}
	};

	double *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
		.columns = 3
	};

	double result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_result_matrix[2] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 3,
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_multiplication_rows_not_equal_m1_r)
{
	int rc;
	
	double test1_matrix[][3] = {
		{1, 2, 2},
		{3, 7, 2}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 3
	};

	double test2_matrix[][2] = {
		{1, 2},
		{3, 7},
		{2, 5}
	};

	double *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 2
	};

	double result_matrix[][2] = {
		{0, 0},
		{0, 0},
		{0, 0}
	};

	double *p_result_matrix[3] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 3,
		.columns = 2,
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_multiplication_columns_not_equal_m2_r)
{
	int rc;
	
	double test1_matrix[][3] = {
		{1, 2, 2},
		{3, 7, 2}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 3
	};

	double test2_matrix[][2] = {
		{1, 2},
		{3, 7},
		{2, 5}
	};

	double *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 2
	};

	double result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_result_matrix[2] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 3,
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

// POS TESTS

START_TEST(test_multiplication_not_square_matrix)
{
	int rc;
	
	double test1_matrix[][4] = {
		{1, 2, 3, 4},
		{3, 7, 3, 4}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 4
	};

	double test2_matrix[][2] = {
		{5, 3},
		{1, 2},
		{3, 7},
		{9, 1}
	};

	double *p_test2_matrix[4] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2],
		test2_matrix[3]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 4,
		.columns = 2
	};

	double result_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	double *p_result_matrix[2] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 2
	};

	double reference_matrix[][2] = {
		{52, 32},
		{67, 48}
	};

	double *p_reference_matrix[2] = {
		reference_matrix[0],
		reference_matrix[1]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 2,
		.columns = 2
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_size_1x1)
{
	int rc;
	
	double test1_matrix[][1] = {
		{2}
	};

	double *p_test1_matrix[1] = {
		test1_matrix[0]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 1,
		.columns = 1
	};

	double test2_matrix[][1] = {
		{3}
	};

	double *p_test2_matrix[1] = {
		test2_matrix[0]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 1,
		.columns = 1
	};

	double result_matrix[][1] = {
		{0}
	};

	double *p_result_matrix[1] = {
		result_matrix[0]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 1,
		.columns = 1
	};

	double reference_matrix[][1] = {
		{6}
	};

	double *p_reference_matrix[1] = {
		reference_matrix[0]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 1,
		.columns = 1
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_square_matrix)
{
	int rc;
	
	double test1_matrix[][3] = {
		{1, 2, 3},
		{5, 2, 1},
		{7, 2, 3}
	};

	double *p_test1_matrix[3] = {
		test1_matrix[0],
		test1_matrix[1],
		test1_matrix[2]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 3,
		.columns = 3
	};

	double test2_matrix[][3] = {
		{5, 3, 11},
		{1, 2, 7},
		{3, 7, 1}
	};

	double *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 3
	};

	double result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_result_matrix[3] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 3,
		.columns = 3
	};

	double reference_matrix[][3] = {
		{16, 28, 28},
		{30, 26, 70},
		{46, 46, 94}
	};

	double *p_reference_matrix[3] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 3,
		.columns = 3
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_equal_matrix)
{
	int rc;
	
	double test1_matrix[][3] = {
		{1, 2, 3},
		{5, 2, 1},
		{7, 2, 3}
	};

	double *p_test1_matrix[3] = {
		test1_matrix[0],
		test1_matrix[1],
		test1_matrix[2]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 3,
		.columns = 3
	};

	double test2_matrix[][3] = {
		{1, 2, 3},
		{5, 2, 1},
		{7, 2, 3}
	};

	double *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 3
	};

	double result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_result_matrix[3] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 3,
		.columns = 3
	};

	double reference_matrix[][3] = {
		{32, 12, 14},
		{22, 16, 20},
		{38, 24, 32}
	};

	double *p_reference_matrix[3] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 3,
		.columns = 3
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_identity_matrix)
{
	int rc;
	
	double test1_matrix[][3] = {
		{1, 2, 3},
		{5, 2, 1},
		{7, 2, 3},
		{9, 8, 7}
	};

	double *p_test1_matrix[4] = {
		test1_matrix[0],
		test1_matrix[1],
		test1_matrix[2],
		test1_matrix[3]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 4,
		.columns = 3
	};

	double test2_matrix[][3] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};

	double *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 3
	};

	double result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_result_matrix[4] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2],
		result_matrix[3]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 4,
		.columns = 3
	};

	double reference_matrix[][3] = {
		{1, 2, 3},
		{5, 2, 1},
		{7, 2, 3},
		{9, 8, 7}
	};

	double *p_reference_matrix[4] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2],
		reference_matrix[3]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 4,
		.columns = 3
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_null_matrix)
{
	int rc;
	
	double test1_matrix[][3] = {
		{1, 2, 3},
		{5, 2, 1},
		{7, 2, 3},
		{9, 8, 7}
	};

	double *p_test1_matrix[4] = {
		test1_matrix[0],
		test1_matrix[1],
		test1_matrix[2],
		test1_matrix[3]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 4,
		.columns = 3
	};

	double test2_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 3
	};

	double result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_result_matrix[4] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2],
		result_matrix[3]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 4,
		.columns = 3
	};

	double reference_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_reference_matrix[4] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2],
		reference_matrix[3]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 4,
		.columns = 3
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_neg_elems)
{
	int rc;
	
	double test1_matrix[][3] = {
		{-2, 2, 3},
		{5, 2, -1},
		{-4, 2, 3},
		{9, 8, -3}
	};

	double *p_test1_matrix[4] = {
		test1_matrix[0],
		test1_matrix[1],
		test1_matrix[2],
		test1_matrix[3]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 4,
		.columns = 3
	};

	double test2_matrix[][3] = {
		{-1, 5, 3},
		{0, -2, 1},
		{7, 8, 3}
	};

	double *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 3
	};

	double result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_result_matrix[4] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2],
		result_matrix[3]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 4,
		.columns = 3
	};

	double reference_matrix[][3] = {
		{23, 10, 5},
		{-12, 13, 14},
		{25, 0, -1},
		{-30, 5, 26}
	};

	double *p_reference_matrix[4] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2],
		reference_matrix[3]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 4,
		.columns = 3
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_double_elems)
{
	int rc;
	
	double test1_matrix[][3] = {
		{1, 6, 4},
		{3, 8.4, -4.2},
		{-3, -9, 4},
		{3.2, 8, 4.5}
	};

	double *p_test1_matrix[4] = {
		test1_matrix[0],
		test1_matrix[1],
		test1_matrix[2],
		test1_matrix[3]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 4,
		.columns = 3
	};

	double test2_matrix[][3] = {
		{2, 9, -6},
		{-4, -6, 4},
		{2, 5.2, 3.4}
	};

	double *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 3
	};

	double result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	double *p_result_matrix[4] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2],
		result_matrix[3]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 4,
		.columns = 3
	};

	double reference_matrix[][3] = {
		{-14, -6.2, 31.6},
		{-36, -45.24, 1.32},
		{38, 47.8, -4.4},
		{-16.6, 4.2, 28.1}
	};

	double *p_reference_matrix[4] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2],
		reference_matrix[3]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 4,
		.columns = 3
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
		{
			if (fabs(reference.matrix[i][j] - result.matrix[i][j]) < 1e-6)
				ck_assert_double_eq(0, 0);
			else
				ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
		}
}
END_TEST

// MAIN

Suite *multiplication_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("multiplication");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_multiplication_columns_not_equal_rows);
	tcase_add_test(tc_neg, test_multiplication_rows_not_equal_m1_r);
	tcase_add_test(tc_neg, test_multiplication_columns_not_equal_m2_r);
	suite_add_tcase(s, tc_neg);


	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_multiplication_not_square_matrix);
    tcase_add_test(tc_pos, test_multiplication_size_1x1);
    tcase_add_test(tc_pos, test_multiplication_square_matrix);
    tcase_add_test(tc_pos, test_multiplication_equal_matrix);
    tcase_add_test(tc_pos, test_multiplication_identity_matrix);
    tcase_add_test(tc_pos, test_multiplication_null_matrix);
    tcase_add_test(tc_pos, test_multiplication_neg_elems);
    tcase_add_test(tc_pos, test_multiplication_double_elems);
    suite_add_tcase(s, tc_pos);

    return s;
}
