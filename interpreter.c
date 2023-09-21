#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "monty.h"


/**
 * main - entry point to the monty interpreter.
 *
 * @args: number of file names passed to the interpreter.
 * @argv: file name passed onto the interpreter.
 * Return: 0 always else 1.
 */

int main(int args, char **argv)
{
	FILE *file;
	char line[512];
	int line_num, index;
	stack_t *head;
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"add", add},
		{"swap", swap},
	};

	if (args != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_num = 1;
	index = 0;
	head = malloc(sizeof(head));
	if (head == NULL)
		exit(EXIT_FAILURE);
	head->n = -1;
	head->prev = NULL;
	head->next = NULL;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		char **response;

		if (line[0] != '\n' /*|| (line[0] != '\r' && line[1] != '\n')*/)
		{
			response = tokenizer(line);
			index = handleInstruction(response[0]);
			if (index == -1)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, response[0]);
				exit(EXIT_FAILURE);
			}
			if (index == 0)
			{
				if (response[1] == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_num);
					exit(EXIT_FAILURE);
				}
			}
			if (index == 0)
				setData(atoi(response[1]));
			if (index != -1)
				instruct[index].f(&head, line_num);
		}
		line_num++;
	}
	fclose(file);
	return (0);
}

/**
 * tokenizer - tokenizes the strings to obtain the instruction.
 * @instruction: instruction to be tokenized.
 * Return: array of strings NULL terminated.
 */

char **tokenizer(char *instruction)
{
	char *token, **result;
	int count;

	result = malloc(sizeof(char **) * 1024);
	count = 0;

	token = strtok(instruction, " \n");
	if (strcmp(token, "pall") == 0)
	{
		result[0] = "pall";
		return (result);
	}

	while (token != NULL)
	{
		result[count] = token;
		token = strtok(NULL, " ");
		count++;
	}
	return (result);
}

/**
 * handleInstruction - checks and returns the index of instruction
 * in the instruction struct array.
 *
 * @instruction: instruction passed.
 * Return: index of instructiion.
 */

int handleInstruction(char *instruction)
{
	if (strcmp(instruction, "push") == 0)
		return (0);
	else if (strcmp(instruction, "pall") == 0)
		return (1);
	else if (strcmp(instruction, "pint") == 0)
		return (2);
	else if (strcmp(instruction, "pop") == 0)
		return (3);
	else if (strcmp(instruction, "nop") == 0)
		return (4);
	else if (strcmp(instruction, "add") == 0)
		return (5);
	else if (strcmp(instruction, "swap") == 0)
		return (6);
	else
		return (-1);
}
