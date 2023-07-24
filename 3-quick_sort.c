#include "sort.h"
/**
 * partition - helper function to patition an array for quicksort
 * @array: Array to partition
 * @left: Left pointer index
 * @right: Right pointer index
 * @size: Size of array to sort
 * Return: The final left pointer value
 */
unsigned int partition(int *array, int left, int right, size_t size)
{
	int ptr_tmp;
	int val_tmp;
	int pivot = right;

	right--;
	while (1)
	{
		while (array[left] < array[pivot])
			left++;
		while (array[right] > array[pivot] && right > 0)
			right--;
		if (left >= right)
			break;
		ptr_tmp = array[right];
		array[right] = array[left];
		array[left] = ptr_tmp;
		print_array(array, size);
		left++;
	}
	val_tmp = array[pivot];
	array[pivot] = array[left];
	array[left] = val_tmp;
	print_array(array, size);
	return (left);
}

/**
 * quick_sort_core - Recursive function to keep partitioning array
 * @array: Array to sort
 * @left: Left index
 * @right: Right index
 * @size: Size of array to sort
 * Return: Nothing
 */
void quick_sort_core(int *array, int left, int right, size_t size)
{
	int pivot_index;

	if (right - left <= 0)
		return;
	pivot_index = partition(array, left, right, size);
	quick_sort_core(array, left, pivot_index - 1, size);
	quick_sort_core(array, pivot_index + 1, right, size);
}

/**
 * quick_sort - Implement the quick sort algorithm
 * @array: Pointer to Array to sort
 * @size: Size of array to sort
 */
void quick_sort(int *array, size_t size)
{
	int left = 0;
	int right = size - 1;

	if (!array || size <= 1)
		return;
	quick_sort_core(array, left, right, size);
}
