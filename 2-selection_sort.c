#include "sort.h"
/**
 * selection_sort - sorts an array of integers
 *
 * @array: the array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (!array && size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
