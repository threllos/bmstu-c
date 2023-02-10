#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "list.h"

// NEG TESTS

START_TEST(test_insert_head_null)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 },
									 { 2, 12, 2001 },
									 { 3, 2, 1999 },
									 { 2, 2, 2000 } },
						  .len = 4 };

	size_t i_before = 2;
	node_t *before;
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

		if (i == i_before)
			before = tmp;
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

	insert(NULL, elem, before);

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

START_TEST(test_insert_elem_null)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 },
									 { 2, 12, 2001 },
									 { 3, 2, 1999 },
									 { 2, 2, 2000 } },
						  .len = 4 };

	size_t i_before = 2;
	node_t *before;

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;

		if (i == i_before)
			before = tmp;
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

	insert(&head, NULL, before);

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

// POS TESTS

START_TEST(test_insert_basic)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 },
									 { 2, 12, 2001 },
									 { 3, 2, 1999 },
									 { 2, 2, 2000 } },
						  .len = 4 };

	size_t i_before = 2;
	node_t *before;
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

		if (i == i_before)
			before = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2000 },
									 	 { 2, 12, 2001 },
									  	 { 3, 2, 1999 },
									 	 { 3, 4, 2000 },
									 	 { 2, 2, 2000 } },
						      .len = 5 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	insert(&head, elem, before);

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

START_TEST(test_insert_before_first_elem)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 },
									 { 2, 12, 2001 },
									 { 3, 2, 1999 },
									 { 2, 2, 2000 } },
						  .len = 4 };

	size_t i_before = 3;
	node_t *before;
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

		if (i == i_before)
			before = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2000 },
									     { 2, 12, 2001 },
									     { 3, 2, 1999 },
									     { 2, 2, 2000 },
									     { 3, 4, 2000 } },
						      .len = 5 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	insert(&head, elem, before);

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

START_TEST(test_insert_before_last_elem)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 },
									 { 2, 12, 2001 },
									 { 3, 2, 1999 },
									 { 2, 2, 2000 } },
						  .len = 4 };

	size_t i_before = 0;
	node_t *before;
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

		if (i == i_before)
			before = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2000 },
										 { 3, 4, 2000 },
									     { 2, 12, 2001 },
									 	 { 3, 2, 1999 },
									  	 { 2, 2, 2000 },
									 	 { 3, 4, 2000 } },
						      .len = 5 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	insert(&head, elem, before);

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

START_TEST(test_insert_before_null)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 },
									 { 2, 12, 2001 },
									 { 3, 2, 1999 },
									 { 2, 2, 2000 } },
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
	storage_t storage_ref = { .array = { { 3, 4, 2000 },
										 { 1, 2, 2000 },
									     { 2, 12, 2001 },
									 	 { 3, 2, 1999 },
									  	 { 2, 2, 2000 },
									 	 { 3, 4, 2000 } },
						      .len = 5 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	insert(&head, elem, NULL);

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

START_TEST(test_insert_2_in_a_row)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 },
									 { 2, 12, 2001 },
									 { 3, 2, 1999 },
									 { 2, 2, 2000 } },
						  .len = 4 };

	size_t i_before = 2;
	node_t *before;
	date_t elem_date = { 3, 4, 2000 };
	node_t *elem = (node_t*) malloc(sizeof(node_t));
	elem->data = &elem_date;
	elem->next = NULL;

	size_t i_before_2 = 2;
	node_t *before_2;
	date_t elem_date_2 = { 5, 5, 2005 };
	node_t *elem_2 = (node_t*) malloc(sizeof(node_t));
	elem_2->data = &elem_date_2;
	elem_2->next = NULL;

	for (size_t i = 0; i < storage.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage.array[i]);
		tmp->next = head;
		head = tmp;

		if (i == i_before)
			before = tmp;
		if (i == i_before_2)
			before_2 = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2000 },
									 	 { 2, 12, 2001 },
									  	 { 3, 2, 1999 },
									  	 { 5, 5, 2005 },
									 	 { 3, 4, 2000 },
									 	 { 2, 2, 2000 } },
						      .len = 6 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	insert(&head, elem, before);
	insert(&head, elem_2, before_2);

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

START_TEST(test_insert_empty_list)
{
	node_t *head = NULL;
	node_t *before = NULL;
	date_t elem_date = { 3, 4, 2000 };
	node_t *elem = (node_t*) malloc(sizeof(node_t));
	elem->data = &elem_date;
	elem->next = NULL;

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 3, 4, 2000 } },
						      .len = 1 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	insert(&head, elem, before);

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

START_TEST(test_insert_1_elem_list)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 } },
						  .len = 1 };

	size_t i_before = 0;
	node_t *before;
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

		if (i == i_before)
			before = tmp;
	}

	node_t *reference = NULL;
	storage_t storage_ref = { .array = { { 1, 2, 2000 },
									 	 { 3, 4, 2000 } },
						      .len = 2 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	insert(&head, elem, before);

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

START_TEST(test_insert_existant_point_before)
{
	node_t *head = NULL;
	storage_t storage = { .array = { { 1, 2, 2000 } },
						  .len = 1 };

	node_t *before = (node_t*) malloc(sizeof(node_t));
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
	storage_t storage_ref = { .array = { { 1, 2, 2000 } },
						      .len = 1 };

	for (size_t i = 0; i < storage_ref.len; i++)
	{
		node_t *tmp = (node_t*) malloc(sizeof(node_t));
		tmp->data = &(storage_ref.array[i]);
		tmp->next = reference;
		reference = tmp;
	}

	insert(&head, elem, before);

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
	free(before);
	free(elem);
}
END_TEST

// MAIN

Suite *insert_suite(void)
{
	Suite *s;
	TCase *tc_neg, *tc_pos;

	s = suite_create("insert");

	tc_neg = tcase_create("negatives");
	tcase_add_test(tc_neg, test_insert_head_null);
	tcase_add_test(tc_neg, test_insert_elem_null);
	suite_add_tcase(s, tc_neg);


	tc_pos = tcase_create("positives");
	tcase_add_test(tc_pos, test_insert_basic);
	tcase_add_test(tc_pos, test_insert_before_first_elem);
	tcase_add_test(tc_pos, test_insert_before_last_elem);
	tcase_add_test(tc_pos, test_insert_before_null);
	tcase_add_test(tc_pos, test_insert_2_in_a_row);
	tcase_add_test(tc_pos, test_insert_empty_list);
	tcase_add_test(tc_pos, test_insert_1_elem_list);
	tcase_add_test(tc_pos, test_insert_existant_point_before);
	suite_add_tcase(s, tc_pos);

    return s;
}
