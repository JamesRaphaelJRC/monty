#include "monty.h"
#include <stdlib.h>

int mod(stack_t **stack, unsigned int line_no);
int pchar(stack_t **stack, unsigned int line_no);
int pstr(stack_t **stack, unsigned int line_no);


/**
 * mod -computes the rest of the division of the second top element of the
 *      stack by the top element of the stack stack,
 *      stores the result in the second top element and removes
 *      the top.
 * @stack: A pointer to the top element of the stack.
 * @line_no: The current line number.
 *
 * Return: EXIT_SUCCESS on success.
 */
int mod(stack_t **stack, unsigned int line_no)
{
	int status;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	status = pop(stack, line_no);

	return (status);
}


/**
 * pchar - Prints the char at the top of the stack
 * @stack: A pointer to the top of the stack
 * @line_no: The current line number.
 *
 * Return: EXIT_SUCCESS on success
 */
int pchar(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_no);
		 exit(EXIT_FAILURE);
	}

	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_no);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->next->n);

	return (EXIT_SUCCESS);
}


/**
 * pstr - prints the string starting at the top of the stack, followed by a
 *		new line
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL)
		exit(EXIT_FAILURE);

	temp = (*stack)->next;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;

		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)line_number;
	return (EXIT_SUCCESS);
}
