#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "list.h"

// POS TESTS

START_TEST(test_ddx_basic)
{
	node_t *head = NULL;
	int ratio[4] = { 4, 2, 0, 6 };
	for (size_t i = 0; i < 4; i++)
		push(&head, ratio[i]);

	node_t *result = NULL;

	node_t *reference = NULL;
	int ratio_ref[3] = { 0, 4, 12 };
	for (size_t i = 0; i < 3; i++)
		push(&reference, ratio_ref[i]);

	result = ddx(head);

	node_t *p = result;
	node_t *p_ref = reference;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head);
	free_list(&reference);
	free_list(&result);
}
END_TEST

START_TEST(test_ddx_all_ratio_zero)
{
	node_t *head = NULL;
	int ratio[4] = { 0, 0, 0, 0 };
	for (size_t i = 0; i < 4; i++)
		push(&head, ratio[i]);

	node_t *result = NULL;

	node_t *reference = NULL;
	int ratio_ref[3] = { 0, 0, 0 };
	for (size_t i = 0; i < 3; i++)
		push(&reference, ratio_ref[i]);

	result = ddx(head);

	node_t *p = result;
	node_t *p_ref = reference;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head);
	free_list(&reference);
	free_list(&result);
}
END_TEST

START_TEST(test_ddx_all_ratio_unit)
{
	node_t *head = NULL;
	int ratio[4] = { 1, 1, 1, 1 };
	for (size_t i = 0; i < 4; i++)
		push(&head, ratio[i]);

	node_t *result = NULL;

	node_t *reference = NULL;
	int ratio_ref[3] = { 1, 2, 3 };
	for (size_t i = 0; i < 3; i++)
		push(&reference, ratio_ref[i]);

	result = ddx(head);

	node_t *p = result;
	node_t *p_ref = reference;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head);
	free_list(&reference);
	free_list(&result);
}
END_TEST

START_TEST(test_ddx_one_ratio)
{
	node_t *head = NULL;
	int ratio[1] = { 6 };
	for (size_t i = 0; i < 1; i++)
		push(&head, ratio[i]);

	node_t *result = NULL;

	node_t *reference = NULL;

	result = ddx(head);

	ck_assert_ptr_eq(result, reference);

	free_list(&head);
	free_list(&reference);
	free_list(&result);
}
END_TEST

Suite *ddx_suite(void)
{
	Suite *s;
	TCase *tc_pos;

	s = suite_create("ddx");

	tc_pos = tcase_create("positives");
	tcase_add_test(tc_pos, test_ddx_basic);
	tcase_add_test(tc_pos, test_ddx_all_ratio_zero);
	tcase_add_test(tc_pos, test_ddx_all_ratio_unit);
	tcase_add_test(tc_pos, test_ddx_one_ratio);
	suite_add_tcase(s, tc_pos);

    return s;
}