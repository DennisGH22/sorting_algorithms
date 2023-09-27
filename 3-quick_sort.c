#include "sort.h"

/**
 * swap - Swap two integers.
 *
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
*/
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * print_array - Print an array of integers.
 *
 * @array: The array to print.
 * @size: The size of the array.
*/
void print_array(int *array, size_t size)
{
	size_t i;

    for (i = 0; i < size; i++)
	{
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}

/**
 * lomuto_partition - Partition the array using the Lomuto scheme.
 *
 * @array: Pointer to the array to be partitioned.
 * @low: Index of the low end of the partition.
 * @high: Index of the high end of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element.
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int *pivot = array + high;
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			i++;
			swap(array + i, array + j);
		}
	}

	swap(array + i + 1, pivot);
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Performs quick sort.
 *
 * @array: Pointer to the array to be sorted.
 * @low: Index of the low end of the partition.
 * @high: Index of the high end of the partition.
 * @size: Size of the array.
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
