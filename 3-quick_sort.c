#include "sort.h"
#include <stdio.h>
/**
 * partition - finds the partition for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @st: lowest index of the partition to sort
 * @en: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t st, ssize_t en, size_t size)
{
	ssize_t j, x;
	int temp, pivot;

	pivot = array[en];
	x = st - 1;

	for (j = st; j < en; j++)
	{
		if (array[j] < pivot)
		{
			x++;
			if (x != j)
			{
				temp = array[x];
				array[x] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[en] < array[x + 1])
	{
		temp = array[x + 1];
		array[x + 1] = pivot;
		pivot = temp;
		print_array(array, size);
	}
	return (x + 1);
}
/**
 * sort_parts - sorts a partition of an array of integers
 * @array: array to sort
 * @st: lowest index of the partition to sort
 * @en: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void sort_parts(int *array, ssize_t st, ssize_t en, size_t size)
{
	ssize_t part;

	if (st < en)
	{
		part = partition(array, st, en, size);

		sort_parts(array, st, part - 1, size);
		sort_parts(array, part + 1, en, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort_parts(array, 0, size - 1, size);
}
