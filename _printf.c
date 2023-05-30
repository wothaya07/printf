#include <unistd.h>
#include "main.h"

/**
 * _printf - THe name of the function
 * @format: The format string representing the output format
 * Return:number of chars printed
 */


int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flag, width, pres, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				output_buffer(buffer, &buff_index)

					printed_chars++;
		}
		else
		{
			output_buffer(buffer, &buff_index);
			flag = get_flags(format, &i);
			width = get_width(format, &i, list);
			pres = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer, flag, width, pres, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	output_buffer(buffer, &buffer_index);
;
	va_end(list);

	return (printed_chars);
}

/**
 * output_buffer - The contents of the buffer are printed if available
 * @buffer : array of chars
 * @buff_index: length of the buffer
 */

void output_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}


