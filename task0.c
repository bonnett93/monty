#include "monty.h"

/**
 * push - Requeriment, but do nothing.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void push(stack_t **head, unsigned int line)
{
	if (head && line)
	{
		;
	}
}

/**
 * pall - Print all n elements of a stack.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void pall(stack_t **head, unsigned int line)
{
	stack_t *tmp = *head;

	(void)line;
	if (*head == NULL)
		return;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
