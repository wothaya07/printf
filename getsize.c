#include "main.h"

/**
 * get_size - Determines the size to use for casting the argument
 * @format: The formatted string specifying the arguments
 * @i: Pointer to the current index in the format string
 * Return: The size to use for casting the argument
*/
int get_size(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;

/* Check if the next character after '%' is 'l' for long */
if (format[curr_i] == 'l')
size = S_LONG;
/* Check if the next character after '%' is 'h' for short */
else if (format[curr_i] == 'h')
size = S_SHORT;

/* If the size is still 0, it means no size specifier was found */
if (size == 0)
*i = curr_i - 1; /* Reset the index to the current position */
else
*i = curr_i;

return (size);
}
