#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, z, m; min;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		z = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
				min = j;
			if (array[j] == array[i])
			{
				for (m = i + 1; m < j; m++)
				{
					if (array[m] == array[i])
						continue;
					else
					{
						temp = array[i + 1];
						array[i + 1] = array[j];
						array[j] = temp;
						print_array(array, size);
					}
				}
			}
		}

		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}

	}
}
