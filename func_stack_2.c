#include "monty.h"
void nop(stack_t **stack, unsigned int line_number);
void nodes_swap(stack_t **stack, unsigned int line_number);
void nodes_sum(stack_t **stack, unsigned int line_number);
void sub_nodes(stack_t **stack, unsigned int line_number);
void div_nodes(stack_t **stack, unsigned int line_number);
/**
 * nop - This does nothing
 * @stack: pointer ot to node of stack.
 * @line_number: opcode line num.
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * nodes_swap - swap nodes
 * @stack: pointing to top node
 * @line_number: opcode line num
 * Return: void
 */
void nodes_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_more(8, line_number, "swap");

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
/**
 * nodes_sum - sum top nodes
 * @stack: pointing to top node
 * @line_number: opcode line num
 * Return: void
 */
void nodes_sum(stack_t **stack, unsigned int line_number)
{
	int add_tops;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_more(8, line_number, "add");

	(*stack) = (*stack)->next;
	add_tops = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add_tops;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * sub_nodes - sub nodes of a stack.
 * @stack: Pointint to top node of stack.
 * @line_number: opcode line number.
 * Return: void
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int add_tops;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err_more(8, line_number, "sub");


	(*stack) = (*stack)->next;
	add_tops = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = add_tops;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * div_nodes - Add top elements of stack.
 * @stack: Pointing to top node of stack.
 * @line_number: opcode line num
 * Return: void
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int add_tops;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_more(8, line_number, "div");

	if ((*stack)->n == 0)
		err_more(9, line_number);
	(*stack) = (*stack)->next;
	add_tops = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = add_tops;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
