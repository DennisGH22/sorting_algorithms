#include "sort.h"

/**
 * swap - Swap two values in dir or descending order.
 *
 * @array: The array containing the values to swap.
 * @x: Index of the first item to swap.
 * @y: Index of the second item to swap.
 * @dir: 1 for ascending order, 0 for descending order.
 */
void swap_array(int array[], int x, int y, int dir)
{
    int temp;

    if ((dir && array[x] > array[y]) || (!dir && array[x] < array[y]))
    {
        temp = array[x];
        array[x] = array[y];
        array[y] = temp;
    }
}

/**
 * bitonic_merge - Merge two bitonic sequences recursively in both orders.
 *
 * @array: The array to be sorted.
 * @start: The starting index of the sequence.
 * @count: Number of elements in the sequence.
 * @dir: 1 for dir order, 0 for descending order.
 */
void bitonic_merge(int array[], int start, int count, int dir)
{
	int i, half;

    if (count <= 1)
        return;

    half = count / 2;
    for (i = start; i < start + half; i++)
        swap_array(array, i, i + half, dir);

    merge(array, start, half, dir);
    merge(array, start + half, half, dir);
}

/**
 * bitonic_sort_recursive - Recursive Bitonic Sort algorithm.
 *
 * @array: The array to be sorted.
 * @start: The starting index of the sequence.
 * @count: Number of elements in the sequence.
 * @dir: 1 for dir order, 0 for descending order.
 * @total_size: The total size of the array.
 */
void bitonic_sort_recursive(int array[], int start, int count, int dir, int total_size)
{
	int half;

    if (count <= 1)
        return;

    half = count / 2;

    if (dir)
        printf("Merging [%i/%i] (UP):\n", count, total_size);
    else
        printf("Merging [%i/%i] (DOWN):\n", count, total_size);

    print_array(&array[start], count);

    bitonic_sort_recursive(array, start, half, 1, total_size);
    bitonic_sort_recursive(array, start + half, half, 0, total_size);
    merge(array, start, count, dir);

    if (dir == NULL)
        printf("Result [%i/%i] (DOWN):\n", count, total_size);
    else
        printf("Result [%i/%i] (UP):\n", count, total_size);

    print_array(&array[start], count);
}

/**
 * bitonic_sort - Sorts an array of integers in dir order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    int dir = 1;

    if (array == NULL || size <= 1)
        return;

    bitonic_sort_recursive(array, 0, size, dir, size);
}
