#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 *
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
*/
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bitonic_merge - Merges two subarrays in bitonic order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 * @start: Start index of the subarray to merge.
 * @bitonic_size: Size of the subarrays to be merged.
*/
void bitonic_merge(int *array, size_t size, int dir, size_t start, size_t bitonic_size) {
    if (bitonic_size > 1) {
        size_t half = bitonic_size / 2;
        for (size_t i = start; i < start + half; i++) {
            if ((array[i] > array[i + half]) == dir) {
                swap(&array[i], &array[i + half]);
            }
        }
    }
}

/**
 * bitonic_sort_recursive - Recursive Bitonic Sort algorithm.
 * @array: The array to be sorted.
 * @low: First element index.
 * @nelemnt: Number of elements to sort.
 * @order: Sorting order (1 for ascending, 0 for descending).
 * @size: Array length.
 */
void bitonic_sort_recursive(int *array, size_t low, size_t nelemnt, int order, size_t size) {
    if (nelemnt > 1) {
        printf("Merging [%lu/%lu] (%s):\n", nelemnt, size, (order ? "UP" : "DOWN"));
        print_array(&array[low], nelemnt);
        
        size_t mid = nelemnt / 2;
        bitonic_sort_recursive(array, low, mid, 1, size);
        bitonic_sort_recursive(array, low + mid, mid, 0, size);
        bitonic_merge(array, size, order, low, nelemnt);
        
        printf("Result [%lu/%lu] (%s):\n", nelemnt, size, (order ? "UP" : "DOWN"));
        print_array(&array[low], nelemnt);
    }
}

/**
 * bitonic_sort - Prepare the terrain for the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: Array length.
 */
void bitonic_sort(int *array, size_t size) {
    if (!array || size < 2) {
        return;
    }

    int order = 1;

    // Find the largest power of 2 less than or equal to size
    size_t bitonic_size = 1;
    while (bitonic_size < size) {
        bitonic_size *= 2;
    }

    bitonic_sort_recursive(array, 0, size, order, size);

    printf("Result [%lu/%lu] (UP):\n", size, size);
    print_array(array, size);
}
