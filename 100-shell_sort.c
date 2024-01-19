#include "sort.h"

/**
 * shell_sort - shell sort algorthim using Knuth sequence
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Void Function
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j, h = 1;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (h <= size / 3)
		h = h * 3 + 1;
	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= h && array[j - h] > tmp; j -= h)
				array[j] = array[j - h];
			array[j] = tmp;
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
