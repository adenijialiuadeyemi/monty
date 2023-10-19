#include "monty.h"
void mul_nodes(stack_t **stack, unsigned int line_number);
void mod_nodes(stack_t **stack, unsigned int line_number);
/**
 * mul_nodes - multiply nodes
 * @stack: Pointing to stack top node
 * @line_number: opcode line num
 * Return: void
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointing to stack top node
 * @line_number: opcode line num
 * Return: void
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int add_tops;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	add_tops = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = add_tops;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
