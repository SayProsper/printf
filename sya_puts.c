#include "main.h"
#include <unistd.h>

/**
 * sya_puts - A function that prints a string of characters
 * @str: The string input to be printed
 * Return: Size of str
 */
int sya_puts(char *str)
{
    int sya_index,  sya_count = 0;

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }
    else
    {
        for (sya_index = 0; str[sya_index] != '\0'; sya_index++)
        {
            sya_putchar(str[sya_index]);
            sya_count++;
        }
    }

    return (sya_count);
}

