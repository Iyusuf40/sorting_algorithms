#include "sort.h"
/**
 * back_sorter - looks for index to insert bakcwards
 * @current: current position of linked list
 * @list: doubly linked lisr
 * Return: pointer to position of insert
 */
listint_t *back_sorter(listint_t *current, listint_t **list)
{
	listint_t *head = *list, *prev;

	while (head)
	{
		if (head->n > current->n)
		{
			prev = head->prev;
			if (prev)
				prev->next = current;
			else
				*list = current;
			head->prev = current;
			current->prev = prev;
			current->next = head;
			return (current);
		}
		head = head->next;
	}
	return (NULL);
}

/**
 * insertion_sort_list - implementation of insertion sort
 * @list: doubly llinked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *prev, *next, *save;

	if (!list)
		return;

	head = *list;
	while (head)
	{
		if (head->prev)
		{
			if (head->n < (head->prev)->n)
			{
				save = head;
				prev = head->prev;
				next = head->next;
				head = back_sorter(head, list);
				if (prev && head)
					prev->next = next;
				if (next && head)
					next->prev = prev;
				if (!head)
					head = save;
				print_list(*list);
			}

		}
		head = head->next;
	}
}
