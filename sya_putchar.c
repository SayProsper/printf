#include <unistd.h>
#include "main.h"

/**
 * sya_putchar - A function that prints one character at a time
 * @c: A character to be printed
 * Return: The size of c 
 */
int sya_putchar(char c)
{
    return (write(1, &c, 1));
}

