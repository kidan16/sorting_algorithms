#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Size of the doubly linked list.
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *temp, *first, * third, *reverse;

	if (!list)
		return;
	head = *list;
	if (!head || !head->next)
		return;
	temp = head->next;
	if (!temp->next)
	{
		if ((temp->n) < (temp->prev->n))
		{
			head = temp;

			temp->next = head->prev;
			temp->prev = NULL;
			head->prev->next = NULL;
			head->prev->prev = temp;
		}
		return;
	}
	if (!temp->next->next)
	{
		if ((temp->n) < (temp->prev->n))
		{
			head = temp;

			temp->next = head->prev;
			temp->prev = NULL;
			head->prev->next = head->next;
			head->prev->prev = temp;
			head->next->prev = head->prev;
			print_list(head);

			temp = temp->next;
		}

		temp = temp->next;
		if ((temp->n) < (temp->prev->n))
		{
			temp->next = head->next;
			temp->prev = head;
			head->next->next = NULL;
			head->next->prev = temp;
			print_list(head);

			head->next = temp;
		}
		return;
	}
	while(temp->next->next)
	{
		reverse = temp;
		temp = temp->next;
		while (reverse->prev->prev)
		{
			if ((reverse->n) < (reverse->prev->n))
			{
				third = reverse;
				first = third->prev->prev;

				third->prev->next = third->next;
				third->prev->prev = third;
				first->next = third;
				third->next->prev = third->prev;
				third->next = third->prev;
				third->prev = first;
				reverse = reverse->next;
				print_list(head);
			}
			reverse = reverse->prev;
		}
	}
}
