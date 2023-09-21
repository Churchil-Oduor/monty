#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

stack_t *createNode(int data);
/**
 * push - pushes element onto stack.
 *
 * @stack: a node of the stack to be pushed to the stack.
 * @line_number: the number of the line where
 * instruction has been read beginnning from 1.
 */

void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new;
	int data;

	data = getData();
	new = createNode(data);
	new->prev = (*stack);
	new->next = (*stack)->next;
	(*stack)->next = new;
}

/**
 * pall - prints the stack elements.
 *
 * @stack: stack.
 * @line_number: number where error occured.
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	current = (*stack)->next;
	if (current != NULL)
	{
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}

/**
 * createNode - creates node to be pushed to the stack.
 * @data: data to be stored into the node.
 * Return: node.
 */

stack_t *createNode(int data)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		/**
		 * appropriate stderror msg required using fprintf
		 */
		exit(EXIT_FAILURE);
	}

	node->n = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/**
 * pint - prints the object at the top of the stack.
 *
 * @stack: stack entry point.
 * @line_number: number where error occurred.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next != NULL)
		printf("%d\n", ((*stack)->next)->n);
	else
	{
		printf("L%d: can't pint, stack empty\n", line_number);
	}
}

/**
 * pop - removes the element at the stop of the stack.
 *
 * @stack: entry point of the stack.
 * @line_number: number where error occurs.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = (*stack)->next;
	if (current != NULL)
	{
		if (current->next != NULL)
		{
			(*stack)->next = current->next;
			(current->next)->prev = (*stack);
		}
		else
		{
			(*stack)->next = NULL;
		}
	}
	else
		printf("L%d: can't pop an empty stack\n", line_number);
}
