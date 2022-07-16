#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

swap(int *x, int *y);

/**
 *swap - swaps two integers.
 *@x: Pointer to the first integer.
 *@y: Pointer tothe second integer.
 *Return: Nothing.
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);

print_array(const int *array, size_t size);
print_list(const listint_t *list);
#endif
