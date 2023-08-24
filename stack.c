#include "monty.h"

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

int check_mode(stack_t **stack)
{
	if ((*stack)->n == STACK)
		return (STACK);
	else if ((*stack)->n == QUEUE)
		return (QUEUE);
	return (2);
}
