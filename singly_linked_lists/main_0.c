#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * _create_list - Creates a linked list
 * @str: String to be inserted into the list
 *
 * Return: Pointer to the created list
 */
list_t *_create_list(const char *str)
{
    list_t *tmp, *head;

    if (str == NULL)
        return (NULL);

    head = malloc(sizeof(list_t));
    if (head == NULL)
        return (NULL);

    head->str = strdup(str);
    if (head->str == NULL)
    {
        free(head);
        return (NULL);
    }

    head->next = NULL;

    return (head);
}

