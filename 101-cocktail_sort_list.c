#include "sort.h"

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
