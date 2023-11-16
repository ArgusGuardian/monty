#ifndef __MONTY_H_
#define __MONTY_H_
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
extern char **arguments;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void read_line(FILE *file);
int brain(stack_t **head, unsigned int counter);
int _isdigit(char *str);
void error_handler(char *line, FILE *file, unsigned int counter, stack_t *head);
void free_stack(stack_t *head);
void free_for_all(char *line, FILE *file, stack_t *head, char **arguments);
int check_line(char *line);
void push_stack(stack_t **head, unsigned int counter);
void pall_stack(stack_t **head, unsigned int counter);
void pint_stack(stack_t **head, unsigned int counter);
void pop_stack(stack_t **head, unsigned int counter);
void swap_stack(stack_t **head, unsigned int counter);

#endif
