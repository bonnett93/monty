#include "monty.h"

/**
 * sub - prints the value at the top of the stack, followed by a new line.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void sub(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line);
		free_mem();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = tmp->n - (*head)->n;
	pop(head, line);
}
