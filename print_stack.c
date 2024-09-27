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
	if (stack == NULL || *stack == NULL)
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
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to top of stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Pointer to top of stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Pointer to top of stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
		{
			break;
		}
		else
		{
			fprintf(stdout, "%c", temp->n);
			temp = temp->next;
		}
	}
	fprintf(stdout, "\n");
}
