#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "item.h"

// POS TESTS

START_TEST(test_sort_data_basic)
{
	item_t test_array[3] = {
		{ "coca", 100, 120 },
		{ "spir", 200, 120 },
		{ "asdf", 150, 150 }
	};

	item_t reference_array[3] = {
		{ "coca", 100, 120 },
		{ "asdf", 150, 150 },
		{ "spir", 200, 120 }
	};

	items_t test = { .len = 3, .array = test_array };
	items_t reference = { .len = 3, .array = reference_array };

	sort_data(&test);

	ck_assert_int_eq(reference.len, test.len);

	for (size_t i = 0; i < reference.len; i++)
		for (size_t j = 0; j < reference.len; j++)
		{
			ck_assert_double_eq(reference.array[i].weight, test.array[i].weight);
			ck_assert_double_eq(reference.array[i].volume, test.array[i].volume);
}		}
END_TEST

START_TEST(test_sort_1_elem)
{
	item_t test_array[1] = {
		{ "coca", 100, 120 }
	};

	item_t reference_array[1] = {
		{ "coca", 100, 120 }
	};

	items_t test = { .len = 1, .array = test_array };
	items_t reference = { .len = 1, .array = reference_array };

	sort_data(&test);

	ck_assert_int_eq(reference.len, test.len);

	for (size_t i = 0; i < reference.len; i++)
		for (size_t j = 0; j < reference.len; j++)
		{
			ck_assert_double_eq(reference.array[i].weight, test.array[i].weight);
			ck_assert_double_eq(reference.array[i].volume, test.array[i].volume);
}		}
END_TEST

START_TEST(test_sort_equal_elems)
{
	item_t test_array[3] = {
		{ "coca", 100, 120 },
		{ "coca", 100, 120 },
		{ "coca", 100, 120 }
	};

	item_t reference_array[3] = {
		{ "coca", 100, 120 },
		{ "coca", 100, 120 },
		{ "coca", 100, 120 }
	};

	items_t test = { .len = 3, .array = test_array };
	items_t reference = { .len = 3, .array = reference_array };

	sort_data(&test);

	ck_assert_int_eq(reference.len, test.len);

	for (size_t i = 0; i < reference.len; i++)
		for (size_t j = 0; j < reference.len; j++)
		{
			ck_assert_double_eq(reference.array[i].weight, test.array[i].weight);
			ck_assert_double_eq(reference.array[i].volume, test.array[i].volume);
}		}
END_TEST

START_TEST(test_sort_sorted_to_low)
{
	item_t test_array[3] = {
		{ "coca", 250, 120 },
		{ "spir", 200, 200 },
		{ "asdf", 100, 300 }
	};

	item_t reference_array[3] = {
		{ "asdf", 100, 300 },
		{ "spir", 200, 200 },
		{ "coca", 250, 120 }
	};

	items_t test = { .len = 3, .array = test_array };
	items_t reference = { .len = 3, .array = reference_array };

	sort_data(&test);

	ck_assert_int_eq(reference.len, test.len);

	for (size_t i = 0; i < reference.len; i++)
		for (size_t j = 0; j < reference.len; j++)
		{
			ck_assert_double_eq(reference.array[i].weight, test.array[i].weight);
			ck_assert_double_eq(reference.array[i].volume, test.array[i].volume);
}		}
END_TEST

START_TEST(test_sort_sorted_to_high)
{
	item_t test_array[3] = {
		{ "asdf", 100, 300 },
		{ "spir", 200, 200 },
		{ "coca", 250, 120 }
	};

	item_t reference_array[3] = {
		{ "asdf", 100, 300 },
		{ "spir", 200, 200 },
		{ "coca", 250, 120 }
	};

	items_t test = { .len = 3, .array = test_array };
	items_t reference = { .len = 3, .array = reference_array };

	sort_data(&test);

	ck_assert_int_eq(reference.len, test.len);

	for (size_t i = 0; i < reference.len; i++)
		for (size_t j = 0; j < reference.len; j++)
		{
			ck_assert_double_eq(reference.array[i].weight, test.array[i].weight);
			ck_assert_double_eq(reference.array[i].volume, test.array[i].volume);
}		}
END_TEST

// MAIN

Suite *sort_data_suite(void)
{
	Suite *s;
	TCase *tc_pos;

	s = suite_create("sort_data");

	tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_data_basic);
    tcase_add_test(tc_pos, test_sort_1_elem);
    tcase_add_test(tc_pos, test_sort_equal_elems);
    tcase_add_test(tc_pos, test_sort_sorted_to_low);
    tcase_add_test(tc_pos, test_sort_sorted_to_high);
    suite_add_tcase(s, tc_pos);

    return s;
}
