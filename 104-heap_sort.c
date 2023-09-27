#include "sort.h"

/**
 * sift_down - Perform the sift-down operation on a binary heap.
 *
 * @array: The array representing the binary heap.
 * @size: The size of the heap.
 * @root: The root of the heap.
 * @max: The maximum index of the heap.
*/
void sift_down(int *array, size_t size, size_t root, size_t max)
{
	size_t largest, left, right;
	int temp;

	largest = root;
	left = (2 * root) + 1;
	right = (2 * root) + 2;

	if (left < max && array[left] > array[largest])
		largest = left;

	if (right < max && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;

		print_array(array, size);
		sift_down(array, size, largest, max);
	}
}

/**
 * heapify - Convert an array into a binary heap.
 *
 * @array: The array to be converted.
 * @size: The size of the array.
*/
void heapify(int *array, size_t size)
{
	size_t i;

	for (i = (size / 2) - 1; (int)i >= 0; i--)
		sift_down(array, size, i, size);
}

/**
 * heap_sort - Sort an array of integers using Heap Sort.
 *
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
*/
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (array == NULL || size <= 1)
		return;

	heapify(array, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
