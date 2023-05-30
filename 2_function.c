#include "main.h"

/********************** PRINT POINTER ***********************/
/**
 * print_pointer - Displays the content stored in pointer variable.
 * @types: List of arguments used.
 * @buffer: Array to manage printing.
 * @flags:  Active flags.
 * @width: Pointer wiidth.
 * @precision: Spec for precision.
 * @size: Spec for size.
 * Return: Number of chars printed.
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long numb_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	numb_addrs = (unsigned long)addrs;

	while (numb_addrs > 0)
	{
		buffer[index--] = map_to[numb_addrs % 16];
		numb_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		c = '+', length++;
	else if (flags & F_SPACE)
		c = ' ', length++;

	index++;

	return (write_pointer(buffer, index, length,
		width, flags, padd, c, padd_start));
}

/********************** PRINT NON PRINTABLE **********************/
/**
 * print_nonPrintable - Displays hexa ASCII codes in of
 * non printable characters
 * @types: List of arguments used.
 * @buffer: Array to manage printing.
 * @flags:  Active flags.
 * @width: Pointer wiidth.
 * @precision: Spec for precision.
 * @size: Spec for size.
 * Return: Number of chars printed
 */
int print_nonPrintable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0, off_set = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + off_set] = str[a];
		else
			off_set += append_hexa_code(str[a], buffer, a + off_set);

		a++;
	}

	buffer[a + off_set] = '\0';

	return (write(1, buffer, a + off_set));
}

/********************** PRINT REVERSE **********************/
/**
 * print_reverse - Prints string in reverse.
 * @types: List of arguments used.
 * @buffer: Array to manage printing.
 * @flags:  Active flags.
 * @width: Pointer wiidth.
 * @precision: Spec for precision.
 * @size: Spec for size.
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int a, tally = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (a = 0; str[a]; a++)
		;

	for (a = a - 1; a >= 0; a--)
	{
		char b = str[a];

		write(1, &b, 1);
		tally++;
	}
	return (tally);
}
/********************** PRINT A STRING IN ROT13 **********************/
/**
 * print_rot13string - Prints string in rot13.
 * @types: List of arguments used.
 * @buffer: Array to manage printing.
 * @flags:  Active flags.
 * @width: Pointer wiidth.
 * @precision: Spec for precision.
 * @size: Spec for size.
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c;
	char *str;
	unsigned int a, b;
	int tally = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				c = out[b];
				write(1, &c, 1);
				tally++;
				break;
			}
		}
		if (!in[b])
		{
			c = str[a];
			write(1, &c, 1);
			tally++;
		}
	}
	return (tally);
}
