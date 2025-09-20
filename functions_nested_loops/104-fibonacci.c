#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers starting with 1 and 2
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long int a = 1, b = 2, c;
	unsigned long int a1, a2, b1, b2, c1, c2;
	int i;

	printf("%lu, %lu", a, b);

	/* print first 92 numbers using unsigned long int */
	for (i = 3; i <= 92; i++)
	{
		c = a + b;
		printf(", %lu", c);
		a = b;
		b = c;
	}

	/* split a and b into high and low parts (billions) */
	a1 = a / 1000000000;
	a2 = a % 1000000000;
	b1 = b / 1000000000;
	b2 = b % 1000000000;

	/* print remaining numbers up to 98 */
	for (; i <= 98; i++)
	{
		c1 = a1 + b1;
		c2 = a2 + b2;
		if (c2 >= 1000000000)
		{
			c2 -= 1000000000;
			c1++;
		}
		printf(", %lu%09lu", c1, c2);

		a1 = b1;
		a2 = b2;
		b1 = c1;
		b2 = c2;
	}
	printf("\n");
	return (0);
}
