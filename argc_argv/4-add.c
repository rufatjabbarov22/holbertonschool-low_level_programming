#include <stdio.h>
#include <stdlib.h>

/**
*main - adds positive numbers
*@argc: number of arguments
*@argv: array of arguments
*Return: 0 on success, 1 on failure
*/
int main(int argc, char *argv[])
{
    int i, j;
    long sum = 0;

    if (argc < 2)
    {
        printf("0\n");
        return 0;
    }

    for (i = 1; i < argc; i++)
    {
        for (j = 0; argv[i][j] != '\0'; j++)
        {
            if (j == 0 && (argv[i][j] == '+' || argv[i][j] == '-'))
                continue;
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                printf("Error\n");
                return 1;
            }
        }
        long num = atol(argv[i]);
        sum += num;
    }
    printf("%ld\n", sum);

    return 0;
}

