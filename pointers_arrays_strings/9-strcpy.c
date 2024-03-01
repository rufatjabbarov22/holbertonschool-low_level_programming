#include "main.h"

/**
* _strcpy - Copy the contents of one string to another
* @dest: Destination string where the copy will be stored
* @src: Source string to be copied
*
* Return: Pointer to the destination string
*/
char *_strcpy(char *dest, const char *src)
{
    char *start = dest;

    // Copy characters from source to destination until null terminator is reached
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    // Add null terminator to the destination string
    *dest = '\0';

    return start;
}
