#include "sort.h"

/**
 * bubble_sort - An algorithm for sorting
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Void Function
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int tmp;

	if (!array || size <= 0)
	{
		return;
	}
	while (j != size)
	{
		for (i = 0; i <= size - 2; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}
}
