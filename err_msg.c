#include "monty.h"
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
/**
 * err - err msgs based on error code.
 * @error_code: The following are the error codes:
 * (1) -> no file was gi en.
 * (2) -> file can't be opened or read.
 * (3) -> file containing invalid instruction.
 * (4) -> unable to alloc more memory.
 * (5) -> When the passed param "push" is not an int.
 * (6) -> empty stack for pint.
 * (7) -> stack empty for pop.
 * (8) -> too short for opr.
 * Return: nothing
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - err handlers.
 * @error_code: The following err codes:
 * (6) -> empty stack for pint.
 * (7) -> empty stack for pop.
 * (8) -> too short for opr.
 * (9) -> zero division
 * Return: void
 */
void more_err(int error_code, ...)
{
	va_list arg;
	char *opr;
	int num_len;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			num_len = va_arg(arg, unsigned int);
			opr = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num_len, opr);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - err handler.
 * @error_code: The following are the err codes:
 * (10) -> The node no is outside the boundary if ASCII
 * (11) -> Empty stack.
 * Return: void
 */
void string_err(int error_code, ...)
{
	va_list arg;
	int num_len;

	va_start(arg, error_code);
	num_len = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num_len);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num_len);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
