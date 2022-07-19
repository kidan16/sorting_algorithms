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
	size_t gap = 1, x, z, temp;
	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (z = gap; z < size; z++)
		{
			for (x = z; x >= 0; x = x - gap)
			{
				if (array[x] < array[x - gap])
				{
					temp = array[x];
					array[x] = array[x - gap];
					array[x - gap] = temp;
				}
				else
					break;
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
