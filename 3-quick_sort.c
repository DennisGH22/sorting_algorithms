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
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			for (size_t k = 0; k < size; k++)
			{
				printf("%d", array[k]);
				if (k < size - 1)
					printf(", ");
			}
			printf("\n");
		}
	}
	swap(&array[i + 1], &array[high]);

	for (size_t k = 0; k < size; k++)
	{
		printf("%d", array[k]);
		if (k < size - 1)
			printf(", ");
	}
	printf("\n");
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quick sort.
 *
 * @array: Pointer to the array to be sorted.
 * @low: Index of the low end of the partition.
 * @high: Index of the high end of the partition.
 * @size: Size of the array.
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

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
