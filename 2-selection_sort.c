#include "sort.h"

/**
 * selection_sort - Implement selection sort in C
 * @array: Array to sort
 * @size: Size of array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i;
	unsigned int j = 0;
	int lowest = array[0];
	int new_least_idx = 0;
	int tmp;
	int will_swap;

	if (!array || size <= 1)
		return;
	while (j < size - 1)
	{
		will_swap = 0;
		lowest = array[j];
		tmp = lowest;
		for (i = j + 1; i < size; i++)
		{
			if (array[i] < lowest)
			{
				lowest = array[i];
				new_least_idx = i;
				will_swap = 1;
			}
		}
		if (will_swap)
		{
			array[j] = lowest;
			array[new_least_idx] = tmp;
			print_array(array, size);
		}
		j++;
	}
}
