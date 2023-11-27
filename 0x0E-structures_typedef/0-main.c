#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = malloc(sizeof(char) * 6);  // Allocating memory for "Poppy" (including null terminator)
    my_dog.owner = malloc(sizeof(char) * 4); // Allocating memory for "Bob" (including null terminator)

    if (my_dog.name == NULL || my_dog.owner == NULL)
    {
        printf("Memory allocation failed\n");
        return 1; // Return an error code
    }

    // Copying the strings into the allocated memory
    strcpy(my_dog.name, "Poppy");
    my_dog.age = 3.5;
    strcpy(my_dog.owner, "Bob");

    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);

    // Don't forget to free the allocated memory
    free(my_dog.name);
    free(my_dog.owner);

    return 0;
}
