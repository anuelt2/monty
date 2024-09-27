#include "monty.h"

/**
 * readline - Reads line from file
 *
 * Return: Buffer holding read line
 */

char *readline(void)
{
	ssize_t char_read;
	size_t len;

	len = 0;
	char_read = getline(&file_args->buf, &len, file_args->stream);
	if (char_read == -1)
	{
		if (feof(file_args->stream))
		{
			return (NULL);
		}
		else
		{
			fprintf(stderr, "Error");
			free(file_args->buf);
			exit(EXIT_FAILURE);
		}
	}
	file_args->line_number++;

	return (file_args->buf);
}

/**
 * init_file_args - Initializes members of file struct
 *
 * Return: Void
 */

void init_file_args(void)
{
	file_args = malloc(sizeof(file));
	if (file_args == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	file_args->stream = NULL;
	file_args->buf = NULL;
	file_args->line_number = 0;
}

/**
 * tokenize - Tokenizes data from stream
 *
 * Return: Void
 */

void tokenize(void)
{
	int token_count = 0, index = 0, buf_len = strlen(file_args->buf) + 1;
	char *buf_cpy, *token;

	buf_cpy = malloc(buf_len);
	if (buf_cpy == NULL)
		malloc_fail();
	strcpy(buf_cpy, file_args->buf);
	token = strtok(buf_cpy, " \n");
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, " \n");
	}
	file_args->args = malloc(sizeof(char *) * (token_count + 1));
	if (file_args->args == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(buf_cpy);
		exit(EXIT_FAILURE);
	}
	strcpy(buf_cpy, file_args->buf);
	token = strtok(buf_cpy, " \n");
	while (token != NULL)
	{
		file_args->args[index] = strdup(token);
		if (file_args->args[index] == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			while (--index >= 0)
				free(file_args->args[index]);
			free(file_args->args);
			free(buf_cpy);
			exit(EXIT_FAILURE);
		}
		index++;
		token = strtok(NULL, " \n");
	}
	file_args->args[index] = NULL;
	free(buf_cpy);
}

/**
 * malloc_fail - Handles malloc failure
 *
 * Return: Void
 */

void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
