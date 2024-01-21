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
	int i, tmp, compare, *radix;

	if (!array || size <= 0)
		return;
	for(i = 0; i < (int)size; i++)
	{
		if ((array[i] % 10) > (array[i + 1] % 10))
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
		}
	}
	compare = array[size - 1];
	print_array(array, size);
	radix = malloc(sizeof(int) * size);
	if (radix == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		radix[i] = (array[i] / 10);
	if (compare / 10 == 0)
	{
		free(radix);
		return;
	}
	radix_sort(radix, size);
}
