#include "main.h"
#include <stdio.h>

/**
*_strchr - returns a pointer to the first occurrence
*of the character c in the string s, or NULL if the
*characher is not found
*@s: string targeted
*@c:character targeted
*
*Returns: returns pointer to first occurence of c
*/

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}
