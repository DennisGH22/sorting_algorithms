#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two values in an array.
 *
 * @arr: The array containing the values to swap.
 * @item1: Index of the first item to swap.
 * @item2: Index of the second item to swap.
 */
void swap(int arr[], int item1, int item2)
{
    int temp = arr[item1];
    arr[item1] = arr[item2];
    arr[item2] = temp;
}

/**
 * bitonic_merge - Merge two subarrays in bitonic order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 * @bitonic_size: Size of the subarrays to be merged.
 */
void bitonic_merge(int *array, size_t size, int dir, size_t bitonic_size)
{
    size_t half, i;
    int temp;

    if (bitonic_size > 1)
    {
        half = bitonic_size / 2;

        if (dir == 1)
        {
            printf("Merging [%zu/%zu] (UP):\n", bitonic_size, size);
            print_array(array, bitonic_size);
        }
        else
        {
            printf("Merging [%zu/%zu] (DOWN):\n", bitonic_size, size);
            print_array(array, bitonic_size);
        }

        for (i = 0; i < size - half; i++)
        {
            if ((array[i] > array[i + half]) == dir)
            {
                temp = array[i];
                array[i] = array[i + half];
                array[i + half] = temp;
            }
        }

        bitonic_merge(array, half, dir, bitonic_size / 2);
        bitonic_merge(array + half, half, dir, bitonic_size / 2);

        if (dir == 0)
        {
            printf("Result [%zu/%zu] (DOWN):\n", bitonic_size, size);
            print_array(array, bitonic_size);
        }
        else
        {
            printf("Result [%zu/%zu] (UP):\n", bitonic_size, size);
            print_array(array, bitonic_size);
        }
    }
}

/**
 * bitonic_sort_recursive - Recursive Bitonic Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 * @bitonic_size: Size of the subarrays.
 */
void bitonic_sort_recursive(int *array, size_t size, int dir, size_t bitonic_size)
{
    size_t half;

    if (bitonic_size > 1)
    {
        half = bitonic_size / 2;

        bitonic_sort_recursive(array, half, 1, half);
        bitonic_sort_recursive(array + half, half, 0, half);
        bitonic_merge(array, size, dir, bitonic_size);
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

    bitonic_sort_recursive(array, size, 1, size);
}
