#include "sort.h"

/**
 * dlistint_len - counts the size of a doubly linked list
 * @list: pointer to the head of the list
 *
 * Return: size of the list
 */
int listint_len(listint_t *list)
{
    listint_t *current = list;
    int size = 0;

    while (current != NULL)
	{
        size++;
        current = current->next;
    }

    return size;
}


/**
 * insertion_sort_list - insertion sort algorithm for linked list
 * @list: list to be sorted
 * 
 * Return: Void Function
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *node, *current;
	int size, i = 1;

	if (!list || !*list)
	{
		return;
	}
	size = listint_len(*list);
	while (i < size - 1)
	{
		node = *list;
		while (node != NULL && node->next != NULL)
		{
			if (node->n > (node->next)->n)
			{
				current = node;
				tmp = current->next;
				current->next = tmp->next;
				if (tmp->next != NULL)
					(tmp->next)->prev = current;
				tmp->prev = current->prev;
				if (current->prev == NULL)
				{
					tmp->next = *list;
					(*list)->prev = tmp;
					*list = tmp;
				}
				else
				{
					(current->prev)->next = tmp;
					tmp->next = current;
					current->prev = tmp;
				}
				
				node = tmp;
				print_list(*list);
			}

			node = node->next;
		}
		i++;
	}
}
