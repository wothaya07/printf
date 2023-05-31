#include "main.h"

/**
 * get_flags - Calculates active flags based on a formatted string
 * @format: Formatted string containing flag characters
 * @i: Pointer to an index in the formatted string
 *
 * This function iterates over the characters in the formatted string starting
 * from the index pointed to by 'i' and calculates the active flags based on
 * the encountered flag characters.
 *
 * Return: Calculated flags
 */
int get_flags(const char *format, int *i)
{
    /* Flag characters: - + 0 # ' ' */
    /* Corresponding flag values: 1  2  4  8  16  */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
/* Check if the current character is a flag character */
	for (j = 0; FLAGS_CH[j] != '\0'; j++)
	{
	if (format[curr_i] == FLAGS_CH[j])
	{
/* Activate the corresponding flag */
	flags |= FLAGS_ARR[j];
	break;
	}

/* Break if the current character is not a flag character */
	if (FLAGS_CH[j] == '\0')
		break;
	}

    /* Update the index with the last processed position */
	*i = curr_i - 1;

	return (flags);
}
