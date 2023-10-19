#include "monty.h"
/**
 * main - prog entry
 * @argc: arg_c
 * @argv: arg_v
 * Return: success always
 */
stack_t *head = NULL;
int main(int argc, char **argv)
{
	if (argc != 2)
		err(1);
	open_file(argv[1]);
	free_nodes();
	return (0);
}
