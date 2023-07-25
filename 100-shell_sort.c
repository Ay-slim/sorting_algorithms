#include "sort.h"

/**
 * shell_sort - Implement shell sort with the Knuth sequence
 * @array: Array to sort
 * @size: Size of array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int interval = 1;
	int size_casted = (int)size;
	int i;
	int temp;
	int j;

	while (interval <= size_casted / 3)
		interval = interval * 3 + 1;
	while (interval > 0)
	{
		for (i = interval; i < size_casted; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		interval = (interval - 1) / 3;

		for (i = 0; i < size_casted; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
	}
}
