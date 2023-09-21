#include "monty.h"
#include <stdlib.h>


/**
 * nop - does not do anything.
 * @stack: starting point.
 * @line_number: line where error occurs.
 */
void nop(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{}


/**
 * add - adds the two elements of the stack if they exist.
 *
 * @stack: entry point of program.
 * @line_number: line where error occured
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int res;

	current = (*stack)->next;
	res = 0;
	if (current != NULL && current->next != NULL)
	{
		res = current->n + (current->next)->n;
		(*stack)->next = (current->next);
		(current->next)->prev = (*stack);
		(current->next)->n = res;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * swap - swaps two numbers
 *
 * @stack: programs entry point.
 * @line_number: number where error occured.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = (*stack)->next;
	if (current != NULL && current->next != NULL)
	{
		current->n = (current->next)->n + current->n;
		(current->next)->n = current->n - (current->next)->n;
		current->n = current->n - (current->next)->n;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
