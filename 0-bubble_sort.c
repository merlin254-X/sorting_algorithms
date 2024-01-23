#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *				 using the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;

				printf("%d", array[0]);
				for (k = 1; k < size; k++)
				{
					printf(", %d", array[k]);
				}
				printf("\n");
			}
		}
		if (swapped == 0)
			break;
	}
}

