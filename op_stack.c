#include "monty.h"

/**
 * push - Inserts a new node at the top of a stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;

	(void)line_number;
	if (file_args->args[1] == NULL || !check_num(file_args->args[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", file_args->line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(file_args->args[1]);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
