#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    list_t *head;
    list_t *new;
    list_t hello = {"World", 5, NULL};
    size_t n;

    head = &hello;

    new = malloc(sizeof(list_t));
    if (new == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new->str = strdup("Hello");
    if (new->str == NULL)
    {
        printf("Error\n");
        free(new);
        return (1);
    }
    new->len = strlen(new->str);
    new->next = head;
    head = new;

    n = print_list(head);
    printf("-> %lu elements\n", n);

    printf("\n");

    /* Free the memory allocated for the strings */
    free(new->str);
    new->str = NULL;

    /* Print the list after setting the string to NULL */
    n = print_list(head);
    printf("-> %lu elements\n", n);

    /* Free the dynamically allocated memory */
    free(new);
    return (0);
}

