#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "list.h"

// POS TESTS

START_TEST(test_sum_basic)
{
	node_t *head_1 = NULL;
	int ratio_1[4] = { 4, 2, 0, 6 };
	for (size_t i = 0; i < 4; i++)
		push(&head_1, ratio_1[i]);

	node_t *head_2 = NULL;
	int ratio_2[3] = { 12, 4, 0 };
	for (size_t i = 0; i < 3; i++)
		push(&head_2, ratio_2[i]);

	node_t *result = NULL;

	node_t *reference = NULL;
	int ratio_ref[4] = { 6, 4, 14, 4 };
	for (size_t i = 0; i < 4; i++)
		push(&reference, ratio_ref[i]);

	result = sum(head_1, head_2);

	node_t *p = result;
	node_t *p_ref = reference;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head_1);
	free_list(&head_2);
	free_list(&reference);
	free_list(&result);
}
END_TEST

START_TEST(test_sum_equal_size)
{
	node_t *head_1 = NULL;
	int ratio_1[4] = { 4, 2, 0, 6 };
	for (size_t i = 0; i < 4; i++)
		push(&head_1, ratio_1[i]);

	node_t *head_2 = NULL;
	int ratio_2[4] = { 1, 1, 1, 1 };
	for (size_t i = 0; i < 4; i++)
		push(&head_2, ratio_2[i]);

	node_t *result = NULL;

	node_t *reference = NULL;
	int ratio_ref[4] = { 7, 1, 3, 5 };
	for (size_t i = 0; i < 4; i++)
		push(&reference, ratio_ref[i]);

	result = sum(head_1, head_2);

	node_t *p = result;
	node_t *p_ref = reference;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head_1);
	free_list(&head_2);
	free_list(&reference);
	free_list(&result);
}
END_TEST

Suite *sum_suite(void)
{
	Suite *s;
	TCase *tc_pos;

	s = suite_create("sum");

	tc_pos = tcase_create("positives");
	tcase_add_test(tc_pos, test_sum_basic);
	tcase_add_test(tc_pos, test_sum_equal_size);
	suite_add_tcase(s, tc_pos);

    return s;
}