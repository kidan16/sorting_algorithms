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
 * insertion_sort_list - sorts a doubly linkded list
 * @list: the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *reverse, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	temp = (*list)->next;
	while (temp)
	{
		reverse = temp;
		while (reverse->prev)
		{
			if (reverse->prev->n > reverse->n)
			{
				swap(reverse->prev, reverse);
				if (!reverse->prev)
					*list = reverse;
				print_list((const listint_t *)*list);
			}
			else
				reverse = reverse->prev;
		}
		temp = temp->next;
	}
}
