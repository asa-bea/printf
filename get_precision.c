#include "main.h"
/**
* get_precision - Compute the precision for printing
* @format: Formatted string in which to print the arguments
* @h: List of args to be printed.
* @list: list of args.
*
* Return: Precision.
*/
int get_precision(const char *format, int *h, va_list list)
{
int curr_h = *h + 1;
int precision = -1;
if (format[curr_h] != '.')
return (precision);
precision = 0;
for (curr_h += 1; format[curr_h] != '\0'; curr_h++)
{
if (is_digit(format[curr_h]))
{
precision *= 10;
precision += format[curr_h] - '0';
}
else if (format[curr_h] == '*')
{
curr_h++;
precision = va_arg(list, int);
break;
}
else
break;

}
*h = curr_h - 1;
return (precision);
}
