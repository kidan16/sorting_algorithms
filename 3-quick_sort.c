#include "sort.h"
/**
 * partition - finds the partitions for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @start: lowest index of the partition to sort
 * @end: highest index of the partition to sort
 * @size: size
 * Return: index of the partition
 */
size_t partition(int *array, size_t start, size_t end, size_t size)
{
	size_t j;
	int temp;
	size_t partition_index = start - 1;
	int pivot = array[end];

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			partition_index++;
			if (partition_index != j)
			{
				temp = array[j];
				array[j] = array[partition_index];
				array[partition_index] = temp;
				print_array(array, size)
			}
		}
	}
	if (pivot < array[partition_index + 1])
	{
		temp = array[partition_index + 1];
		array[partition_index + 1] = pivot;
		pivot = temp;
		print_array(array, size);
	}
	return (partition_index + 1);
}
/**
 * sort - sorts a partition of an array of integers.
 * @array: array to sort
 * @start: lowest index of the partition
 * @end: highest index of the partition
 * @size: size
 * Return: void
 */
void sort(int *array, size_t start, size_t end, size_t size)
{
	ssize_t partition_index;
	if (start < end)
	{
		partition_index = partition(array, start, end, size);

		sort(array, start, partition_index - 1, size);
		sort(array, partition_index + 1, end, size);
	}
}

/**
 * quick_sort -Sort an array using quick_sort algorithm
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
