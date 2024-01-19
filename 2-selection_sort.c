#include "sort.h"

/**
 * selection_sort - selection_sort algorthim
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Void function
*/

void selection_sort(int *array, size_t size)
{
	size_t smallest, tmp;
	size_t i, j;

	if (array == NULL || size <= 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
			{
				smallest = j;
				continue;
			}
		}
		if (smallest != i)
		{
			tmp = array[i];
			array[i] = array[smallest];
			array[smallest] = tmp;
			print_array(array, size);
		}
	}
}
