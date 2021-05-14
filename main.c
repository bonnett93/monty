#include "monty.h"
stack_t *head = NULL;

/**
 * main - program that executes Monty 0.98 scripting language.
 * @argc: Amount of program arguments in command line.
 * @argv: Array of arguments.
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_textfile(argv[1]);
	free_mem();
	return (EXIT_SUCCESS);
}

/**
 * read_textfile - Read the file in the argv[1] argument.
 * @filename: argv[1], file that contains Monty script
 */
void read_textfile(const char *filename)
{
	FILE *fd;
	int control = 0;
	unsigned int line = 1;
	char *instruction = NULL;
	size_t bytes_read;

	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (control != EOF)
	{
		control = getline(&instruction, &bytes_read, fd);
		if (control > 1)
		{
			instruction[control - 1] = '\0';
			run_line(instruction, line);
		}
		line++;
	}
	fclose(fd);
	free(instruction);
}

/**
 * free_mem - Free stack memory
 */
void free_mem(void)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
