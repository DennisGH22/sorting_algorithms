#include "sort.h"

/**
 * swap_array - Swap two values in an array.
 *
 * @array: The array containing the values to swap.
 * @x: Index of the first item to swap.
 * @y: Index of the second item to swap.
*/
void swap_array(int array[], int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
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
            printf("Merging [%i/%i] (UP):\n", bitonic_size, size);
        else
            printf("Merging [%i/%i] (DOWN):\n", bitonic_size, size);

        print_array(array, bitonic_size);

        for (i = 0; i < size - half; i++)
        {
            if ((array[i] > array[i + half]) == dir)
            {
                swap_array(array, i, i + half);
            }
        }

        bitonic_merge(array, half, dir, bitonic_size / 2);
        bitonic_merge(array + half, half, dir, bitonic_size / 2);

        if (dir == 0)
            printf("Result [%i/%i] (DOWN):\n", bitonic_size, size);
        else
            printf("Result [%i/%i] (UP):\n", bitonic_size, size);

        print_array(array, bitonic_size);
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
