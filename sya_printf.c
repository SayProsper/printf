#include <stdarg.h>
#include "main.h"

/**
 * _printf - A function that produces output according to a format
 * @format: input character string for _printf
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int sya_index, sya_count = 0, sya_str_count;
	va_list sya_list;

	if (!format)
		return (-1);

	va_start(sya_list, format);

	for (sya_index = 0; format[sya_index] != '\0'; sya_index++)
	{
		if (format[sya_index] != '%')
		{
			sya_putchar(format[sya_index]);
			sya_count++;
		}
		else
		{
			if (format[sya_index + 1] == '\0')
				return (-1);
			else if (case_func(format[sya_index + 1]) != NULL)
			{
				sya_count += case_func(format[sya_index + 1])(sya_list);
				sya_index++;
			}
			else
			{
				switch (format[sya_index + 1])
				{
					case 'c':
						sya_putchar(va_arg(sya_list, int));
						sya_index++, sya_count++;
						break;
					case 's':
						sya_str_count = sya_puts(va_arg(sya_list, char *));
						sya_index++, sya_count += sya_str_count;
						break;
					case '%':
						sya_putchar('%');
						sya_index++, sya_count++;
						break;
					default:
						sya_putchar(format[sya_index]);
						sya_count++;
				}
			}
		}
	}

	va_end(sya_list);
	return (sya_count);
}

/**
 * case_func - A function that checks format specifiers
 * @y: Character input to be evaluated
 * Return: Pointer to the corresponding print function or NULL
 */
int (*case_func(const char y))(va_list)
{
	sya_print_f sya_print[] = {
		{'i', print_num},
		{'d', print_num},
		{'b', print_bin},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexadecimal},
		{'X', print_HEX},
		{'p', print_pointer},
		{'S', print_string},
		{'r', printf_string_reverse},
		{'R', print_rot13},
		{'\0', NULL}
	};

	int sya_index = 0;

	while (sya_print[sya_index].sya_ptr != '\0')
	{
		if (sya_print[sya_index].sya_ptr == y)
		{
			return (sya_print[sya_index].sya_func);
		}
		sya_index++;
	}

	return (NULL);
}
