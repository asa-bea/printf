#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - custom Printf function
 * @form: the format string
 * Return: the number of characters Printed
 */
int _printf(const char *form, ...)
{
	int kim, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)

		return (-1);
	va_start(list, form);
	for (kim = 0; form && form[kim] != '\0'; kim++)
	{
		if (form[kim] != '%')
		{
			buffer[buff_ind++] = form[kim];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &form[k], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(form, &kim);
			width = get_width(form, &kim, list);
			precision = get_precision(form, &kim, list);
			size = get_size(form, &kim);
			++kim;
			printed = handle_print(form, &kim, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
