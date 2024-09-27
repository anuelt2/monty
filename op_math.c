#include "monty.h"

/**
 * add - Adds the top two elements of a stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * sub - Subtracts the top element from the second top element of a stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
