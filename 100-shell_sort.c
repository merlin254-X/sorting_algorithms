#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *               using the Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Find the largest gap in Knuth sequence less than or equal to size */
	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			/* Shift elements that are greater than temp to the right */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			/* Insert temp at its correct position */
			array[j] = temp;
		}

		/* Print array after each decrease in interval (gap) */
		print_array(array, size);

		/* Move to the next gap in Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
