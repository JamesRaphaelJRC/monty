#include "monty.h"
#include <string.h>
#include <stdlib.h>

/**
 * parse_to_func - Matches the opcode with it's corresponding function.
 * @stack: A pointer to the top of the stack
 * @word1: The opcode to match
 * @word2: The next str in the read line
 * @line_no: The current line number
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE otherwise
 */
int parse_to_func(stack_t **stack, char *word1, char *word2, unsigned int line_no)
{
        int i = 0;
        instruction_t op_funcs[] = { 
                {"push", push},
                {"pall", pall},
                {NULL, NULL}
        };

        while (op_funcs[i].opcode)
        {
                if (strcmp(op_funcs[i].opcode, word1) == 0)
                {
                        op_funcs[i].f(stack, word2, line_no);
                        return (EXIT_SUCCESS);
                }
                i++;
        }
        fprintf(stderr, "L%d: unknown instruction %s\n", line_no, word2);
        return (EXIT_FAILURE);
}
