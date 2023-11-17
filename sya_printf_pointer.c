#include "main.h"

/**
 * print_pointer - Function to print address values.
 * @sya_list: input argument
 * Return: int
 */
int print_pointer(va_list sya_list)
{
    void *ptr;
    char *str = "(nil)";
    long int input;
    int sya_count, sya_index;

    ptr = va_arg(sya_list, void*);
    if (ptr == NULL)
    {
        sya_index = 0;
        while (str[sya_index] != '\0')
        {
            sya_putchar(str[sya_index]);
            sya_index++;
        }
        return (sya_index);
    }

    input = (unsigned long int)ptr;
    sya_putchar('0');
    sya_putchar('x');
    sya_count = print_hex_ptr(input);
    return (sya_count + 2);
}

