#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @k1: A pointer to the first node to swap.
 * @k2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **k1, listint_t *k2)
{
	(*k1)->next = k2->next;
	if (k2->next != NULL)
		k2->next->prev = *k1;
	k2->prev = (*k1)->prev;
	k2->next = *k1;

	if ((*k1)->prev != NULL)
		(*k1)->prev->next = k2;
	else
		*h = k2;

	(*k1)->prev = k2;
	*k1 = k2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers in ascending order
 * using the Insertion sort algorithm.
 * @list: A pointer to the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insert = current->prev;
		while (insert != NULL && current->n < insert->n)
		{
			swap_nodes(list, &insert, current);
			print_list((const listint_t *)*list);
		}

	}
}
