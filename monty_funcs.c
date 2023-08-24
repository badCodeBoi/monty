#include "monty.h"

/**
 * monty_add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty file.
 * Return: None.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}
