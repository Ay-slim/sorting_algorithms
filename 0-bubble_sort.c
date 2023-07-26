#include "sort.h"

/**
 * bubble_sort - A function to implement the bubble sort algorithm
 * @array: Array to sort
 * @size: Size of array
 * Returns: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int all_good = 0;
	unsigned int i;
	int t;
	unsigned int j = size;

	if (size < 1 || !array)
		return;
	while (!all_good)
	{
		all_good = 1;
		for (i = 0; i < j - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				t = array[i];
				array[i] = array[i + 1];
				array[i + 1] = t;
				print_array(array, size);
				all_good = 0;
			}
		}
		j--;
	}
}
