#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void sub(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line);
		free_mem();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = tmp->n - (*head)->n;
	pop(head, line);
}

/**
 * divided - divides the second top element of the stack by
 * the top element of the stack.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void divided(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line);
		free_mem();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line);
		free_mem();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = tmp->n / (*head)->n;
	pop(head, line);
}

/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack.
 * @head: Pointer to dlinkedlist head.
 * @line: File number line where the instruction is.
 */
void mul(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line);
		free_mem();
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	tmp->n = tmp->n * (*head)->n;
	pop(head, line);
}
