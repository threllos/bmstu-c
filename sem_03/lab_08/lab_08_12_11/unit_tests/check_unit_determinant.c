#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <check.h>
#include "matrix.h"

// NEG TESTS

START_TEST(test_determinant_not_square_matrix)
{
	int rc;
	
	double test_matrix[][3] = {
		{1, 2, 2},
		{3, 7, 2}
	};

	double *p_test_matrix[2] = {
		test_matrix[0],
		test_matrix[1]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 2,
		.columns = 3
	};

	double result = 0;

	rc = determinant(test, &result);

	ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

// POS TESTS

START_TEST(test_determinant_size_1x1)
{
	int rc;
	
	double test_matrix[][1] = {
		{3}
	};

	double *p_test_matrix[1] = {
		test_matrix[0]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 1,
		.columns = 1
	};

	double result = 0;

	double reference = 3;

	rc = determinant(test, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_double_eq(result, reference);
}
END_TEST

START_TEST(test_determinant_size_2x2)
{
	int rc;
	
	double test_matrix[][2] = {
		{3, 4},
		{5, 7}
	};

	double *p_test_matrix[2] = {
		test_matrix[0],
		test_matrix[1]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 2,
		.columns = 2
	};

	double result = 0;

	double reference = 1;

	rc = determinant(test, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_double_eq(result, reference);
}
END_TEST

START_TEST(test_determinant_size_3x3)
{
	int rc;
	
	double test_matrix[][3] = {
		{3, 4, 2},
		{5, 7, 9},
		{11, 2, 4}
	};

	double *p_test_matrix[3] = {
		test_matrix[0],
		test_matrix[1],
		test_matrix[2]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 3,
		.columns = 3
	};

	double result = 0;

	double reference = 212;

	rc = determinant(test, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_double_eq(result, reference);
}
END_TEST

START_TEST(test_determinant_size_4x4)
{
	int rc;
	
	double test_matrix[][4] = {
		{3, 4, 2, 7},
		{5, 7, 9, 2},
		{11, 2, 4, 3},
		{9, 3, 3, 4}
	};

	double *p_test_matrix[4] = {
		test_matrix[0],
		test_matrix[1],
		test_matrix[2],
		test_matrix[3]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 4,
		.columns = 4
	};

	double result = 0;

	double reference = -436;

	rc = determinant(test, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_double_eq(result, reference);
}
END_TEST

START_TEST(test_determinant_row_null)
{
	int rc;
	
	double test_matrix[][4] = {
		{3, 4, 2, 7},
		{0, 0, 0, 0},
		{11, 2, 4, 3},
		{9, 3, 3, 4}
	};

	double *p_test_matrix[4] = {
		test_matrix[0],
		test_matrix[1],
		test_matrix[2],
		test_matrix[3]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 4,
		.columns = 4
	};

	double result = 0;

	double reference = 0;

	rc = determinant(test, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_double_eq(result, reference);
}
END_TEST

START_TEST(test_determinant_column_null)
{
	int rc;
	
	double test_matrix[][4] = {
		{3, 0, 2, 7},
		{6, 0, 5, 13},
		{11, 0, 4, 3},
		{9, 0, 3, 4}
	};

	double *p_test_matrix[4] = {
		test_matrix[0],
		test_matrix[1],
		test_matrix[2],
		test_matrix[3]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 4,
		.columns = 4
	};

	double result = 0;

	double reference = 0;

	rc = determinant(test, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_double_eq(result, reference);
}
END_TEST

START_TEST(test_determinant_equal_elems)
{
	int rc;
	
	double test_matrix[][4] = {
		{7, 7, 7, 7},
		{7, 7, 7, 7},
		{7, 7, 7, 7},
		{7, 7, 7, 7}
	};

	double *p_test_matrix[4] = {
		test_matrix[0],
		test_matrix[1],
		test_matrix[2],
		test_matrix[3]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 4,
		.columns = 4
	};

	double result = 0;

	double reference = 0;

	rc = determinant(test, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_double_eq(result, reference);
}
END_TEST

START_TEST(test_determinant_equal_rows)
{
	int rc;
	
	double test_matrix[][4] = {
		{7, 1, 3, 4},
		{7, 1, 3, 4},
		{7, 1, 3, 4},
		{7, 1, 3, 4}
	};

	double *p_test_matrix[4] = {
		test_matrix[0],
		test_matrix[1],
		test_matrix[2],
		test_matrix[3]
	};

	matrix_t test = {
		.matrix = p_test_matrix,
		.rows = 4,
		.columns = 4
	};

	double result = 0;

	double reference = 0;

	rc = determinant(test, &result);

	ck_assert_int_eq(rc, EXIT_SUCCESS);	

	ck_assert_double_eq(result, reference);
}
END_TEST

// MAIN

Suite *determinant_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("determinant");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_determinant_not_square_matrix);
	suite_add_tcase(s, tc_neg);


	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_determinant_size_1x1);
    tcase_add_test(tc_pos, test_determinant_size_2x2);
    tcase_add_test(tc_pos, test_determinant_size_3x3);
    tcase_add_test(tc_pos, test_determinant_size_4x4);
    tcase_add_test(tc_pos, test_determinant_row_null);
    tcase_add_test(tc_pos, test_determinant_column_null);
    tcase_add_test(tc_pos, test_determinant_equal_elems);
    tcase_add_test(tc_pos, test_determinant_equal_rows);
    suite_add_tcase(s, tc_pos);

    return s;
}
