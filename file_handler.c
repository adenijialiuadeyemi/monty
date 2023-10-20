#include "monty.h"
void file_open(char *file_name);
void file_read(FILE *fd);
int interpret_line(char *lineptr, int line_number, int format);
void find_func(char *opcode, char *value, int ln, int format);
void func_call(op_func f, char *op, char *val, int ln, int format);
/**
 * file_open - oening file
 * @file_name: file name
 * Return: void
 */
void file_open(char *file_name)
{
	FILE *file_descr;

	if (file_name == NULL)
		err(2, file_name);
	if (access(file_name, R_OK) == -1)
		err(2, file_name);
	file_descr = fopen(file_name, "r");
	if (file_descr == NULL)
		err(2, file_name);
	file_read(file_descr);
	fclose(file_descr);
}
/**
 * file_read - reading the file
 * @fd: file_descr
 */
void file_read(FILE *fd)
{
	int line_num;
	int fmt;
	char *lp;
	size_t num;

	lp = NULL;
	num = 0;
	fmt = 0;

	for (line_num = 1; getline(&lp, &num, fd) != -1; line_num++)
	{
		fmt = interpret_line(lp, line_num, fmt);
	}
	free(lp);
}
/**
 * interpret_line - interprete line
 * @lineptr: line_ptr
 * @line_number: opcode line no
 * @format: format specifier, 0 if nodes will be entered as a stack
 * 1 if nodes will be entered as a queue
 * Return: 0 if the opcode is stack or 1 if queue
 */
int interpret_line(char *lineptr, int line_number, int format)
{
	const char *delim;
	char *opcode;
	char *val;

	if (lineptr == NULL)
		err(4);
	delim = "\n ";
	opcode = strtok(lineptr, delim);

	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	find_func(opcode, val, line_number, format);
	return (format);
}
/**
 * find_func - finding the func to run the opcode
 * @opcode: opr code
 * @value: possible value
 * @ln: line num
 * @format: format specifier, 0 if nodes will be entered as a stack
 * 1 if nodes will be entered as a queue
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int c;
	int flg;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", top_print},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", nodes_swap},
		{"add", nodes_sum},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", nodes_mul},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (flg = 1, c = 0; func_list[c].opcode != NULL; c++)
	{
		if (strcmp(opcode, func_list[c].opcode) == 0)
		{
			func_call(func_list[c].f, opcode, value, ln, format);
			flg = 0;
		}
	}
	if (flg == 1)
		err(3, ln, opcode);
}
/**
 * func_call - func call
 * @f: func to called pointr
 * @op: str opcode repr
 * @val: str repr num
 * @ln: instr line no
 * @format: fmt specifier, 0 if nodes will be entered as a stack
 * 1 if nodes will be entered as a queue
 * Return: void
 */
void func_call(op_func f, char *op, char *val, int ln, int format)
{
	stack_t *nd;
	int flg;
	int c;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (c = 0; val[c] != '\0'; c++)
		{
			if (isdigit(val[c]) == 0)
				err(5, ln);
		}
		nd = create_node(atoi(val) * flg);
		if (format == 0)
			f(&nd, ln);
		if (format == 1)
			add_to_queue(&nd, ln);
	}
	else
		f(&head, ln);
}
