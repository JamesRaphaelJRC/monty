#include "monty.h"
#include <stdlib.h>

int mod(stack_t **stack, unsigned int line_no);
int pchar(stack_t **stack, unsigned int line_no);
int pstr(stack_t **stack, unsigned int line_no);
int rotl(stack_t **stack, unsigned int line_no);
int rotr(stack_t **stack, unsigned int line_no);


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
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;

	return (EXIT_SUCCESS);
}


/**
 * rotl - Rotates stack to the top. The top element becomes the last one and
 *		the second top element becomes the first one
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *tmp;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next->next == NULL)
		return (EXIT_FAILURE);

	last = tmp = (*stack)->next;

	while (last->next != NULL)
		last = last->next;

	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
	tmp->prev = last;

	(void)line_number;

	return (EXIT_SUCCESS);
}


/**
 * rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;

	return (EXIT_SUCCESS);
}
