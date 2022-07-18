#include "sort.h"
/**
 * real_sorter - quick sort implementation
 * @arr: array to sort
 * @low: lowest index
 * @high: highest index
 * @size: size pf the array
 */
void real_sorter(int arr[], int low, int high, size_t size)
{
	int index, last_memb, save, current;
	int high_1, high_2, low_1, low_2;

	last_memb = arr[high];
	index = 0;
	current = high;

	while (index < high)
	{
		if (arr[index] > last_memb && index < current)
		{
			save = arr[index];
			arr[index] = last_memb;
			arr[current] = save;
			current = index;
		}
		if (arr[index] < last_memb && index > current)
		{
			arr[current] = arr[index];
			arr[index] = last_memb;
			save = index;
			index = current;
			current = save;
		}
		index++;
	}
	/*printf("%d -- ", last_memb);*/
	print_array(arr, size);
	if (index == high && index > 0)
		index = (low + high) / 2;

	low_1 = low;
	high_1 = current - 1;
	low_2 = current + 1;
	high_2 = high;

	if (low_1 < high_1)
		real_sorter(arr, low_1, high_1, size);
	if (low_2 < high_2)
		real_sorter(arr, low_2, high_2, size);
}

/**
 * quick_sort - quick_sort implementation
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	if (size < 2)
		return;

	low = 0;
	high = (int)size - 1;

	real_sorter(array, low, high, size);
}
