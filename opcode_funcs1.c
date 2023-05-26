include "monty.h"

int push(stack_t **stack, char *word2, unsigned int line_number);

/**
 * push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @word2: An int to use to initialize the stack
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: EXIT_SUCCESS on success and EXIT_FAILURE on failure.
 */
int push(stack_t **stack, char *word2, unsigned int line_number)
{
        stack_t *tmp, *newnode;

        newnode = malloc(sizeof(stack_t));
        if (newnode == NULL)
                return (EXIT_FAILURE);

        if (word2 == NULL || (atoi(word2) == 0)) 
        {
                fprintf(stdout, "L%u: usage: push integer\n", line_number);
                return (EXIT_FAILURE);
        }

        newnode->n = atoi(word2);
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
 * Return: EXIT_SUCCESS on success and EXIT_FAILURE on failure.
 */
int pall(stack_t **stack, char *word2, unsigned int line_number)
{
        stack_t *temp;

        (void)word2;

        temp = (*stack)->next;

        while (temp)
        {
                printf("%d\n", temp->n);
                temp = temp->next;
        }
        (void)line_number;
        return (EXIT_SUCCESS);
}

