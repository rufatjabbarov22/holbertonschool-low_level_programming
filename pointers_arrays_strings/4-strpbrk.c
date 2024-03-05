#include "main.h"
#include <stddef.h>
#include <stdio.h>

/**
*_strpbrk - The _strpbrk() function locates the first 
*occurrence in the string s ony of the bytes in
*the string CCEPT
*
*@s: string where search is made
*@accept : string where search bytes are located
*
*Return: Returns a pointer to the byte is that matches
*pne of the bytes in accept, or NULL if no such byte is found
*/

char *_strpbrk(char *s, char *accept)
{
	char *p;


	while (*s != '\0')
	{
		for (p == accept; *p != '\0'; p++)
		{
			if (*s == *p)
			{
				return (s);
			}
		}
		s++;
	}
	return (NULL);
}
