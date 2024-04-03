#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
    char *str;
    struct list_s *next;
} list_t;

/* Function prototypes */
list_t *add_node_end(list_t **head, const char *str);
void print_list(const list_t *h);

#endif /* LISTS_H */

