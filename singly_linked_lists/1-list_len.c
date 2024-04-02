#include "lists.h"
#include <stdlib.h>

/**
*list_len - list number of element in linked list
*@h: pointer to head
*
*Return: number of elements in list_t
*/

size_t list_len(const list_t *h)
{
	size_t count = 0;
	const list_t *current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
