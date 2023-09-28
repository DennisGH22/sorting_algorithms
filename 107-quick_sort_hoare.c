#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 *
 * @x: Pointer to the first element.
 * @y: Pointer to the second element.
*/
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * hoare_partition - Partitions an array using the Hoare scheme.
 *
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: Index of the pivot element.
*/
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quicksort_hoare_recursive - Recursive Quick Sort algorithm.
 *
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
*/
void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = hoare_partition(array, low, high, size);

		quicksort_hoare_recursive(array, low, pivot_idx, size);
		quicksort_hoare_recursive(array, pivot_idx - 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quicksort_hoare_recursive(array, 0, size - 1, size);
}
