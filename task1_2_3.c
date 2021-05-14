#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void pint(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes the top element of the stack.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void pop(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
		return;
	}
	free(*head);
	*head = NULL;
}
