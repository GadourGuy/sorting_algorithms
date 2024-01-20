#include "sort.h"

/**
 * swap_nodes - swapes two nodes in a linked list
 * @head: head of list
 * @first: first node to be swapped
 * @second:second node to be swaped
 * 
 * Return: returns the new swapped list
*/
void swap_nodes(listint_t **head, listint_t *first, listint_t *second)
{
	if (!head || !*head || !first || !second)
		return;
	if (first == second)
		return;
	first->next = second->next;
	if (second->next)
	{
		(second->next)->prev = first;
	}
	second->prev = first->prev;
	if (first->prev)
	{
		(first->prev)->next = second;
	}
	else
	{
		*head = second;
	}
	first->prev = second;
	second->next = first;
}

/**
 * cocktail_sort_list - cocktail_sort_list algorthim for sorting
 * @list: list to be sorted
 *
 * Return: Void Function
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end = NULL;
	int swap;

	if (!list || !*list)
		return;
	do {
		swap = 0;
		start = *list;
		while (start && start->next != end)
		{
			if (start->n > (start->next)->n)
			{
				swap_nodes(list, start, start->next);
				swap = 1;
			}
			else
			{
				start = start->next;
			}
		}
		if (!swap)
			break;
		end = start;
		swap = 0;
		start = start->prev;
		while(start && start->prev != end)
		{
			if (start->n < (start->prev->n))
			{
				swap_nodes(list, start, start->prev);
				swap = 1;
			}
			else
			{
				start = start->prev;
			}
		}
	} while (swap);
}
