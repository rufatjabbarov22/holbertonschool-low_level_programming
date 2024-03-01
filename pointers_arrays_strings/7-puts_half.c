#include "main.h"

/**
*puts_half - function that prints half of a string, followed by a new line
*
*@str: this is my input char or string
*/
void puts_half(char *str)
{
	int i, half;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	half = i / 2;
	if (i % 2 != 0)
	{
		half++;
	}

	while (str[half] != '\0')
	{
		_putchar(str[half]);
		half++;
	}

	_putchar('\n');
}
