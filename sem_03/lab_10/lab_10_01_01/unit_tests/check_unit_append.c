#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "list.h"

// NEG TESTS

START_TEST(test_append_p_head_1_null)
{
	node_t *head_2 = NULL;
	storage_t storage_2 = { .array = { { 17, 5, 1877 },
									   { 11, 1, 1890 },
									   { 15, 6, 1902 },
									   { 30, 1, 1882 } },
						    .len = 4 };

	for (size_t i = 0; i < storage_2.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_2.array[i]);
		tmp->next = head_2;
		head_2 = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 17, 5, 1877 },
									 	 { 11, 1, 1890 },
									  	 { 15, 6, 1902 },
									 	 { 30, 1, 1882 } },
						      .len = 4 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	append(NULL, &head_2);

	node_t *p = head_2;
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

	free_list(&head_2);
	free_list(&reference);
}
END_TEST

START_TEST(test_append_p_head_2_null)
{
	node_t *head_1 = NULL;
	storage_t storage_1 = { .array = { { 1, 2, 2000 },
									   { 2, 12, 2001 },
									   { 3, 2, 1999 },
									   { 2, 2, 2000 } },
						    .len = 4 };

	for (size_t i = 0; i < storage_1.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_1.array[i]);
		tmp->next = head_1;
		head_1 = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2000 },
									 	 { 2, 12, 2001 },
									 	 { 3, 2, 1999 },
									 	 { 2, 2, 2000 } },
						      .len = 4 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	append(&head_1, NULL);

	node_t *p = head_1;
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

	free_list(&head_1);
	free_list(&reference);
}
END_TEST

// POS TESTS

START_TEST(test_append_basic)
{
	node_t *head_1 = NULL;
	storage_t storage_1 = { .array = { { 1, 2, 2000 },
									   { 2, 12, 2001 },
									   { 3, 2, 1999 },
									   { 2, 2, 2000 } },
						    .len = 4 };

	node_t *head_2 = NULL;
	storage_t storage_2 = { .array = { { 17, 5, 1877 },
									   { 11, 1, 1890 },
									   { 15, 6, 1902 },
									   { 30, 1, 1882 } },
						    .len = 4 };

	for (size_t i = 0; i < storage_1.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_1.array[i]);
		tmp->next = head_1;
		head_1 = tmp;
	}

	for (size_t i = 0; i < storage_2.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_2.array[i]);
		tmp->next = head_2;
		head_2 = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 17, 5, 1877 },
									 	 { 11, 1, 1890 },
									  	 { 15, 6, 1902 },
									 	 { 30, 1, 1882 },
									 	 { 1, 2, 2000 },
									 	 { 2, 12, 2001 },
									 	 { 3, 2, 1999 },
									 	 { 2, 2, 2000 } },
						      .len = 8 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	append(&head_1, &head_2);

	node_t *p = head_1;
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
	ck_assert_ptr_eq(head_2, NULL);

	free_list(&head_1);
	free_list(&reference);
}
END_TEST

START_TEST(test_append_head_1_null)
{
	node_t *head_1 = NULL;

	node_t *head_2 = NULL;
	storage_t storage_2 = { .array = { { 17, 5, 1877 },
									   { 11, 1, 1890 },
									   { 15, 6, 1902 },
									   { 30, 1, 1882 } },
						    .len = 4 };

	for (size_t i = 0; i < storage_2.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_2.array[i]);
		tmp->next = head_2;
		head_2 = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 17, 5, 1877 },
									 	 { 11, 1, 1890 },
									  	 { 15, 6, 1902 },
									 	 { 30, 1, 1882 } },
						      .len = 4 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	append(&head_1, &head_2);

	node_t *p = head_1;
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
	ck_assert_ptr_eq(head_2, NULL);

	free_list(&head_1);
	free_list(&reference);
}
END_TEST

START_TEST(test_append_head_2_null)
{
	node_t *head_1 = NULL;
	storage_t storage_1 = { .array = { { 1, 2, 2000 },
									   { 2, 12, 2001 },
									   { 3, 2, 1999 },
									   { 2, 2, 2000 } },
						    .len = 4 };

	node_t *head_2 = NULL;

	for (size_t i = 0; i < storage_1.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_1.array[i]);
		tmp->next = head_1;
		head_1 = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2000 },
									 	 { 2, 12, 2001 },
									 	 { 3, 2, 1999 },
									 	 { 2, 2, 2000 } },
						      .len = 4 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	append(&head_1, &head_2);

	node_t *p = head_1;
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
	ck_assert_ptr_eq(head_2, NULL);

	free_list(&head_1);
	free_list(&reference);
}
END_TEST

// MAIN

Suite *append_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("append");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_append_p_head_1_null);
	tcase_add_test(tc_neg, test_append_p_head_2_null);
	suite_add_tcase(s, tc_neg);

	tc_pos = tcase_create("positives");
	tcase_add_test(tc_pos, test_append_basic);
	tcase_add_test(tc_neg, test_append_head_1_null);
	tcase_add_test(tc_neg, test_append_head_2_null);
	suite_add_tcase(s, tc_pos);

    return s;
}
