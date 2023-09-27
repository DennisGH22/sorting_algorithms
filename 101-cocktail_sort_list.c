#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the linked list.
 * @a: Pointer to the first node to swap.
 * @b: Pointer to the second node to swap.
*/
void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *prev_a, *next_a, *prev_b, *next_b;

	prev_a = (*a)->prev;
	next_a = (*a)->next;
	prev_b = (*b)->prev;
	next_b = (*b)->next;

	if (prev_a)
		prev_a->next = *b;
	else
		*list = *b;

	if (next_b)
		next_b->prev = *a;

	(*a)->prev = prev_b;
	(*a)->next = next_b;
	(*b)->prev = prev_a;
	(*b)->next = *a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Cocktail Shaker Sort.
 *
 * @list: Pointer to a pointer to the head of the linked list.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &current->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &current->prev, &current);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
	}
}
