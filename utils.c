#include "main.h"
/**
* is_printable - Access if a character is printable
* @h: Char to be assessed.
*
* Return: 1 if h is printable, 0 otherwise (successful)
*/
int is_printable(char h)
{
if (h >= 32 && h < 127)
return (1);
return (0);
}
/**
* append_hexa_code - Append ascci in hexadecimal code to buffer
* @buffer: An array of characters.
* @a: Index at which to start appending.
* @ascii_code: ASSCI CODE.
* Return: Always 3 (successful)
*/
int append_hexa_code(char ascii_code, char buffer[], int a)
{
char map_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
if (ascii_code < 0)
ascii_code *= -1;
buffer[a++] = '\\';
buffer[a++] = 'x';
buffer[a++] = map_to[ascii_code / 16];
buffer[a] = map_to[ascii_code % 16];
return (3);
}
/**
* is_digit - Confirms if a char is a digit
* @y: Character to be assessed
*
* Return: 1 if y is a digit, 0 otherwise
*/
int is_digit(char y)
{
if (y >= '0' && y <= '9')
return (1);
return (0);
}
/**
* convert_size_number - Converts a number to the specified size
* @number: Number to be converted
* @size: Size indicating the type to be converted to.
*
* Return: Converted value of num

*/
long int convert_size_number(long int number, int size)
{
if (size == S_LONG)
return (number);
else if (size == S_SHORT)
return ((short)number);
return ((int)number);
}
/**
* convert_size_unsgnd - Converting a number to the specified size
* @number: Number to be converted
* @size: Number indicating the type to be changed
*
* Return: Converted value of number
*/
long int convert_size_unsgnd(unsigned long int number, int size)
{
if (size == S_LONG)
return (number);
else if (size == S_SHORT)
return ((unsigned short)number);
return ((unsigned int)number);
}
