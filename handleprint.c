#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @formatString: Formatted string specifying the printing format
 * @currentIndex: Pointer to the current index of the format string
 * @argumentList: List of arguments for printing
 * @printBuffer: Buffer array to handle printing
 * @flag: Active flags for formatting
 * @printWidth: Width specification
 * @pres: Precision specification
 * @printSize: Size specifier
 *
 * This function handles the printing of an argument based on its type and
 * format specifier. It searches for the appropriate format specifier in the
 * fmt_types array and invokes the corresponding printing function.
 *
 * Return: Number of characters printed on success, -1 if an unknown format
 *         specifier is encountered.
 */
int handle_print(const char *formatString, int *currentIndex,
va_list argumentList, char printBuffer[],
	int flag, int printWidth, int pres, int printSize)
{
	int i, unknown_len = 0, printed_chars = -1;

/* Array of format types and their associated printing functions */
	fmt_t fmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

/* Iterate over the format types array to find the matching format specifier */
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
	if (formatString[*currentIndex] ==
			fmt_types[i].fmt)
	return (fmt_types[i].fn(argumentList, printBuffer, flag,
			printWidth, pres, printSize));
	}

/* Handle the case of an unknown format specifier */
	if (fmt_types[i].fmt == '\0')
	{
	if (formatString[*currentIndex] == '\0'
			return (-1);

/* Print the literal '%' character */
	unknown_len += write(1, "%%", 1);

/* Handle the flag for space padding */
	if (formatString[*currentIndex - 1] == ' unknown_len += write(1, " ", 1);
	else if (printWidth)
	{
/* Adjust the index to the previous non-space character */
	--(*currentIndex);
	while (formatString[*currentIndex]
			!= ' ' && formatString[*currentIndex] != '%' )
		--(*currentIndex);

/* Adjust the index to skip the current format specifier */
	if (formatString[*currentIndex] == ' ')
	--(*currentIndex);

	return 1;
	}

/* Print the unknown format specifier */
	unknown_len += write(1, &formatString[*currentIndex], 1);
	return unknown_len;
	}

	return printed_chars;
}

