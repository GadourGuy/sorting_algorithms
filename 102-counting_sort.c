#include "sort.h"

/**
 * counting_sort - countig sort algorthim for sorting
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Void function
*/
void counting_sort(int *array, size_t size)
{
	int *count, *out;
	int j, k = 0, i;

	if (!array || size <= 1)
		return;
	for (i = 0; i < (int)size; i++)
	{
		if (k <= array[i])
			k = array[i];
	}
	count = malloc((k + 1) * sizeof(int));
	if (count == NULL)
		return;
	out = malloc(size * sizeof(int));
	if (out == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < (k + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
	{
		j = array[i];
		count[j] = count[j] + 1;
	}
	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, k + 1);
	for (i = size - 1; i >= 0; i--)
	{
		j = array[i];
		count[j] = count[j] - 1;
		out[count[j]] = array[i];
	}
	for (i = 0; i < (int)size; i++)
		array[i] = out[i];
	free(count);
	free(out);
}
