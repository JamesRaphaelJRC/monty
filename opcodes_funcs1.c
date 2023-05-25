#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_no: ammount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_no)
{
	char *n = global.arg;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		status = EXIT_FAILURE;
		return;
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.arg)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.arg)))
		{
			return;
			status = EXIT_FAILURE;
		}
	}
}


/**
 * pall - prints the stack
 * @stack: stack given by main
 * @line_no: ammount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_no __attribute__((unused)))
{
	print_stack(*stack);
}


/**
 * pint - print the top data
 * @stack: stack given by main
 * @line_no: ammount of lines
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_no)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}


/**
* pop - pops the very top
* @stack: stack given by main
* @line_no: line number for error messages
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
		status = EXIT_FAILURE;
		return;
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}


/**
 * swap -  swaps data from top to previous
 * @stack: stack given by main
 * @line_no: ammount of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		status = EXIT_FAILURE;
		return;
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;

}
