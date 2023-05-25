#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * my_getline - Reads input from a stream.
 * @lineptr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 0;
	ssize_t chars_read = my_getline(lineptr, &bufsize, stream);
	*n = bufsize;
	return chars_read;
}

