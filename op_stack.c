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

/**
 * pop - Removes element at the top of a stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

/**
 * swap - Swaps the top two elements of a stack
 * @stack: Pointer to top of the stack
 * @line_number: Line number of command in file
 *
 * Return: Void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1;
	stack_t *temp_2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp_1 = *stack;
	temp_2 = temp_1->next;
	temp_1->next = temp_2->next;
	if (temp_1->next != NULL)
	{
		temp_1->next->prev = temp_1;
	}
	temp_2->prev = NULL;
	temp_1->prev = temp_2;
	temp_2->next = temp_1;
	*stack = temp_2;
}
