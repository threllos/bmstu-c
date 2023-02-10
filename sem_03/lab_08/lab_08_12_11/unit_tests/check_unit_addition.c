#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "matrix.h"

// NEG TESTS

START_TEST(test_addition_size_not_equal_m1_m2)
{
	int rc;
	
	double test1_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2
	};

	double test2_matrix[][3] = {
		{1, 2, 4},
		{3, 7, 5},
		{7, 9, 8}
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
		.columns = 2,
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_addition_size_not_equal_m1_r)
{
	int rc;
	
	double test1_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2
	};

	double test2_matrix[][2] = {
		{1, 2},
		{3, 7}
	};

	double *p_test2_matrix[3] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
		.columns = 2
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
		.columns = 3,
	};

	rc = multiplication(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

// POS TESTS

START_TEST(test_addition_equal_sizes)
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

	double test2_matrix[][4] = {
		{5, 3, 2, 1},
		{1, 2, 2, 1}
	};

	double *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
		.columns = 4
	};

	double result_matrix[][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	double *p_result_matrix[2] = {
		result_matrix[0],
		result_matrix[1]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 2,
		.columns = 4
	};

	double reference_matrix[][4] = {
		{6, 5, 5, 5}, 
		{4, 9, 5, 5}
	};

	double *p_reference_matrix[2] = {
		reference_matrix[0],
		reference_matrix[1]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 2,
		.columns = 4
	};

	rc = addition(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_addition_size_1x1)
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
		{5}
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
		{7}
	};

	double *p_reference_matrix[1] = {
		reference_matrix[0]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 1,
		.columns = 1
	};

	rc = addition(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_addition_null_matrixs)
{
	int rc;
	
	double test1_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2
	};

	double test2_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	double *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
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
		{0, 0}, 
		{0, 0}
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

	rc = addition(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_addition_one_matrix_null)
{
	int rc;
	
	double test1_matrix[][2] = {
		{1, 3},
		{2, 4}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2
	};

	double test2_matrix[][2] = {
		{0, 0},
		{0, 0}
	};

	double *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
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
		{1, 3}, 
		{2, 4}
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

	rc = addition(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_addition_matrix_with_neg_elems)
{
	int rc;
	
	double test1_matrix[][2] = {
		{-2, -2},
		{-7, -3}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2
	};

	double test2_matrix[][2] = {
		{1, -3},
		{-1, 3}
	};

	double *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
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
		{-1, -5}, 
		{-8, 0}
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

	rc = addition(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_addition_matrix_with_double_elems)
{
	int rc;
	
	double test1_matrix[][2] = {
		{1.2, -2.33},
		{0.1, 3}
	};

	double *p_test1_matrix[2] = {
		test1_matrix[0],
		test1_matrix[1]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 2,
		.columns = 2
	};

	double test2_matrix[][2] = {
		{-4, -3.1},
		{1, 2.5}
	};

	double *p_test2_matrix[2] = {
		test2_matrix[0],
		test2_matrix[1]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 2,
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
		{-2.8, -5.43}, 
		{1.1, 5.5}
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

	rc = addition(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

START_TEST(test_addition_big_size)
{
	int rc;
	
	double test1_matrix[][7] = {
		{1, 2, 3, 4, 5, 6, 7},
		{8, 9, 10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19, 20, 21},
		{22, 23, 24, 25, 26, 27, 28},
		{29, 30, 31, 32, 33, 34, 35},
		{36, 37, 38, 39, 40, 41, 42},
		{43, 44, 45, 46, 47, 48, 49}
	};

	double *p_test1_matrix[7] = {
		test1_matrix[0],
		test1_matrix[1],
		test1_matrix[2],
		test1_matrix[3],
		test1_matrix[4],
		test1_matrix[5],
		test1_matrix[6]
	};

	matrix_t test1 = {
		.matrix = p_test1_matrix,
		.rows = 7,
		.columns = 7
	};

	double test2_matrix[][7] = {
		{49, 48, 47, 46, 45, 44, 43},
		{42, 41, 40, 39, 38, 37, 36},
		{35, 34, 33, 32, 31, 30, 29},
		{28, 27, 26, 25, 24, 23, 22},
		{21, 20, 19, 18, 17, 16, 15},
		{14, 13, 12, 11, 10, 9, 8},
		{7, 6, 5, 4, 3, 2, 1}
	};

	double *p_test2_matrix[7] = {
		test2_matrix[0],
		test2_matrix[1],
		test2_matrix[2],
		test2_matrix[3],
		test2_matrix[4],
		test2_matrix[5],
		test2_matrix[6]
	};

	matrix_t test2 = {
		.matrix = p_test2_matrix,
		.rows = 7,
		.columns = 7
	};

	double result_matrix[][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0}
	};

	double *p_result_matrix[7] = {
		result_matrix[0],
		result_matrix[1],
		result_matrix[2],
		result_matrix[3],
		result_matrix[4],
		result_matrix[5],
		result_matrix[6]
	};

	matrix_t result = {
		.matrix = p_result_matrix,
		.rows = 7,
		.columns = 7
	};

	double reference_matrix[][7] = {
		{50, 50, 50, 50, 50, 50, 50},
		{50, 50, 50, 50, 50, 50, 50},
		{50, 50, 50, 50, 50, 50, 50},
		{50, 50, 50, 50, 50, 50, 50},
		{50, 50, 50, 50, 50, 50, 50},
		{50, 50, 50, 50, 50, 50, 50},
		{50, 50, 50, 50, 50, 50, 50}
	};

	double *p_reference_matrix[7] = {
		reference_matrix[0],
		reference_matrix[1],
		reference_matrix[2],
		reference_matrix[3],
		reference_matrix[4],
		reference_matrix[5],
		reference_matrix[6]
	};

	matrix_t reference = {
		.matrix = p_reference_matrix,
		.rows = 7,
		.columns = 7
	};

	rc = addition(test1, test2, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_int_eq(reference.rows, result.rows);
	ck_assert_int_eq(reference.columns, result.columns);

	for (size_t i = 0; i < reference.rows; i++)
		for (size_t j = 0; j < reference.columns; j++)
			ck_assert_double_eq(reference.matrix[i][j], result.matrix[i][j]);
}
END_TEST

// MAIN

Suite *addition_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("addition");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_addition_size_not_equal_m1_m2);
	tcase_add_test(tc_neg, test_addition_size_not_equal_m1_r);
	suite_add_tcase(s, tc_neg);


	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_addition_equal_sizes);
    tcase_add_test(tc_pos, test_addition_size_1x1);
    tcase_add_test(tc_pos, test_addition_null_matrixs);
    tcase_add_test(tc_pos, test_addition_one_matrix_null);
    tcase_add_test(tc_pos, test_addition_matrix_with_neg_elems);
    tcase_add_test(tc_pos, test_addition_matrix_with_double_elems);
    tcase_add_test(tc_pos, test_addition_big_size);
    suite_add_tcase(s, tc_pos);

    return s;
}
