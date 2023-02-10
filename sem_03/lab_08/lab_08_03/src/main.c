#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int main(void)
{
	setbuf(stdout, NULL);

	matrix_t a, b;
	matrix_t a_result, b_result;
	matrix_t tmp;
	matrix_t result;
	size_t a_power, b_power;
	size_t tmp_rows = 0, tmp_columns = 0;

	if (size_input(&tmp_rows, &tmp_columns))
		return EXIT_FAILURE;

	a = create(tmp_rows, tmp_columns);
	if (!a.matrix)
		return EXIT_FAILURE;

	if (input(&a))
	{
		free_memory(&a);
		return EXIT_FAILURE;
	}

	if (size_input(&tmp_rows, &tmp_columns))
	{
		free_memory(&a);
		return EXIT_FAILURE;
	}

	b = create(tmp_rows, tmp_columns);
	if (!b.matrix)
	{
		free_memory(&a);
		return EXIT_FAILURE;
	}

	if (input(&b))
	{
		free_memory(&a);
		free_memory(&b);
		return EXIT_FAILURE;
	}

	make_square(&a);
	make_square(&b);

	if (a.rows < b.rows)
	{
		a_result = create(b.rows, b.columns);
		if (!a_result.matrix)
		{
			free_memory(&a);
			free_memory(&b);
			return EXIT_FAILURE;
		}

		b_result = create(b.rows, b.columns);
		if (!b_result.matrix)
		{
			free_memory(&a);
			free_memory(&b);
			free_memory(&a_result);
			return EXIT_FAILURE;
		}

		fill(b, &b_result);
		fill(a, &a_result);
	}
	else if (b.rows < a.rows)
	{
		a_result = create(a.rows, a.columns);
		if (!a_result.matrix)
		{
			free_memory(&a);
			free_memory(&b);
			return EXIT_FAILURE;
		}

		b_result = create(a.rows, a.columns);
		if (!b_result.matrix)
		{
			free_memory(&a);
			free_memory(&b);
			free_memory(&a_result);
			return EXIT_FAILURE;
		}

		fill(a, &a_result);
		fill(b, &b_result);
	}
	else
	{
		a_result = create(a.rows, a.columns);
		if (!a_result.matrix)
		{
			free_memory(&a);
			free_memory(&b);
			return EXIT_FAILURE;
		}

		b_result = create(b.rows, b.columns);
		if (!b_result.matrix)
		{
			free_memory(&a);
			free_memory(&b);
			free_memory(&a_result);
			return EXIT_FAILURE;
		}

		fill(a, &a_result);
		fill(b, &b_result);
	}

	free_memory(&a);
	free_memory(&b);

	if (power_input(&a_power))
	{
		free_memory(&a_result);
		free_memory(&b_result);
		return EXIT_FAILURE;
	}
	if (power_input(&b_power))
	{
		free_memory(&a_result);
		free_memory(&b_result);
		return EXIT_FAILURE;
	}

	tmp = create(a_result.rows, a_result.columns);
	if (!tmp.matrix)
	{
		free_memory(&a_result);
		free_memory(&b_result);
		return EXIT_FAILURE;
	}

	if (power(a_result, &tmp, a_power))
	{
		free_memory(&a_result);
		free_memory(&b_result);
		free_memory(&tmp);
		return EXIT_FAILURE;
	}

	if (copy(tmp, &a_result))
	{
		free_memory(&a_result);
		free_memory(&b_result);
		free_memory(&tmp);
		return EXIT_FAILURE;
	}
		
	free_memory(&tmp);

	tmp = create(b_result.rows, b_result.columns);
	if (!tmp.matrix)
	{
		free_memory(&a_result);
		free_memory(&b_result);
		return EXIT_FAILURE;
	}

	if (power(b_result, &tmp, b_power))
	{
		free_memory(&a_result);
		free_memory(&b_result);
		free_memory(&tmp);
		return EXIT_FAILURE;
	}

	if (copy(tmp, &b_result))
	{
		free_memory(&a_result);
		free_memory(&b_result);
		free_memory(&tmp);
		return EXIT_FAILURE;
	}

	free_memory(&tmp);

	result = create(a_result.rows, a_result.columns);
	if (!result.matrix)
	{
		free_memory(&a_result);
		free_memory(&b_result);
		return EXIT_FAILURE;
	}

	if (multiplication(a_result, b_result, &result))
	{
		free_memory(&a_result);
		free_memory(&b_result);
		free_memory(&result);
		return EXIT_FAILURE;
	}

	free_memory(&a_result);
	free_memory(&b_result);

	output(result);

	free_memory(&result);

	return EXIT_SUCCESS;
}