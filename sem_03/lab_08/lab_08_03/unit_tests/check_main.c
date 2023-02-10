#include <stdlib.h>
#include <stdio.h>
#include <check.h>

int main(void)
{
	Suite *make_square_suite(void);
	Suite *fill_suite(void);
	Suite *multiplication_suite(void);
	Suite *power_suite(void);

	int failed = 0;

	SRunner *runner;

	runner = srunner_create(make_square_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(fill_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(multiplication_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(power_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	printf("failed - %d\n", failed);

	return EXIT_SUCCESS;
}
