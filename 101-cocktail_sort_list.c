#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the linked list.
 * @node: Node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev = node->prev;
	listint_t *next = node->next;

	if (prev)
		prev->next = next;
	else
		*list = next;

	if (next)
		next->prev = prev;

	node->prev = next;
	node->next = next ? next->next : NULL;

	if (next)
		next->next = node;

	if (node->next)
		node->next->prev = node;
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

	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current);
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
				swap_nodes(list, current->prev);
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
