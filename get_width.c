#include "main.h"

/**
 * get_width - determines appropriate width for printing
 * @format: formatted string used for printing arguments
 * @c: arguments to be printed
 * @list: arguments
 * Return: Width.
 */
int get_width(const char *format, int *c, va_list list)
{
	int h;
	int width = 0;

	for (h = *c + 1; format[h] != '\0'; h++)
	{
		if (is_digit(format[h]))
		{
			width *= 10;
			width += format[p] - '0';
		}
		else if (format[h] == '*')
		{
			h++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*c = h - 1;

	return (width);
}
