#include "monty.h"
stack_t *create_node(int n);
void free_nodes(void);
/**
 * create_node - creating a node
 * @n: integer value
 * Return: nd
 */
stack_t *create_node(int n)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		err(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = n;
	return (nd);
}
/**
 * free_nodes - freeing stack odes
 * Return: void
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
