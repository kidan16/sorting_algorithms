#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size) 
{
	int j, k;
	int * sort, * array_copy;
	
	if (!array || size < 2)
		return;
	
	k = array[0];
	for (j = 0; j < size; j++) 
	{
		if (array[j] > k)
		k = array[j];
	}
	
	sort = malloc(sizeof(int) * (k + 1));
	if (!sort)
		return;

	for (j = 0; j < k + 1; j++)
		sort[j] = 0;

	for (j = 0; j < k + 1; j++)
		sort[array[j]]++;

	for (j = 0; j < k + 1; j++)
		sort[j] += sort[j - 1];

	array_copy = malloc(sizeof(int) * size);
	if (!array_copy)
	{
		free(sort);
		return;
	}
	for (j = 0; j < size; j++)
		array_copy[j] = array[j];
	for (j = 0; j < size; j++)
		array_copy[--sort[array[j]]] = array[j];

	for (j = 0; j < size; j++)
		array[j] = array_copy[j];

	print_array(array, size);
	free(sort);
	free(array_copy);
}
