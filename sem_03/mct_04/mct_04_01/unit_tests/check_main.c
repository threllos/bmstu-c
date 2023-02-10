#include <stdlib.h>
#include <stdio.h>
#include <check.h>

int main(void)
{
	Suite *pop_suite(void);

	int failed = 0;

	SRunner *runner;

	runner = srunner_create(pop_suite());
	srunner_run_all(runner, CK_VERBOSE);
	failed += srunner_ntests_failed(runner);
	srunner_free(runner);
	printf("\n");

	printf("failed - %d\n", failed);

	return EXIT_SUCCESS;
}
