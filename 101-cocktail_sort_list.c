#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: An array of integers to be sorted.
 * @size: Size of the array.
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, z, temp;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
		for (z = j - 1; z > 0; z--)
		{
			if (array[z] < array[z - 1])
			{
				temp = array[z];
				array[z] = array[z - 1];
				array[z - 1] = temp;

				print_array(array, size);
			}

		}
		
	
	}
}
