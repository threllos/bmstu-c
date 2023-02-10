#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "list.h"

// NEG TESTS

START_TEST(test_sorted_insert_p_head_null)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2010 },
									 { 2, 12, 2004 },
									 { 3, 2, 2001 },
									 { 2, 2, 1999 } },
						  .len = 4 };

	date_t elem_date = { 3, 4, 2015 };
	node_t *elem = (node_t*) malloc(sizeof(node_t));
	elem->data = &elem_date;
	elem->next = NULL;

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2010 },
									 	 { 2, 12, 2004 },
									  	 { 3, 2, 2001 },
									 	 { 2, 2, 1999 } },
						      .len = 4 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	sorted_insert(NULL, elem, cmp);

	node_t *p = head;
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
	free_list(&reference);
	free(elem);
}
END_TEST

START_TEST(test_sorted_insert_elem_null)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2010 },
									 { 2, 12, 2004 },
									 { 3, 2, 2001 },
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
	storage_t storage_ref = { .array = { { 1, 2, 2010 },
									 	 { 2, 12, 2004 },
									  	 { 3, 2, 2001 },
									 	 { 2, 2, 1999 } },
						      .len = 4 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	sorted_insert(&head, NULL, cmp);

	node_t *p = head;
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
	free_list(&reference);
}
END_TEST

START_TEST(test_sorted_insert_cmp_null)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2010 },
									 { 2, 12, 2004 },
									 { 3, 2, 2001 },
									 { 2, 2, 1999 } },
						  .len = 4 };

	date_t elem_date = { 3, 4, 2015 };
	node_t *elem = (node_t*) malloc(sizeof(node_t));
	elem->data = &elem_date;
	elem->next = NULL;

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2010 },
									 	 { 2, 12, 2004 },
									  	 { 3, 2, 2001 },
									 	 { 2, 2, 1999 } },
						      .len = 4 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	sorted_insert(&head, elem, NULL);

	node_t *p = head;
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
	free_list(&reference);
	free(elem);
}
END_TEST

// POS TESTS

START_TEST(test_sorted_insert_basic)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2010 },
									 { 2, 12, 2004 },
									 { 3, 2, 2001 },
									 { 2, 2, 1999 } },
						  .len = 4 };

	date_t elem_date = { 3, 4, 2000 };
	node_t *elem = (node_t*) malloc(sizeof(node_t));
	elem->data = &elem_date;
	elem->next = NULL;

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2010 },
									 	 { 2, 12, 2004 },
									  	 { 3, 2, 2001 },
									  	 { 3, 4, 2000 },
									 	 { 2, 2, 1999 } },
						      .len = 5 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	sorted_insert(&head, elem, cmp);

	node_t *p = head;
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
	free_list(&reference);
}
END_TEST

START_TEST(test_sorted_insert_before_first)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2010 },
									 { 2, 12, 2004 },
									 { 3, 2, 2001 },
									 { 2, 2, 1999 } },
						  .len = 4 };

	date_t elem_date = { 3, 4, 1900 };
	node_t *elem = (node_t*) malloc(sizeof(node_t));
	elem->data = &elem_date;
	elem->next = NULL;

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2010 },
									 	 { 2, 12, 2004 },
									  	 { 3, 2, 2001 },
									 	 { 2, 2, 1999 },
									 	 { 3, 4, 1900 }, },
						      .len = 5 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	sorted_insert(&head, elem, cmp);

	node_t *p = head;
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
	free_list(&reference);
}
END_TEST

START_TEST(test_sorted_insert_before_last)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2010 },
									 { 2, 12, 2004 },
									 { 3, 2, 2001 },
									 { 2, 2, 1999 } },
						  .len = 4 };

	date_t elem_date = { 3, 4, 2008 };
	node_t *elem = (node_t*) malloc(sizeof(node_t));
	elem->data = &elem_date;
	elem->next = NULL;

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2010 },
										 { 3, 4, 2008 },
									 	 { 2, 12, 2004 },
									  	 { 3, 2, 2001 },
									 	 { 2, 2, 1999 } },
						      .len = 5 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	sorted_insert(&head, elem, cmp);

	node_t *p = head;
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
	free_list(&reference);
}
END_TEST

START_TEST(test_sorted_insert_after_last)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2010 },
									 { 2, 12, 2004 },
									 { 3, 2, 2001 },
									 { 2, 2, 1999 } },
						  .len = 4 };

	date_t elem_date = { 3, 4, 2015 };
	node_t *elem = (node_t*) malloc(sizeof(node_t));
	elem->data = &elem_date;
	elem->next = NULL;

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 3, 4, 2015 }, 
										 { 1, 2, 2010 },
									 	 { 2, 12, 2004 },
									  	 { 3, 2, 2001 },
									 	 { 2, 2, 1999 } },
						      .len = 5 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	sorted_insert(&head, elem, cmp);

	node_t *p = head;
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
	free_list(&reference);
}
END_TEST

START_TEST(test_sorted_insert_empty_list)
{
	node_t *head = NULL;

	date_t elem_date = { 3, 4, 2015 };
	node_t *elem = (node_t*) malloc(sizeof(node_t));
	elem->data = &elem_date;
	elem->next = NULL;

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 3, 4, 2015 } },
						      .len = 1 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	sorted_insert(&head, elem, cmp);

	node_t *p = head;
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
	free_list(&reference);
}
END_TEST

// MAIN

Suite *sorted_insert_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("sorted_insert");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_sorted_insert_cmp_null);
	tcase_add_test(tc_neg, test_sorted_insert_p_head_null);
	tcase_add_test(tc_neg, test_sorted_insert_elem_null);
	suite_add_tcase(s, tc_neg);

	tc_pos = tcase_create("positives");
	tcase_add_test(tc_pos, test_sorted_insert_basic);
	tcase_add_test(tc_pos, test_sorted_insert_before_first);
	tcase_add_test(tc_pos, test_sorted_insert_before_last);
	tcase_add_test(tc_pos, test_sorted_insert_after_last);
	tcase_add_test(tc_pos, test_sorted_insert_empty_list);
	suite_add_tcase(s, tc_pos);

    return s;
}