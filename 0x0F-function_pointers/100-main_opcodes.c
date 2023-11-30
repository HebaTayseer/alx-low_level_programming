#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on incorrect number of arguments, 2 on negative number of bytes
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	int num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	char *main_ptr = (char *)main;

	for (int i = 0; i < num_bytes; i++)
	{
		printf("%02x", main_ptr[i] & 0xFF);

		if (i < num_bytes - 1)
			printf(" ");
	}

	printf("\n");
	exit(0);
}

