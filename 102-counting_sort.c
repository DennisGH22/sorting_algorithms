#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 *
 * @array: Pointer to the array of integers to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int max, min, i;
    int *count, *output;

    if (array == NULL || size < 2)
        return;

    max = array[0];
    min = array[0];
    for (i = 1; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }

    count = malloc(sizeof(int) * (max - min + 1));
    if (count == NULL)
        return;

    for (i = 0; i <= max - min; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[array[i] - min]++;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
    {
        free(count);
        return;
    }

    for (i = 1; i <= max - min; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[array[i] - min] - 1] = array[i];
        count[array[i] - min]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    printf("Counting array: ");
    for (i = 0; i <= max - min; i++)
    {
        if (i < max - min)
            printf("%d, ", count[i]);
        else
            printf("%d\n", count[i]);
    }

    free(count);
    free(output);
}
