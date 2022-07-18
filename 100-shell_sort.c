#include "sort.h"
/**
 * shell_sort - sort array with shell method
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
*/

void shell_sort(int *array, size_t size)
{
	size_t gap, first, last, temp;

	if (!array || size < 2)
		return;

	gap = (size - 1) / 3;

	while (gap >= 1)
	{
		for (last = gap; gap < size; last++)
		{
			for (first = last - gap; first >= 0; last - gap)
			{
				if (array[first + gap] > array[first])
				{
					break;
				}
				else
				{
					temp = array[first + gap];
					array[first + gap] = array[first];
					array[first] = temp;
					print_array(array, size);
				}
			}
		}
		gap = (gap - 1) / 3;
	}
}
