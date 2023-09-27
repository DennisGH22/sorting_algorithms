#include "sort.h"

/**
 * merge - Merges two subarrays back into the original array.
 *
 * @array: The original array.
 * @left: The left subarray.
 * @right: The right subarray.
 * @size: The size of the original array.
*/
void merge(int *array, int *left, int *right, size_t size)
{
    int *temp;
    size_t i = 0, j = 0, k = 0;

    temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, size / 2);
    printf("[right]: ");
    print_array(right, size - (size / 2));

    while (i < size / 2 && j < size - (size / 2))
    {
        if (left[i] < right[j])
            temp[k++] = left[i++];
        else
            temp[k++] = right[j++];
    }

    while (i < size / 2)
        temp[k++] = left[i++];

    while (j < size - (size / 2))
        temp[k++] = right[j++];

    for (i = 0; i < size; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array, size);

    free(temp);
}

/**
 * merge_sort - Sorts an array of integers using Merge Sort.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
*/
void merge_sort(int *array, size_t size)
{
    size_t middle;
    int *left, *right;

    if (array == NULL || size <= 1)
        return;

    if (size > 1)
    {
        middle = size / 2;
        left = array;
        right = array + middle;

        merge_sort(left, middle);
        merge_sort(right, size - middle);

        merge(array, left, right, size);
    }
}
