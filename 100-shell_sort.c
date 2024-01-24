#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @list: A pointer to the head of the doubly-linked list.
 * @a: A pointer to the first node to swap.
 * @b: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
		a->prev->next = b;
	else
		*list = b;

	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *						order using the Cocktail shaker sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *tail;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (tail = current; tail->prev != NULL; tail = tail->prev)
		{
			if (tail->n < tail->prev->n)
			{
				swap_nodes(list, tail->prev, tail);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}

