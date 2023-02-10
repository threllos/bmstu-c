#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "queue.h"

START_TEST(test_pop_basic)
{
    queue_t queue;
	int val, reference = 1;
	int rc;

    init(&queue);
	fill(&queue, 3, 1, 2, 3);
	rc = pop(&queue, &val);

	ck_assert_int_eq(EXIT_SUCCESS, rc);
    ck_assert_int_eq(reference, val);

    free_queue(&queue);
}
END_TEST

START_TEST(test_one_elem)
{
    queue_t queue;
	int val, reference = 5;
	int rc;

    init(&queue);
	push(&queue, 5);
	rc = pop(&queue, &val);

	ck_assert_int_eq(EXIT_SUCCESS, rc);
    ck_assert_int_eq(reference, val);
}
END_TEST

START_TEST(test_two_pop_in_a_row)
{
    queue_t queue;
	int val, reference = 1;
	int rc;

    init(&queue);
	fill(&queue, 3, 1, 2, 3);
	rc = pop(&queue, &val);

	ck_assert_int_eq(EXIT_SUCCESS, rc);
    ck_assert_int_eq(reference, val);

   	reference = 2;
    rc = pop(&queue, &val);

	ck_assert_int_eq(EXIT_SUCCESS, rc);
    ck_assert_int_eq(reference, val);

    free_queue(&queue);
}
END_TEST

START_TEST(test_pop_push_pop)
{
    queue_t queue;
	int val, reference = 2;
	int rc;

    init(&queue);
	fill(&queue, 3, 1, 2, 3);
	pop(&queue, &val);
	push(&queue, 4);
	rc = pop(&queue, &val);

	ck_assert_int_eq(EXIT_SUCCESS, rc);
    ck_assert_int_eq(reference, val);

    free_queue(&queue);
}
END_TEST

START_TEST(test_empty_stacks)
{
    queue_t queue;
	int val;
	int rc;

    init(&queue);
	rc = pop(&queue, &val);

	ck_assert_int_eq(EXIT_FAILURE, rc);
}
END_TEST

START_TEST(test_queue_is_null)
{
	int val;
	int rc;

	rc = pop(NULL, &val);

	ck_assert_int_eq(EXIT_FAILURE, rc);
}
END_TEST

START_TEST(test_empty_queue)
{
    queue_t queue;
	int val;
	int rc;

    init(&queue);
    push(&queue, 1);
    pop(&queue, &val);
	rc = pop(&queue, &val);

	ck_assert_int_eq(EXIT_FAILURE, rc);
}
END_TEST

Suite *pop_suite(void)
{
	Suite *s;
	TCase *tc_pos, *tc_neg;

	s = suite_create("pop");

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_pop_basic);
    tcase_add_test(tc_pos, test_one_elem);
    tcase_add_test(tc_pos, test_two_pop_in_a_row);
    tcase_add_test(tc_pos, test_pop_push_pop);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_empty_queue);
    tcase_add_test(tc_neg, test_queue_is_null);
    tcase_add_test(tc_neg, test_empty_stacks);
    suite_add_tcase(s, tc_neg);

    return s;
}

