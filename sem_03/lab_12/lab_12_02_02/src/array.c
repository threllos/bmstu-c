#include "array.h"

ARRAY_DLL int ARRAY_DECL fibonacci_fill(int *array, int size)
{
	if (!array)
		return FAILURE;
	if (size < 1)
		return FAILURE;

	if (size > 0)
		array[0] = 0;
	if (size > 1)
		array[1] = 1;
	if (size > 2)
		for (int i = 2; i < size; i++)
			array[i] = array[i - 2] + array[i - 1];

	return SUCCESS;
}

ARRAY_DLL void ARRAY_DECL filter(int *src, int src_size, int *dst, int *dst_size)
{
	if (!src || !dst)
	{
		*dst_size = 0;
		return;
	}
	
	int cur_size = 0;
	int f;

	for (int i = 0; i < src_size; i++)
	{
		f = 1;

		for (int j = 0; j < cur_size; j++)
			if (src[i] == dst[j])
				f = 0;

		if (f)
		{
			dst[cur_size] = src[i];
			cur_size += 1;
		}
	}

	*dst_size = cur_size;
}