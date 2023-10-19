#include "monty.h"
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);
void print_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
/**
 * add_to_stack - Append a node to the stack LIFO.
 * (at the start)
 * @new_node: new node pointer
 * @ln: opcode line num.
 * Return: void
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}
/**
 * add_to_queue - Append a node to the queue FIFO.
 * (at the rear)
 * @new_node: new node pointer.
 * @ln: opcode line num.
 * Return: void
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}
/**
 * print_stack - prints nodes in the stack.
 * @stack: Pointing to stack top node
 * @line_number: opcode line number
 * Return: void
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * print_top - output top value
 * @stack: Pointing to the top node
 * @line_number: opcode line number.
 * Return: void
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
/**
 * pop_top - Poping the top value
 * @stack: Pointing to the top.
 * @line_number: opcode line number
 * Return: void
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
