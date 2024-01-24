#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort_radix - Sort an array of integers using counting sort.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 * @exp: The current digit to consider.
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count, i;
	size_t index;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	count = malloc(sizeof(int) * 10);
	if (count == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (index = 0; index < size; index++)
		count[(array[index] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (index = size - 1; (int)index >= 0; index--)
	{
		output[count[(array[index] / exp) % 10] - 1] = array[index];
		count[(array[index] / exp) % 10]--;
	}

	for (index = 0; index < size; index++)
	{
		array[index] = output[index];
		print_array(array, size);
	}

	free(output);
	free(count);
}

/**
 * radix_sort - Sort an array of integers in ascending order
 * using LSD Radix sort.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
	}
}

