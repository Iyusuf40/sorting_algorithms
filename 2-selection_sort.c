#include "sort.h"
/**
 * selection_sort - implementation of selction sort
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int save, min;
	size_t i = 0, j, tail_index;

	while (i < size)
	{
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				tail_index = j;
			}
		}
		if (min != array[i])
		{
			save = array[i];
			array[i] = min;
			array[tail_index] = save;
			print_array(array, size);
		}
		i++;
	}
}
