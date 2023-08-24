#include "monty.h"

/**
 * pop_error - handles pop errors for empty stacks
 * @line_number: line in script where error flagged
 * Return: Exit
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - handles pint errors for empty stacks
 * @line_number: line in monty where error flagged
 * Return: Exits
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack too short\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * div_error - handles division errors for trying to divide by 0
 * @line_number: line in code where error was flagged
 * Return: Exits
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - handles pchar errors for empty stacks and non-char values
 * @line_number: line where error was flagged
 * @message: pchar message
 * Return: Exits
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
