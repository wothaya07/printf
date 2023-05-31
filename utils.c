#include "main.h"

/**
 * isPrintable - Checks if a character is printable
 * @c: Character to be checked.
 *
 * Return: 1 if c is printable, 0 otherwise.
 */
int isPrintable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
 * appendHexCode - Appends ASCII in hexadecimal code to the buffer.
 * @buffer: Array of characters.
 * @i: Index at which to start appending.
 * @asciiCode: ASCII code.
 * Return: Always 3.
 */
int appendHexCode(char asciiCode, char buffer[], int i)
{
char mapTo[] = "0123456789ABCDEF";
/* The hexadecimal format code is always 2 digits long */
if (asciiCode < 0)
asciiCode *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = mapTo[asciiCode / 16];
buffer[i] = mapTo[asciiCode % 16];

return (3);
}
