#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @x: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *x)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int p, curr_x;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_x = *x + 1; format[curr_x] != '\0'; curr_x++)
	{
		for (p = 0; FLAGS_CH[p] != '\0'; p++)
			if (format[curr_x] == FLAGS_CH[p])
			{
				flags |= FLAGS_ARR[p];
				break;
			}

		if (FLAGS_CH[p] == 0)
			break;
	}

	*x = curr_x - 1;

	return (flags);
} /*by Joshua Ryan Akakpo and Lillian Quarshie*/
