#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "list.h"

// NEG TESTS

START_TEST(test_pop_front_null_head)
{
	date_t *result;
	date_t *reference = NULL;
	result = pop_front(NULL);

	ck_assert_ptr_eq(result, reference);
}
END_TEST

START_TEST(test_pop_front_null_p_head)
{
	node_t *head = NULL;
	date_t *result;
	date_t *reference = NULL;
	result = pop_front(&head);

	ck_assert_ptr_eq(result, reference);
}
END_TEST

// POS TESTS

START_TEST(test_pop_front_basic)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 },
									 { 2, 12, 2001 },
									 { 3, 2, 1999 },
									 { 2, 2, 2000 } },
						  .len = 4 };
	date_t *result;
	date_t *reference = &(storage.array[3]);

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	result = pop_front(&head);

	ck_assert_ptr_eq(result, reference);

	free_list(&head);
}
END_TEST

START_TEST(test_pop_front_2_in_a_row)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 },
									 { 2, 12, 2001 },
									 { 3, 2, 1999 },
									 { 2, 2, 2000 } },
						  .len = 4 };
	date_t *result;
	date_t *reference = &(storage.array[2]);

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	result = pop_front(&head);
	result = pop_front(&head);

	ck_assert_ptr_eq(result, reference);

	free_list(&head);
}
END_TEST

START_TEST(test_pop_front_1_elem)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 } },
						  .len = 1 };
	date_t *result;
	date_t *reference = &(storage.array[0]);

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	result = pop_front(&head);

	ck_assert_ptr_eq(result, reference);
	ck_assert_ptr_eq(head, NULL);

	free_list(&head);
}
END_TEST

// MAIN

Suite *pop_front_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("pop_front");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_pop_front_null_head);
	tcase_add_test(tc_neg, test_pop_front_null_p_head);
	suite_add_tcase(s, tc_neg);

	tc_pos = tcase_create("positives");
	tcase_add_test(tc_pos, test_pop_front_basic);
	tcase_add_test(tc_pos, test_pop_front_2_in_a_row);
	tcase_add_test(tc_pos, test_pop_front_1_elem);
	suite_add_tcase(s, tc_pos);

    return s;
}
