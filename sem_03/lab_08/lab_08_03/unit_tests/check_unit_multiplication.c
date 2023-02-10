#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "matrix.h"

// NEG TESTS

START_TEST(test_multiplication_size_not_equal_m1_m2)
{
	int rc;
	
	int test1_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int test2_matrix[][3] = {
		{1, 2, 4},
		{3, 7, 5},
		{7, 9, 8}
	};

	int *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int result_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	int *p_result_matrix[3] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_multiplication_size_not_equal_m1_r)
{
	int rc;
	
	int test1_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int test2_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_result_matrix[3] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_multiplication_m1_not_square)
{
	int rc;
	
	int test1_matrix[][3] = {
		{1, 2, 3},
		{3, 7, 7}
	};

	int *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 3,
		.const_rows = 2,
		.const_columns = 3
	};

	int test2_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int result_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	int *p_result_matrix[2] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_multiplication_m2_not_square)
{
	int rc;
	
	int test1_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int test2_matrix[][3] = {
		{1, 2, 7},
		{3, 7, 9}
	};

	int *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
		.columns = 3,
		.const_rows = 2,
		.const_columns = 3
	};

	int result_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	int *p_result_matrix[2] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_multiplication_r_not_square)
{
	int rc;
	
	int test1_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int test2_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_result_matrix[2] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 3,
		.const_rows = 2,
		.const_columns = 3
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

// POS TESTS

START_TEST(test_multiplication_basic)
{
	int rc;
	
	int test1_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int test2_matrix[][2] = {
		{5, 3},
		{1, 2}
	};

	int *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int result_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	int *p_result_matrix[2] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int reference_matrix[][2] = {
		{7, 7}, 
		{22, 23}
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

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);
	ck_assert_int_eq(reference.const_rows, result.const_rows);
	ck_assert_int_eq(reference.const_columns, result.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_size_1x1)
{
	int rc;
	
	int test1_matrix[][1] = {
		{2}
	};

	int *p_test1_matrix[1] = {
		test1_matrix[0]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 1,
		.columns = 1,
		.const_rows = 1,
		.const_columns = 1
	};

	int test2_matrix[][1] = {
		{3}
	};

	int *p_test2_matrix[1] = {
		test2_matrix[0]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 1,
		.columns = 1,
		.const_rows = 1,
		.const_columns = 1
	};

	int result_matrix[][1] = {
		{0}
	};

	int *p_result_matrix[1] = {
		result_matrix[0]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 1,
		.columns = 1,
		.const_rows = 1,
		.const_columns = 1
	};

	int reference_matrix[][1] = {
		{6}
	};

	int *p_reference_matrix[1] = {
		reference_matrix[0]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 1,
		.columns = 1,
		.const_rows = 1,
		.const_columns = 1
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);
	ck_assert_int_eq(reference.const_rows, result.const_rows);
	ck_assert_int_eq(reference.const_columns, result.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_equal_matrix)
{
	int rc;
	
	int test1_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int test2_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	int *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int result_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	int *p_result_matrix[2] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 2,
		.const_rows = 2,
		.const_columns = 2
	};

	int reference_matrix[][2] = {
		{7, 16}, 
		{24, 55}
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

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);
	ck_assert_int_eq(reference.const_rows, result.const_rows);
	ck_assert_int_eq(reference.const_columns, result.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_identity_matrix)
{
	int rc;
	
	int test1_matrix[][3] = {
		{1, 2, 8},
		{3, 7, 9},
		{-2, 0, 2}
	};

	int *p_test1_matrix[3] = {
		test1_matrix[0],
		test1_matrix[1],
		test1_matrix[2]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int test2_matrix[][3] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};

	int *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_result_matrix[3] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int reference_matrix[][3] = {
		{1, 2, 8},
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

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);
	ck_assert_int_eq(reference.const_rows, result.const_rows);
	ck_assert_int_eq(reference.const_columns, result.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_multiplication_zero_matrix)
{
	int rc;
	
	int test1_matrix[][3] = {
		{1, 2, 8},
		{3, 7, 9},
		{-2, 0, 2}
	};

	int *p_test1_matrix[3] = {
		test1_matrix[0],
		test1_matrix[1],
		test1_matrix[2]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int test2_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int result_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	int *p_result_matrix[3] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 3,
		.columns = 3,
		.const_rows = 3,
		.const_columns = 3
	};

	int reference_matrix[][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
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

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);
	ck_assert_int_eq(reference.const_rows, result.const_rows);
	ck_assert_int_eq(reference.const_columns, result.const_columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_int_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

// MAIN

Suite *multiplication_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("multiplication");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_multiplication_size_not_equal_m1_m2);
	tcase_add_test(tc_neg, test_multiplication_size_not_equal_m1_r);
	tcase_add_test(tc_neg, test_multiplication_m1_not_square);
	tcase_add_test(tc_neg, test_multiplication_m2_not_square);
	tcase_add_test(tc_neg, test_multiplication_r_not_square);
	suite_add_tcase(s, tc_neg);


	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_multiplication_basic);
    tcase_add_test(tc_pos, test_multiplication_size_1x1);
    tcase_add_test(tc_pos, test_multiplication_equal_matrix);
    tcase_add_test(tc_pos, test_multiplication_identity_matrix);
    tcase_add_test(tc_pos, test_multiplication_zero_matrix);
    suite_add_tcase(s, tc_pos);

    return s;
}
