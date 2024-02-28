#include "main.h"
/**
*print_square - prints the alphabet.
*@size: square size
*/

void print_square(int size)
{
	int pr;
		int rm;
	if (size > 0)
{

		for (pr = 0; pr < size; pr++)
		{
			for (rm = 0; rm < size; rm++)
			{
				_putchar(35);
			}
				_putchar('\n');
		}
}
else
{
	_putchar('\n');
}
}
