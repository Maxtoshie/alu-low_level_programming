#include <stdio.h>

/**
 * main - finds and prints the sum of even Fibonacci terms
 *        below 4,000,000
 *
 * Return: Always 0
 */
int main(void)
{
	long int a = 1, b = 2, c, sum = 0;

	while (b <= 4000000)
	{
		if (b % 2 == 0)
			sum += b;
		c = a + b;
		a = b;
		b = c;
	}
	printf("%ld\n", sum);
	return (0);
}
