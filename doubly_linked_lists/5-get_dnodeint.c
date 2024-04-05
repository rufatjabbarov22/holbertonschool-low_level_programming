#include "lists.h"

/**
* get_dnodeint_at_index - Retrieves the nth node of a dlistint_t linked list
* @head: A pointer to the head of the linked list
* @index: The index of the node to retrieve
*
* Return: If the node does not exist, return NULL.
*         Otherwise, return a pointer to the nth node.
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    dlistint_t *current = head;
    unsigned int i = 0;

    /* Traverse the list until reaching the desired index */
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    /* If the index exceeds the length of the list, return NULL */
    if (current == NULL)
        return NULL;

    /* Return a pointer to the node at the desired index */
    return current;
}

