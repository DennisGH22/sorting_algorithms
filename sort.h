#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void swap(int *x, int *y);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge(int *array, int *left, int *right, size_t size);
void merge_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t max);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
int get_max(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void quicksort_hoare_recursive(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
