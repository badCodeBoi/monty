#include "monty.h"

/**
 * usage_error - Prints usage errors
 * Return: exits
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - Handles malloc errors
 * Return: exits
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints w/ filename errors
 * @filename: name of file that failed to open
 * Return: exit.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - handles unknown instructions errors
 * @opcode: code where these instruction errors were flagged
 * @line_number: line in bytecodes where error flagged 
 * Return: Exits
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - handles invalid push errors
 * @line_number: line in monty code where error flagged
 * Return: Exits
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
