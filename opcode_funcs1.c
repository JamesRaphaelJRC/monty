#include "monty.h"

int push(stack_t **stack, unsigned int line_number);
int pall(stack_t **stack, unsigned int line_number);


/**
 * push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc faile\n");
		return (EXIT_FAILURE);
	}

	if (line[1] == NULL || (atoi(line[1]) == 0))
	{
		fprintf(stdout, "L%u: usage: push integer\n", line_number);
		return (EXIT_FAILURE);
	}

	newnode->n = atoi(line[1]);
	tmp = (*stack)->next;
	newnode->prev = *stack;
	newnode->next = tmp;
	if (tmp)
		tmp->prev = newnode;
	(*stack)->next = newnode;

	return (EXIT_SUCCESS);
}


/**
 * pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)line_number;
	return (EXIT_SUCCESS);
}
