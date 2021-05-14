#include "monty.h"

/**
 * run_line - Get a Monty script, parse it and call find_match function.
 * @instruction: Monty script line.
 * @line: File number line where the instruction is.
 */
void run_line(char *instruction, unsigned int line)
{
	char *opcode, *n;

	opcode = strtok(instruction, " ");
	if (opcode == NULL)
		return;
	n = strtok(NULL, " ");
	find_match(opcode, n, line);
}

/**
 * find_match - find the function to execute.
 * @opcode: Monty opcode to execute.
 * @n: The value of node estructure.
 * @line: File number line where the instruction is.
 */
void find_match(char *opcode, char *n, unsigned int line)
{
	int i, match = 99;

	instruction_t match_array[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	for (i = 0; match_array[i].opcode; i++)
	{
		if (strcmp(opcode, match_array[i].opcode) == 0)
		{
			match = i;
			break;
		}
	}
	if (match == 99)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
	if (match == 0)
		new_node(n, line);
	else
		match_array[match].f(&head, line);
}

/**
 * new_node - Create a node and add to stack top.
 * @n: The value of node estructure.
 * @line: File number line where the instruction is.
 */
void new_node(char *n, unsigned int line)
{
	int j = 0;
	stack_t *new;

	if (n == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	if (n[0] == '-')
		j = 1;
	for (; n[j]; j++)
	{
		if (isdigit(n[j]) == 0)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(n);
	new->prev = NULL;
	new->next = head;
	if (head != NULL)
		(head)->prev = new;
	head = new;
}
