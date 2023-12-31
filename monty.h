#ifndef MONTY_H
#define MONTY_H

/**** Calls of standard libary ****/
#define  _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

/**** Variables that are global ****/

extern stack_t *head;

/*** TYPEDEF FOR OPCODE FUNCTIONS ****/

typedef void (*op_func)(stack_t **, unsigned int);

/**** FILE OPERATIONS ****/

void file_open(char *);
void file_read(FILE *);
int len_chars(FILE *);
int interpret_line(char *, int, int);
void find_func(char *, char *, int, int);
void func_call(op_func, char *, char *, int, int);

/**** Operations on stack ****/

stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void top_print(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void nodes_swap(stack_t **, unsigned int);

/**** Operations with node based on math ****/

void nodes_sum(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void nodes_mul(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/**** Operations on strings  ****/

void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

/*** STDERROR MESSAGE HANDLERS ****/

void err(int err_code, ...);
void err_more(int err_code, ...);
void strng_err(int err_code, ...);

#endif /* MONTY_H */
