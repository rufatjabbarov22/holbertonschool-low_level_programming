#include "lists.h"

/**
*get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
*@head: pointer to the head of the list
*@index: index of the node to return
*
*Return: pointer to the nth node, or NULL if the node does not exist
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *current = head;
	
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}
	
	return current;
}

