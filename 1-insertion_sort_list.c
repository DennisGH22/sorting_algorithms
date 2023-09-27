#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list
 * in ascending order.
 *
 * @list: Pointer to a pointer to the head of the list.
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        insert = current;

        while (insert->prev != NULL && insert->n < insert->prev->n)
        {
            temp = insert->prev;
            insert->prev = temp->prev;

            if (temp->prev != NULL)
                temp->prev->next = insert;

            temp->next = insert->next;
            if (insert->next != NULL)
                insert->next->prev = temp;

            insert->next = temp;
            temp->prev = insert;

            if (insert->prev == NULL)
                *list = insert;
            else
                insert->prev->next = insert;

            print_list(*list);
        }

        current = current->next;
    }
}
