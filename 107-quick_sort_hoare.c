#include "sort.h"

/**
 * swap_positions - Swaps two elements in an integer array.
 *
 * @array: The array containing the elements to swap.
 * @x: Index of the first element to swap.
 * @y: Index of the second element to swap.
 */
void swap_positions(int *array, ssize_t x, ssize_t y)
{
	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}

/**
 * hoare_partition - Implements the Hoare partition scheme.
 *
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: Index of the pivot element.
 */
int hoare_partition(int *array, int low, int high, int size)
{
	int left = low - 1,
		right = high + 1,
		pivot = array[high];

	while (1)
	{
		do {
			left++;
		} while (array[left] < pivot);

		do {
			right--;
		} while (array[right] > pivot);

		if (left >= right)
			return left;

		swap_positions(array, left, right);
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
void quicksort_hoare_recursive(int *array, ssize_t low, ssize_t high, int size)
{
	ssize_t pivot_index = 0;

	if (low < high)
	{
		pivot_index = hoare_partition(array, low, high, size);
		quicksort_hoare_recursive(array, low, pivot_index - 1, size);
		quicksort_hoare_recursive(array, pivot_index, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an integer array in ascending order.
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
