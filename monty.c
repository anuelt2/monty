#include "monty.h"

file *file_args = NULL;

/**
 * main - Entry point
 * @argc: Number of commandline arguments
 * @argv: Pointer to array of commandline arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char **argv)
{
	char *line;
	stack_t *stack, *temp;

	stack = NULL;
	(void) argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init_file_args();
	file_args->stream = fopen(argv[1], "r");
	if (file_args->stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line = readline()) != NULL)
	{
		tokenize();
		call_opcodes(&stack);
		free_args();
		free(file_args->buf);
		file_args->buf = NULL;
	}
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}

	fclose(file_args->stream);
	free(file_args->buf);
	free(file_args);

	return (0);
}
