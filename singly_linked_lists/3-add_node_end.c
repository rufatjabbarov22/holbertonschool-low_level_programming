#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer to the head of the list
 * @str: string to be duplicated and added to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node, *last_node;

    /* Allocate memory for new node */
    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    /* Initialize new node */
    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }
    new_node->next = NULL;

    /* If the list is empty, set the new node as the head */
    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    /* Traverse the list to find the last node */
    last_node = *head;
    while (last_node->next != NULL)
        last_node = last_node->next;

    /* Append the new node to the end of the list */
    last_node->next = new_node;

    return (new_node);
}

