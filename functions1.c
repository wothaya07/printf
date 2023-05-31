#include "main.h"

/****************** OUTPUT UNSIGNED NUMBER IN OCTAL ******************/
/**
 * output_octal - Outputs an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array for output handling
 * @flag: Calculates active flags
 * @width: Width specifier
 * @pres: Precision specifier
 * @size: Size specifier
 * Return: Number of characters outputted
 */
int output_octal(va_list types, char buffer[],
	int flag, int width, int pres, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 8) + '0';
	num /= 8;
	}

	if (flag & F_HASH && init_num != 0)
	buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, pres, size));
}

/***************** OUTPUT UNSIGNED NUMBER IN HEXADECIMAL *****************/
/**
 * output_hexadecimal - Outputs an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array for output handling
 * @flag: Calculates active flags
 * @width: Width specifier
 * @pres: Precision specifier
 * @size: Size specifier
 * Return: Number of characters outputted
 */
int output_hexadecimal(va_list types, char buffer[],
	int flag, int width, int pres, int size)
{
	return (output_hexa(types, "0123456789abcdef", buffer,
	flag, 'x', width, pres, size));
}

/*************** OUTPUT HEX NUMBER IN LOWER OR UPPER CASE ***************/
/**
 * output_hexa - Outputs a hexadecimal number in either lowercase or uppercase
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array for output handling
 * @flag: Calculates active flags
 * @flag_ch: Flag character
 * @width: Width specifier
 * @pres: Precision specifier
 * @size: Size specifier
 * Return: Number of characters outputted
 */
int output_hexa(va_list types, char map_to[], char buffer[],
	int flag, char flag_ch, int width, int pres, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = map_to[num % 16];
	num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
	buffer[i--] = flag_ch;
	buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, pres, size));
}

/******************* OUTPUT UNSIGNED NUMBER *******************/
/**
 * output_unsigned - Outputs an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array for output handling
 * @flag: Calculates active flags
 * @width: Width specifier
 * @pres: Precision specifier
 * @size: Size specifier
 * Return: Number of characters outputted
 */
int output_unsigned(va_list types, char buffer[],
	int flag, int width, int pres, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 10) + '0';
	num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, pres, size));
}

/**************** OUTPUT UNSIGNED NUMBER IN UPPER HEXADECIMAL ****************/
/**
 * output_hexa_upper - Outputs an unsigned no. in uppercase hexadecimal
 * @types: List of arguments
 * @buffer: Buffer array for output handling
 * @flag: Calculates active flags
 * @width: Width specifier
 * @pres: Precision specifier
 * @size: Size specifier
 * Return: Number of characters outputted
 */
int output_hexa_upper(va_list types, char buffer[],
	int flag, int width, int pres, int size)
{
	return (output_hexa(types, "0123456789ABCDEF", buffer, flag,
'X', width, pres, size));
}
