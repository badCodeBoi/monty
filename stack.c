#include "monty.h"

/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the top of the stack.
 *
 * This function frees all the nodes in the stack.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initializes a stack with default mode.
 * @stack: Pointer to the stack.
 *
 * This function initializes the stack with default mode LIFO (STACK).
 */
void init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());
	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;
	*stack = s;
}

/**
 * check_mode - Checks the mode of the stack.
 * @stack: Pointer to the stack.
 *
 * Return: The current mode of the stack (STACK or QUEUE).
 */
int check_mode(stack_t **stack)
{
	if ((*stack)->n == STACK)
		return (STACK);
	else if ((*stack)->n == QUEUE)
		return (QUEUE);
	return (2);
}
