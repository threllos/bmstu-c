#include <stdlib.h>
#include <stdio.h>
#include <check.h>

int main(void)
{
	Suite *pop_front_suite(void);
	Suite *insert_suite(void);
	Suite *append_suite(void);
	Suite *sorted_insert_suite(void);
	Suite *sort_suite(void);

	int failed = 0;

	SRunner *runner;

	runner = srunner_create(pop_front_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(insert_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(append_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(sorted_insert_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(sort_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	printf("failed - %d\n", failed);

	return EXIT_SUCCESS;
}
