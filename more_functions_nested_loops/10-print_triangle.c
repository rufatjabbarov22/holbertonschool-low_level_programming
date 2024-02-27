#include <stdio>

/**
*  main - main block, solve fizz buzz from numbers 1 to 100
* Description: Multiples of 3, print Fizz. Multiples of 5, print Buzz.
* Multiples of both 3 and 5 should print FizzBuzz.
* Return: 0
*/
int main(void)
{
	int i;

	for (i = 1; i < 100; i++)
	{
		if ((i % 3 == 0) &&  (i % 5 == 0))
		{
			printf("FizzBuzz\n");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz\n");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz\n");
		}
		else
		{
			printf("%d\n", i);
		}
	}
	return (0);
}
