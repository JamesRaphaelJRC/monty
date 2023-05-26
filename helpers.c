#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


/**
 * init_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
stack_t *init_stack(stack_t **stack)
{
        stack_t *s; 

        s = malloc(sizeof(stack_t));
        if (s == NULL)
                return (NULL);

        s->n = 0;
        s->prev = NULL;
        s->next = NULL;

        *stack = s;

        return (*stack);
}
