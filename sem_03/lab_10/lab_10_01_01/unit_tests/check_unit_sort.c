#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "list.h"

// NEG TESTS

START_TEST(test_sort_cmp_null)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2005 },
									 { 2, 12, 2012 },
									 { 3, 2, 1989 },
									 { 2, 2, 1999 } },
						  .len = 4 };

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *result = sort(head, NULL);

	ck_assert_ptr_eq(result, NULL);

	free_list(&head);
}
END_TEST

START_TEST(test_sort_head_null)
{
	node_t *head = NULL;

	node_t *result = sort(head, cmp);

	ck_assert_ptr_eq(result, NULL);
}
END_TEST

// POS TESTS

START_TEST(test_sort_basic)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2005 },
									 { 2, 12, 2012 },
									 { 3, 2, 1989 },
									 { 2, 2, 1999 } },
						  .len = 4 };

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 2, 12, 2012 },
									 	 { 1, 2, 2005 },
									  	 { 2, 2, 1999 },
									 	 { 3, 2, 1989 } },
						      .len = 4 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	node_t *result = sort(head, cmp);

	node_t *p = result;
	node_t *p_ref = reference;

	while (p)
	{
		date_t *p_data = (date_t *) p->data;
		date_t *p_ref_data = (date_t *) p_ref->data;

		ck_assert_int_eq(p_data->day, p_ref_data->day);
		ck_assert_int_eq(p_data->month, p_ref_data->month);
		ck_assert_int_eq(p_data->year, p_ref_data->year);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head);
	free_list(&result);
	free_list(&reference);
}
END_TEST

START_TEST(test_sort_1_elem)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2005 } },
						  .len = 1 };

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2005 } },
						      .len = 1 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	node_t *result = sort(head, cmp);

	node_t *p = result;
	node_t *p_ref = reference;

	while (p)
	{
		date_t *p_data = (date_t *) p->data;
		date_t *p_ref_data = (date_t *) p_ref->data;

		ck_assert_int_eq(p_data->day, p_ref_data->day);
		ck_assert_int_eq(p_data->month, p_ref_data->month);
		ck_assert_int_eq(p_data->year, p_ref_data->year);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head);
	free_list(&result);
	free_list(&reference);
}
END_TEST

START_TEST(test_sort_equal_elems)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2005 },
									 { 1, 2, 2005 },
									 { 1, 2, 2005 },
									 { 1, 2, 2005 } },
						  .len = 4 };

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2005 },
									 	 { 1, 2, 2005 },
									  	 { 1, 2, 2005 },
									 	 { 1, 2, 2005 } },
						      .len = 4 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	node_t *result = sort(head, cmp);

	node_t *p = result;
	node_t *p_ref = reference;

	while (p)
	{
		date_t *p_data = (date_t *) p->data;
		date_t *p_ref_data = (date_t *) p_ref->data;

		ck_assert_int_eq(p_data->day, p_ref_data->day);
		ck_assert_int_eq(p_data->month, p_ref_data->month);
		ck_assert_int_eq(p_data->year, p_ref_data->year);

		p = p->next;
		p_ref = p_ref->next;
	}

	ck_assert_ptr_eq(p_ref, NULL);

	free_list(&head);
	free_list(&result);
	free_list(&reference);
}
END_TEST

// MAIN

Suite *sort_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("sort");
	
	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_sort_cmp_null);
	tcase_add_test(tc_neg, test_sort_head_null);
	suite_add_tcase(s, tc_neg);

	tc_pos = tcase_create("positives");
	tcase_add_test(tc_pos, test_sort_basic);
	tcase_add_test(tc_pos, test_sort_1_elem);
	tcase_add_test(tc_pos, test_sort_equal_elems);
	suite_add_tcase(s, tc_pos);

    return s;
}