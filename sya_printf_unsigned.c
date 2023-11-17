#include "main.h"

/**
 * print_unsigned - A function that prints unsigned specifier
 * @sya_list: unsigned arguement to be evaluated
 * Return: Number of characters printed (nBytes)
 */
int print_unsigned(va_list sya_list)
{
    unsigned int number = va_arg(sya_list, unsigned int);
    int num, last_digit, digit, tmp_div, sya_count = 1;

    number /= 10;
    num = number;
    last_digit = number % 10;
    tmp_div = 1;
    sya_count = 1;

    if (last_digit < 0)
    {
        sya_putchar(45);
        num *= (-1);
        number *= (-1);
        last_digit *= (-1);
        sya_count++;
    }
    if (num > 0)
    {
        while (num / 10 != 0)
        {
            tmp_div *= 10;
            num /= 10;
        }
        num = number;
        while (tmp_div > 0)
        {
            digit = num / tmp_div;
            sya_putchar(digit + 48);
            num -= (digit * tmp_div);
            tmp_div /= 10;
            sya_count++;
        }
    }
    sya_putchar(last_digit + 48);

    return (sya_count);
}

