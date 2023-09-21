#include "monty.h"
#include <stdlib.h>

/**
 * _div -  divides the second top element of the
 * stack by the top element of the stack.
 *
 * @stack: entry point to the stack.
 * @line_number: line where error occurs.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int res;

	current = (*stack)->next;
	res = 0;
	if (current != NULL && current->next != NULL)
	{
		if (current->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		res = (current->next)->n / current->n;
		(*stack)->next = (current->next);
		(current->next)->prev = (*stack);
		(current->next)->n = res;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - multiplies the second top element of the
 * stack with the top element of the stack.
 *
 * @stack: entry point to the stack.
 * @line_number: line where an error first occurs.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int res;

	current = (*stack)->next;
	res = 0;
	if (current != NULL && current->next != NULL)
	{
		res = current->n * (current->next)->n;
		(*stack)->next = (current->next);
		(current->next)->prev = (*stack);
		(current->next)->n = res;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod -  computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 *
 * @stack: entry point to the stack.
 * @line_number: line where an error first occurs.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int res;

	current = (*stack)->next;
	res = 0;
	if (current != NULL && current->next != NULL)
	{
		if (current->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		res = (current->next)->n % current->n;
		(*stack)->next = (current->next);
		(current->next)->prev = (*stack);
		(current->next)->n = res;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
