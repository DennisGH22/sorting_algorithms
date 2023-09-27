#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting Sort.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
*/
void counting_sort(int *array, size_t size)
{
    size_t i;
    int j,  max, *count, *output; 

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = calloc(max + 1, sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (j = (int)size - 1; j >= 0; j--)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
