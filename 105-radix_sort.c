#include "sort.h"

/**
 * radix_sort - radix sort algorthm for sorting numbers
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Void Function
*/
void radix_sort(int *array, size_t size)
{
	int i, max = 0, factor = 1;
	int *count = NULL, *output = NULL;

	if (!array || size <= 1)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}
	while (max / factor > 0)
	{
		count = malloc(size * sizeof(int));
		output = malloc(size * sizeof(int));
		if (!count || !output)
		{
			free(count);
			free(output);
			return;
		}
		for (i = 0; i < (int)size; i++)
			count[i] = 0;
		for (i = 0; i < (int)size; i++)
			count[(array[i] / factor) % 10]++;
		for (i = 1; i < (int)size; i++)
			count[i] += count[i - 1];
		for (i = size - 1; i >= 0; i--)
		{
			output[count[(array[i] / factor) % 10] - 1] = array[i];
			count[(array[i] / factor) % 10]--;
		}
		for (i = 0; i < (int)size; i++)
			array[i] = output[i];
		print_array(array, size);
		factor *= 10;
		free(count);
		free(output);
	}
}
