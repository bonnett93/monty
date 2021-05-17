#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
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

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void pstr(stack_t **head, unsigned int line)
{
	stack_t *tmp = *head;

	(void)line;
	while (tmp != NULL)
	{
		if ((tmp->n <= 0 || tmp->n > 127))
		{
			break;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void rotl(stack_t **head, unsigned int line)
{
	
	int x = 0;
	stack_t *tmp = *head;

	(void)line;
	if (*head == NULL || (*head)->next == NULL)
		return;

	x = (*head)->n;
	while(tmp->next != NULL)
	{
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
	tmp->n = x;
}
