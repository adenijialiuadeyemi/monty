#include "monty.h"

stack_t *head = NULL;

/**
 * main - prog entry
 * @argc: arg_c
 * @argv: arg_v
 * Return: success always
 */

int main(int argc, char **argv)
{
	if (argc != 2)
		err(1);
	head = NULL;
	file_open(argv[1]);
	free_nodes();
	return (0);
}
