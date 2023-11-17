#include "custom_printf.h"

/**
 * print_number - Prints a number
 * @num: Variable va_list
 * Return: Number of digits printed
 */
int print_number(va_list num)
{
    long int number = va_arg(num, int);
    int digit_count = 0;

    if (number < 0)
    {
        number *= -1;
        sya_putchar('-');
        digit_count++;
    }

    if (number == 0)
    {
        sya_putchar('0');
        digit_count++;
    }
    else
    {
        digit_count += print_digits(number);
    }

    return digit_count;
}

/**
 * print_binary - Prints the binary representation of a number
 * @num: Input number to be printed in binary
 * Return: Number of binary digits printed
 */
int print_binary(va_list num)
{
    unsigned int number = va_arg(num, unsigned int);
    int binary_count = 0;

    if (number == 0)
    {
        sya_putchar('0');
        binary_count++;
    }
    else
    {
        binary_count += print_binary_digits(number);
    }

    return binary_count;
}

/**
 * print_digits - Helper function to print digits of a number
 * @number: Number to be printed
 * Return: Number of digits printed
 */
int print_digits(long int number)
{
    int base_ten = 10;
    int digit_count = 0;

    while ((number / base_ten) > 0)
    {
        digit_count += print_digit(number % base_ten);
        number /= base_ten;
    }

    digit_count += print_digit(number);

    return digit_count;
}

/**
 * print_binary_digits - Helper function to print binary digits of a number
 * @number: Number to be printed in binary
 * Return: Number of binary digits printed
 */
int print_binary_digits(unsigned int number)
{
    int binary_count = 0;
    int left_shift = 1;

    for (int bns_index = 31; bns_index >= 0; bns_index--)
    {
        unsigned int position = (left_shift << bns_index);
        int bit = (position & number) ? 1 : 0;

        if (bit || binary_count > 0)
        {
            sya_putchar(bit + '0');
            binary_count++;
        }
    }

    if (binary_count == 0)
    {
        sya_putchar('0');
        binary_count++;
    }

    return binary_count;
}

/**
 * print_digit - Helper function to print a single digit
 * @digit: Digit to be printed
 * Return: Always 1 (for consistency)
 */
int print_digit(int digit)
{
    sya_putchar(digit + '0');
    return 1;
}

