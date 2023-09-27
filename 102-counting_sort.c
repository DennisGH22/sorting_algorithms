#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting Sort.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
*/
void counting_sort(int *array, size_t size)
{
    int i, max, *output, *count;
    size_t j;

    if (array == NULL || size < 2)
        return;

    max = array[0];
    for (j = 1; j < size; j++)
    {
        if (array[j] > max)
            max = array[j];
    }

    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (j = 0; j < size; j++)
        count[array[j]]++;

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    output = malloc(size * sizeof(int));
    if (output == NULL)
    {
        free(count);
        return;
    }

    for (i = (int)size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (j = 0; j < size; j++)
        array[j] = output[j];

    free(output);
    free(count);
}
