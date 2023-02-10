#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "list.h"

// POS TESTS

START_TEST(test_val_basic)
{
	int a = 7;
	node_t *head = NULL;
	int ratio[4] = { 4, 2, 0, 6 };
	int result;
	int reference = 1476;

	for (size_t i = 0; i < 4; i++)
		push(&head, ratio[i]);

	result = val(head, a);

	ck_assert_int_eq(result, reference);

	free_list(&head);
}
END_TEST

START_TEST(test_val_all_ratio_unit)
{
	int a = 5;
	node_t *head = NULL;
	int ratio[3] = { 1, 1, 1 };
	int result;
	int reference = 31;

	for (size_t i = 0; i < 3; i++)
		push(&head, ratio[i]);

	result = val(head, a);

	ck_assert_int_eq(result, reference);

	free_list(&head);
}
END_TEST

START_TEST(test_val_all_ratio_zero)
{
	int a = 5;
	node_t *head = NULL;
	int ratio[3] = { 0, 0, 0 };
	int result;
	int reference = 0;

	for (size_t i = 0; i < 3; i++)
		push(&head, ratio[i]);

	result = val(head, a);

	ck_assert_int_eq(result, reference);

	free_list(&head);
}
END_TEST

START_TEST(test_val_one_ratio)
{
	int a = 12;
	node_t *head = NULL;
	int ratio[1] = { 5 };
	int result;
	int reference = 5;

	for (size_t i = 0; i < 1; i++)
		push(&head, ratio[i]);

	result = val(head, a);

	ck_assert_int_eq(result, reference);

	free_list(&head);
}
END_TEST

START_TEST(test_val_a_is_zero)
{
	int a = 0;
	node_t *head = NULL;
	int ratio[3] = { 4, 1, 2 };
	int result;
	int reference = 2;

	for (size_t i = 0; i < 3; i++)
		push(&head, ratio[i]);

	result = val(head, a);

	ck_assert_int_eq(result, reference);

	free_list(&head);
}
END_TEST

Suite *val_suite(void)
{
	Suite *s;
	TCase *tc_pos;

	s = suite_create("val");

	tc_pos = tcase_create("positives");
	tcase_add_test(tc_pos, test_val_basic);
	tcase_add_test(tc_pos, test_val_all_ratio_unit);
	tcase_add_test(tc_pos, test_val_all_ratio_zero);
	tcase_add_test(tc_pos, test_val_one_ratio);
	tcase_add_test(tc_pos, test_val_a_is_zero);
	suite_add_tcase(s, tc_pos);

    return s;
}
