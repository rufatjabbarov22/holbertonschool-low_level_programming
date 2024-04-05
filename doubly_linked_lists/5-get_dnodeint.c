#include "lists.h"

/**
*get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list
i
*@head: Pointer to the head of the list
*@index: Index of the node, starting from 0
*
*Return: Address of the nth node, or NULL if it does not exist
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i = 0;

    while (head && i < index)
    {
        head = head->next;
	i++;
    }
    
    return (head);
}

