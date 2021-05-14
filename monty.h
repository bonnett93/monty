#ifndef MONTY_H
#define MONTY_H

/* --Headers-- */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>

/* --Structures-- */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* --Global extern variables-- */
extern stack_t *head;


/* --Functions-- */

/*main*/
void read_textfile(const char *filename);

void free_mem(void);

/*calls*/
void run_line(char *instruction, unsigned int line);

void find_match(char *opcode, char *n, unsigned int line);

void new_node(char *n, unsigned int line);

/*task0*/
void push(stack_t **head, unsigned int n);

void pall(stack_t **head, unsigned int n);

/*task_1_to_5*/
void pint(stack_t **head, unsigned int n);

void pop(stack_t **head, unsigned int n);

void swap(stack_t **head, unsigned int line);

void add(stack_t **head, unsigned int line);

void nop(stack_t **head, unsigned int line);

/*task_6_to_9*/
void sub(stack_t **head, unsigned int line);

void divided(stack_t **head, unsigned int line);

void mul(stack_t **head, unsigned int line);

#endif
