#include "main.h"

/**
 * print_string_reverse - A function that prints a string in reverse
 * @sya_list: type struct va_arg where is allocated printf arguments
 * Return: int
 */
int printf_string_reverse(va_list sya_list)
{
    char *str;
    int sya_index, sya_count;

    str = va_arg(sya_list, char*);
    if (str == NULL)
        str = "(null)";
    sya_count = 0;
    while (str[sya_count] != '\0')
        sya_count++;
    sya_index = (sya_count - 1);
    while (sya_index >= 0)
    {
        sya_putchar(str[sya_index]);
        sya_index--;
    }
    return (sya_count);
}

