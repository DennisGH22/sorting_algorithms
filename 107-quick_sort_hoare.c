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
 * median_of_three - Finds the median value among three integers.
 *
 * @array: Array of integers.
 * @low: Index of the first integer.
 * @high: Index of the third integer.
 *
 * Return: The median value.
*/
int median_of_three(int *array, int low, int high)
{
    int mid = (low + high) / 2;

    if (array[low] > array[mid])
        swap(&array[low], &array[mid]);

    if (array[low] > array[high])
        swap(&array[low], &array[high]);

    if (array[mid] > array[high])
        swap(&array[mid], &array[high]);

    return (array[mid]);
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
int hoare_partition(int *array, int low, int high)
{
    int pivot = median_of_three(array, low, high);
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
            return j;

        swap(&array[i], &array[j]);
    }
	return (j);
}

/**
 * quicksort_hoare_recursive - Recursive Quick Sort algorithm.
 *
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
*/
void quicksort_hoare_recursive(int *array, int low, int high)
{
	int pivot_idx;

    if (low < high)
	{
        pivot_idx = hoare_partition(array, low, high);

        quicksort_hoare_recursive(array, low, pivot_idx);
        quicksort_hoare_recursive(array, pivot_idx + 1, high);
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
    if (!array || size <= 1)
        return;

    quicksort_hoare_recursive(array, 0, size - 1);
}
