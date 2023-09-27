#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 *
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
*/
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bitonic_merge - Merges two subarrays in bitonic order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 * @start: Start index of the subarray to merge.
 * @bitonic_size: Size of the subarrays to be merged.
*/
void bitonic_merge(int *array, size_t size, int dir, size_t start, size_t bitonic_size)
{
	size_t half, i;

	if (bitonic_size > 1)
	{
		half = bitonic_size / 2;

		for (i = start; i < start + half; i++)
		{
			if ((array[i] > array[i + half]) == dir)
			{
				swap(&array[i], &array[i + half]);
			}
		}
	}
}

/**
 * bitonic_sort_recursive - Recursive Bitonic Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 * @start: Start index of the subarray.
 * @bitonic_size: Size of the subarrays.
*/
void bitonic_sort_recursive(int *array, size_t size, int dir, size_t start, size_t bitonic_size)
{
	size_t half;

	if (bitonic_size > 1)
	{
		half = bitonic_size / 2;

		bitonic_sort_recursive(array, size, 1, start, half);
		bitonic_sort_recursive(array, size, 0, start + half, half);
		bitonic_merge(array, size, dir, start, bitonic_size);

		printf("Result [%zu/%zu] (%s):\n", bitonic_size, size, dir ? "UP" : "DOWN");
		print_array(array, size);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	printf("Merging [%zu/%zu] (UP):\n", size);
	print_array(array, size);

	bitonic_sort_recursive(array, size, 1, 0);
}
