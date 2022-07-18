#include "sort.h"
/**
 * swap - swap the nodes
 * @a: the first node
 * @b: the 2nd node
 */

void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a doubly linkded list.
 * @list: the list to be sorted.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *reverse, *temp, *head;

	if (!list)
		return;

	head = *list;
	if (!head || !head->next)
		return;

	temp = head->next;
	while (temp)
	{
		reverse = temp;
		temp = temp->next;
		while (reverse->prev)
		{
			if (reverse->prev->n > reverse->n)
			{
				swap(reverse->prev, reverse);
				if (!reverse->prev)
					head = reverse;
				print_list(head);
			}
			reverse = reverse->prev;
		}
	}
}
