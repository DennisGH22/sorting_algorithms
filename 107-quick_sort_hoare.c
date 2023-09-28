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
	int low_pivot, high_pivot;

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

	if (j == high && array[j] == pivot)
		return high;

	if (i == low && array[i] == pivot)
		return low;

	low_pivot = hoare_partition(array, low, j, size);
	high_pivot = hoare_partition(array, i, high, size);

	if (low_pivot < high_pivot)
		return high_pivot;
	else
		return low_pivot;
}

/**
 * insertion_sort - Sorts an array..
 *
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
*/
void insertion_sort(int *array, int low, int high, size_t size)
{
    int i, j;

    for (i = low + 1; i <= high; i++)
    {
        int key = array[i];
        j = i - 1;

        while (j >= low && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
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
		if (high - low + 1 <= 10)
        {
            insertion_sort(array, low, high, size);
            return;
        }

		pivot_idx = hoare_partition(array, low, high, size);

		quicksort_hoare_recursive(array, low, pivot_idx, size);
		quicksort_hoare_recursive(array, pivot_idx + 1, high, size);
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
