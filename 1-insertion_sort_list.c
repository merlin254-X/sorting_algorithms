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
		listint_t *current, *insert_node, *temp;
		int key;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insert_node = current;
		key = insert_node->n;

		while (insert_node->prev != NULL && insert_node->prev->n > key)
		{
			/**Swap node instead of modifying the integer n**/
			temp = insert_node->prev;
			insert_node->prev = temp->prev;

			if (temp->prev != NULL)
				temp->prev->next = insert_node;

			temp->next = insert_node->next;

			if (insert_node->next != NULL)
				insert_node->next->prev = temp;

			insert_node->next = temp;
			temp->prev = insert_node;

			if (insert_node->prev != NULL)
				insert_node->prev->next = insert_node;

			print_list(*list);
		}

		current = current->next;
	}
}

