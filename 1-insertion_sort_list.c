#include "sort.h"
/**
 *insertion_sort_list - Implements insertion sort
 *@list: Linkedlist to sort
 *Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *tmp2, *aux1, *aux2;
	int not_sorted;

	if (list)
	{
		tmp1 = *list;
		tmp2 = *list;
		while (list && tmp1->next)
		{
			if (tmp1->next)
			{
				not_sorted = 0;
				tmp2 = tmp1;
				while (tmp2 && tmp2->n > tmp2->next->n)
				{
					aux1 = tmp2;
					aux2 = tmp2->next;
					aux1->next = aux2->next;
					if (aux2->next)
						aux2->next->prev = aux1;
					if (aux2)
					{
						aux2->prev = aux1->prev;
						aux2->next = aux1;
					}
					if (aux1)
						aux1->prev = aux2;
					if (aux2->prev)
						aux2->prev->next = aux2;
					tmp2 = aux2->prev;
					if (!aux2->prev)
						*list = aux2;
					print_list(*list);
					not_sorted = 1;
				}
			}
			if (!not_sorted)
				tmp1 = tmp1->next;
		}
	}
}
