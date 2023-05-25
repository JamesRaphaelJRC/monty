#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>


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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @arg: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int data_struct;
	char *arg;
} help;
help global;


#define OPCODES { \
	{"push", push},\
	{"pall", pall},\
	{NULL, NULL} \
}

#define DELIM " \n\t\a\b"
extern int status;

/* opcodes */
void push(stack_t **stack, unsigned int line_cnt);
void pall(stack_t **stack, unsigned int line_cnt);
void pint(stack_t **stack, unsigned int line_cnt);
void swap(stack_t **stack, unsigned int line_cnt);
void pop(stack_t **stack, unsigned int line_cnt);
void nop(stack_t **stack, unsigned int line_cnt);

/* helper_functions */
void run_opcode(stack_t **stack, char *str, unsigned int line_no);
void free_stack(stack_t *stack);
stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
int is_digit(char *string);
int isnumber(char *str);
size_t print_stack(const stack_t *stack);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

#endif
