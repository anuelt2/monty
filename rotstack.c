#include "monty.h"

/**
 * rotl - Swaps the top two elements of a stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *last;

	(void)line_number;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	first = last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}
