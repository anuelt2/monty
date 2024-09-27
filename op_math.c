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

/**
 * _div - Divides the second top element by the top element of a stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = quotient;
}

/**
 * mul - Multiplies the second top element with the top element of a stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = product;
}
