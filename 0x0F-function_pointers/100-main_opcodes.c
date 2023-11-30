#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * main - prints a name as is
 * @argc: number of arguments
 * @argv: arguments vector
 *
 * Return: 0 on success, 1 on incorrect number of arguments, 2 on negative number
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	if (atoi(argv[1]) < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/* Placeholder for printing the name */
	printf("Name: %s\n", argv[1]);

	return (0);
}

