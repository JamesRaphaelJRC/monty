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
		exit(EXIT_FAILURE);
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


/**
 * pint - Prints the value at the top of the stack
 * @stack: A pointer to the top of the stack
 * @line_no: The current line number.
 *
 * Return: EXIT_SUCCESS on success
 */
int pint(stack_t **stack, unsigned int line_no)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		 exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->next->n);

	return (EXIT_SUCCESS);
}


/**
 * pop - Removes the top element of a stack_t linked list
 * @stack: A pointer to the top node of the list
 * @line_no: The current line_number
 *
 * Return: EXIT_SUCCESS on success.
 */
int pop(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->prev = NULL;
	(*stack)->next = NULL;
	free(*stack);
	*stack = tmp;

	return (EXIT_SUCCESS);
}


/**
 * swap - Swaps the top two elements of a staack_t linked list.
 * @stack: A pointer to the top node of the list.
 * @line_no: The current line number
 *
 * Return: EXIT_SUCCESS on success.
 */
int swap(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	if ((*stack)->next->next == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;

	exit(EXIT_SUCCESS);
}
