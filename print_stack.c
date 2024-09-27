#include "monty.h"

/**
 * pall - Prints all elements in a stack
 * @stack: Pointer to top of stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*stack == NULL)
	{
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Prints all elements in a stack
 * @stack: Pointer to top of stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}
