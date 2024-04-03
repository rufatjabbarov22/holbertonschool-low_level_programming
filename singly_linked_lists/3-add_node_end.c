#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
*add_node_end - adds a new node at the end of a list_t list
*@head: pointer to the pointer of the head of the list
*@str: string to be added as data of the new node
*
*Return: the address of the new element, or NULL if it failed
*/

list_t *add_node_end(list_t **head, const char *str)
{
        list_t  *new_node,  *last_node;
	unsigned int len = 0;

	if (str == NULL)
                return ( NULL );
	
	new_node = malloc(sizeof( list_t ));
	if (new_node == NULL)
		return (NULL);

        new_node->str = strdup(str);
        if (new_node->str == NULL)
        {
                free(new_node);
                return (NULL);
        }

        new_node->next = NULL;

        while (str[len] != '\0')
                len++;

        new_node->len = len;

        if (*head == NULL)
        {
                *head = new_node;
        }
        else
        {
                last_node = *head;
                while (last_node->next != NULL)
                {
                        last_node = last_node->next;
                }
                last_node->next = new_node;
        }

        return (new_node);
}

