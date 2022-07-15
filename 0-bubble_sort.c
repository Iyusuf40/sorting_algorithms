#include "sort.h"
/**
 * bubble_sort - implementation of bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t swapped = 0, i = 0;
	int save;

	while (1)
	{
		if (size < 2)
			return;

		i = 0;
		swapped = 0;
		while (i < (size - 1))
		{
			if (array[i] > array[i + 1])
			{
				save = array[i];
				array[i] = array[i + 1];
				array[i + 1] = save;
				print_array(array, size);
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break;
	}
}
