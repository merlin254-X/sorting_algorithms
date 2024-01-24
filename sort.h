#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/*enum bool - Enumeration of boolean values*/
/**
 * enum bool - Enumeration of boolean values
 * @false: Represents the logical value "false" or "0"
 * @true: Represents the logical value "true" or "1"
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/*Helper for swapping*/
void swap_ints(int *a, int *b);

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

/* functions */
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);

/*task 2*/
void quick_sort(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

void shell_sort(int *array, size_t size);

/*task 5*/
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t **k1, listint_t *k2);


void counting_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);

void heap_sort(int *array, size_t size);

void radix_sort(int *array, size_t size);
#endif
