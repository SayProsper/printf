#include "main.h"
/**
 * print_string - A function print exclusuives string.
 * @sya_list: The input argument
 * Return: int
 */

int print_string(va_list sya_list)
{
    char *str;
    int sya_index, sya_count;
    int num;

    sya_count = 0, sya_index = 0;
    str = va_arg(sya_list, char *);
    if (str == NULL)
        str = "(null)";
    while (str[sya_index] != '\0')
    {
        if (str[sya_index] < 32 || str[sya_index] >= 127)
        {
            sya_putchar('\\');
            sya_putchar('x');
            sya_count += 2;
            num = str[sya_index];
            if (num < 16)
            {
                sya_putchar('0');
                sya_count++;
            }
            sya_count += print_hex_ptr(num);
        }
        else
        {
            sya_putchar(str[sya_index]);
            sya_count++;
        }
        sya_index++;
    }
    return (sya_count);
}

