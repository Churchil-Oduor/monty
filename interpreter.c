#include <stdlib.h>
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
	char *file;
	int fd;

	if (args != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = argv[1];
	fd = open(file, O_WRONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	/* implement code to check for valid instructions here */

	return (0);
}
