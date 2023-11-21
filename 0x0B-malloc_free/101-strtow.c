#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * count_words - Count the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
static int count_words(char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str == ' ')
        {
            in_word = 0;
        }
        else if (in_word == 0)
        {
            in_word = 1;
            count++;
        }
        str++;
    }

    return (count);
}

/**
 * alloc_and_copy - Allocate memory and copy characters.
 * @str: The source string.
 * @len: The length to copy.
 *
 * Return: A new string.
 */
static char *alloc_and_copy(char *str, int len)
{
    char *new_str;
    int i;

    new_str = (char *)malloc((len + 1) * sizeof(char));
    if (new_str == NULL)
        return (NULL);

    for (i = 0; i < len; i++)
        new_str[i] = *str++;

    new_str[len] = '\0';

    return (new_str);
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A pointer to an array of strings (words), or NULL if it fails.
 */
char **strtow(char *str)
{
    int words, i;
    char **result;

    if (str == NULL || *str == '\0')
        return (NULL);

    words = count_words(str);

    if (words == 0)
        return (NULL);

    result = (char **)malloc((words + 1) * sizeof(char *));
    if (result == NULL)
        return (NULL);

    for (i = 0; i < words; i++)
    {
        int len = 0;

        while (*str == ' ')
            str++;

        while (str[len] != ' ' && str[len] != '\0')
            len++;

        result[i] = alloc_and_copy(str, len);
        if (result[i] == NULL)
        {
            while (i > 0)
                free(result[--i]);
            free(result);
            return (NULL);
        }

        str += len;
    }

    result[words] = NULL;

    return (result);
}

