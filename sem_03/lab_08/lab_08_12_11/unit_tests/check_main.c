#include <stdlib.h>
#include <stdio.h>
#include <check.h>

int main(void)
{
	Suite *addition_suite(void);
	Suite *multiplication_suite(void);
	Suite *determinant_suite(void);

	int failed = 0;

	SRunner *runner;

	runner = srunner_create(addition_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(multiplication_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	runner = srunner_create(determinant_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	printf("failed - %d\n", failed);

	return EXIT_SUCCESS;
}
