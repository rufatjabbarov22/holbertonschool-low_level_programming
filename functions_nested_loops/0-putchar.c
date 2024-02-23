#include "main.h"

/**
 *  * main - The entry point
 *   * Description: Prints _putchar, followed by a new line
 *    * Return: Always (0) when Successfull
 *     */


int main(void)
{
         int i = 0;
         char array[8] = {'_', 'p', 'u', 't',
                         'c', 'h', 'a', 'r'};

     while (i < 8)
	{
	      
	       	_putchar(array[i]);
	        
	       	i++;
	}

        _putchar('\n');
	return (0);
}
