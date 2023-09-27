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
 * bubble_sort - Sort an array of integers in ascending order.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;
	size_t k;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;

				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
						printf(", ");
				}
				printf("\n");
			}
		}

		if (swapped == 0)
			break;
	}
}
