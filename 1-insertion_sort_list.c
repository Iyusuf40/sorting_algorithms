#include "sort.h"
/**
 * insertion_sort_list - implementation of insertion sort
 * @list: doubly llinked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *prev, *next;

	if (!list)
		return;

	head = *list;
	while (head)
	{
		if (head->prev)
		{
			if (head->n < (head->prev)->n)
			{
				prev = head->prev;
				next = head->next;
				head->prev = prev->prev;
				if (prev->prev)
					(prev->prev)->next = head;
				else
					*list = head;
				head->next = prev;
				prev->prev = head;
				prev->next = next;
				if (next)
					next->prev = prev;
				print_list(*list);
				head = *list;
			}

		}
		head = head->next;
	}
}
