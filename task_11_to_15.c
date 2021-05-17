#include "monty.h"

/**
 * pchar - multiplies the second top element of the stack with
 * the top element of the stack.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void pchar(stack_t **head, unsigned int line)
{
	int x = 127;

	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line);
		free_mem();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > x)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", line);
		free_mem();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
