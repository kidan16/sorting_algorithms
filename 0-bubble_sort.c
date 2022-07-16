#include "sort.h"
/**
 *bubble_sort - Sorts an array of integers in ascending order
 *@array: An array of integers to be sorted.
 *@size: Size of the array.
 *Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	while (!array || size == 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
