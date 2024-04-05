#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n) of a dlistint_t linked list
 * @head: A pointer to the head of the linked list
 *
 * Return: The sum of all the data (n) of the linked list
 *         If the list is empty, return 0
 */
int sum_dlistint(dlistint_t *head)
{
    int sum = 0;

    /* Traverse the list and accumulate the sum of data */
    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }

    return sum;
}
