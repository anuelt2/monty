#include "monty.h"

/**
 * call_opcodes - Executes opcode functions
 * @stack: Pointer to top of stack
 *
 * Return: Void
 */

void call_opcodes(stack_t **stack)
{
	int idx;
	instruction_t action_call[] = {
		{"push", push}, {"pall", pall},
		{NULL, NULL}
	};
	if (file_args->args[0] == NULL)
	{
		return;
	}

	idx = 0;
	while (action_call[idx].opcode != NULL)
	{
		if (strcmp(action_call[idx].opcode, file_args->args[0]) == 0)
		{
			action_call[idx].f(stack, file_args->line_number);
			return;
		}
		idx++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n",
		file_args->line_number, file_args->args[0]);
	exit(EXIT_FAILURE);
}

/**
 * check_num - Checks that string is a digit
 * @str: String to check
 *
 * Return: 0 on success
 */

int check_num(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
	{
		i++;
	}

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * free_args - Free array elements
 *
 * Return: Void
 */

void free_args(void)
{
	int idx;

	if (file_args->args != NULL)
	{
		idx = 0;
		while (file_args->args[idx] != NULL)
		{
			free(file_args->args[idx]);
			idx++;
		}
		free(file_args->args);
		file_args->args = NULL;
	}
}
