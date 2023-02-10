#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "list.h"

// POS TESTS

START_TEST(test_dvd_basic)
{
	node_t *head = NULL;
	int ratio[4] = { 4, 2, 0, 6 };
	for (size_t i = 0; i < 4; i++)
		push(&head, ratio[i]);

	node_t *even = NULL;
	node_t *odd = NULL;

	node_t *reference_even = NULL;
	int ratio_ref_even[2] = { 6, 2 };
	for (size_t i = 0; i < 2; i++)
		push(&reference_even, ratio_ref_even[i]);

	node_t *reference_odd = NULL;
	int ratio_ref_odd[2] = { 0, 4 };
	for (size_t i = 0; i < 2; i++)
		push(&reference_odd, ratio_ref_odd[i]);

	dvd(head, &even, &odd);

	node_t *p = even;
	node_t *p_ref = reference_even;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	p = odd;
	p_ref = reference_odd;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head);
	free_list(&even);
	free_list(&odd);
	free_list(&reference_even);
	free_list(&reference_odd);
}
END_TEST

START_TEST(test_dvd_even_more)
{
	node_t *head = NULL;
	int ratio[5] = { 1, 4, 2, 0, 6 };
	for (size_t i = 0; i < 5; i++)
		push(&head, ratio[i]);

	node_t *even = NULL;
	node_t *odd = NULL;

	node_t *reference_even = NULL;
	int ratio_ref_even[3] = { 6, 2, 1 };
	for (size_t i = 0; i < 3; i++)
		push(&reference_even, ratio_ref_even[i]);

	node_t *reference_odd = NULL;
	int ratio_ref_odd[2] = { 0, 4 };
	for (size_t i = 0; i < 2; i++)
		push(&reference_odd, ratio_ref_odd[i]);

	dvd(head, &even, &odd);

	node_t *p = even;
	node_t *p_ref = reference_even;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	p = odd;
	p_ref = reference_odd;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head);
	free_list(&even);
	free_list(&odd);
	free_list(&reference_even);
	free_list(&reference_odd);
}
END_TEST

START_TEST(test_dvd_no_odd)
{
	node_t *head = NULL;
	int ratio[1] = { 6 };
	for (size_t i = 0; i < 1; i++)
		push(&head, ratio[i]);

	node_t *even = NULL;
	node_t *odd = NULL;

	node_t *reference_even = NULL;
	int ratio_ref_even[1] = { 6 };
	for (size_t i = 0; i < 1; i++)
		push(&reference_even, ratio_ref_even[i]);

	node_t *reference_odd = NULL;

	dvd(head, &even, &odd);

	node_t *p = even;
	node_t *p_ref = reference_even;
	while (p)
	{
		ck_assert_int_eq(p->ratio, p_ref->ratio);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	ck_assert_ptr_eq(odd, reference_odd);

	free_list(&head);
	free_list(&even);
	free_list(&odd);
	free_list(&reference_even);
	free_list(&reference_odd);
}
END_TEST

Suite *dvd_suite(void)
{
	Suite *s;
	TCase *tc_pos;

	s = suite_create("dvd");

	tc_pos = tcase_create("positives");
	tcase_add_test(tc_pos, test_dvd_basic);
	tcase_add_test(tc_pos, test_dvd_even_more);
	tcase_add_test(tc_pos, test_dvd_no_odd);
	suite_add_tcase(s, tc_pos);

    return s;
}