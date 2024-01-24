#include "sort.h"

/**
 * heapify - Create a max heap from an array.
 * @array: The array to be transformed into a heap.
 * @size: The size of the array.
 * @root: The root index of the current subtree to heapify.
 * @max_size: The maximum size of the heap (used to print the array).
 */
void heapify(int *array, size_t size, size_t root, size_t max_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		/* Swap root with largest and print the array */
		int temp = array[root];

		array[root] = array[largest];
		array[largest] = temp;
		print_array(array, max_size);

		/* Recursively heapify the affected subtree */
		heapify(array, size, largest, max_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in
 * ascending order using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Build heap (rearrange array) */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* One by one extract an element from heap */
	for (i = size - 1; i > 0; i--)
	{
		/* Move current root to end */
		temp = array[0];

		array[0] = array[i];
		array[i] = temp;

		/* Print the array after each swap */
		print_array(array, size);

		/* Call max heapify on the reduced heap */
		heapify(array, i, 0, size);
	}
}

