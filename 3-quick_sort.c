#include "sort.h"
/**
 * partition - finds the partitions for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @start: lowest index of the partition to sort
 * @end: highest index of the partition to sort
 * Return: index of the partition
 */
size_t partition(int *array, size_t start, size_t end)
{
	size_t j;
	int temp;
	size_t partition_index = start;
	int pivot = array[end];
	size_t n = sizeof(array) / sizeof(array[0]);

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[j];
			array[j] = array[partition_index];
			array[partition_index] = temp;
			partition_index++;
			print_array(array, n)
		}
	}

	temp = array[partition_index];
	array[partition_index] = pivot;
	pivot = temp;
	print_array(array, n);
	return (partition_index);
}
/**
 * sort - sorts a partition of an array of integers.
 * @array: array to sort
 * @start: lowest index of the partition
 * @end: highest index of the partition
 * Return: void
 */
void sort(int *array, size_t start, size_t end)
{
	if (start > end)
	{
		size_t partition_index = partition(array, start, end);

		sort(array, start, partition_index - 1);
		sort(array, partition_index + 1, end);
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
	sort(array, 0, size - 1);
}
