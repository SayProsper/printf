#include "main.h"

/**
 * print_rot13 - A function that prints a string to ROT13 place into buffer
 * @sya_list: input argument
 * Return: int
 */

int print_rot13(va_list sya_list)
{
    int sya_index, sya_count, i, j;
    char *str;
    char alpha[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char beta[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

    sya_count = 0;
    str = va_arg(sya_list, char*);
    if (str == NULL)
        str = "(null)";
    sya_index = 0;
    while (str[sya_index])
    {
        j = 0;
        for (i = 0; alpha[i] && !j; i++)
        {
            if (str[sya_index] == alpha[i])
            {
                sya_putchar(beta[i]);
                sya_count++;
                j = 1;
            }
        }
        if (!j)
        {
            sya_putchar(str[sya_index]);
            sya_count++;
        }
        sya_index++;
    }
    return (sya_count);
}

