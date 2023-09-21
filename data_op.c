void setData(int n);
int getData(void);
extern int data = 0;
/**
 * setData - sets the data to be appended to stack.
 *
 * @n: integer value to be sent to stack.
 */

void setData(int n)
{
	data = n;
}


/**
 * getData - gets the data stored in the global variable data.
 * Return: value stored in data.
 */

int getData(void)
{
	return (data);
}
