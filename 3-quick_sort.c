#include "sort.h"

int partition(int *array, int start, int end);

/**
 * quick - recursion function for quick sort
 * @array: array to be sorted
 * @start: start of array
 * @end: end of array
 * @size: size of array
 *
 * Return: Void Function
*/

void quick(int *array, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;
	pivot = partition(array, start, end);
	print_array(array, size);
	quick(array, start, pivot - 1, size);
	quick(array, pivot + 1, end, size);
}

/**
 * partition - locates a pivot
 * @array: array to be splited
 * @start: start of array
 * @end: end of an array
 *
 * Return: the pivot
*/
int partition(int *array, int start, int end)
{
	int pivot = array[end];
	int i = start - 1;
	int j, tmp;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	i++;
	tmp = array[i];
	array[i] = array[end];
	array[end] = tmp;
	return (i);
}

/**
 * quick_sort - quick sort algorthim for sorting data
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Void function
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	quick(array, 0, size - 1, size);
	print_array(array, size);
}
