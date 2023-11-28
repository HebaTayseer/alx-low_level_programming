#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees memory allocated for a struct dog
 * @d: Pointer to the struct dog to free
 *
 * Description: This function frees the memory allocated for a struct dog.
 */
void free_dog(dog_t *d)
{
    if (d != NULL)
    {
        free(d->name);
        free(d->owner);
        free(d);
    }
}
