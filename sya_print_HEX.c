#include "main.h"

/**
 * print_HEX - Function that prints hexadecimal value of a number.
 * @sya_list: Number to be evaluated for its hexadecimal.
 * Return: int.
 */
int print_HEX(va_list sya_list)
{
    int sya_index, sya_count;
    int *array;
    unsigned int number, tmp;

    sya_count = 0;
    number = va_arg(sya_list, unsigned int);
    tmp = number;
    while (number / 16 != 0)
    {
        number /= 16;
        sya_count++;
    }
    sya_count++;
    array = malloc(sya_count * sizeof(int));

    sya_index = 0;
    while (sya_index < sya_count)
    {
        array[sya_index] = tmp % 16;
        tmp /= 16;
        sya_index++;
    }
    for (sya_index = sya_count - 1; sya_index >= 0; sya_index--)
    {
        if (array[sya_index] > 9)
            array[sya_index] = array[sya_index] + 7;
        sya_putchar(array[sya_index] + 48);
    }
    free(array);
    return (sya_count);
}

