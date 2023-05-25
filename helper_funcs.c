#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <ctype.h>


 void free_stack(stack_t *stack);
 stack_t *queue_node(stack_t **stack, const int n);
 stack_t *add_node(stack_t **stack, const int n);


/**
 * free_stack - frees a dlistint_t linked list
 * @stack: list head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (tmp)
		{
			free(tmp);
			tmp = next;
			if (next)
				next = next->next;
		}
	}
}

/**
 * queue_node - adds a node to a stack_t stack in queue node
 * @stack: stack head
 * @n: number of the node
 *
 * Return: newnly created node, if memory allocation fails, the function will
 * return NULL.
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!newnode)
	{
		free(newnode);
		return (NULL);
	}
	newnode->n = n;

	if (!*stack)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		*stack = newnode;
		return (newnode);
	}

	while (current)
	{
		if (!current->next)
		{
			newnode->next = NULL;
			newnode->prev = current;
			current->next = newnode;
			break;
		}
		current = current->next;
	}

	return (newnode);
}


/**
 * add_node - adds a node to the start of a stack_t stack
 * @stack: stack head
 * @n: number for the newnode node
 *
 * Return: newly created node, if creation fails, the
 * function will return NULL.
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newnode);
		return (NULL);
	}
	newnode->n = n;

	newnode->next = *stack;
	newnode->prev = NULL;
	if (*stack)
		(*stack)->prev = newnode;

	*stack = newnode;

	return (newnode);
}


/**
 * print_stack - prints the contents of a stack_t stack
 * @stack: stack head
 *
 * Return: number of elements of the list
 */
size_t print_stack(const stack_t *stack)
{
	size_t num = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		num++;
	}

	return (num);
}


/**
 * is_digit - checks if a string is a digit
 * @string: string to check
 *
 * Return: 1 if success, 0 if not
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}


/**
 * isnumber - checks if a string is a number
 * @str: provided string
 *
 * Return: 1 if the string is a number, else, 0.
 */
int isnumber(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}
