#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "matrix.h"

START_TEST(test_swap_columns_basic)
{
    size_t column1 = 0, column2 = 1;

    int test_matrix[][2] = {
        {1, 2},
        {3, 4}
    };

    int *p_test_matrix[2] = {
        test_matrix[0],
        test_matrix[1]
    };

    matrix_t test = {
        .matrix = p_test_matrix,
        .rows = 2,
        .columns = 2
    };

    int reference_matrix[][2] = {
        {2, 1}, 
        {4, 3}
    };

    int *p_reference_matrix[2] = {
        reference_matrix[0],
        reference_matrix[1]
    };

    matrix_t reference = {
        .matrix = p_reference_matrix,
        .rows = 2,
        .columns = 2
    };

    swap_columns(test, column1, column2);

    ck_assert_int_eq(reference.rows, test.rows);
    ck_assert_int_eq(reference.columns, test.columns);

    for (size_t i = 0; i < reference.rows; i++)
        for (size_t j = 0; j < reference.columns; j++)
            ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

START_TEST(test_swap_columns_equal_columns)
{
    size_t column1 = 1, column2 = 1;

    int test_matrix[][2] = {
        {1, 2},
        {3, 4}
    };

    int *p_test_matrix[2] = {
        test_matrix[0],
        test_matrix[1]
    };

    matrix_t test = {
        .matrix = p_test_matrix,
        .rows = 2,
        .columns = 2
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
        .columns = 2
    };

    swap_columns(test, column1, column2);

    ck_assert_int_eq(reference.rows, test.rows);
    ck_assert_int_eq(reference.columns, test.columns);

    for (size_t i = 0; i < reference.rows; i++)
        for (size_t j = 0; j < reference.columns; j++)
            ck_assert_int_eq(reference.matrix[i][j], test.matrix[i][j]);
}
END_TEST

Suite *swap_columns_suite(void)
{
	Suite *s;
	TCase *tc_pos;

	s = suite_create("swap_columns");

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_swap_columns_basic);
    tcase_add_test(tc_pos, test_swap_columns_equal_columns);
    suite_add_tcase(s, tc_pos);

    return s;
}
