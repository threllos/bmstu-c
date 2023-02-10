#include <stdlib.h>
#include <stdio.h>
#include <check.h>

int main(void)
{
	Suite *count_len_suite(void);
	Suite *read_array_suite(void);
	Suite *key_suite(void);
	Suite *mysort_suite(void);

	int no_failed = 0;

	SRunner *runner;

	runner = srunner_create(count_len_suite());
	srunner_run_all(runner, CK_VERBOSE);
	no_failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(read_array_suite());
	srunner_run_all(runner, CK_VERBOSE);
	no_failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(key_suite());
	srunner_run_all(runner, CK_VERBOSE);
	no_failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(mysort_suite());
	srunner_run_all(runner, CK_VERBOSE);
	no_failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	printf("failed - %d\n", no_failed);

	return EXIT_SUCCESS;
}