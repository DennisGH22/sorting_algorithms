#include "sort.h"

/**
 * get_max - Get the maximum element from an array.
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * Return: The maximum element in the array.
*/
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort_radix - Perform counting sort on the array based on a
 * specific significant digit.
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @exp: The current significant digit (e.g., 1, 10, 100, ...).
*/
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sort an array of integers in ascending order.
 *
 * @array: The array of integers.
 * @size: The size of the array.
*/
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	if (array == NULL || size <= 1)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
