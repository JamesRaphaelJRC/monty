#ifndef __MONTY_H__
#define __MONTY_H__


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

#define DELIM " ,\n\t\r"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	int (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *line[1024];


/* opcode functions */
int push(stack_t **stack, unsigned int line_number);
int pall(stack_t **stack, unsigned int line_number);
int pint(stack_t **stack, unsigned int line_no);
int pop(stack_t **stack, unsigned int line_no);
int swap(stack_t **stack, unsigned int line_no);
int add(stack_t **stack, unsigned int line_no);
int nop(stack_t **stack, unsigned int line_no);
int sub(stack_t **stack, unsigned int line_no);
int divi(stack_t **stack, unsigned int line_no);
int mul(stack_t **stack, unsigned int line_no);


/* helper functions */
int parse_to_func(stack_t **stack, unsigned int line_no);
void init_stack(stack_t **stack);
void free_stack(stack_t *stack);
void check_file_PATH(char *path);


#endif /* __MONTY_H__ */
