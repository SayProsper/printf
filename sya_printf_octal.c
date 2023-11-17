#include "main.h"

/**
 * print_octal - function that prints octal of a number
 * @sya_list: Number to be evaluated for octal value
 * Return: int
 */
int print_octal(va_list sya_list)
{
    int sya_index, sya_count;
    int *array;
    unsigned int number, tmp;

    sya_count = 0;
    number = va_arg(sya_list, unsigned int);
    tmp = number;
    while (number / 8 != 0)
    {
        number /= 8;
        sya_count++;
    }
    sya_count++;
    array = malloc(sya_count * sizeof(int));

    sya_index = 0;
    while (sya_index < sya_count)
    {
        array[sya_index] = tmp % 8;
        tmp /= 8;
        sya_index++;
    }
    for (sya_index = sya_count - 1; sya_index >= 0; sya_index--)
    {
        sya_putchar(array[sya_index] + 48);
    }
    free(array);
    return (sya_count);
}

