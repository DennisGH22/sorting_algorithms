#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting Sort.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
*/
void counting_sort(int *array, size_t size)
{
	int i, max, *output, *count;

	if (array == NULL || size <= 1)
		return;

	output = malloc(size * sizeof(int));
	if (array == NULL)
	{
		free(output);
		return;
	}

	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc((max + 1) * sizeof(int));
	for (i = 0; i <= max; ++i)
		count[i] = 0;

	if (count == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; ++i)
		array[i] = output[i];

	free(count);
	free(output);
}
